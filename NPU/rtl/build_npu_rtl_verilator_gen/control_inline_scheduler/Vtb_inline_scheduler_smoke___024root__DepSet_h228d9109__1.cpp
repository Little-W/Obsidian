// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_inline_scheduler_smoke.h for the primary calling header

#include "Vtb_inline_scheduler_smoke__pch.h"
#include "Vtb_inline_scheduler_smoke__Syms.h"
#include "Vtb_inline_scheduler_smoke___024root.h"

VlCoroutine Vtb_inline_scheduler_smoke___024root___eval_initial__TOP__Vtiming__0__2(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_initial__TOP__Vtiming__0__2\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x12U;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel0;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel0;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel0;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel0;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel0: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x12U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel1;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel1;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel1;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel1;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel1: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x12U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel2;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel2;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel2;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel2;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel2: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x12U;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel3;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel3;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel3;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel3;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel3: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 18\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x13U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x13U;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x13U;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel4;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel4;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel4;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel4;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel4: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x13U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel5;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel5;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel5;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel5;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel5: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x13U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel6;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel6;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel6;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel6;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel6: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x13U;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel7;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel7;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel7;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel7;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel7: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 19\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x14U;
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x14U;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x14U;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel8;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel8;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel8;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel8;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel8: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x14U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel9;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel9;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel9;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel9;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel9: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x14U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel10;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel10;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel10;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel10;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel10: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x14U;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel11;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel11;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel11;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel11;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel11: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 20\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x15U;
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x15U;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x15U;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel12;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel12;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel12;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel12;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel12: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x15U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel13;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel13;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel13;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel13;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel13: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x15U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel14;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel14;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel14;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel14;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel14: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x15U;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel15;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel15;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel15;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel15;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel15: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 21\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x16U;
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x16U;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x16U;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel16;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel16;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel16;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel16;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel16: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x16U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel17;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel17;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel17;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel17;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel17: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x16U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel18;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel18;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel18;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel18;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel18: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x16U;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel19;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel19;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel19;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel19;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel19: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 22\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x17U;
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x17U;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x17U;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel20;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel20;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel20;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel20;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel20: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x17U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel21;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel21;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel21;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel21;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel21: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x17U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel22;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel22;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel22;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel22;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel22: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x17U;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel23;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel23;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel23;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel23;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel23: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 23\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x18U;
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x18U;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x18U;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel24;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel24;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel24;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel24;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel24: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x18U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel25;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel25;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel25;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel25;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel25: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x18U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel26;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel26;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel26;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel26;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel26: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x18U;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel27;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel27;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel27;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel27;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel27: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 24\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x19U;
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x19U;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x19U;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel28;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel28;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel28;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel28;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel28: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x19U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel29;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel29;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel29;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel29;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel29: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x19U;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel30;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel30;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel30;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel30;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel30: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x19U;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel31;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel31;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel31;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel31;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel31: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 25\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x1aU;
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x1aU;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x1aU;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel32;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel32;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel32;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel32;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel32: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x1aU;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel33;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel33;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel33;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel33;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel33: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x1aU;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel34;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel34;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel34;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel34;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel34: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x1aU;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel35;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel35;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel35;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel35;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel35: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 26\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x1bU;
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x1bU;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x1bU;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel36;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel36;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel36;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel36;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel36: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x1bU;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel37;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel37;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel37;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel37;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel37: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x1bU;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel38;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel38;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel38;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel38;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel38: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x1bU;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel39;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel39;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel39;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel39;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel39: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 27\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
}

