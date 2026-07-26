// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cmd_dfu_smoke.h for the primary calling header

#include "Vtb_cmd_dfu_smoke__pch.h"
#include "Vtb_cmd_dfu_smoke__Syms.h"
#include "Vtb_cmd_dfu_smoke___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__0(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__low_word;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__low_word = 0;
    QData/*63:0*/ tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__high_word;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__high_word = 0;
    VlWide<4>/*127:0*/ tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command;
    VL_ZERO_W(128, tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command);
    VlWide<3>/*79:0*/ tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_payload;
    VL_ZERO_W(80, tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_payload);
    QData/*63:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__data;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__data = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__first;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__first = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__last;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__last = 0;
    QData/*63:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__data;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__data = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__first;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__first = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__last;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__last = 0;
    SData/*11:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__2__expected_id;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__2__expected_id = 0;
    CData/*7:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__2__expected_status;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__2__expected_status = 0;
    SData/*11:0*/ __Vfunc_npu_cmd_header_flags__3__Vfuncout;
    __Vfunc_npu_cmd_header_flags__3__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_header_flags__3__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_header_flags__3__command);
    SData/*11:0*/ __Vfunc_npu_cmd_header_flags__3__flags;
    __Vfunc_npu_cmd_header_flags__3__flags = 0;
    SData/*11:0*/ __Vfunc_npu_cmd_wait0__4__Vfuncout;
    __Vfunc_npu_cmd_wait0__4__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_wait0__4__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_wait0__4__command);
    SData/*11:0*/ __Vfunc_npu_v2_event_ref__5__Vfuncout;
    __Vfunc_npu_v2_event_ref__5__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_npu_v2_event_ref__5__event_id;
    __Vfunc_npu_v2_event_ref__5__event_id = 0;
    SData/*11:0*/ __Vfunc_npu_cmd_wait1__6__Vfuncout;
    __Vfunc_npu_cmd_wait1__6__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_wait1__6__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_wait1__6__command);
    SData/*11:0*/ __Vfunc_npu_v2_event_ref__7__Vfuncout;
    __Vfunc_npu_v2_event_ref__7__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_npu_v2_event_ref__7__event_id;
    __Vfunc_npu_v2_event_ref__7__event_id = 0;
    SData/*11:0*/ __Vfunc_npu_cmd_signal__8__Vfuncout;
    __Vfunc_npu_cmd_signal__8__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_signal__8__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_signal__8__command);
    SData/*11:0*/ __Vfunc_npu_v2_event_ref__9__Vfuncout;
    __Vfunc_npu_v2_event_ref__9__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_npu_v2_event_ref__9__event_id;
    __Vfunc_npu_v2_event_ref__9__event_id = 0;
    QData/*63:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__data;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__data = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__first;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__first = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__last;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__last = 0;
    QData/*63:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__data;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__data = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__first;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__first = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__last;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__last = 0;
    SData/*11:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__12__expected_id;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__12__expected_id = 0;
    CData/*7:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__12__expected_status;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__12__expected_status = 0;
    QData/*63:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__data;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__data = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__first;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__first = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__last;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__last = 0;
    QData/*63:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__data;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__data = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__first;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__first = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__last;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__last = 0;
    SData/*11:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__15__expected_id;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__15__expected_id = 0;
    CData/*7:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__15__expected_status;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__15__expected_status = 0;
    QData/*63:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__data;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__data = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__first;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__first = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__last;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__last = 0;
    QData/*63:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__data;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__data = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__first;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__first = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__last;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__last = 0;
    SData/*11:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__18__expected_id;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__18__expected_id = 0;
    CData/*7:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__18__expected_status;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__18__expected_status = 0;
    QData/*63:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__data;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__data = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__first;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__first = 0;
    CData/*0:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__last;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__last = 0;
    SData/*11:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__20__expected_id;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__20__expected_id = 0;
    CData/*7:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__20__expected_status;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__20__expected_status = 0;
    IData/*31:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__numeric_cfg;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__numeric_cfg = 0;
    IData/*31:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0;
    IData/*31:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__numeric_cfg;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__numeric_cfg = 0;
    IData/*31:0*/ __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0;
    // Body
    vlSelfRef.tb_cmd_dfu_smoke__DOT__clk = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__reset_n = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = 0ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__ts_cmd_ready = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_ready = 1U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__expected_lookup_id = 1U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_valid = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_addr = 0x1000ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_id = 0x2aU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_engine = 1U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_crc = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_req_ready = 1U;
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         249);
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         249);
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         249);
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         249);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__reset_n = 1U;
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         251);
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         251);
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__low_word = 0x1001000000001000ULL;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__high_word = 0x1fffffffff00020ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__last = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__first = 1U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__data 
        = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__low_word;
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         197);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__data;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__first;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__0__last;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 1U;
    while ((1U & (~ ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                     | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             202);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         203);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         204);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = 0ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = 0U;
    VL_WRITEF_NX("INFO: CFE low beat accepted\n",0);
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         260);
    if (VL_UNLIKELY((((0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                      | (5U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:262: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk1_3: CFE exposed a partial CMD128\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 262, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         260);
    if (VL_UNLIKELY((((0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                      | (5U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:262: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk1_3: CFE exposed a partial CMD128\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 262, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         260);
    if (VL_UNLIKELY((((0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                      | (5U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:262: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk1_3: CFE exposed a partial CMD128\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 262, "", false);
    }
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__last = 1U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__first = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__data 
        = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__high_word;
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         197);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__data;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__first;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__1__last;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 1U;
    while ((1U & (~ ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                     | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             202);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         203);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         204);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = 0ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = 0U;
    VL_WRITEF_NX("INFO: CFE high beat accepted\n",0);
    while ((5U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h165597e7__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (3'h5 == tb_cmd_dfu_smoke.u_cfe.state_q))", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             267);
    }
    VL_WRITEF_NX("INFO: CFE response observed\n",0);
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__2__expected_status = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__2__expected_id = 1U;
    if (VL_UNLIKELY(((((((0xfffU & (IData)((QData)((IData)(
                                                           ((0xff00000U 
                                                             & (((IData)(8U) 
                                                                 - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                << 0x14U)) 
                                                            | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                << 0xcU) 
                                                               | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))))) 
                         != (IData)(__Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__2__expected_id)) 
                        | ((0xffU & (IData)(((QData)((IData)(
                                                             ((0xff00000U 
                                                               & (((IData)(8U) 
                                                                   - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                  << 0x14U)) 
                                                              | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                             >> 0xcU))) 
                           != (IData)(__Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__2__expected_status))) 
                       | (8U < (0xffU & (IData)(((QData)((IData)(
                                                                 ((0xff00000U 
                                                                   & (((IData)(8U) 
                                                                       - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                      << 0x14U)) 
                                                                  | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                      << 0xcU) 
                                                                     | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                                 >> 0x14U))))) 
                      | (0ULL != ((QData)((IData)((
                                                   (0xff00000U 
                                                    & (((IData)(8U) 
                                                        - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                       << 0x14U)) 
                                                   | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                       << 0xcU) 
                                                      | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                  >> 0x1cU)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:186: Assertion failed in %Ntb_cmd_dfu_smoke.check_cmd_response: CFE response fields are incorrect\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 186, "", false);
    }
    while ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q))) {
        co_await vlSelfRef.__VtrigSched_hbc886484__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (4'h0 != tb_cmd_dfu_smoke.u_cfe.fifo_count_q))", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             270);
    }
    if (VL_UNLIKELY(((0U != ((((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                                [vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q][0U] 
                                ^ (IData)(tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__low_word)) 
                               | (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                                  [vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q][1U] 
                                  ^ (IData)((tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__low_word 
                                             >> 0x20U)))) 
                              | (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                                 [vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q][2U] 
                                 ^ (IData)(tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__high_word))) 
                             | (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                                [vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q][3U] 
                                ^ (IData)((tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__high_word 
                                           >> 0x20U)))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:272: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2: CFE changed CMD128 data\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 272, "", false);
    }
    vlSelfRef.tb_cmd_dfu_smoke__DOT__ts_cmd_ready = 1U;
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         275);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         276);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__ts_cmd_ready = 0U;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_payload[0U] = 0x44U;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_payload[1U] = 0x10000002U;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_payload[2U] = 0U;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[0U] = 0U;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[1U] = 0U;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[2U] = 0U;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[3U] = 0U;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[0U] 
        = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_payload[0U];
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[1U] 
        = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_payload[1U];
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[2U] 
        = (0xffa90000U | tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_payload[2U]);
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[3U] = 0x943affffU;
    if (VL_UNLIKELY((((((0x85U != ([&]() {
                                        __Vfunc_npu_cmd_header_flags__3__command[0U] 
                                            = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[0U];
                                        __Vfunc_npu_cmd_header_flags__3__command[1U] 
                                            = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[1U];
                                        __Vfunc_npu_cmd_header_flags__3__command[2U] 
                                            = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[2U];
                                        __Vfunc_npu_cmd_header_flags__3__command[3U] 
                                            = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[3U];
                                        __Vfunc_npu_cmd_header_flags__3__flags = 0;
                                        {
                                            if ((1U 
                                                 & (~ 
                                                    (__Vfunc_npu_cmd_header_flags__3__command[3U] 
                                                     >> 0x1fU)))) {
                                                __Vfunc_npu_cmd_header_flags__3__Vfuncout 
                                                    = 
                                                    (0xfffU 
                                                     & (__Vfunc_npu_cmd_header_flags__3__command[2U] 
                                                        >> 8U));
                                                goto __Vlabel0;
                                            }
                                            __Vfunc_npu_cmd_header_flags__3__flags = 0U;
                                            __Vfunc_npu_cmd_header_flags__3__flags 
                                                = (
                                                   (0xff8U 
                                                    & (IData)(__Vfunc_npu_cmd_header_flags__3__flags)) 
                                                   | ((4U 
                                                       & (__Vfunc_npu_cmd_header_flags__3__command[2U] 
                                                          >> 0x13U)) 
                                                      | ((2U 
                                                          & (__Vfunc_npu_cmd_header_flags__3__command[2U] 
                                                             >> 0x15U)) 
                                                         | (1U 
                                                            & (__Vfunc_npu_cmd_header_flags__3__command[2U] 
                                                               >> 0x17U)))));
                                            __Vfunc_npu_cmd_header_flags__3__flags 
                                                = (
                                                   (0xfefU 
                                                    & (IData)(__Vfunc_npu_cmd_header_flags__3__flags)) 
                                                   | (0x10U 
                                                      & (__Vfunc_npu_cmd_header_flags__3__command[2U] 
                                                         >> 0x10U)));
                                            __Vfunc_npu_cmd_header_flags__3__flags 
                                                = (
                                                   (0xf3fU 
                                                    & (IData)(__Vfunc_npu_cmd_header_flags__3__flags)) 
                                                   | (0xc0U 
                                                      & (__Vfunc_npu_cmd_header_flags__3__command[2U] 
                                                         >> 0xcU)));
                                            __Vfunc_npu_cmd_header_flags__3__Vfuncout 
                                                = __Vfunc_npu_cmd_header_flags__3__flags;
                                            __Vlabel0: ;
                                        }
                                    }(), (IData)(__Vfunc_npu_cmd_header_flags__3__Vfuncout))) 
                        | (0xfffU != ([&]() {
                                        __Vfunc_npu_cmd_wait0__4__command[0U] 
                                            = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[0U];
                                        __Vfunc_npu_cmd_wait0__4__command[1U] 
                                            = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[1U];
                                        __Vfunc_npu_cmd_wait0__4__command[2U] 
                                            = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[2U];
                                        __Vfunc_npu_cmd_wait0__4__command[3U] 
                                            = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[3U];
                                        __Vfunc_npu_cmd_wait0__4__Vfuncout 
                                            = (0xfffU 
                                               & ((__Vfunc_npu_cmd_wait0__4__command[3U] 
                                                   >> 0x1fU)
                                                   ? 
                                                  ([&]() {
                                                        __Vfunc_npu_v2_event_ref__5__event_id 
                                                            = 
                                                            (0xffU 
                                                             & (__Vfunc_npu_cmd_wait0__4__command[3U] 
                                                                >> 8U));
                                                        __Vfunc_npu_v2_event_ref__5__Vfuncout 
                                                            = 
                                                            ((0xffU 
                                                              == (IData)(__Vfunc_npu_v2_event_ref__5__event_id))
                                                              ? 0xfffU
                                                              : (IData)(__Vfunc_npu_v2_event_ref__5__event_id));
                                                    }(), (IData)(__Vfunc_npu_v2_event_ref__5__Vfuncout))
                                                   : 
                                                  ((__Vfunc_npu_cmd_wait0__4__command[2U] 
                                                    << 0xcU) 
                                                   | (__Vfunc_npu_cmd_wait0__4__command[2U] 
                                                      >> 0x14U))));
                                    }(), (IData)(__Vfunc_npu_cmd_wait0__4__Vfuncout)))) 
                       | (0xfffU != ([&]() {
                                    __Vfunc_npu_cmd_wait1__6__command[0U] 
                                        = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[0U];
                                    __Vfunc_npu_cmd_wait1__6__command[1U] 
                                        = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[1U];
                                    __Vfunc_npu_cmd_wait1__6__command[2U] 
                                        = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[2U];
                                    __Vfunc_npu_cmd_wait1__6__command[3U] 
                                        = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[3U];
                                    __Vfunc_npu_cmd_wait1__6__Vfuncout 
                                        = (0xfffU & 
                                           ((__Vfunc_npu_cmd_wait1__6__command[3U] 
                                             >> 0x1fU)
                                             ? ([&]() {
                                                    __Vfunc_npu_v2_event_ref__7__event_id 
                                                        = 
                                                        (0xffU 
                                                         & __Vfunc_npu_cmd_wait1__6__command[3U]);
                                                    __Vfunc_npu_v2_event_ref__7__Vfuncout 
                                                        = 
                                                        ((0xffU 
                                                          == (IData)(__Vfunc_npu_v2_event_ref__7__event_id))
                                                          ? 0xfffU
                                                          : (IData)(__Vfunc_npu_v2_event_ref__7__event_id));
                                                }(), (IData)(__Vfunc_npu_v2_event_ref__7__Vfuncout))
                                             : __Vfunc_npu_cmd_wait1__6__command[3U]));
                                }(), (IData)(__Vfunc_npu_cmd_wait1__6__Vfuncout)))) 
                      | (0xfffU != ([&]() {
                                __Vfunc_npu_cmd_signal__8__command[0U] 
                                    = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[0U];
                                __Vfunc_npu_cmd_signal__8__command[1U] 
                                    = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[1U];
                                __Vfunc_npu_cmd_signal__8__command[2U] 
                                    = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[2U];
                                __Vfunc_npu_cmd_signal__8__command[3U] 
                                    = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[3U];
                                __Vfunc_npu_cmd_signal__8__Vfuncout 
                                    = (0xfffU & ((__Vfunc_npu_cmd_signal__8__command[3U] 
                                                  >> 0x1fU)
                                                  ? 
                                                 ([&]() {
                                                __Vfunc_npu_v2_event_ref__9__event_id 
                                                    = 
                                                    (__Vfunc_npu_cmd_signal__8__command[2U] 
                                                     >> 0x18U);
                                                __Vfunc_npu_v2_event_ref__9__Vfuncout 
                                                    = 
                                                    ((0xffU 
                                                      == (IData)(__Vfunc_npu_v2_event_ref__9__event_id))
                                                      ? 0xfffU
                                                      : (IData)(__Vfunc_npu_v2_event_ref__9__event_id));
                                            }(), (IData)(__Vfunc_npu_v2_event_ref__9__Vfuncout))
                                                  : 
                                                 ((__Vfunc_npu_cmd_signal__8__command[3U] 
                                                   << 0x14U) 
                                                  | (__Vfunc_npu_cmd_signal__8__command[3U] 
                                                     >> 0xcU))));
                            }(), (IData)(__Vfunc_npu_cmd_signal__8__Vfuncout))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:298: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2: CMD128 V2 header fields decode incorrectly\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 298, "", false);
    }
    vlSelfRef.tb_cmd_dfu_smoke__DOT__expected_lookup_id = 0x3aU;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__last = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__first = 1U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__data 
        = (((QData)((IData)(tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[1U])) 
            << 0x20U) | (QData)((IData)(tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[0U])));
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         197);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__data;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__first;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__10__last;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 1U;
    while ((1U & (~ ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                     | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             202);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         203);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         204);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = 0ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__last = 1U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__first = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__data 
        = (((QData)((IData)(tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[3U])) 
            << 0x20U) | (QData)((IData)(tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[2U])));
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         197);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__data;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__first;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__11__last;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 1U;
    while ((1U & (~ ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                     | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             202);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         203);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         204);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = 0ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = 0U;
    while ((5U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h165597e7__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (3'h5 == tb_cmd_dfu_smoke.u_cfe.state_q))", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             303);
    }
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__12__expected_status = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__12__expected_id = 0x3aU;
    if (VL_UNLIKELY(((((((0xfffU & (IData)((QData)((IData)(
                                                           ((0xff00000U 
                                                             & (((IData)(8U) 
                                                                 - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                << 0x14U)) 
                                                            | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                << 0xcU) 
                                                               | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))))) 
                         != (IData)(__Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__12__expected_id)) 
                        | ((0xffU & (IData)(((QData)((IData)(
                                                             ((0xff00000U 
                                                               & (((IData)(8U) 
                                                                   - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                  << 0x14U)) 
                                                              | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                             >> 0xcU))) 
                           != (IData)(__Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__12__expected_status))) 
                       | (8U < (0xffU & (IData)(((QData)((IData)(
                                                                 ((0xff00000U 
                                                                   & (((IData)(8U) 
                                                                       - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                      << 0x14U)) 
                                                                  | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                      << 0xcU) 
                                                                     | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                                 >> 0x14U))))) 
                      | (0ULL != ((QData)((IData)((
                                                   (0xff00000U 
                                                    & (((IData)(8U) 
                                                        - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                       << 0x14U)) 
                                                   | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                       << 0xcU) 
                                                      | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                  >> 0x1cU)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:186: Assertion failed in %Ntb_cmd_dfu_smoke.check_cmd_response: CFE response fields are incorrect\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 186, "", false);
    }
    while ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q))) {
        co_await vlSelfRef.__VtrigSched_hbc886484__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (4'h0 != tb_cmd_dfu_smoke.u_cfe.fifo_count_q))", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             305);
    }
    if (VL_UNLIKELY(((0U != ((((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                                [vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q][0U] 
                                ^ tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[0U]) 
                               | (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                                  [vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q][1U] 
                                  ^ tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[1U])) 
                              | (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                                 [vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q][2U] 
                                 ^ tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[2U])) 
                             | (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                                [vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q][3U] 
                                ^ tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[3U])))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:307: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2: CFE changed CMD128 V2 data\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 307, "", false);
    }
    vlSelfRef.tb_cmd_dfu_smoke__DOT__ts_cmd_ready = 1U;
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         310);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         311);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__ts_cmd_ready = 0U;
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[3U] 
        = (0x703b0000U | (0x8000ffffU & tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[3U]));
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__last = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__first = 1U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__data 
        = (((QData)((IData)(tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[1U])) 
            << 0x20U) | (QData)((IData)(tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[0U])));
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         197);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__data;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__first;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__13__last;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 1U;
    while ((1U & (~ ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                     | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             202);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         203);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         204);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = 0ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__last = 1U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__first = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__data 
        = (((QData)((IData)(tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[3U])) 
            << 0x20U) | (QData)((IData)(tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__v2_command[2U])));
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         197);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__data;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__first;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__14__last;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 1U;
    while ((1U & (~ ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                     | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             202);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         203);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         204);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = 0ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = 0U;
    while ((5U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h165597e7__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (3'h5 == tb_cmd_dfu_smoke.u_cfe.state_q))", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             318);
    }
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__15__expected_status = 1U;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__15__expected_id = 0x3bU;
    if (VL_UNLIKELY(((((((0xfffU & (IData)((QData)((IData)(
                                                           ((0xff00000U 
                                                             & (((IData)(8U) 
                                                                 - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                << 0x14U)) 
                                                            | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                << 0xcU) 
                                                               | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))))) 
                         != (IData)(__Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__15__expected_id)) 
                        | ((0xffU & (IData)(((QData)((IData)(
                                                             ((0xff00000U 
                                                               & (((IData)(8U) 
                                                                   - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                  << 0x14U)) 
                                                              | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                             >> 0xcU))) 
                           != (IData)(__Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__15__expected_status))) 
                       | (8U < (0xffU & (IData)(((QData)((IData)(
                                                                 ((0xff00000U 
                                                                   & (((IData)(8U) 
                                                                       - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                      << 0x14U)) 
                                                                  | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                      << 0xcU) 
                                                                     | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                                 >> 0x14U))))) 
                      | (0ULL != ((QData)((IData)((
                                                   (0xff00000U 
                                                    & (((IData)(8U) 
                                                        - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                       << 0x14U)) 
                                                   | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                       << 0xcU) 
                                                      | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                  >> 0x1cU)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:186: Assertion failed in %Ntb_cmd_dfu_smoke.check_cmd_response: CFE response fields are incorrect\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 186, "", false);
    }
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:321: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2: disabled V2 P1 opcode reached the scheduler output\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 321, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         323);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__expected_lookup_id = 1U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__last = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__first = 1U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__data 
        = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__low_word;
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         197);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__data;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__first;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__16__last;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 1U;
    while ((1U & (~ ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                     | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             202);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         203);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         204);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = 0ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__last = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__first = 1U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__data 
        = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__high_word;
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         197);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__data;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__first;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__17__last;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 1U;
    while ((1U & (~ ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                     | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             202);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         203);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         204);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = 0ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = 0U;
    while ((5U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h165597e7__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (3'h5 == tb_cmd_dfu_smoke.u_cfe.state_q))", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             328);
    }
    VL_WRITEF_NX("INFO: malformed CFE response observed\n",0);
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__18__expected_status = 2U;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__18__expected_id = 1U;
    if (VL_UNLIKELY(((((((0xfffU & (IData)((QData)((IData)(
                                                           ((0xff00000U 
                                                             & (((IData)(8U) 
                                                                 - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                << 0x14U)) 
                                                            | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                << 0xcU) 
                                                               | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))))) 
                         != (IData)(__Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__18__expected_id)) 
                        | ((0xffU & (IData)(((QData)((IData)(
                                                             ((0xff00000U 
                                                               & (((IData)(8U) 
                                                                   - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                  << 0x14U)) 
                                                              | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                             >> 0xcU))) 
                           != (IData)(__Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__18__expected_status))) 
                       | (8U < (0xffU & (IData)(((QData)((IData)(
                                                                 ((0xff00000U 
                                                                   & (((IData)(8U) 
                                                                       - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                      << 0x14U)) 
                                                                  | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                      << 0xcU) 
                                                                     | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                                 >> 0x14U))))) 
                      | (0ULL != ((QData)((IData)((
                                                   (0xff00000U 
                                                    & (((IData)(8U) 
                                                        - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                       << 0x14U)) 
                                                   | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                       << 0xcU) 
                                                      | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                  >> 0x1cU)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:186: Assertion failed in %Ntb_cmd_dfu_smoke.check_cmd_response: CFE response fields are incorrect\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 186, "", false);
    }
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:332: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2: malformed CMD reached the scheduler output\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 332, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         334);
    tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__low_word = 0x1002000000001000ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__last = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__first = 1U;
    __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__data 
        = tb_cmd_dfu_smoke__DOT__unnamedblk2__DOT__low_word;
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         197);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__data;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__first;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = __Vtask_tb_cmd_dfu_smoke__DOT__send_cmd_beat__19__last;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 1U;
    while ((1U & (~ ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                     | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
        co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             202);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         203);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         204);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data = 0ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last = 0U;
    while ((5U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h165597e7__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (3'h5 == tb_cmd_dfu_smoke.u_cfe.state_q))", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             338);
    }
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__20__expected_status = 9U;
    __Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__20__expected_id = 2U;
    if (VL_UNLIKELY(((((((0xfffU & (IData)((QData)((IData)(
                                                           ((0xff00000U 
                                                             & (((IData)(8U) 
                                                                 - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                << 0x14U)) 
                                                            | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                << 0xcU) 
                                                               | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))))) 
                         != (IData)(__Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__20__expected_id)) 
                        | ((0xffU & (IData)(((QData)((IData)(
                                                             ((0xff00000U 
                                                               & (((IData)(8U) 
                                                                   - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                  << 0x14U)) 
                                                              | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                             >> 0xcU))) 
                           != (IData)(__Vtask_tb_cmd_dfu_smoke__DOT__check_cmd_response__20__expected_status))) 
                       | (8U < (0xffU & (IData)(((QData)((IData)(
                                                                 ((0xff00000U 
                                                                   & (((IData)(8U) 
                                                                       - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                                      << 0x14U)) 
                                                                  | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                                      << 0xcU) 
                                                                     | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                                 >> 0x14U))))) 
                      | (0ULL != ((QData)((IData)((
                                                   (0xff00000U 
                                                    & (((IData)(8U) 
                                                        - (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)) 
                                                       << 0x14U)) 
                                                   | (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q) 
                                                       << 0xcU) 
                                                      | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id))))) 
                                  >> 0x1cU)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:186: Assertion failed in %Ntb_cmd_dfu_smoke.check_cmd_response: CFE response fields are incorrect\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 186, "", false);
    }
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:341: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2: timed-out CMD reached the scheduler output\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 341, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         343);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_request_count = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__numeric_cfg = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 1U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[1U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 2U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[2U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 3U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[3U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 4U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[4U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 5U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[5U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 6U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[6U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 7U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[7U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 8U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[8U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 9U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[9U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0xaU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xaU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0xbU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xbU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0xcU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xcU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0xdU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xdU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0xeU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xeU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0xfU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xfU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x10U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x10U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x11U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x11U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x12U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x12U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x13U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x13U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x14U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x14U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x15U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x15U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x16U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x16U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x17U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x17U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x18U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x18U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x19U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x19U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x1aU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1aU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x1bU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1bU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x1cU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1cU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x1dU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1dU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x1eU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1eU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x1fU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1fU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__unnamedblk1__DOT__word_idx = 0x20U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0U] = 0x1000101ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[7U] 
        = (0x1234567800000000ULL | (QData)((IData)(__Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__21__numeric_cfg)));
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         219);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_valid = 1U;
    while ((0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             221);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         222);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         223);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_valid = 0U;
    VL_WRITEF_NX("INFO: valid DFU request started\n",0);
    while ((4U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_hfb15c31a__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (3'h4 == tb_cmd_dfu_smoke.u_dfu.state_q))", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             348);
    }
    VL_WRITEF_NX("INFO: valid DFU response observed\n",0);
    if (VL_UNLIKELY(((((0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q)) 
                       | ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__command_id_q) 
                          != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_id))) 
                      | (0x20U != vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_request_count))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:353: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2: valid 256-byte Descriptor fetch failed\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 353, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 0\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[3U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[2U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [1U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 1\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[5U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[4U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [2U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 2\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[7U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[6U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [3U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 3\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[9U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[8U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [4U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 4\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0xbU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0xaU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [5U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 5\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0xdU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0xcU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [6U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 6\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0xfU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0xeU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [7U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 7\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x11U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x10U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [8U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 8\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x13U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x12U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [9U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 9\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x15U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x14U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0xaU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 10\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x17U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x16U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0xbU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 11\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x19U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x18U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0xcU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 12\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x1bU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x1aU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0xdU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 13\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x1dU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x1cU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0xeU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 14\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x1fU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x1eU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0xfU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 15\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x21U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x20U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x10U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 16\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x23U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x22U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x11U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 17\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x25U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x24U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x12U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 18\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x27U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x26U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x13U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 19\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x29U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x28U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x14U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 20\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x2bU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x2aU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x15U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 21\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x2dU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x2cU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x16U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 22\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x2fU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x2eU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x17U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 23\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x31U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x30U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x18U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 24\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x33U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x32U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x19U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 25\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x35U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x34U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x1aU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 26\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x37U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x36U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x1bU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 27\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x39U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x38U]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x1cU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 28\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x3bU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x3aU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x1dU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 29\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x3dU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x3cU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x1eU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 30\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    if (VL_UNLIKELY((((((QData)((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x3fU])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0x3eU]))) 
                      != vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                      [0x1fU])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:358: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2.unnamedblk3: DFU changed descriptor word 31\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 358, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         361);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_request_count = 0U;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__numeric_cfg = 0x100U;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 1U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[1U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 2U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[2U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 3U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[3U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 4U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[4U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 5U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[5U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 6U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[6U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 7U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[7U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 8U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[8U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 9U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[9U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0xaU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xaU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0xbU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xbU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0xcU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xcU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0xdU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xdU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0xeU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xeU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0xfU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0xfU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x10U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x10U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x11U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x11U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x12U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x12U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x13U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x13U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x14U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x14U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x15U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x15U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x16U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x16U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x17U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x17U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x18U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x18U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x19U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x19U] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x1aU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1aU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x1bU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1bU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x1cU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1cU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x1dU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1dU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x1eU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1eU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x1fU;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0x1fU] = 0ULL;
    __Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__unnamedblk1__DOT__word_idx = 0x20U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[0U] = 0x1000101ULL;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words[7U] 
        = (0x1234567800000000ULL | (QData)((IData)(__Vtask_tb_cmd_dfu_smoke__DOT__start_fetch__22__numeric_cfg)));
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         219);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_valid = 1U;
    while ((0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             221);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         222);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         223);
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_valid = 0U;
    VL_WRITEF_NX("INFO: reserved accumulator encoding DFU request started\n",0);
    while ((4U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_hfb15c31a__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (3'h4 == tb_cmd_dfu_smoke.u_dfu.state_q))", 
                                                             "control/tb_cmd_dfu_smoke.sv", 
                                                             366);
    }
    VL_WRITEF_NX("INFO: reserved accumulator encoding DFU response observed\n",0);
    if (VL_UNLIKELY(((((2U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q)) 
                       | (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__fault_addr_q 
                          != vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_addr)) 
                      | (8U != vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_request_count))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:371: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2: reserved accumulator encoding was not rejected\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 371, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hefdb7d35__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         373);
    co_await vlSelfRef.__VtrigSched_hefdb7bf8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_cmd_dfu_smoke.clk)", 
                                                         "control/tb_cmd_dfu_smoke.sv", 
                                                         374);
    if (VL_UNLIKELY(((1U & ((((~ ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                                  & (0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)))) 
                              | (0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q))) 
                             | (2U != vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_accepted_count)) 
                            | (3U != vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error_count)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:378: Assertion failed in %Ntb_cmd_dfu_smoke.unnamedblk2: CFE/DFU state/count error: cfe_idle=%0b dfu_idle=%0b accepted=%0# errors=%0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     1,((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                        & (0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q))),
                     1,(0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q)),
                     32,vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_accepted_count,
                     32,vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error_count);
        VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 378, "", false);
    }
    VL_WRITEF_NX("PASS: CFE atomic/timeout checks and DFU numeric checks\n",0);
    VL_FINISH_MT("control/tb_cmd_dfu_smoke.sv", 386, "");
}

VL_INLINE_OPT VlCoroutine Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__1(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x186a0ULL, 
                                         nullptr, "control/tb_cmd_dfu_smoke.sv", 
                                         390);
    VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:391: Assertion failed in %Ntb_cmd_dfu_smoke: smoke test timeout\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
    VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 391, "", false);
}

VL_INLINE_OPT VlCoroutine Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__2(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "control/tb_cmd_dfu_smoke.sv", 
                                             55);
        vlSelfRef.tb_cmd_dfu_smoke__DOT__clk = (1U 
                                                & (~ (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___dump_triggers__act(Vtb_cmd_dfu_smoke___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_cmd_dfu_smoke___024root___eval_triggers__act(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_triggers__act\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vtrigprevexpr_h9262126c__0;
    __Vtrigprevexpr_h9262126c__0 = 0;
    CData/*0:0*/ __Vtrigprevexpr_h68bfd761__0;
    __Vtrigprevexpr_h68bfd761__0 = 0;
    CData/*0:0*/ __Vtrigprevexpr_h6b2234f7__0;
    __Vtrigprevexpr_h6b2234f7__0 = 0;
    // Body
    __Vtrigprevexpr_h9262126c__0 = (5U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q));
    __Vtrigprevexpr_h68bfd761__0 = (0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q));
    __Vtrigprevexpr_h6b2234f7__0 = (4U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q));
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_cmd_dfu_smoke__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__reset_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_cmd_dfu_smoke__DOT__reset_n__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((~ (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_cmd_dfu_smoke__DOT__clk__0)));
    vlSelfRef.__VactTriggered.setBit(3U, ((IData)(__Vtrigprevexpr_h9262126c__0) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr_h9262126c__1)));
    vlSelfRef.__VactTriggered.setBit(4U, ((IData)(__Vtrigprevexpr_h68bfd761__0) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr_h68bfd761__1)));
    vlSelfRef.__VactTriggered.setBit(5U, ((IData)(__Vtrigprevexpr_h6b2234f7__0) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr_h6b2234f7__1)));
    vlSelfRef.__VactTriggered.setBit(6U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb_cmd_dfu_smoke__DOT__clk__0 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_cmd_dfu_smoke__DOT__reset_n__0 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__reset_n;
    vlSelfRef.__Vtrigprevexpr_h9262126c__1 = __Vtrigprevexpr_h9262126c__0;
    vlSelfRef.__Vtrigprevexpr_h68bfd761__1 = __Vtrigprevexpr_h68bfd761__0;
    vlSelfRef.__Vtrigprevexpr_h6b2234f7__1 = __Vtrigprevexpr_h6b2234f7__0;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(3U, 1U);
        vlSelfRef.__VactTriggered.setBit(4U, 1U);
        vlSelfRef.__VactTriggered.setBit(5U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_cmd_dfu_smoke___024root___dump_triggers__act(vlSelf);
    }
#endif
}

extern const VlWide<64>/*2047:0*/ Vtb_cmd_dfu_smoke__ConstPool__CONST_h6be9aa18_0;

VL_INLINE_OPT void Vtb_cmd_dfu_smoke___024root___nba_sequent__TOP__0(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___nba_sequent__TOP__0\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd;
    VL_ZERO_W(128, tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd);
    CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT____VdfgExtracted_h654434c1__0;
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT____VdfgExtracted_h654434c1__0 = 0;
    SData/*11:0*/ __Vfunc_npu_cmd_command_id__23__Vfuncout;
    __Vfunc_npu_cmd_command_id__23__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_command_id__23__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_command_id__23__command);
    CData/*2:0*/ __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__29__Vfuncout;
    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__29__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__29__pointer;
    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__29__pointer = 0;
    CData/*2:0*/ __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__30__Vfuncout;
    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__30__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__30__pointer;
    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__30__pointer = 0;
    CData/*2:0*/ __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__31__Vfuncout;
    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__31__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__31__pointer;
    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__31__pointer = 0;
    CData/*2:0*/ __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__32__Vfuncout;
    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__32__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__32__pointer;
    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__32__pointer = 0;
    CData/*0:0*/ __Vfunc_npu_v2_compact_opcode_valid__33__Vfuncout;
    __Vfunc_npu_v2_compact_opcode_valid__33__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_npu_v2_compact_opcode_valid__33__compact_opcode;
    __Vfunc_npu_v2_compact_opcode_valid__33__compact_opcode = 0;
    SData/*15:0*/ __Vfunc_npu_desc_bytes_for_engine__34__Vfuncout;
    __Vfunc_npu_desc_bytes_for_engine__34__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_npu_desc_bytes_for_engine__34__engine;
    __Vfunc_npu_desc_bytes_for_engine__34__engine = 0;
    CData/*7:0*/ __Vfunc_npu_mem_to_task_status__40__Vfuncout;
    __Vfunc_npu_mem_to_task_status__40__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_npu_mem_to_task_status__40__status;
    __Vfunc_npu_mem_to_task_status__40__status = 0;
    IData/*31:0*/ __Vdly__tb_cmd_dfu_smoke__DOT__mem_request_count;
    __Vdly__tb_cmd_dfu_smoke__DOT__mem_request_count = 0;
    IData/*31:0*/ __VdlyMask__tb_cmd_dfu_smoke__DOT__mem_request_count;
    __VdlyMask__tb_cmd_dfu_smoke__DOT__mem_request_count = 0;
    CData/*2:0*/ __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q = 0;
    CData/*3:0*/ __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q = 0;
    CData/*2:0*/ __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q = 0;
    CData/*2:0*/ __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 0;
    CData/*0:0*/ __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q = 0;
    CData/*2:0*/ __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 0;
    CData/*5:0*/ __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q = 0;
    CData/*5:0*/ __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q = 0;
    VlWide<4>/*127:0*/ __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0;
    VL_ZERO_W(128, __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0);
    CData/*2:0*/ __VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0;
    __VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0;
    __VdlySet__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1;
    VL_ZERO_W(128, __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1);
    CData/*2:0*/ __VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1;
    __VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1;
    __VdlySet__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1 = 0;
    // Body
    if (vlSelfRef.tb_cmd_dfu_smoke__DOT__reset_n) {
        if (VL_UNLIKELY(((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_valid) 
                           | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_rsp_valid)) 
                          | (5U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)))))) {
            VL_WRITEF_NX("TRACE: t=%0t lookup_v=%0b lookup_rsp=%0b cmd_rsp=%0b state=%0#\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         1,(IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_valid),
                         1,vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_rsp_valid,
                         1,(5U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)),
                         3,(IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q));
        }
    }
    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q;
    __VdlySet__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0 = 0U;
    __VdlySet__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1 = 0U;
    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q;
    if (vlSelfRef.tb_cmd_dfu_smoke__DOT__reset_n) {
        if (vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error) {
            vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error_count 
                = ((IData)(1U) + vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error_count);
        }
        if (vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_accepted) {
            vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_accepted_count 
                = ((IData)(1U) + vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_accepted_count);
        }
        if ((4U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q))) {
                __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 0U;
            } else if ((1U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q))) {
                __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 0U;
            } else if (vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_rsp_valid) {
                __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 0U;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q))) {
                if ((1U & ((~ (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__prefix_valid)) 
                           | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__crc_enable_q)))) {
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q = 2U;
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__fault_addr_q 
                        = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_addr_q;
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 4U;
                } else if ((0x40U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__expected_desc_bytes))) {
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q = 0U;
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 4U;
                } else {
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q 
                        = (0x3fU & ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__expected_desc_bytes) 
                                    >> 3U));
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q = 8U;
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 1U;
                }
            } else if (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__mem_response_handshake) {
                if (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__abort_pending_q) {
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q = 0xaU;
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__fault_addr_q 
                        = vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_req_addr;
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__abort_pending_q = 0U;
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 4U;
                } else if ((0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_status))) {
                    __Vfunc_npu_mem_to_task_status__40__status 
                        = vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_status;
                    __Vfunc_npu_mem_to_task_status__40__Vfuncout 
                        = ((4U & (IData)(__Vfunc_npu_mem_to_task_status__40__status))
                            ? ((2U & (IData)(__Vfunc_npu_mem_to_task_status__40__status))
                                ? 2U : ((1U & (IData)(__Vfunc_npu_mem_to_task_status__40__status))
                                         ? 2U : 5U))
                            : ((2U & (IData)(__Vfunc_npu_mem_to_task_status__40__status))
                                ? ((1U & (IData)(__Vfunc_npu_mem_to_task_status__40__status))
                                    ? 6U : 4U) : ((1U 
                                                   & (IData)(__Vfunc_npu_mem_to_task_status__40__status))
                                                   ? 4U
                                                   : 0U)));
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q 
                        = __Vfunc_npu_mem_to_task_status__40__Vfuncout;
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__fault_addr_q 
                        = vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_req_addr;
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 4U;
                } else {
                    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU 
                                               & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q), 6U)), vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q, vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_data);
                    if (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q) 
                         == (0x3fU & ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q) 
                                      - (IData)(1U))))) {
                        if ((8U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q))) {
                            __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 3U;
                        } else {
                            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q = 0U;
                            __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 4U;
                        }
                    } else {
                        __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q 
                            = (0x3fU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q)));
                        __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 1U;
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q))) {
            if (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__mem_request_handshake) {
                __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 2U;
            }
        } else if (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_valid) 
                    & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_ready))) {
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_addr_q 
                = vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_addr;
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__command_id_q 
                = vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_id;
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__engine_q 
                = vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_engine;
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__crc_enable_q 
                = vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_crc;
            __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q = 0U;
            __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q = 8U;
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q = 0U;
            IData/*31:0*/ __Vilp1;
            __Vilp1 = 0U;
            while ((__Vilp1 <= 0x3fU)) {
                vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[__Vilp1] 
                    = Vtb_cmd_dfu_smoke__ConstPool__CONST_h6be9aa18_0[__Vilp1];
                __Vilp1 = ((IData)(1U) + __Vilp1);
            }
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__abort_pending_q = 0U;
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__fault_addr_q = 0ULL;
            if ((0U != (0x3fU & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_addr)))) {
                vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q = 2U;
                vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__fault_addr_q 
                    = vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_addr;
                __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 4U;
            } else {
                __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 1U;
            }
        }
    } else {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error_count = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_accepted_count = 0U;
        __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_addr_q = 0ULL;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__command_id_q = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__engine_q = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__crc_enable_q = 0U;
        __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q = 0U;
        __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__fault_addr_q = 0ULL;
        IData/*31:0*/ __Vilp2;
        __Vilp2 = 0U;
        while ((__Vilp2 <= 0x3fU)) {
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[__Vilp2] 
                = Vtb_cmd_dfu_smoke__ConstPool__CONST_h6be9aa18_0[__Vilp2];
            __Vilp2 = ((IData)(1U) + __Vilp2);
        }
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__abort_pending_q = 0U;
    }
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q 
        = __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q 
        = __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q;
    if (vlSelfRef.tb_cmd_dfu_smoke__DOT__reset_n) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_accepted = 0U;
        if ((2U == (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now) 
                     << 1U) | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake)))) {
            __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0[0U] 
                = (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q);
            __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0[1U] 
                = (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q 
                           >> 0x20U));
            __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0[2U] 
                = (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q);
            __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0[3U] 
                = (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                           >> 0x20U));
            __VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0 
                = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q;
            __VdlySet__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0 = 1U;
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q 
                = ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
                   | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q))));
            __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__29__pointer 
                = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q;
            {
                if ((7U == (IData)(__Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__29__pointer))) {
                    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__29__Vfuncout = 0U;
                    goto __Vlabel0;
                }
                __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__29__Vfuncout 
                    = (7U & ((IData)(1U) + (IData)(__Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__29__pointer)));
                __Vlabel0: ;
            }
            __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q 
                = __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__29__Vfuncout;
            __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)));
        } else if ((1U == (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now) 
                            << 1U) | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake)))) {
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q 
                = ((~ ((IData)(1U) << (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q))) 
                   & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q));
            __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__30__pointer 
                = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q;
            {
                if ((7U == (IData)(__Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__30__pointer))) {
                    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__30__Vfuncout = 0U;
                    goto __Vlabel1;
                }
                __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__30__Vfuncout 
                    = (7U & ((IData)(1U) + (IData)(__Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__30__pointer)));
                __Vlabel1: ;
            }
            __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q 
                = __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__30__Vfuncout;
            __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q 
                = (0xfU & ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q) 
                           - (IData)(1U)));
        } else if ((3U == (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now) 
                            << 1U) | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake)))) {
            __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1[0U] 
                = (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q);
            __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1[1U] 
                = (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q 
                           >> 0x20U));
            __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1[2U] 
                = (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q);
            __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1[3U] 
                = (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                           >> 0x20U));
            __VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1 
                = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q;
            __VdlySet__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1 = 1U;
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q 
                = ((~ ((IData)(1U) << (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q))) 
                   & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q));
            vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q 
                = ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
                   | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q))));
            __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__31__pointer 
                = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q;
            {
                if ((7U == (IData)(__Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__31__pointer))) {
                    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__31__Vfuncout = 0U;
                    goto __Vlabel2;
                }
                __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__31__Vfuncout 
                    = (7U & ((IData)(1U) + (IData)(__Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__31__pointer)));
                __Vlabel2: ;
            }
            __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q 
                = __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__31__Vfuncout;
            __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__32__pointer 
                = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q;
            {
                if ((7U == (IData)(__Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__32__pointer))) {
                    __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__32__Vfuncout = 0U;
                    goto __Vlabel3;
                }
                __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__32__Vfuncout 
                    = (7U & ((IData)(1U) + (IData)(__Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__32__pointer)));
                __Vlabel3: ;
            }
            __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q 
                = __Vfunc_tb_cmd_dfu_smoke__DOT__u_cfe__DOT__increment_ptr__32__Vfuncout;
        }
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((3U 
                                                 == 
                                                 (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake))) 
                                                << 2U) 
                                               | (((1U 
                                                    == 
                                                    (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now) 
                                                      << 1U) 
                                                     | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now) 
                                                       << 1U) 
                                                      | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake))))))))))) {
            if ((0U != (((3U == (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now) 
                                  << 1U) | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake))) 
                         << 2U) | (((1U == (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake))) 
                                    << 1U) | (2U == 
                                              (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now) 
                                                << 1U) 
                                               | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: npu_cmd_frontend.sv:160: Assertion failed in %Ntb_cmd_dfu_smoke.u_cfe: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -12,vlSymsp->name(),
                                 2,(((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now) 
                                     << 1U) | (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake)));
                    VL_STOP_MT("control/npu_cmd_frontend.sv", 160, "");
                }
            }
        }
        if ((4U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) {
                __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 0U;
            } else if ((1U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) {
                if (vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_rsp_valid) {
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 0U;
                }
            } else {
                vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q = 0U;
                vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_accepted = 1U;
                __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) {
                if (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_valid) 
                     & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_ready))) {
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q = 1U;
                }
                if (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q) 
                     & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_rsp_valid))) {
                    if (vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_busy) {
                        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q = 2U;
                        vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error = 1U;
                        __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 5U;
                    } else if ((8U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q))) {
                        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q = 2U;
                        vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error = 1U;
                        __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 5U;
                    } else {
                        __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 4U;
                    }
                }
            } else if (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__header_format_valid) {
                if (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__opcode_format_valid) {
                    if (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate) {
                        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q = 2U;
                        vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error = 1U;
                        __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 5U;
                    } else {
                        __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q = 0U;
                        __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 3U;
                    }
                } else {
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q = 1U;
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error = 1U;
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 5U;
                }
            } else {
                vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q = 2U;
                vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error = 1U;
                __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 5U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) {
            if (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__input_handshake) {
                vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                    = vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data;
                if (((~ (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first)) 
                     & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last))) {
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 2U;
                } else {
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q = 2U;
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error = 1U;
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 5U;
                }
            } else if ((0x1fU == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__wait_high_count_q))) {
                vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q = 9U;
                vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error = 1U;
                __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 5U;
            } else {
                vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__wait_high_count_q 
                    = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__wait_high_count_q)));
            }
        } else {
            __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q = 0U;
            if (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__input_handshake) {
                vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q 
                    = vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_data;
                if (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_first) 
                     & (~ (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_last)))) {
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__wait_high_count_q = 0U;
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 1U;
                } else {
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q = 2U;
                    vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error = 1U;
                    __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 5U;
                }
            }
        }
    } else {
        __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q = 0ULL;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q = 0ULL;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q = 0U;
        __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__wait_high_count_q = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q = 0U;
        __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q = 0U;
        __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q = 0U;
        __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__cfe_error = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_accepted = 0U;
    }
    __Vfunc_npu_desc_bytes_for_engine__34__engine = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__engine_q;
    __Vfunc_npu_desc_bytes_for_engine__34__Vfuncout 
        = ((8U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
            ? 0U : ((4U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                     ? ((2U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                         ? 0U : ((1U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                                  ? 0U : 0x100U)) : 
                    ((2U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                      ? ((1U & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                          ? 0xc0U : 0x100U) : ((1U 
                                                & (IData)(__Vfunc_npu_desc_bytes_for_engine__34__engine))
                                                ? 0x100U
                                                : 0x40U))));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__expected_desc_bytes 
        = __Vfunc_npu_desc_bytes_for_engine__34__Vfuncout;
    if (vlSelfRef.tb_cmd_dfu_smoke__DOT__reset_n) {
        if (VL_UNLIKELY((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_valid) 
                          & (2U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:172: Assertion failed in %Ntb_cmd_dfu_smoke: DFU did not accept its pending memory response\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name());
            VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 172, "", false);
        }
        vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_valid = 0U;
        if (((1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_req_ready))) {
            __Vdly__tb_cmd_dfu_smoke__DOT__mem_request_count 
                = ((IData)(1U) + vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_request_count);
            __VdlyMask__tb_cmd_dfu_smoke__DOT__mem_request_count = 0xffffffffU;
            vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_valid = 1U;
            vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_data 
                = vlSelfRef.tb_cmd_dfu_smoke__DOT__descriptor_words
                [(0x1fU & (IData)((0x1fffffffffffULL 
                                   & ((vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_req_addr 
                                       - vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_addr) 
                                      >> 3U))))];
            vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_status = 0U;
        }
    } else {
        __Vdly__tb_cmd_dfu_smoke__DOT__mem_request_count = 0U;
        __VdlyMask__tb_cmd_dfu_smoke__DOT__mem_request_count = 0xffffffffU;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_valid = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_data = 0ULL;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_status = 0U;
    }
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q 
        = __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q 
        = __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q 
        = __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q 
        = __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q;
    if (__VdlySet__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q[__VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0][0U] 
            = __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0[0U];
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q[__VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0][1U] 
            = __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0[1U];
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q[__VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0][2U] 
            = __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0[2U];
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q[__VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0][3U] 
            = __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v0[3U];
    }
    if (__VdlySet__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q[__VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1][0U] 
            = __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1[0U];
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q[__VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1][1U] 
            = __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1[1U];
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q[__VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1][2U] 
            = __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1[2U];
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q[__VdlyDim0__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1][3U] 
            = __VdlyVal__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q__v1[3U];
    }
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q 
        = __Vdly__tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__prefix_valid 
        = ((((((1U == (0xffU & vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0U])) 
               & ((0xffU & (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0U] 
                            >> 8U)) == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__engine_q))) 
              & ((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0U] 
                  >> 0x10U) == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__expected_desc_bytes))) 
             & (0x40U <= (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0U] 
                          >> 0x10U))) & (0x100U >= 
                                         (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0U] 
                                          >> 0x10U))) 
           & ((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__engine_q))
               ? (0U == vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0xeU])
               : ([&]() {
                    vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg 
                        = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q[0xeU];
                    vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__dtype_fields_valid 
                        = (((([&]() {
                                        vlSelfRef.__Vfunc_npu_dtype_valid__36__dtype 
                                            = (3U & vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg);
                                        vlSelfRef.__Vfunc_npu_dtype_valid__36__Vfuncout 
                                            = ((((0U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__36__dtype)) 
                                                 | (1U 
                                                    == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__36__dtype))) 
                                                | (2U 
                                                   == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__36__dtype))) 
                                               | (3U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__36__dtype)));
                                    }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__36__Vfuncout)) 
                             & ([&]() {
                                        vlSelfRef.__Vfunc_npu_dtype_valid__37__dtype 
                                            = (3U & 
                                               (vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg 
                                                >> 2U));
                                        vlSelfRef.__Vfunc_npu_dtype_valid__37__Vfuncout 
                                            = ((((0U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__37__dtype)) 
                                                 | (1U 
                                                    == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__37__dtype))) 
                                                | (2U 
                                                   == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__37__dtype))) 
                                               | (3U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__37__dtype)));
                                    }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__37__Vfuncout))) 
                            & ([&]() {
                                    vlSelfRef.__Vfunc_npu_dtype_valid__38__dtype 
                                        = (3U & (vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg 
                                                 >> 4U));
                                    vlSelfRef.__Vfunc_npu_dtype_valid__38__Vfuncout 
                                        = ((((0U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__38__dtype)) 
                                             | (1U 
                                                == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__38__dtype))) 
                                            | (2U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__38__dtype))) 
                                           | (3U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__38__dtype)));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__38__Vfuncout))) 
                           & ([&]() {
                                vlSelfRef.__Vfunc_npu_dtype_valid__39__dtype 
                                    = (3U & (vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg 
                                             >> 6U));
                                vlSelfRef.__Vfunc_npu_dtype_valid__39__Vfuncout 
                                    = ((((0U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__39__dtype)) 
                                         | (1U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__39__dtype))) 
                                        | (2U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__39__dtype))) 
                                       | (3U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__39__dtype)));
                            }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__39__Vfuncout)));
                    vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__Vfuncout 
                        = ((IData)(vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__dtype_fields_valid) 
                           & (0U == (0xfffe0300U & vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__cfg)));
                }(), (IData)(vlSelfRef.__Vfunc_npu_numeric_cfg_valid__35__Vfuncout))));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_request_count 
        = ((__Vdly__tb_cmd_dfu_smoke__DOT__mem_request_count 
            & __VdlyMask__tb_cmd_dfu_smoke__DOT__mem_request_count) 
           | (vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_request_count 
              & (~ __VdlyMask__tb_cmd_dfu_smoke__DOT__mem_request_count)));
    __VdlyMask__tb_cmd_dfu_smoke__DOT__mem_request_count = 0U;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_req_addr = 
        (0xffffffffffffULL & (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_addr_q 
                              + (QData)((IData)(((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q) 
                                                 << 3U)))));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q 
        = __Vdly__tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q;
    if ((1U & (~ VL_ONEHOT_I((((1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                               << 1U) | (0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))))))) {
        if ((0U != (((1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
                     << 1U) | (0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: npu_cmd_frontend.sv:134: Assertion failed in %Ntb_cmd_dfu_smoke.u_cfe: unique case, but multiple matches found for '3'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name(),3,
                             (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q));
                VL_STOP_MT("control/npu_cmd_frontend.sv", 134, "");
            }
        }
    }
    vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_rsp_valid 
        = (5U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now 
        = (4U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q));
    if (vlSelfRef.tb_cmd_dfu_smoke__DOT__reset_n) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_rsp_valid 
            = vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_pending_q;
        if (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_valid) 
             & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_ready))) {
            if (VL_UNLIKELY((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id) 
                              != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__expected_lookup_id))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_cmd_dfu_smoke.sv:121: Assertion failed in %Ntb_cmd_dfu_smoke: CFE lookup used the wrong command ID\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("control/tb_cmd_dfu_smoke.sv", 121, "", false);
            }
            vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_busy = 0U;
        }
        vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_pending_q 
            = ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_valid) 
               & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_ready));
    } else {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_pending_q = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_rsp_valid = 0U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_busy = 0U;
    }
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[0U] 
        = (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q);
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[1U] 
        = (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q 
                   >> 0x20U));
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[2U] 
        = (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q);
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[3U] 
        = (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                   >> 0x20U));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_ready = 
        (0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__fetch_rsp_valid 
        = (4U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__mem_response_handshake 
        = ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_rsp_valid) 
           & (2U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q)));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__lookup_valid = 
        ((~ (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q)) 
         & (3U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)));
    __Vfunc_npu_cmd_command_id__23__command[0U] = tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[0U];
    __Vfunc_npu_cmd_command_id__23__command[1U] = tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[1U];
    __Vfunc_npu_cmd_command_id__23__command[2U] = tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[2U];
    __Vfunc_npu_cmd_command_id__23__command[3U] = tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[3U];
    __Vfunc_npu_cmd_command_id__23__Vfuncout = (0xfffU 
                                                & ((__Vfunc_npu_cmd_command_id__23__command[3U] 
                                                    >> 0x1fU)
                                                    ? 
                                                   (0x3ffU 
                                                    & (__Vfunc_npu_cmd_command_id__23__command[3U] 
                                                       >> 0x10U))
                                                    : 
                                                   ((__Vfunc_npu_cmd_command_id__23__command[1U] 
                                                     << 0x10U) 
                                                    | (__Vfunc_npu_cmd_command_id__23__command[1U] 
                                                       >> 0x10U))));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id 
        = __Vfunc_npu_cmd_command_id__23__Vfuncout;
    __Vfunc_npu_v2_compact_opcode_valid__33__compact_opcode 
        = (0x1fU & (tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_cmd[3U] 
                    >> 0x1aU));
    __Vfunc_npu_v2_compact_opcode_valid__33__Vfuncout 
        = ((0x1cU != (IData)(__Vfunc_npu_v2_compact_opcode_valid__33__compact_opcode)) 
           & (0x1eU != (IData)(__Vfunc_npu_v2_compact_opcode_valid__33__compact_opcode)));
    tb_cmd_dfu_smoke__DOT__u_cfe__DOT____VdfgExtracted_h654434c1__0 
        = __Vfunc_npu_v2_compact_opcode_valid__33__Vfuncout;
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 0U;
    if (((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
         & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [0U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [0U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [0U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [0U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
            == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 1U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [1U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [1U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [1U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [1U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 2U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [2U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [2U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [2U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [2U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 3U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [3U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [3U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [3U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [3U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 4U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [4U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [4U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [4U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [4U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 5U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [5U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [5U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [5U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [5U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 6U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [6U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [6U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [6U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [6U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q) 
          >> 7U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[0U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [7U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [7U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[2U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [7U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                            = vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q
                            [7U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__24__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__24__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = 1U;
    }
    if ((1U & (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                       >> 0x3fU)))) {
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__header_format_valid = 1U;
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__opcode_format_valid 
            = tb_cmd_dfu_smoke__DOT__u_cfe__DOT____VdfgExtracted_h654434c1__0;
    } else {
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode 
            = (0xffU & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q));
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__header_format_valid 
            = ((((IData)(((0ULL == (0x3fULL & vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q)) 
                          & (0x100000000000000ULL == 
                             (0xff000000000c0000ULL 
                              & vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q)))) 
                 & ([&]() {
                            vlSelfRef.__Vfunc_npu_event_ref_valid__25__event_ref 
                                = (0xfffU & (IData)(
                                                    (vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                                                     >> 0x14U)));
                            vlSelfRef.__Vfunc_npu_event_ref_valid__25__Vfuncout 
                                = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__25__event_ref)) 
                                   | (0xffU != (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__25__event_ref))));
                        }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__25__Vfuncout))) 
                & ([&]() {
                        vlSelfRef.__Vfunc_npu_event_ref_valid__26__event_ref 
                            = (0xfffU & (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                                                 >> 0x20U)));
                        vlSelfRef.__Vfunc_npu_event_ref_valid__26__Vfuncout 
                            = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__26__event_ref)) 
                               | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__26__event_ref))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__26__Vfuncout))) 
               & ([&]() {
                    vlSelfRef.__Vfunc_npu_event_ref_valid__27__event_ref 
                        = (0xfffU & (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q 
                                             >> 0x2cU)));
                    vlSelfRef.__Vfunc_npu_event_ref_valid__27__Vfuncout 
                        = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__27__event_ref)) 
                           | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__27__event_ref))));
                }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__27__Vfuncout)));
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine 
            = (0xfU & (IData)((vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q 
                               >> 0x3cU)));
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__Vfuncout 
            = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine) 
                         >> 3U))) && ((4U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine))
                                       ? ((1U & (~ 
                                                 ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine) 
                                                  >> 1U))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine))) 
                                              && (((((0x80U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)) 
                                                     | (0x81U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                    | (0x82U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                   | (0x84U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                  | (0x86U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)))))
                                       : ((2U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine))
                                           ? ((1U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine))
                                               ? ((
                                                   ((((((((0x60U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)) 
                                                          | (0x61U 
                                                             == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                         | (0x62U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                        | (0x63U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                       | (0x64U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                      | (0x65U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                     | (0x66U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                    | (0x67U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                   | (0x68U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                  | (0x69U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)))
                                               : ((
                                                   ((0x40U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)) 
                                                    | (0x41U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                   | (0x42U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                  | (0x43U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))))
                                           : ((1U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__engine))
                                               ? ((
                                                   ((((0x20U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)) 
                                                      | (0x21U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                     | (0x22U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                    | (0x23U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                   | (0x24U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                  | (0x25U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)))
                                               : ((
                                                   (((0U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)) 
                                                     | (1U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                    | (2U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                   | (3U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode))) 
                                                  | (4U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__opcode)))))));
        vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__opcode_format_valid 
            = vlSelfRef.__Vfunc_npu_opcode_engine_valid__28__Vfuncout;
    }
}
