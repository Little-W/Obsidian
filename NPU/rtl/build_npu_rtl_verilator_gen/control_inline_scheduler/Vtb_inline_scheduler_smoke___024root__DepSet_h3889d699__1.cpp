// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_inline_scheduler_smoke.h for the primary calling header

#include "Vtb_inline_scheduler_smoke__pch.h"
#include "Vtb_inline_scheduler_smoke___024root.h"

VL_INLINE_OPT void Vtb_inline_scheduler_smoke___024root___nba_sequent__TOP__3(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___nba_sequent__TOP__3\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [1U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [1U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [2U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [2U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [2U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [3U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [3U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [3U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 3U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [4U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [4U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [4U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [4U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [4U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [4U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 4U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [5U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [5U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [5U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [5U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [5U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [5U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 5U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [6U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [6U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [6U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [6U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [6U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [6U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 6U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [7U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [7U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [7U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [7U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                     [7U])) {
                    if ((1U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                         [7U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select = 7U;
                        }
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vtb_inline_scheduler_smoke___024root___nba_comb__TOP__0(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___nba_comb__TOP__0\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*11:0*/ __Vfunc_npu_cmd_command_id__29__Vfuncout;
    __Vfunc_npu_cmd_command_id__29__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_command_id__29__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_command_id__29__command);
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_header_flags__30__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_header_flags__30__command);
    SData/*11:0*/ __Vfunc_npu_cmd_wait0__31__Vfuncout;
    __Vfunc_npu_cmd_wait0__31__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_wait0__31__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_wait0__31__command);
    SData/*11:0*/ __Vfunc_npu_cmd_wait1__33__Vfuncout;
    __Vfunc_npu_cmd_wait1__33__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_wait1__33__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_wait1__33__command);
    SData/*11:0*/ __Vfunc_npu_cmd_signal__35__Vfuncout;
    __Vfunc_npu_cmd_signal__35__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_signal__35__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_signal__35__command);
    // Body
    __Vfunc_npu_cmd_wait0__31__command[0U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_wait0__31__command[1U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_wait0__31__command[2U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_wait0__31__command[3U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U];
    __Vfunc_npu_cmd_wait0__31__Vfuncout = (0xfffU & 
                                           ((__Vfunc_npu_cmd_wait0__31__command[3U] 
                                             >> 0x1fU)
                                             ? ([&]() {
                    vlSelfRef.__Vfunc_npu_v2_event_ref__32__event_id 
                        = (0xffU & (__Vfunc_npu_cmd_wait0__31__command[3U] 
                                    >> 8U));
                    vlSelfRef.__Vfunc_npu_v2_event_ref__32__Vfuncout 
                        = ((0xffU == (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__32__event_id))
                            ? 0xfffU : (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__32__event_id));
                }(), (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__32__Vfuncout))
                                             : ((__Vfunc_npu_cmd_wait0__31__command[2U] 
                                                 << 0xcU) 
                                                | (__Vfunc_npu_cmd_wait0__31__command[2U] 
                                                   >> 0x14U))));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0 
        = __Vfunc_npu_cmd_wait0__31__Vfuncout;
    __Vfunc_npu_cmd_wait1__33__command[0U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_wait1__33__command[1U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_wait1__33__command[2U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_wait1__33__command[3U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U];
    __Vfunc_npu_cmd_wait1__33__Vfuncout = (0xfffU & 
                                           ((__Vfunc_npu_cmd_wait1__33__command[3U] 
                                             >> 0x1fU)
                                             ? ([&]() {
                    vlSelfRef.__Vfunc_npu_v2_event_ref__34__event_id 
                        = (0xffU & __Vfunc_npu_cmd_wait1__33__command[3U]);
                    vlSelfRef.__Vfunc_npu_v2_event_ref__34__Vfuncout 
                        = ((0xffU == (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__34__event_id))
                            ? 0xfffU : (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__34__event_id));
                }(), (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__34__Vfuncout))
                                             : __Vfunc_npu_cmd_wait1__33__command[3U]));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1 
        = __Vfunc_npu_cmd_wait1__33__Vfuncout;
    __Vfunc_npu_cmd_signal__35__command[0U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_signal__35__command[1U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_signal__35__command[2U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_signal__35__command[3U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U];
    __Vfunc_npu_cmd_signal__35__Vfuncout = (0xfffU 
                                            & ((__Vfunc_npu_cmd_signal__35__command[3U] 
                                                >> 0x1fU)
                                                ? ([&]() {
                    vlSelfRef.__Vfunc_npu_v2_event_ref__36__event_id 
                        = (__Vfunc_npu_cmd_signal__35__command[2U] 
                           >> 0x18U);
                    vlSelfRef.__Vfunc_npu_v2_event_ref__36__Vfuncout 
                        = ((0xffU == (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__36__event_id))
                            ? 0xfffU : (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__36__event_id));
                }(), (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__36__Vfuncout))
                                                : (
                                                   (__Vfunc_npu_cmd_signal__35__command[3U] 
                                                    << 0x14U) 
                                                   | (__Vfunc_npu_cmd_signal__35__command[3U] 
                                                      >> 0xcU))));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal 
        = __Vfunc_npu_cmd_signal__35__Vfuncout;
    __Vfunc_npu_cmd_command_id__29__command[0U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_command_id__29__command[1U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_command_id__29__command[2U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_command_id__29__command[3U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U];
    __Vfunc_npu_cmd_command_id__29__Vfuncout = (0xfffU 
                                                & ((__Vfunc_npu_cmd_command_id__29__command[3U] 
                                                    >> 0x1fU)
                                                    ? 
                                                   (0x3ffU 
                                                    & (__Vfunc_npu_cmd_command_id__29__command[3U] 
                                                       >> 0x10U))
                                                    : 
                                                   ((__Vfunc_npu_cmd_command_id__29__command[1U] 
                                                     << 0x10U) 
                                                    | (__Vfunc_npu_cmd_command_id__29__command[1U] 
                                                       >> 0x10U))));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_command_id 
        = __Vfunc_npu_cmd_command_id__29__Vfuncout;
    __Vfunc_npu_cmd_header_flags__30__command[0U] = 
        vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_header_flags__30__command[1U] = 
        vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_header_flags__30__command[2U] = 
        vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_header_flags__30__command[3U] = 
        vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U];
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_npu_cmd_header_flags__30__flags = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17311288755175545044ull);
    {
        if ((1U & (~ (__Vfunc_npu_cmd_header_flags__30__command[3U] 
                      >> 0x1fU)))) {
            vlSelfRef.__Vfunc_npu_cmd_header_flags__30__Vfuncout 
                = (0xfffU & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                             >> 8U));
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags = 0U;
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags 
            = ((0xff8U & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags)) 
               | ((4U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                         >> 0x13U)) | ((2U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                                              >> 0x15U)) 
                                       | (1U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                                                >> 0x17U)))));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags 
            = ((0xfefU & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags)) 
               | (0x10U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                           >> 0x10U)));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags 
            = ((0xf3fU & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags)) 
               | (0xc0U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                           >> 0xcU)));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__Vfuncout 
            = vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags;
        __Vlabel0: ;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_header_flags 
        = vlSelfRef.__Vfunc_npu_cmd_header_flags__30__Vfuncout;
}

void Vtb_inline_scheduler_smoke___024root___timing_resume(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___timing_resume\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hb281dba9__0.resume(
                                                   "@(posedge tb_inline_scheduler_smoke.clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hb281dc6c__0.resume(
                                                   "@(negedge tb_inline_scheduler_smoke.clk)");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h01ef22e1__0.resume(
                                                   "@( (3'h2 == (tb_inline_scheduler_smoke.dut.event_state_q[8'h7])))");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hd0c76f01__0.resume(
                                                   "@( ((3'h0 == (tb_inline_scheduler_smoke.dut.event_state_q[8'h7])) & (4'h1 == (tb_inline_scheduler_smoke.dut.event_generation_q[8'h7]))))");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h995f0f28__0.resume(
                                                   "@( (((((~ tb_inline_scheduler_smoke.dut.dma_active_q) & tb_inline_scheduler_smoke.dut.dma_select_found) & ((~ tb_inline_scheduler_smoke.dut.matrix_active_q) & tb_inline_scheduler_smoke.dut.matrix_select_found)) & ((~ tb_inline_scheduler_smoke.dut.vector_active_q) & tb_inline_scheduler_smoke.dut.vector_select_found)) & ((~ tb_inline_scheduler_smoke.dut.complex_active_q) & tb_inline_scheduler_smoke.dut.complex_select_found)))");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_inline_scheduler_smoke___024root___timing_commit(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___timing_commit\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hb281dba9__0.commit(
                                                   "@(posedge tb_inline_scheduler_smoke.clk)");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hb281dc6c__0.commit(
                                                   "@(negedge tb_inline_scheduler_smoke.clk)");
    }
    if ((! (0x10ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h01ef22e1__0.commit(
                                                   "@( (3'h2 == (tb_inline_scheduler_smoke.dut.event_state_q[8'h7])))");
    }
    if ((! (0x20ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hd0c76f01__0.commit(
                                                   "@( ((3'h0 == (tb_inline_scheduler_smoke.dut.event_state_q[8'h7])) & (4'h1 == (tb_inline_scheduler_smoke.dut.event_generation_q[8'h7]))))");
    }
    if ((! (0x40ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h995f0f28__0.commit(
                                                   "@( (((((~ tb_inline_scheduler_smoke.dut.dma_active_q) & tb_inline_scheduler_smoke.dut.dma_select_found) & ((~ tb_inline_scheduler_smoke.dut.matrix_active_q) & tb_inline_scheduler_smoke.dut.matrix_select_found)) & ((~ tb_inline_scheduler_smoke.dut.vector_active_q) & tb_inline_scheduler_smoke.dut.vector_select_found)) & ((~ tb_inline_scheduler_smoke.dut.complex_active_q) & tb_inline_scheduler_smoke.dut.complex_select_found)))");
    }
}

void Vtb_inline_scheduler_smoke___024root___eval_triggers__act(Vtb_inline_scheduler_smoke___024root* vlSelf);
void Vtb_inline_scheduler_smoke___024root___eval_act(Vtb_inline_scheduler_smoke___024root* vlSelf);

bool Vtb_inline_scheduler_smoke___024root___eval_phase__act(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_phase__act\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<7> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_inline_scheduler_smoke___024root___eval_triggers__act(vlSelf);
    Vtb_inline_scheduler_smoke___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_inline_scheduler_smoke___024root___timing_resume(vlSelf);
        Vtb_inline_scheduler_smoke___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtb_inline_scheduler_smoke___024root___eval_nba(Vtb_inline_scheduler_smoke___024root* vlSelf);

bool Vtb_inline_scheduler_smoke___024root___eval_phase__nba(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_phase__nba\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_inline_scheduler_smoke___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___dump_triggers__nba(Vtb_inline_scheduler_smoke___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___dump_triggers__act(Vtb_inline_scheduler_smoke___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_inline_scheduler_smoke___024root___eval(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_inline_scheduler_smoke___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("control/tb_inline_scheduler_smoke.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_inline_scheduler_smoke___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("control/tb_inline_scheduler_smoke.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_inline_scheduler_smoke___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_inline_scheduler_smoke___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_inline_scheduler_smoke___024root___eval_debug_assertions(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_debug_assertions\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