VlCoroutine Vtb_inline_scheduler_smoke___024root___eval_initial__TOP__Vtiming__0__3(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_initial__TOP__Vtiming__0__3\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*79:0*/ tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__dma_payload;
    VL_ZERO_W(80, tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__dma_payload);
    VlWide<3>/*79:0*/ tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload;
    VL_ZERO_W(80, tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload);
    VlWide<3>/*79:0*/ tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__vector_payload;
    VL_ZERO_W(80, tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__vector_payload);
    VlWide<3>/*79:0*/ tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__complex_payload;
    VL_ZERO_W(80, tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__complex_payload);
    VlWide<3>/*79:0*/ tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload;
    VL_ZERO_W(80, tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload);
    VlWide<4>/*127:0*/ tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command;
    VL_ZERO_W(128, tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command);
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__Vfuncout;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command);
    VlWide<4>/*127:0*/ __Vtask_tb_inline_scheduler_smoke__DOT__submit__16__command;
    VL_ZERO_W(128, __Vtask_tb_inline_scheduler_smoke__DOT__submit__16__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command);
    VlWide<4>/*127:0*/ __Vtask_tb_inline_scheduler_smoke__DOT__submit__18__command;
    VL_ZERO_W(128, __Vtask_tb_inline_scheduler_smoke__DOT__submit__18__command);
    VlWide<4>/*127:0*/ __Vtask_tb_inline_scheduler_smoke__DOT__submit__19__command;
    VL_ZERO_W(128, __Vtask_tb_inline_scheduler_smoke__DOT__submit__19__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command);
    VlWide<4>/*127:0*/ __Vtask_tb_inline_scheduler_smoke__DOT__submit__21__command;
    VL_ZERO_W(128, __Vtask_tb_inline_scheduler_smoke__DOT__submit__21__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command);
    VlWide<4>/*127:0*/ __Vtask_tb_inline_scheduler_smoke__DOT__submit__23__command;
    VL_ZERO_W(128, __Vtask_tb_inline_scheduler_smoke__DOT__submit__23__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command);
    VlWide<4>/*127:0*/ __Vtask_tb_inline_scheduler_smoke__DOT__submit__25__command;
    VL_ZERO_W(128, __Vtask_tb_inline_scheduler_smoke__DOT__submit__25__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command);
    VlWide<4>/*127:0*/ __Vtask_tb_inline_scheduler_smoke__DOT__submit__27__command;
    VL_ZERO_W(128, __Vtask_tb_inline_scheduler_smoke__DOT__submit__27__command);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__compact_opcode;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command_id;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__dtype;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__payload;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__payload);
    VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command);
    // Body
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x1cU;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x1cU;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:392: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: disabled P1 compact opcode 28 was accepted\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 392, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x1dU;
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x1dU;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x1dU;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel0;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel0;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel0;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel0;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel0: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x1dU;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel1;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel1;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel1;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel1;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel1: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x1dU;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel2;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel2;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel2;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel2;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel2: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x1dU;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel3;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel3;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel3;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel3;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel3: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 29\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x1eU;
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x1eU;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:392: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: disabled P1 compact opcode 30 was accepted\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 392, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x1fU;
    VL_SCOPED_RAND_RESET_W(80, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result, __VscopeHash, 10128997844861888519ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
    if ((0x10U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 4U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x400020U;
                    } else {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x80U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0U;
                }
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                     ? 0x204000U : 0x200000U));
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x200000U : 0x200040U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x300000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x200000U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
                } else {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x300U;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
                }
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                        ? 0x40U : 0x1000U);
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x40U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x800300U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0x10U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x20408U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
            }
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] 
                = ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))
                    ? 0x20408U : 0x20240U);
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
        if ((2U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x12345678U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x20000004U;
            } else {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            }
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U] = 0x44U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U] = 0x10000002U;
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] = 0U;
        } else {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U] 
                = (0xf000U | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U]);
        }
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id = 1U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x1fU;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xffffffU & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] 
        = ((0xfffc0000U & vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U]) 
           | (((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype) 
               << 0x10U) | vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload[2U]));
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U];
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x1fU;
                                                {
                                                    if (
                                                        (4U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 0U;
                                                        goto __Vlabel4;
                                                    }
                                                    if (
                                                        (0xaU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 1U;
                                                        goto __Vlabel4;
                                                    }
                                                    if (
                                                        (0xeU 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 2U;
                                                        goto __Vlabel4;
                                                    }
                                                    if (
                                                        (0x18U 
                                                         >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode))) {
                                                        vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 3U;
                                                        goto __Vlabel4;
                                                    }
                                                    vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout = 4U;
                                                    __Vlabel4: ;
                                                }
                                            }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__2__Vfuncout)))) 
                              | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                 != ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x1fU;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode;
                                                    goto __Vlabel5;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x20U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(5U))));
                                                    goto __Vlabel5;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x40U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xbU))));
                                                    goto __Vlabel5;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(0x60U) 
                                                            + 
                                                            ((IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode) 
                                                             - (IData)(0xfU))));
                                                    goto __Vlabel5;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout 
                                                    = 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x86U
                                                          : 0x85U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x84U
                                                          : 0x83U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x82U
                                                          : 0x81U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode))
                                                          ? 0x80U
                                                          : 0xffU)))
                                                       : 0xffU)
                                                      : 0xffU);
                                                __Vlabel5: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_opcode__3__Vfuncout)))) 
                             | ((0xffU & (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                          >> 8U)) != 
                                VL_EXTEND_II(8,4, ([&]() {
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x1fU;
                                            {
                                                if (
                                                    (4U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 0U;
                                                    goto __Vlabel6;
                                                }
                                                if (
                                                    (0xaU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 1U;
                                                    goto __Vlabel6;
                                                }
                                                if (
                                                    (0xeU 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 2U;
                                                    goto __Vlabel6;
                                                }
                                                if (
                                                    (0x18U 
                                                     >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode))) {
                                                    vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 3U;
                                                    goto __Vlabel6;
                                                }
                                                vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout = 4U;
                                                __Vlabel6: ;
                                            }
                                        }(), (IData)(vlSelfRef.__Vfunc_npu_v2_engine__4__Vfuncout))))) 
                            | ((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                >> 0x10U) != ([&]() {
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x1fU;
                                    {
                                        if ((4U >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 0U;
                                            goto __Vlabel7;
                                        }
                                        if ((0xaU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 1U;
                                            goto __Vlabel7;
                                        }
                                        if ((0xeU >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 2U;
                                            goto __Vlabel7;
                                        }
                                        if ((0x18U 
                                             >= (IData)(vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode))) {
                                            vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 3U;
                                            goto __Vlabel7;
                                        }
                                        vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout = 4U;
                                        __Vlabel7: ;
                                    }
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine 
                                        = vlSelfRef.__Vfunc_npu_v2_engine__6__Vfuncout;
                                    vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                            ? 0U : 
                                           ((4U & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0U
                                                  : 0x100U))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0xc0U
                                                  : 0x100U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__engine))
                                                  ? 0x100U
                                                  : 0x40U))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_desc_bytes_for_engine__5__Vfuncout)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 31\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode = 0x17U;
    VL_ZERO_W(80, __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result);
    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0U;
    if ((0x10U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
        if ((8U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
            if ((4U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
                if ((2U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
                    if ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
                        __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x20U;
                        __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x400020U;
                        __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0x10U;
                    }
                } else if ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0U;
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x20U;
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0x10U;
                }
            } else {
                if ((2U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
                    if ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
                        __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 4U;
                        __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x400020U;
                    } else {
                        __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x40U;
                        __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x20U;
                    }
                } else if ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x80U;
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x20U;
                } else {
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x300000U;
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0U;
                }
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0x10U;
            }
        } else if ((4U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x300000U;
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] 
                = ((2U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))
                    ? ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))
                        ? 0xffff0001U : 0x200040U) : 
                   ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))
                     ? 0x204000U : 0x200000U));
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0x10U;
        } else if ((2U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x300000U;
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] 
                = ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))
                    ? 0x200000U : 0x200040U);
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0x10U;
        } else {
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x300000U;
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x200000U;
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0x10U;
        }
    } else if ((8U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
        if ((4U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
            if ((2U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
                if ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x300000U;
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x200000U;
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0x10U;
                } else {
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x40U;
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x300U;
                    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0U;
                }
            } else {
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] 
                    = ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))
                        ? 0x40U : 0x1000U);
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x800300U;
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0x10U;
            }
        } else if ((2U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
            if ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x40U;
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x800300U;
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0x10U;
            } else {
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x20408U;
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x10000002U;
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0U;
            }
        } else {
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] 
                = ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))
                    ? 0x20408U : 0x20240U);
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x10000002U;
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0U;
        }
    } else if ((4U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
        if ((2U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
            if ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x12345678U;
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x20000004U;
            } else {
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x44U;
                __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x10000002U;
            }
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0U;
        } else if ((1U & (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__compact_opcode))) {
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U] = 0x44U;
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U] = 0x10000002U;
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] = 0U;
        } else {
            __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U] 
                = (0xf000U | __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U]);
        }
    }
    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__result[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__payload[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__Vfuncout[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__payload[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__Vfuncout[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__payload[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__8__Vfuncout[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__dtype = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command_id = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__compact_opcode = 0x17U;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__7__Vfuncout[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = (4U | vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         409);
    if (VL_UNLIKELY((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:411: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: VCLAMP accepted a nonzero reserved broadcast field\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 411, "", false);
    }
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[0U] = 0x400000b3U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[1U] = 0x800300U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[2U] = 0x10U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__payload[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__payload[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__payload[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__dtype = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command_id = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__compact_opcode = 0xbU;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__9__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         421);
    if (VL_UNLIKELY(((1U & ((((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                                | (0U != (0xcU & vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0xeU]))) 
                               | (~ (vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x17U] 
                                     >> 2U))) | (1U 
                                                 != 
                                                 vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x27U])) 
                             | (0x1300U != (0xff00U 
                                            & vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x2cU]))) 
                            | ((~ vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x2cU]) 
                               | (0x400ULL != (((QData)((IData)(
                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0xbU])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0xaU])))))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:429: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: inline Matrix output scaling fields are incorrect\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 429, "", false);
    }
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[0U] 
        = (0x3ffffffU & tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[0U]);
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[1U] 
        = (0xffffffc0U & tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[1U]);
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[0U] 
        = (0x40U | (0xffffff80U & tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[0U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__payload[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__payload[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__payload[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__dtype = 3U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command_id = 2U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__compact_opcode = 0xbU;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__10__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         437);
    if (VL_UNLIKELY((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:439: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: inline Matrix accepted INT16 A with b_int4 set\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 439, "", false);
    }
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[1U] 
        = (0xfffffU & tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[1U]);
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[2U] = 0U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[0U] 
        = (0xffffc07fU & tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[0U]);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__payload[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__payload[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__payload[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__dtype = 3U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command_id = 3U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__compact_opcode = 0xeU;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__11__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         447);
    if (VL_UNLIKELY(((1U & (((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                             | (0U != (((((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[2U] 
                                           | vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[3U]) 
                                          | vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[4U]) 
                                         | vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[5U]) 
                                        | vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[6U]) 
                                       | vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[7U]))) 
                            | (0U != vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x12U])))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:451: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: inline Matrix ZERO fields are incorrect\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 451, "", false);
    }
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[2U] 
        = (0x10U | (3U & tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__payload[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__payload[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__payload[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__requant_payload[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__dtype = 3U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command_id = 4U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__compact_opcode = 0xeU;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__12__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         456);
    if (VL_UNLIKELY((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:458: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: inline Matrix ZERO accepted a nonzero A reference\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 458, "", false);
    }
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[0U] = 0x2b40U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[1U] = 0x800300U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[2U] = 0x10U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__payload[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__payload[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__payload[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__dtype = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command_id = 5U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__compact_opcode = 0xcU;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__13__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         467);
    if (VL_UNLIKELY(((1U & ((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                              | (0U != (0xcU & vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0xeU]))) 
                             | (1U != vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x13U])) 
                            | (0xd00U != (0xff00U & 
                                          vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x2cU]))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:472: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: inline Matrix BMM fields are incorrect\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 472, "", false);
    }
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[0U] 
        = (1U | tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[0U]);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__payload[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__payload[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__payload[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__dtype = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command_id = 6U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__compact_opcode = 0xcU;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__Vfuncout[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__Vfuncout[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__Vfuncout[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__14__Vfuncout[3U];
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         477);
    if (VL_UNLIKELY((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:479: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: inline Matrix BMM accepted a reserved payload bit\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 479, "", false);
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__payload[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__payload[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__payload[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__dtype = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command_id = 9U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__compact_opcode = 1U;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__command[3U];
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__Vfuncout[0U];
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__Vfuncout[1U];
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__Vfuncout[2U];
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__15__Vfuncout[3U];
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[2U] 
        = (0x7000000U | (0xffffffU & tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[2U]));
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__16__command[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[0U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__16__command[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[1U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__16__command[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[2U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__16__command[3U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[3U];
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         205);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__16__command[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__16__command[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__16__command[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__16__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)))) {
        co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                             "control/tb_inline_scheduler_smoke.sv", 
                                                             208);
    }
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         209);
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         210);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] = 0U;
    while ((2U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
            [7U])) {
        co_await vlSelfRef.__VtrigSched_h01ef22e1__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (3'h2 == (tb_inline_scheduler_smoke.dut.event_state_q[8'h7])))", 
                                                             "control/tb_inline_scheduler_smoke.sv", 
                                                             487);
    }
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__payload[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__payload[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__payload[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__dtype = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command_id = 0xaU;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__compact_opcode = 2U;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__command[3U];
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__Vfuncout[0U];
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__Vfuncout[1U];
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__Vfuncout[2U];
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__17__Vfuncout[3U];
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[2U] 
        = (0x7000000U | (0xffffffU & tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[2U]));
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__18__command[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[0U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__18__command[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[1U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__18__command[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[2U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__18__command[3U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__event_command[3U];
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         205);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__18__command[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__18__command[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__18__command[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__18__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)))) {
        co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                             "control/tb_inline_scheduler_smoke.sv", 
                                                             208);
    }
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         209);
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         210);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] = 0U;
    while ((1U & (~ ((0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                      [7U]) & (1U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                               [7U]))))) {
        co_await vlSelfRef.__VtrigSched_hd0c76f01__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( ((3'h0 == (tb_inline_scheduler_smoke.dut.event_state_q[8'h7])) & (4'h1 == (tb_inline_scheduler_smoke.dut.event_generation_q[8'h7]))))", 
                                                             "control/tb_inline_scheduler_smoke.sv", 
                                                             494);
    }
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         496);
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         496);
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         496);
    if (VL_UNLIKELY((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                       [7U]) | (1U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                                [7U]))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:499: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: EVENT_REARM was treated as an ordinary signal\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 499, "", false);
    }
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__payload[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__payload[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__payload[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__dtype = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command_id = 0x11U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__compact_opcode = 0U;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__command[3U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__19__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__Vfuncout[0U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__19__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__Vfuncout[1U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__19__command[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__Vfuncout[2U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__19__command[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__20__Vfuncout[3U];
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         205);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__19__command[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__19__command[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__19__command[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__19__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)))) {
        co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                             "control/tb_inline_scheduler_smoke.sv", 
                                                             208);
    }
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         209);
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         210);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] = 0U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__dma_payload[0U] = 0x44U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__dma_payload[1U] = 0x10000002U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__dma_payload[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__payload[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__dma_payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__payload[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__dma_payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__payload[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__dma_payload[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__dtype = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command_id = 0x12U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__compact_opcode = 5U;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__command[3U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__21__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__Vfuncout[0U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__21__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__Vfuncout[1U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__21__command[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__Vfuncout[2U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__21__command[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__22__Vfuncout[3U];
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         205);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__21__command[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__21__command[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__21__command[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__21__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)))) {
        co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                             "control/tb_inline_scheduler_smoke.sv", 
                                                             208);
    }
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         209);
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         210);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] = 0U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[0U] = 0x40U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[1U] = 0x800300U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[2U] = 0x10U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__payload[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__payload[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__payload[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__matrix_payload[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__dtype = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command_id = 0x13U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__compact_opcode = 0xbU;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__command[3U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__23__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__Vfuncout[0U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__23__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__Vfuncout[1U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__23__command[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__Vfuncout[2U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__23__command[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__24__Vfuncout[3U];
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         205);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__23__command[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__23__command[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__23__command[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__23__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)))) {
        co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                             "control/tb_inline_scheduler_smoke.sv", 
                                                             208);
    }
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         209);
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         210);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] = 0U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__vector_payload[0U] = 0x300000U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__vector_payload[1U] = 0x200000U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__vector_payload[2U] = 0x10U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__payload[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__vector_payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__payload[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__vector_payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__payload[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__vector_payload[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__dtype = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command_id = 0x14U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__compact_opcode = 0xfU;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__command[3U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__25__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__Vfuncout[0U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__25__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__Vfuncout[1U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__25__command[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__Vfuncout[2U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__25__command[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__26__Vfuncout[3U];
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         205);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__25__command[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__25__command[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__25__command[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__25__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)))) {
        co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                             "control/tb_inline_scheduler_smoke.sv", 
                                                             208);
    }
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         209);
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         210);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] = 0U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__complex_payload[0U] = 0x80U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__complex_payload[1U] = 0x20U;
    tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__complex_payload[2U] = 0x10U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__payload[0U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__complex_payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__payload[1U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__complex_payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__payload[2U] 
        = tb_inline_scheduler_smoke__DOT__unnamedblk1__DOT__complex_payload[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__dtype = 1U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command_id = 0x15U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__compact_opcode = 0x19U;
    VL_ZERO_W(128, __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command);
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[0U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[1U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[2U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[3U] = 0U;
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[2U] 
        = ((0xffffffU & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[2U]) 
           | ((IData)((0xffffffULL | (((QData)((IData)(
                                                       (0x20U 
                                                        | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__compact_opcode)))) 
                                       << 0x22U) | 
                                      ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command_id)) 
                                       << 0x18U)))) 
              << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[3U] 
        = (((IData)((0xffffffULL | (((QData)((IData)(
                                                     (0x20U 
                                                      | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__compact_opcode)))) 
                                     << 0x22U) | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command_id)) 
                                                  << 0x18U)))) 
            >> 8U) | ((IData)(((0xffffffULL | (((QData)((IData)(
                                                                (0x20U 
                                                                 | (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__compact_opcode)))) 
                                                << 0x22U) 
                                               | ((QData)((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command_id)) 
                                                  << 0x18U))) 
                               >> 0x20U)) << 0x18U));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__payload[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__payload[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[2U]) 
           | (((IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__dtype) 
               << 0x10U) | __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__payload[2U]));
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__Vfuncout[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[0U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__Vfuncout[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[1U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__Vfuncout[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[2U];
    __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__Vfuncout[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__command[3U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__27__command[0U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__Vfuncout[0U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__27__command[1U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__Vfuncout[1U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__27__command[2U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__Vfuncout[2U];
    __Vtask_tb_inline_scheduler_smoke__DOT__submit__27__command[3U] 
        = __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__28__Vfuncout[3U];
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         205);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__27__command[0U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__27__command[1U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__27__command[2U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
        = __Vtask_tb_inline_scheduler_smoke__DOT__submit__27__command[3U];
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)))) {
        co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                             "control/tb_inline_scheduler_smoke.sv", 
                                                             208);
    }
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         209);
    co_await vlSelfRef.__VtrigSched_hb281dc6c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         210);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] = 0U;
    while ((1U & (~ (((((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_active_q)) 
                        & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found)) 
                       & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_active_q)) 
                          & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found))) 
                      & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_active_q)) 
                         & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found))) 
                     & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_active_q)) 
                        & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found)))))) {
        co_await vlSelfRef.__VtrigSched_h995f0f28__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (((((~ tb_inline_scheduler_smoke.dut.dma_active_q) & tb_inline_scheduler_smoke.dut.dma_select_found) & ((~ tb_inline_scheduler_smoke.dut.matrix_active_q) & tb_inline_scheduler_smoke.dut.matrix_select_found)) & ((~ tb_inline_scheduler_smoke.dut.vector_active_q) & tb_inline_scheduler_smoke.dut.vector_select_found)) & ((~ tb_inline_scheduler_smoke.dut.complex_active_q) & tb_inline_scheduler_smoke.dut.complex_select_found)))", 
                                                             "control/tb_inline_scheduler_smoke.sv", 
                                                             538);
    }
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         540);
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         540);
    if (VL_UNLIKELY(((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dfu_request_count)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:543: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: V2 descriptor request count is not zero\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 543, "", false);
    }
    if (VL_UNLIKELY((((((((0x20U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                           [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select]) 
                          | (0x12U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                             [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select])) 
                         | (1U != (0xffU & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                            [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0U] 
                                            >> 8U)))) 
                        | (0x100ULL != (((QData)((IData)(
                                                         vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                         [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                          [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][2U]))))) 
                       | (0x200ULL != (((QData)((IData)(
                                                        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                        [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][9U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][8U]))))) 
                      | (4U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                         [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x12U]))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:550: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: DMA V2 expansion mismatch\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 550, "", false);
    }
    if (VL_UNLIKELY((((((((0x40U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                           [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select]) 
                          | (0x13U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                             [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select])) 
                         | (2U != (0xffU & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                            [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0U] 
                                            >> 8U)))) 
                        | (1U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                           [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x10U])) 
                       | (1U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                          [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x11U])) 
                      | (1U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                         [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x12U]))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:557: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: Matrix V2 expansion mismatch\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 557, "", false);
    }
    if (VL_UNLIKELY(((((((0x60U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                          [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select]) 
                         | (0x14U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                            [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])) 
                        | (3U != (0xffU & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                           [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0U] 
                                           >> 8U)))) 
                       | (1U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                          [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x10U])) 
                      | (1U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                         [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x11U]))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:563: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: Vector V2 expansion mismatch\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 563, "", false);
    }
    if (VL_UNLIKELY((((((((0x80U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                           [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select]) 
                          | (0x15U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                             [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select])) 
                         | (4U != (0xffU & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                            [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0U] 
                                            >> 8U)))) 
                        | (1U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                           [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x10U])) 
                       | (1U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                          [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x11U])) 
                      | (0x3f800000U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                         [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x1cU]))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:570: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1: Complex V2 expansion mismatch\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 570, "", false);
    }
    VL_WRITEF_NX("PASS: CMD128 V2 expands all engine classes with zero DFU requests %0b\n",0,
                 1,(1U & ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_active_q) 
                          ^ ((VL_REDXOR_64(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_addr_q
                                           [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select]) 
                              ^ (VL_REDXOR_32(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                                              [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select]) 
                                 ^ VL_REDXOR_32(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select]))) 
                             ^ ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                                 [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select] 
                                 >> 5U) ^ (((((VL_REDXOR_32(
                                                            (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][1U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][2U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][3U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][4U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][5U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][6U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][7U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][8U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][9U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0xaU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0xbU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0xcU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0xdU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0xeU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0xfU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x10U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x11U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x12U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x13U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x14U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x15U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x16U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x17U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x18U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x19U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x1aU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x1bU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x1cU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x1dU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x1eU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x1fU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x20U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x21U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x22U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x23U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x24U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x25U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x26U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x27U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x28U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x29U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x2aU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x2bU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x2cU]) 
                                                                               ^ 
                                                                               vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                               [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x2dU]) 
                                                                              ^ 
                                                                              vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                              [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x2eU]) 
                                                                             ^ 
                                                                             vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                             [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x2fU]) 
                                                                            ^ 
                                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                            [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x30U]) 
                                                                           ^ 
                                                                           vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                           [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x31U]) 
                                                                          ^ 
                                                                          vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                          [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x32U]) 
                                                                         ^ 
                                                                         vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                         [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x33U]) 
                                                                        ^ 
                                                                        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                        [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x34U]) 
                                                                       ^ 
                                                                       vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                       [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x35U]) 
                                                                      ^ 
                                                                      vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x36U]) 
                                                                     ^ 
                                                                     vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                     [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x37U]) 
                                                                    ^ 
                                                                    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x38U]) 
                                                                   ^ 
                                                                   vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                   [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x39U]) 
                                                                  ^ 
                                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                  [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x3aU]) 
                                                                 ^ 
                                                                 vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                 [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x3bU]) 
                                                                ^ 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x3cU]) 
                                                               ^ 
                                                               vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                               [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x3dU]) 
                                                              ^ 
                                                              vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                              [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x3eU]) 
                                                             ^ 
                                                             vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                             [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select][0x3fU])) 
                                               ^ VL_REDXOR_32(
                                                              (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][1U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][2U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][3U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][4U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][5U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][6U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][7U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][8U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][9U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0xaU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0xbU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0xcU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0xdU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0xeU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0xfU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x10U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x11U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x12U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x13U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x14U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x15U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x16U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x17U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x18U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x19U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x1aU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x1bU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x1cU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x1dU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x1eU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x1fU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x20U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x21U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x22U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x23U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x24U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x25U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x26U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x27U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x28U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x29U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x2aU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x2bU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x2cU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x2dU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x2eU]) 
                                                                               ^ 
                                                                               vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                               [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x2fU]) 
                                                                              ^ 
                                                                              vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                              [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x30U]) 
                                                                             ^ 
                                                                             vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                             [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x31U]) 
                                                                            ^ 
                                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                            [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x32U]) 
                                                                           ^ 
                                                                           vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                           [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x33U]) 
                                                                          ^ 
                                                                          vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                          [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x34U]) 
                                                                         ^ 
                                                                         vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                         [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x35U]) 
                                                                        ^ 
                                                                        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                        [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x36U]) 
                                                                       ^ 
                                                                       vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                       [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x37U]) 
                                                                      ^ 
                                                                      vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x38U]) 
                                                                     ^ 
                                                                     vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                     [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x39U]) 
                                                                    ^ 
                                                                    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x3aU]) 
                                                                   ^ 
                                                                   vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                   [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x3bU]) 
                                                                  ^ 
                                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                  [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x3cU]) 
                                                                 ^ 
                                                                 vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                 [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x3dU]) 
                                                                ^ 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x3eU]) 
                                                               ^ 
                                                               vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                               [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select][0x3fU]))) 
                                              ^ VL_REDXOR_32(
                                                             (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][1U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][2U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][3U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][4U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][5U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][6U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][7U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][8U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][9U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0xaU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0xbU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0xcU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0xdU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0xeU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0xfU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x10U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x11U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x12U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x13U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x14U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x15U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x16U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x17U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x18U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x19U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x1aU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x1bU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x1cU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x1dU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x1eU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x1fU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x20U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x21U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x22U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x23U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x24U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x25U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x26U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x27U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x28U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x29U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x2aU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x2bU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x2cU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x2dU]) 
                                                                               ^ 
                                                                               vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                               [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x2eU]) 
                                                                              ^ 
                                                                              vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                              [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x2fU]) 
                                                                             ^ 
                                                                             vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                             [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x30U]) 
                                                                            ^ 
                                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                            [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x31U]) 
                                                                           ^ 
                                                                           vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                           [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x32U]) 
                                                                          ^ 
                                                                          vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                          [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x33U]) 
                                                                         ^ 
                                                                         vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                         [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x34U]) 
                                                                        ^ 
                                                                        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                        [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x35U]) 
                                                                       ^ 
                                                                       vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                       [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x36U]) 
                                                                      ^ 
                                                                      vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x37U]) 
                                                                     ^ 
                                                                     vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                     [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x38U]) 
                                                                    ^ 
                                                                    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x39U]) 
                                                                   ^ 
                                                                   vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                   [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x3aU]) 
                                                                  ^ 
                                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                  [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x3bU]) 
                                                                 ^ 
                                                                 vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                 [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x3cU]) 
                                                                ^ 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x3dU]) 
                                                               ^ 
                                                               vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                               [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x3eU]) 
                                                              ^ 
                                                              vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                              [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select][0x3fU]))) 
                                             ^ VL_REDXOR_32(
                                                            (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][1U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][2U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][3U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][4U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][5U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][6U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][7U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][8U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][9U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0xaU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0xbU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0xcU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0xdU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0xeU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0xfU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x10U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x11U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x12U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x13U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x14U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x15U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x16U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x17U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x18U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x19U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x1aU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x1bU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x1cU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x1dU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x1eU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x1fU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x20U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x21U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x22U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x23U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x24U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x25U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x26U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x27U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x28U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x29U]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x2aU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x2bU]) 
                                                                                ^ 
                                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x2cU]) 
                                                                               ^ 
                                                                               vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                               [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x2dU]) 
                                                                              ^ 
                                                                              vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                              [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x2eU]) 
                                                                             ^ 
                                                                             vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                             [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x2fU]) 
                                                                            ^ 
                                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                            [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x30U]) 
                                                                           ^ 
                                                                           vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                           [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x31U]) 
                                                                          ^ 
                                                                          vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                          [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x32U]) 
                                                                         ^ 
                                                                         vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                         [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x33U]) 
                                                                        ^ 
                                                                        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                        [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x34U]) 
                                                                       ^ 
                                                                       vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                       [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x35U]) 
                                                                      ^ 
                                                                      vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x36U]) 
                                                                     ^ 
                                                                     vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                     [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x37U]) 
                                                                    ^ 
                                                                    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x38U]) 
                                                                   ^ 
                                                                   vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                   [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x39U]) 
                                                                  ^ 
                                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                  [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x3aU]) 
                                                                 ^ 
                                                                 vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                 [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x3bU]) 
                                                                ^ 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x3cU]) 
                                                               ^ 
                                                               vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                               [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x3dU]) 
                                                              ^ 
                                                              vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                              [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x3eU]) 
                                                             ^ 
                                                             vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                             [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select][0x3fU]))) 
                                            ^ ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found) 
                                               ^ ((
                                                   VL_REDXOR_32(
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select]) 
                                                   ^ 
                                                   (VL_REDXOR_32(
                                                                 vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                                                                 [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select]) 
                                                    ^ 
                                                    (VL_REDXOR_32(
                                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                                                                  [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select]) 
                                                     ^ 
                                                     VL_REDXOR_32(
                                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                                                                  [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select])))) 
                                                  ^ 
                                                  (VL_REDXOR_64(
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_fault_addr_q
                                                                [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select]) 
                                                   ^ 
                                                   (VL_REDXOR_64(
                                                                 vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_progress_q
                                                                 [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select]) 
                                                    ^ 
                                                    ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select] 
                                                      & (0U 
                                                         == 
                                                         vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                                                         [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select])) 
                                                     ^ 
                                                     (((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                                                        [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select] 
                                                        >> 1U) 
                                                       & (0U 
                                                          != 
                                                          vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                                                          [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select])) 
                                                      ^ 
                                                      (~ 
                                                       ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__lookup_rsp_valid) 
                                                        ^ 
                                                        ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__lookup_busy_q) 
                                                         ^ 
                                                         ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_active_q) 
                                                          ^ 
                                                          ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_active_q) 
                                                           ^ 
                                                           ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_active_q) 
                                                            ^ 
                                                            ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_active_q) 
                                                             ^ 
                                                             ((~ 
                                                               ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_active_q) 
                                                                | (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_rsp_valid_q))) 
                                                              ^ 
                                                              ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_rsp_valid_q) 
                                                               ^ 
                                                               VL_REDXOR_64(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_rsp_data_q))))))))))))))))) 
                                           ^ (VL_REDXOR_4(vlSelfRef.tb_inline_scheduler_smoke__DOT__task_query_state) 
                                              ^ (VL_REDXOR_32(
                                                              vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                                                              [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select]) 
                                                 ^ 
                                                 (VL_REDXOR_64(
                                                               vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_fault_addr_q
                                                               [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select]) 
                                                  ^ 
                                                  ((VL_REDXOR_64(
                                                                 vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_progress_q
                                                                 [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select]) 
                                                    ^ 
                                                    VL_REDXOR_32(
                                                                 vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q
                                                                 [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select][0xfU])) 
                                                   ^ 
                                                   (VL_REDXOR_32(
                                                                 vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_signal_q
                                                                 [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select]) 
                                                    ^ 
                                                    (VL_REDXOR_32(
                                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_error_info_q
                                                                  [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select]) 
                                                     ^ 
                                                     (VL_REDXOR_32(
                                                                   vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_done_flags_q
                                                                   [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select]) 
                                                      ^ 
                                                      ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found) 
                                                       ^ 
                                                       (((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_active_q)) 
                                                         & ((0U 
                                                             == (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy)) 
                                                            & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_active_q)) 
                                                               & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_active_q)) 
                                                                  & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_active_q)) 
                                                                     & (~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_active_q))))))) 
                                                        ^ 
                                                        (VL_REDXOR_16(vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy) 
                                                         ^ 
                                                         (VL_REDXOR_32(
                                                                       (((vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] 
                                                                          ^ 
                                                                          vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U]) 
                                                                         ^ 
                                                                         vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U]) 
                                                                        ^ 
                                                                        vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U])) 
                                                          ^ 
                                                          ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o) 
                                                           ^ 
                                                           (VL_REDXOR_4(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                                            ^ 
                                                            (VL_REDXOR_8(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.opcode_o) 
                                                             ^ 
                                                             VL_REDXOR_32(
                                                                          (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0U] 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[1U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[2U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[3U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[4U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[5U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[6U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[7U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[8U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[9U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0xaU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0xbU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0xcU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0xdU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0xeU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0xfU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x10U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x11U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x12U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x13U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x14U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x15U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x16U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x17U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x18U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x19U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x1aU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x1bU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x1cU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x1dU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x1eU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x1fU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x20U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x21U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x22U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x23U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x24U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x25U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x26U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x27U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x28U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x29U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x2aU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x2bU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x2cU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x2dU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x2eU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x2fU]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x30U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x31U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x32U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x33U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x34U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x35U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x36U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x37U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x38U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x39U]) 
                                                                                ^ 
                                                                                vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x3aU]) 
                                                                               ^ 
                                                                               vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x3bU]) 
                                                                              ^ 
                                                                              vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x3cU]) 
                                                                             ^ 
                                                                             vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x3dU]) 
                                                                            ^ 
                                                                            vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x3eU]) 
                                                                           ^ 
                                                                           vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.desc_flat_o[0x3fU]))))))))))))))))))))));
    VL_FINISH_MT("control/tb_inline_scheduler_smoke.sv", 593, "");
}
