// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_inline_scheduler_smoke.h for the primary calling header

#include "Vtb_inline_scheduler_smoke__pch.h"
#include "Vtb_inline_scheduler_smoke__Syms.h"
#include "Vtb_inline_scheduler_smoke___024root.h"

VlCoroutine Vtb_inline_scheduler_smoke___024root___eval_initial__TOP__Vtiming__0__0(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_initial__TOP__Vtiming__0__0\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_inline_scheduler_smoke__DOT__clk = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__reset_n = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd_valid = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[0U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[1U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] = 0U;
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         373);
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         373);
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         373);
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         373);
    vlSelfRef.tb_inline_scheduler_smoke__DOT__reset_n = 1U;
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         375);
    co_await vlSelfRef.__VtrigSched_hb281dba9__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_inline_scheduler_smoke.clk)", 
                                                         "control/tb_inline_scheduler_smoke.sv", 
                                                         375);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0U;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 0\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 1U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 1U;
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
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = (0x1000000U | (0xffffffU & vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U]));
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 1U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 1U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 1U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 1U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 2U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 2U;
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
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = (0x1000000U | (0xffffffU & vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U]));
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 2U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 2U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 2U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 2U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 2\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 3U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 3U;
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
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U] 
        = (0x3000000U | (0xffffffU & vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[2U]));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U] 
        = (0x102U | (0xffff0000U & vlSelfRef.tb_inline_scheduler_smoke__DOT__decode_cmd[3U]));
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "control/tb_inline_scheduler_smoke.sv", 
                                         389);
    if (VL_UNLIKELY(((1U & (((((~ (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.valid_o)) 
                               | ((IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.engine_o) 
                                  != ([&]() {
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 3U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 3U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 3U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 3U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 3\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 4U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 4U;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 4U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 4U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 4U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 4U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 4\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 5U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 5U;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 5U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 5U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 5U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 5U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 5\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 6U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 6U;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 6U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 6U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 6U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 6U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 6\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 7U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 7U;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 7U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 7U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 7U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 7U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 7\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 8U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 8U;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 8U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 8U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 8U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 8U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 8\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 9U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 9U;
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command, __VscopeHash, 317119334941036678ull);
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[0U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[1U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[2U] = 0U;
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command[3U] = 0U;
}

VlCoroutine Vtb_inline_scheduler_smoke___024root___eval_initial__TOP__Vtiming__0__1(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_initial__TOP__Vtiming__0__1\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 9U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 9U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 9U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 9U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 9\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0xaU;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0xaU;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0xaU;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0xaU;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0xaU;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0xaU;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 10\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0xbU;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0xbU;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0xbU;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0xbU;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0xbU;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0xbU;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 11\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0xcU;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0xcU;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0xcU;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0xcU;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0xcU;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0xcU;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 12\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0xdU;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0xdU;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0xdU;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0xdU;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0xdU;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0xdU;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 13\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0xeU;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0xeU;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0xeU;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0xeU;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0xeU;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0xeU;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 14\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0xfU;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0xfU;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0xfU;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0xfU;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0xfU;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0xfU;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 15\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x10U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x10U;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x10U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x10U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x10U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x10U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 16\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x11U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x11U;
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
                                                vlSelfRef.__Vfunc_npu_v2_engine__2__compact_opcode = 0x11U;
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
                                            vlSelfRef.__Vfunc_npu_v2_opcode__3__compact_opcode = 0x11U;
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
                                            vlSelfRef.__Vfunc_npu_v2_engine__4__compact_opcode = 0x11U;
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
                                    vlSelfRef.__Vfunc_npu_v2_engine__6__compact_opcode = 0x11U;
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
        VL_WRITEF_NX("[%0t] %%Fatal: tb_inline_scheduler_smoke.sv:400: Assertion failed in %Ntb_inline_scheduler_smoke.unnamedblk1.unnamedblk2: V2 expansion failed for compact opcode 17\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("control/tb_inline_scheduler_smoke.sv", 400, "", false);
    }
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode = 0x12U;
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
    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode = 0x12U;
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
}
