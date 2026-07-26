// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_axi_slave_frontend.h for the primary calling header

#include "Vtb_npu_axi_slave_frontend__pch.h"
#include "Vtb_npu_axi_slave_frontend__Syms.h"
#include "Vtb_npu_axi_slave_frontend___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__0(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ tb_npu_axi_slave_frontend__DOT__read_data;
    tb_npu_axi_slave_frontend__DOT__read_data = 0;
    IData/*31:0*/ tb_npu_axi_slave_frontend__DOT__command_count_before;
    tb_npu_axi_slave_frontend__DOT__command_count_before = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__0__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__0__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__0__message;
    IData/*23:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__addr;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__len;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__len = 0;
    CData/*2:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__size;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__size = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__burst;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__burst = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__id = 0;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__strb;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__last = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__3__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__3__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__3__message;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__strb;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__last = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__5__expected_resp;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__5__expected_resp = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__5__expected_id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__5__expected_id = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__6__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__6__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__6__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__7__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__7__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__7__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__8__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__8__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__8__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__9__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__9__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__9__message;
    IData/*23:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__addr;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__len;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__len = 0;
    CData/*2:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__size;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__size = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__burst;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__burst = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__id = 0;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__data = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_resp;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_resp = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_last = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_id = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__12__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__12__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__12__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__13__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__13__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__13__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__14__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__14__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__14__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__15__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__15__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__15__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__16__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__16__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__16__message;
    IData/*23:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__addr;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__len;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__len = 0;
    CData/*2:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__size;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__size = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__burst;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__burst = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__id = 0;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__strb;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__last = 0;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__strb;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__last = 0;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__strb;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__last = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__21__expected_resp;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__21__expected_resp = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__21__expected_id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__21__expected_id = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__22__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__22__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__22__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__23__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__23__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__23__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__24__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__24__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__24__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__25__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__25__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__25__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__26__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__26__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__26__message;
    IData/*23:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__addr;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__len;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__len = 0;
    CData/*2:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__size;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__size = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__burst;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__burst = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__id = 0;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__strb;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__last = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__29__expected_resp;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__29__expected_resp = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__29__expected_id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__29__expected_id = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__30__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__30__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__30__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__31__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__31__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__31__message;
    IData/*23:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__addr;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__len;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__len = 0;
    CData/*2:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__size;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__size = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__burst;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__burst = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__id = 0;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__data = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_resp;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_resp = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_last = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_id = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__34__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__34__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__34__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__35__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__35__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__35__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__36__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__36__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__36__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__37__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__37__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__37__message;
    IData/*23:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__addr;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__len;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__len = 0;
    CData/*2:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__size;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__size = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__burst;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__burst = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__id = 0;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__strb;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__last = 0;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__strb;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__last = 0;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__strb;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__last = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__42__expected_resp;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__42__expected_resp = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__42__expected_id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__42__expected_id = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__43__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__43__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__43__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__44__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__44__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__44__message;
    IData/*23:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__addr;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__len;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__len = 0;
    CData/*2:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__size;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__size = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__burst;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__burst = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__id = 0;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__data = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_resp;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_resp = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_last = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_id = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__47__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__47__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__47__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__48__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__48__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__48__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__49__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__49__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__49__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__50__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__50__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__50__message;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__data = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_resp;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_resp = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_last = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_id = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__52__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__52__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__52__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__53__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__53__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__53__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__54__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__54__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__54__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__55__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__55__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__55__message;
    QData/*63:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__data = 0;
    CData/*1:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_resp;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_resp = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_last;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_last = 0;
    CData/*7:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_id;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_id = 0;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__57__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__57__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__57__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__58__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__58__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__58__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__59__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__59__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__59__message;
    CData/*0:0*/ __Vtask_tb_npu_axi_slave_frontend__DOT__check__60__condition;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__60__condition = 0;
    std::string __Vtask_tb_npu_axi_slave_frontend__DOT__check__60__message;
    // Body
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__clk_i = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__reset_n = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awid = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awsize = 3U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awburst = 1U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlock = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bready = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arid = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlen = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arsize = 3U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arburst = 1U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlock = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arvalid = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_enable = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error_clear = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[1U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[2U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[3U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[4U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[5U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[6U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[7U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[8U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[9U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0xaU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0xbU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0xcU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0xdU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0xeU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0xfU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x10U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x11U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x12U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x13U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x14U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x15U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x16U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x17U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x18U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x19U] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x1aU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x1bU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x1cU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x1dU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x1eU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[0x1fU] = 0ULL;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__byte_index = 0U;
    while (VL_GTS_III(32, 0x100U, vlSelfRef.tb_npu_axi_slave_frontend__DOT__byte_index)) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem[(0xffU 
                                                          & vlSelfRef.tb_npu_axi_slave_frontend__DOT__byte_index)] = 0ULL;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__byte_index 
            = ((IData)(1U) + vlSelfRef.tb_npu_axi_slave_frontend__DOT__byte_index);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         433);
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         433);
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         433);
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         433);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__reset_n = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         435);
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         435);
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__0__message = 
        std::string{"AXI frontend did not become idle after reset"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__0__condition 
        = ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid)) 
           & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid)) 
                 & (0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__0__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__0__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__id = 0x31U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__burst = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__size = 3U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__len = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__addr = 0x20000U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         309);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__addr;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__len;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awsize 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__size;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awburst 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__burst;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awid 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__1__id;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         316);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             316);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         317);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__last = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__strb = 0xffU;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__data = 0x2000000000001000ULL;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         328);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__data;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__strb;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__2__last;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         333);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             333);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         334);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 0U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         441);
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         441);
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         441);
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__3__message = 
        std::string{"low command word escaped before burst commit"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__3__condition 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_valid)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__3__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__3__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__last = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__strb = 0xffU;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__data = 0x1fffffffff00040ULL;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         328);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__data;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__strb;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__4__last;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         333);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             333);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         334);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__5__expected_id = 0x31U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__5__expected_resp = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bready = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         345);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             345);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__6__message = 
        std::string{"unexpected AXI B response"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__6__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__5__expected_resp));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__6__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__6__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__7__message = 
        std::string{"unexpected AXI B ID"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__7__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_id_q) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__5__expected_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__7__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__7__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         348);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bready = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__8__message = 
        std::string{"committed command was reported idle"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__8__condition 
        = (1U & (~ ((1U != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
                    & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q)) 
                       & (0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q))))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__8__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__8__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_enable = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         447);
    while ((1U != vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_command_count_q)) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             447);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__9__message = 
        std::string{"CFE received the wrong low command word"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__9__condition 
        = (0x2000000000001000ULL == vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_low_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__9__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__9__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__id = 0x42U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__burst = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__size = 3U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__len = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__addr = 0x20008U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         361);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__addr;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlen 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__len;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arsize 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__size;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arburst 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__burst;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arid 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__10__id;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         368);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             368);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         369);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_id = 0x42U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_last = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_resp = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         382);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             382);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__data 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rdata;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__12__message = 
        std::string{"unexpected AXI R response"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__12__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rresp) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_resp));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__12__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__12__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__13__message = 
        std::string{"unexpected AXI RLAST"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__13__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rlast) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_last));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__13__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__13__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__14__message = 
        std::string{"unexpected AXI R ID"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__14__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rid) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__expected_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__14__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__14__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         387);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready = 0U;
    tb_npu_axi_slave_frontend__DOT__read_data = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__11__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__15__message = 
        std::string{"command response ID mismatch"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__15__condition 
        = (0U == (0xfffU & (IData)(tb_npu_axi_slave_frontend__DOT__read_data)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__15__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__15__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__16__message = 
        std::string{"command response status mismatch"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__16__condition 
        = (0U == (0xffU & (IData)((tb_npu_axi_slave_frontend__DOT__read_data 
                                   >> 0xcU))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__16__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__16__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    tb_npu_axi_slave_frontend__DOT__command_count_before 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_command_count_q;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__id = 0x32U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__burst = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__size = 3U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__len = 2U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__addr = 0x20000U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         309);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__addr;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__len;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awsize 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__size;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awburst 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__burst;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awid 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__17__id;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         316);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             316);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         317);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__last = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__strb = 0xffU;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__data = 1ULL;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         328);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__data;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__strb;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__18__last;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         333);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             333);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         334);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__last = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__strb = 0xffU;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__data = 2ULL;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         328);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__data;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__strb;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__19__last;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         333);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             333);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         334);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__last = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__strb = 0xffU;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__data = 3ULL;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         328);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__data;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__strb;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__20__last;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         333);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             333);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         334);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__21__expected_id = 0x32U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__21__expected_resp = 2U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bready = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         345);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             345);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__22__message = 
        std::string{"unexpected AXI B response"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__22__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__21__expected_resp));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__22__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__22__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__23__message = 
        std::string{"unexpected AXI B ID"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__23__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_id_q) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__21__expected_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__23__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__23__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         348);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bready = 0U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         463);
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         463);
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         463);
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         463);
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         463);
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__24__message = 
        std::string{"malformed command burst changed CFE state"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__24__condition 
        = (vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_command_count_q 
           == tb_npu_axi_slave_frontend__DOT__command_count_before);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__24__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__24__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__25__message = 
        std::string{"malformed command did not set sticky error"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__25__condition 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__25__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__25__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error_clear = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         469);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error_clear = 0U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         471);
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__26__message = 
        std::string{"sticky protocol error did not clear"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__26__condition 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__26__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__26__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__id = 0x51U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__burst = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__size = 3U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__len = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__addr = 0x18U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         309);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__addr;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__len;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awsize 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__size;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awburst 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__burst;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awid 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__27__id;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         316);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             316);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         317);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__last = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__strb = 0xfU;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__data = 0x1122334455667788ULL;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         328);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__data;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__strb;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__28__last;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         333);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             333);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         334);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__29__expected_id = 0x51U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__29__expected_resp = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bready = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         345);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             345);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__30__message = 
        std::string{"unexpected AXI B response"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__30__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__29__expected_resp));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__30__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__30__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__31__message = 
        std::string{"unexpected AXI B ID"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__31__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_id_q) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__29__expected_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__31__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__31__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         348);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bready = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__id = 0x52U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__burst = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__size = 3U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__len = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__addr = 0x18U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         361);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__addr;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlen 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__len;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arsize 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__size;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arburst 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__burst;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arid 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__32__id;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         368);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             368);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         369);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_id = 0x52U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_last = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_resp = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         382);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             382);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__data 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rdata;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__34__message = 
        std::string{"unexpected AXI R response"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__34__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rresp) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_resp));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__34__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__34__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__35__message = 
        std::string{"unexpected AXI RLAST"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__35__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rlast) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_last));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__35__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__35__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__36__message = 
        std::string{"unexpected AXI R ID"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__36__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rid) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__expected_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__36__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__36__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         387);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready = 0U;
    tb_npu_axi_slave_frontend__DOT__read_data = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__33__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__37__message = 
        std::string{"CSR write strobe or read data was incorrect"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__37__condition 
        = (0x55667788ULL == tb_npu_axi_slave_frontend__DOT__read_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__37__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__37__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__id = 0x61U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__burst = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__size = 3U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__len = 2U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__addr = 0x100040U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         309);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__addr;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__len;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awsize 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__size;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awburst 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__burst;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awid 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_address__38__id;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         316);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             316);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         317);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__last = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__strb = 0xffU;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__data = 0x123456789abcdefULL;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         328);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__data;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__strb;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__39__last;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         333);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             333);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         334);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__last = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__strb = 0xffU;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__data = 0xfedcba9876543210ULL;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         328);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__data;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__strb;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__40__last;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         333);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             333);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         334);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__last = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__strb = 0xffU;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__data = 0xf1e2d3c4b5a6978ULL;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         328);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__data;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__strb;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_write_data__41__last;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         333);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             333);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         334);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__42__expected_id = 0x61U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__42__expected_resp = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bready = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         345);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             345);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__43__message = 
        std::string{"unexpected AXI B response"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__43__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__42__expected_resp));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__43__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__43__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__44__message = 
        std::string{"unexpected AXI B ID"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__44__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_id_q) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_wait_b__42__expected_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__44__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__44__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         348);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bready = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__id = 0x62U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__burst = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__size = 3U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__len = 2U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__addr = 0x100040U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         361);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__addr;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlen 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__len;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arsize 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__size;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arburst 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__burst;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arid 
        = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_address__45__id;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arvalid = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         368);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arready)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             368);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         369);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arvalid = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_id = 0x62U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_last = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_resp = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         382);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             382);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__data 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rdata;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__47__message = 
        std::string{"unexpected AXI R response"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__47__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rresp) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_resp));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__47__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__47__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__48__message = 
        std::string{"unexpected AXI RLAST"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__48__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rlast) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_last));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__48__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__48__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__49__message = 
        std::string{"unexpected AXI R ID"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__49__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rid) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__expected_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__49__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__49__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         387);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready = 0U;
    tb_npu_axi_slave_frontend__DOT__read_data = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__46__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__50__message = 
        std::string{"L1 beat 0 mismatch"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__50__condition 
        = (0x123456789abcdefULL == tb_npu_axi_slave_frontend__DOT__read_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__50__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__50__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_id = 0x62U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_last = 0U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_resp = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         382);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             382);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__data 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rdata;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__52__message = 
        std::string{"unexpected AXI R response"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__52__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rresp) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_resp));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__52__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__52__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__53__message = 
        std::string{"unexpected AXI RLAST"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__53__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rlast) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_last));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__53__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__53__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__54__message = 
        std::string{"unexpected AXI R ID"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__54__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rid) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__expected_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__54__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__54__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         387);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready = 0U;
    tb_npu_axi_slave_frontend__DOT__read_data = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__51__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__55__message = 
        std::string{"L1 beat 1 mismatch"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__55__condition 
        = (0xfedcba9876543210ULL == tb_npu_axi_slave_frontend__DOT__read_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__55__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__55__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_id = 0x62U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_last = 1U;
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_resp = 0U;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready = 1U;
    co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         382);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid)))) {
        co_await vlSelfRef.__VtrigSched_h4a2ae8f4__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_axi_slave_frontend.clk_i)", 
                                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                                             382);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__data 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rdata;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__57__message = 
        std::string{"unexpected AXI R response"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__57__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rresp) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_resp));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__57__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__57__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__58__message = 
        std::string{"unexpected AXI RLAST"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__58__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rlast) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_last));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__58__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__58__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__59__message = 
        std::string{"unexpected AXI R ID"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__59__condition 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rid) 
           == (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__expected_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__59__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__59__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h4a2ae8b1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_axi_slave_frontend.clk_i)", 
                                                         "tb/tb_npu_axi_slave_frontend.sv", 
                                                         387);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready = 0U;
    tb_npu_axi_slave_frontend__DOT__read_data = __Vtask_tb_npu_axi_slave_frontend__DOT__axi_read_beat__56__data;
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__60__message = 
        std::string{"L1 beat 2 mismatch"};
    __Vtask_tb_npu_axi_slave_frontend__DOT__check__60__condition 
        = (0xf1e2d3c4b5a6978ULL == tb_npu_axi_slave_frontend__DOT__read_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_axi_slave_frontend__DOT__check__60__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:297: Assertion failed in %Ntb_npu_axi_slave_frontend.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_axi_slave_frontend__DOT__check__60__message));
        VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 297, "", false);
    }
    VL_WRITEF_NX("TB_MODULE_FRONTEND_PASS commands=%0#\n",0,
                 32,vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_command_count_q);
    VL_FINISH_MT("tb/tb_npu_axi_slave_frontend.sv", 499, "");
}

VL_INLINE_OPT VlCoroutine Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__1(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0xbebc200ULL, 
                                         nullptr, "tb/tb_npu_axi_slave_frontend.sv", 
                                         503);
    VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:504: Assertion failed in %Ntb_npu_axi_slave_frontend: frontend module test timed out\n",0,
                 64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
    VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 504, "", false);
}

VL_INLINE_OPT VlCoroutine Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__2(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "tb/tb_npu_axi_slave_frontend.sv", 
                                             195);
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__clk_i 
            = (1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__clk_i)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___dump_triggers__act(Vtb_npu_axi_slave_frontend___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_npu_axi_slave_frontend___024root___eval_triggers__act(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_triggers__act\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_axi_slave_frontend__DOT__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reset_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_axi_slave_frontend__DOT__reset_n__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__clk_i)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_axi_slave_frontend__DOT__clk_i__0)));
    vlSelfRef.__VactTriggered.setBit(3U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_axi_slave_frontend__DOT__clk_i__0 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_axi_slave_frontend__DOT__reset_n__0 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__reset_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_npu_axi_slave_frontend___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_npu_axi_slave_frontend___024root___nba_sequent__TOP__0(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___nba_sequent__TOP__0\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value = 0;
    QData/*63:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__Vfuncout;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__data;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__data = 0;
    CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__size;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__size = 0;
    CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__addr_low;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__addr_low = 0;
    QData/*63:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__mask;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__mask = 0;
    CData/*3:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__Vfuncout;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__base;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__amount;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__amount = 0;
    IData/*31:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__value;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__value = 0;
    CData/*3:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__Vfuncout;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__base;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__value;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__value = 0;
    CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__Vfuncout;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__base;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__value;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__value = 0;
    CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__Vfuncout;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__base;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__value;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__value = 0;
    QData/*63:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_low_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_low_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_have_low_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_have_low_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid;
    __Vdly__tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid = 0;
    CData/*0:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__reg_pending_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__reg_pending_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__l1_pending_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__l1_pending_q = 0;
    CData/*1:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__s_axi_rvalid;
    __Vdly__tb_npu_axi_slave_frontend__DOT__s_axi_rvalid = 0;
    CData/*2:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 0;
    SData/*8:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q = 0;
    IData/*23:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q = 0;
    IData/*23:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q = 0;
    SData/*8:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q = 0;
    SData/*8:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q = 0;
    CData/*1:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q = 0;
    CData/*2:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 0;
    QData/*63:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg0_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg0_q = 0;
    QData/*63:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg1_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg1_q = 0;
    CData/*1:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_op_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_op_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q = 0;
    CData/*7:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q = 0;
    QData/*63:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q = 0;
    QData/*63:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q = 0;
    CData/*7:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q = 0;
    CData/*7:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q = 0;
    SData/*8:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q = 0;
    CData/*2:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_size_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_size_q = 0;
    CData/*1:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q = 0;
    CData/*4:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q = 0;
    CData/*3:0*/ __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v0;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v0 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v0;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v0;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v1;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v1 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v1;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v1;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v2;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v2 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v2;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v2;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v3;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v3 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v3;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v3;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v3 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v4;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v4 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v4;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v4;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v4 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v5;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v5 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v5;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v5 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v5;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v5 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v6;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v6 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v6;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v6;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v6 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v7;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v7 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v7;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v7;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v7 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v0;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v0;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v0;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v1;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v1;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v1;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v2;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v2 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v2;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v2;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v3;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v3 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v3;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v3;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v3 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v4;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v4 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v4;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v4;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v4 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v5;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v5 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v5;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v5 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v5;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v5 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v6;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v6 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v6;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v6;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v6 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v7;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v7 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v7;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v7;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v7 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0;
    __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0 = 0;
    CData/*2:0*/ __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0;
    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0 = 0;
    // Body
    __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_low_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_low_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_have_low_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_have_low_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__reg_pending_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_pending_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__l1_pending_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_pending_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v0 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v1 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v2 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v3 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v4 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v5 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v6 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v7 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v0 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v1 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v2 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v3 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v4 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v5 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v6 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v7 = 0U;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg0_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg0_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg1_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg1_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_op_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_op_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_size_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_size_q;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0 = 0U;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__s_axi_rvalid 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14 = 0U;
    __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15 = 0U;
    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q;
    if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__reset_n) {
        if ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q))) {
            if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_valid) 
                 & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_ready))) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q))) {
            if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_valid) 
                 & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_ready))) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q = 2U;
            }
        } else if ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q))) {
            if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q = 0U;
            }
        } else {
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q = 0U;
        }
        if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error_clear) {
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error = 0U;
        }
        if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid) 
             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bready))) {
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid = 0U;
        }
        if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid) 
             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready))) {
            __Vdly__tb_npu_axi_slave_frontend__DOT__s_axi_rvalid = 0U;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_pop_rsp_q = 0U;
            if ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q))) {
                if (((0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q))) 
                     == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q))) {
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 0U;
                } else {
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q)));
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q 
                        = (0xffffffU & ((IData)(8U) 
                                        + vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q));
                    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_req_sent_q = 0U;
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 1U;
                }
            } else if ((4U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q))) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 0U;
            }
        }
        if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid) 
             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awready))) {
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_id_q 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awid;
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr;
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen)));
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q = 0U;
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q = 0U;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_sent_q = 0U;
            if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_cmd_format_w) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q = 0U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 1U;
            } else if ((((0x20020U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr) 
                         | ((0x20028U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr) 
                            | ((0x20030U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr) 
                               | (0x20048U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr)))) 
                        & ((1U == (0x1ffU & ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen)))) 
                           & ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awsize)) 
                              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlock)) 
                                 & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awburst))))))) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q = 3U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 2U;
            } else if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_csr_format_w) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q = 1U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 2U;
            } else if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_l1_format_w) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q = 2U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 2U;
            } else {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q = 0U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q = 1U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 5U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error = 1U;
            }
        }
        if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w) {
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__base 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_rptr_q;
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__value 
                = ((IData)(2U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__base));
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__Vfuncout 
                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__value);
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_rptr_q 
                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__71__Vfuncout;
        }
        if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid) 
             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready))) {
            if ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q))) {
                __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0 
                    = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata;
                __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0 
                    = (0xfU & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q));
                __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0 = 1U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q 
                    = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w;
                if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w) {
                    if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w) {
                        vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error = 1U;
                        vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp = 2U;
                    } else {
                        if ((0U < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0 
                                = ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [0U]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0 = 1U;
                        }
                        if ((1U < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(1U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1 
                                = ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [1U]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1 = 1U;
                        }
                        if ((2U < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(2U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2 
                                = ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [2U]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2 = 1U;
                        }
                        if ((3U < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(3U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3 
                                = ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [3U]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3 = 1U;
                        }
                        if ((4U < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(4U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4 
                                = ((4U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [4U]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4 = 1U;
                        }
                        if ((5U < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(5U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5 
                                = ((5U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [5U]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5 = 1U;
                        }
                        if ((6U < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(6U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6 
                                = ((6U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [6U]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6 = 1U;
                        }
                        if ((7U < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(7U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7 
                                = ((7U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [7U]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7 = 1U;
                        }
                        if ((8U < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(8U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8 
                                = ((8U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [8U]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8 = 1U;
                        }
                        if ((9U < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(9U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9 
                                = ((9U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [9U]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9 = 1U;
                        }
                        if ((0xaU < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(0xaU) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10 
                                = ((0xaU == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [0xaU]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10 = 1U;
                        }
                        if ((0xbU < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(0xbU) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11 
                                = ((0xbU == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [0xbU]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11 = 1U;
                        }
                        if ((0xcU < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(0xcU) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12 
                                = ((0xcU == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [0xcU]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12 = 1U;
                        }
                        if ((0xdU < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(0xdU) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13 
                                = ((0xdU == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [0xdU]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13 = 1U;
                        }
                        if ((0xeU < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(0xeU) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14 
                                = ((0xeU == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [0xeU]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14 = 1U;
                        }
                        if ((0xfU < (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value 
                                = ((IData)(0xfU) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__base));
                            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__value);
                            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15 
                                = ((0xfU == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata
                                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem
                                   [0xfU]);
                            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15 
                                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__68__Vfuncout;
                            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15 = 1U;
                        }
                        vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp = 0U;
                    }
                    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid = 1U;
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 0U;
                } else {
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q)));
                }
            } else if ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q))) {
                if ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q))) {
                    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp = 0U;
                    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid = 1U;
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 0U;
                    if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w) 
                         | (0xffU != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb)))) {
                        vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp = 2U;
                        vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error = 1U;
                    } else {
                        if ((0x20020U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q)) {
                            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg0_q 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata;
                        } else if ((0x20028U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q)) {
                            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg1_q 
                                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata;
                        } else if ((0x20030U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q)) {
                            if ((((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q) 
                                  | (0ULL != (vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata 
                                              >> 2U))) 
                                 | (0U == (3U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata))))) {
                                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp = 2U;
                            } else {
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_op_q 
                                    = (3U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata));
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q = 1U;
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q = 0U;
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q = 0U;
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q = 1U;
                            }
                        } else if ((0x20048U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q)) {
                            if ((1U & (((1ULL != vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata) 
                                        | (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q))) 
                                       | (2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_op_q))))) {
                                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp = 2U;
                            } else if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q) {
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q = 0U;
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q = 0U;
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q = 1U;
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q = 0xaU;
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q = 0xaULL;
                            } else if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_inflight_q) {
                                vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_inflight_q = 0U;
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q = 0U;
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q = 1U;
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q = 0xaU;
                                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q = 0xaULL;
                            }
                        } else {
                            vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp = 2U;
                        }
                        if ((1U & (~ VL_ONEHOT_I(((
                                                   ((0x20048U 
                                                     == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q) 
                                                    << 3U) 
                                                   | ((0x20030U 
                                                       == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q) 
                                                      << 2U)) 
                                                  | (((0x20028U 
                                                       == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q) 
                                                      << 1U) 
                                                     | (0x20020U 
                                                        == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q))))))) {
                            if ((0U != ((((0x20048U 
                                           == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q) 
                                          << 3U) | 
                                         ((0x20030U 
                                           == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q) 
                                          << 2U)) | 
                                        (((0x20028U 
                                           == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q) 
                                          << 1U) | 
                                         (0x20020U 
                                          == vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q))))) {
                                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                                    VL_WRITEF_NX("[%0t] %%Error: npu_axi_slave_frontend.sv:638: Assertion failed in %Ntb_npu_axi_slave_frontend.dut: unique case, but multiple matches found for '24'h%x'\n",0,
                                                 64,
                                                 VL_TIME_UNITED_Q(1000),
                                                 -9,
                                                 vlSymsp->name(),
                                                 24,
                                                 vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q);
                                    VL_STOP_MT("top/npu_axi_slave_frontend.sv", 638, "");
                                }
                            }
                        }
                    }
                } else {
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wdata;
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q 
                        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb;
                    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_addr_q 
                        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q;
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q 
                        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w;
                    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_sent_q = 0U;
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 3U;
                }
            } else if ((5U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q))) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q = 1U;
                if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_current_error_w) {
                    vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error = 1U;
                }
                if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w) {
                    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp = 2U;
                    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid = 1U;
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 0U;
                } else {
                    __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q)));
                }
            }
        }
        if ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q))) {
            if (((((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)) 
                   & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_valid)) 
                  & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_pending_q))) 
                 | (((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)) 
                     & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_valid)) 
                    & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_pending_q))))) {
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_sent_q = 1U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 4U;
            }
        }
        if (((4U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
             & ((((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)) 
                  & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_pending_q)) 
                 & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_ready)) 
                | (((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)) 
                    & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_pending_q)) 
                   & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_ready))))) {
            if ((((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)) 
                  & (0U != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_status_q))) 
                 | ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)) 
                    & (0U != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_status_q))))) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q = 1U;
            }
            if (((0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))) 
                 == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q))) {
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp 
                    = ((((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q) 
                         | ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)) 
                            & (0U != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_status_q)))) 
                        | ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)) 
                           & (0U != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_status_q))))
                        ? 2U : 0U);
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid = 1U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 0U;
            } else {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q)));
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q 
                    = (0xffffffU & ((IData)(8U) + vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q));
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_sent_q = 0U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 2U;
            }
        }
        if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arvalid) 
             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arready))) {
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr;
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q = 0U;
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arid;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rid 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arid;
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlen)));
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_size_q 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arsize;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_req_sent_q = 0U;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_pop_rsp_q = 0U;
            if (((0x20008U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
                 & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT____VdfgRegularize_h97cdcae2_0_0))) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 4U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q = 0U;
            } else if (((0x20010U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
                        & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT____VdfgRegularize_h97cdcae2_0_0))) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 3U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q = 0U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rdata 
                    = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__fifo_status_w;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rresp = 0U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rlast = 1U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__s_axi_rvalid = 1U;
            } else if ((((0x20020U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
                         | ((0x20028U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
                            | ((0x20038U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
                               | (0x20040U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr)))) 
                        & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT____VdfgRegularize_h97cdcae2_0_0))) {
                if ((1U & (~ VL_ONEHOT_I(((((0x20040U 
                                             == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
                                            << 3U) 
                                           | ((0x20038U 
                                               == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
                                              << 2U)) 
                                          | (((0x20028U 
                                               == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
                                              << 1U) 
                                             | (0x20020U 
                                                == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr))))))) {
                    if ((0U != ((((0x20040U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
                                  << 3U) | ((0x20038U 
                                             == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
                                            << 2U)) 
                                | (((0x20028U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
                                    << 1U) | (0x20020U 
                                              == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: npu_axi_slave_frontend.sv:758: Assertion failed in %Ntb_npu_axi_slave_frontend.dut: unique case, but multiple matches found for '24'h%x'\n",0,
                                         64,VL_TIME_UNITED_Q(1000),
                                         -9,vlSymsp->name(),
                                         24,vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr);
                            VL_STOP_MT("top/npu_axi_slave_frontend.sv", 758, "");
                        }
                    }
                }
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 3U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q = 0U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rdata 
                    = ((0x20020U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr)
                        ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg0_q
                        : ((0x20028U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr)
                            ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg1_q
                            : ((0x20038U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr)
                                ? (((QData)((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q)) 
                                    << 8U) | (QData)((IData)(
                                                             (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q) 
                                                               << 1U) 
                                                              | (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q)))))
                                : ((0x20040U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr)
                                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q
                                    : 0ULL))));
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rresp = 0U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rlast = 1U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__s_axi_rvalid = 1U;
            } else if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ar_csr_format_w) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 1U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q = 1U;
            } else if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ar_l1_format_w) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 1U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q = 2U;
            } else {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 3U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q = 0U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rdata = 0ULL;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rresp = 2U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rlast = 1U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__s_axi_rvalid = 1U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error = 1U;
            }
        }
        if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w) {
            __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_data;
            __VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_wptr_q;
            __VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0 = 1U;
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__base 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_wptr_q;
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__value 
                = ((IData)(1U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__base));
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__Vfuncout 
                = (7U & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__value);
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_wptr_q 
                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__72__Vfuncout;
        }
        if ((((4U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid))) 
             & (0U != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q)))) {
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rid 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rdata 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem
                [vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_rptr_q];
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rresp = 0U;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rlast = 1U;
            __Vdly__tb_npu_axi_slave_frontend__DOT__s_axi_rvalid = 1U;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_pop_rsp_q = 1U;
        }
        if ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q))) {
            if (((((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q)) 
                   & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_valid)) 
                  & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_pending_q))) 
                 | (((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q)) 
                     & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_valid)) 
                    & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_pending_q))))) {
                __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 2U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_req_sent_q = 1U;
            }
        }
        if (((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
             & ((((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q)) 
                  & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_pending_q)) 
                 & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_ready)) 
                | (((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q)) 
                    & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_pending_q)) 
                   & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_ready))))) {
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__addr_low 
                = (7U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q);
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__size 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_size_q;
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 3U;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rid 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q;
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__data 
                = ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q))
                    ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_data_q
                    : vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_data_q);
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rlast 
                = ((0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q))) 
                   == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q));
            __Vdly__tb_npu_axi_slave_frontend__DOT__s_axi_rvalid = 1U;
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__mask 
                = ((0U == (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__size))
                    ? VL_SHIFTL_QQI(64,64,32, 0xffULL, 
                                    VL_SHIFTL_III(32,32,32, (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__addr_low), 3U))
                    : ((1U == (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__size))
                        ? VL_SHIFTL_QQI(64,64,32, 0xffffULL, 
                                        VL_SHIFTL_III(32,32,32, (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__addr_low), 3U))
                        : ((2U == (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__size))
                            ? VL_SHIFTL_QQI(64,64,32, 0xffffffffULL, 
                                            VL_SHIFTL_III(32,32,32, (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__addr_low), 3U))
                            : 0xffffffffffffffffULL)));
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__Vfuncout 
                = (__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__data 
                   & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__mask);
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rdata 
                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__narrow_read_data__69__Vfuncout;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rresp 
                = ((((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q)) 
                     & (0U != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_status_q))) 
                    | ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q)) 
                       & (0U != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_status_q))))
                    ? 2U : 0U);
        }
        if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q) {
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q = 0U;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_inflight_q = 1U;
        }
        if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_commit_w) {
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__amount 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q;
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__base 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q;
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__value 
                = ((IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__base) 
                   + __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__amount);
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__Vfuncout 
                = (0xfU & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__value);
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q 
                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__70__Vfuncout;
        }
        if ((2U == (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_commit_w) 
                     << 1U) | (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w)))) {
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q 
                = (0x1fU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q) 
                            + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q)));
        } else if ((1U == (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_commit_w) 
                            << 1U) | (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w)))) {
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q 
                = (0x1fU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q) 
                            - (IData)(2U)));
        } else if ((3U == (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_commit_w) 
                            << 1U) | (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w)))) {
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q 
                = (0x1fU & (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q) 
                             + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q)) 
                            - (IData)(2U)));
        }
        if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_pop_w) {
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__base 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_rptr_q;
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__value 
                = ((IData)(1U) + (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__base));
            __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__Vfuncout 
                = (7U & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__value);
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_rptr_q 
                = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_ptr_add__73__Vfuncout;
        }
        if ((2U == (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w) 
                     << 1U) | (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_pop_w)))) {
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q)));
        } else if ((1U == (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w) 
                            << 1U) | (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_pop_w)))) {
            __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q 
                = (0xfU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q) 
                           - (IData)(1U)));
        }
    } else {
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_rptr_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_wptr_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_rptr_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_id_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_sent_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q = 0ULL;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_addr_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_size_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_req_sent_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_pop_rsp_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bresp = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rid = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rdata = 0ULL;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rresp = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rlast = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__s_axi_rvalid = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg0_q = 0ULL;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg1_q = 0ULL;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q = 0ULL;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_inflight_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_op_q = 0U;
    }
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg0_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg0_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg1_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg1_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_op_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_op_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_size_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_size_q;
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem__v0;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem__v0;
    }
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__s_axi_rvalid;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q;
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v0;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v1;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v2;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v3;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v4;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v5;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v6;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v7;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v8;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v9;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v10;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v11;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v12;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v13;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v14;
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15] 
            = __VdlyVal__tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem__v15;
    }
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w 
        = ((0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))) 
           == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q));
    if (vlSelfRef.tb_npu_axi_slave_frontend__DOT__reset_n) {
        if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_valid) 
             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_ready))) {
            if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_first) 
                 & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_last)))) {
                if (VL_UNLIKELY((vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_have_low_q))) {
                    VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:228: Assertion failed in %Ntb_npu_axi_slave_frontend: CFE model received two low command words\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name());
                    VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 228, "", false);
                }
                __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_low_q 
                    = vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_data;
                __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_have_low_q = 1U;
            } else if (VL_LIKELY(((((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_first)) 
                                    & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_last)) 
                                   & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_have_low_q))))) {
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_command_count_q 
                    = ((IData)(1U) + vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_command_count_q);
                __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_have_low_q = 0U;
                __Vdly__tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid = 1U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_data 
                    = (0x700000ULL | (QData)((IData)(
                                                     (0xfffU 
                                                      & (IData)(
                                                                (vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_low_q 
                                                                 >> 0x30U))))));
            } else {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:240: Assertion failed in %Ntb_npu_axi_slave_frontend: CFE model saw invalid first/last markers\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 240, "", false);
            }
        }
        if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid) 
             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_ready))) {
            __Vdly__tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid = 0U;
        }
        if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_valid) 
             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_ready))) {
            if (VL_UNLIKELY(((IData)((0U != (0xff07U 
                                             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr))))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:250: Assertion failed in %Ntb_npu_axi_slave_frontend: CSR model received an invalid address\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 250, "", false);
            }
            __Vdly__tb_npu_axi_slave_frontend__DOT__reg_pending_q = 1U;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_status_q = 0U;
            vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_data_q 
                = vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem
                [(0x1fU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr) 
                           >> 3U))];
            if ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q))) {
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__byte_index = 8U;
                if ((1U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v0 
                        = (0xffU & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q));
                    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v0 
                        = (0x1fU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr) 
                                    >> 3U));
                    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v0 = 1U;
                }
                if ((2U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v1 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                            >> 8U)));
                    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v1 
                        = (0x1fU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr) 
                                    >> 3U));
                    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v1 = 1U;
                }
                if ((4U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v2 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                            >> 0x10U)));
                    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v2 
                        = (0x1fU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr) 
                                    >> 3U));
                    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v2 = 1U;
                }
                if ((8U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v3 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                            >> 0x18U)));
                    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v3 
                        = (0x1fU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr) 
                                    >> 3U));
                    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v3 = 1U;
                }
                if ((0x10U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v4 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                            >> 0x20U)));
                    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v4 
                        = (0x1fU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr) 
                                    >> 3U));
                    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v4 = 1U;
                }
                if ((0x20U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v5 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                            >> 0x28U)));
                    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v5 
                        = (0x1fU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr) 
                                    >> 3U));
                    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v5 = 1U;
                }
                if ((0x40U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v6 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                            >> 0x30U)));
                    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v6 
                        = (0x1fU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr) 
                                    >> 3U));
                    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v6 = 1U;
                }
                if ((0x80U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                    __VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v7 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                            >> 0x38U)));
                    __VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v7 
                        = (0x1fU & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr) 
                                    >> 3U));
                    __VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v7 = 1U;
                }
            }
        }
        if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_pending_q) 
             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_ready))) {
            __Vdly__tb_npu_axi_slave_frontend__DOT__reg_pending_q = 0U;
        }
        if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_valid) 
             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_ready))) {
            if (VL_UNLIKELY(((0U != (7U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_axi_slave_frontend.sv:270: Assertion failed in %Ntb_npu_axi_slave_frontend: L1 model received an unaligned address\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("tb/tb_npu_axi_slave_frontend.sv", 270, "", false);
            }
            __Vdly__tb_npu_axi_slave_frontend__DOT__l1_pending_q = 1U;
            if ((0x100U > (0x1ffffU & (vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
                                       >> 3U)))) {
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_status_q = 0U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_data_q 
                    = vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem
                    [(0xffU & (vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
                               >> 3U))];
                if ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q))) {
                    vlSelfRef.tb_npu_axi_slave_frontend__DOT__byte_index = 8U;
                    if ((1U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                        __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v0 
                            = (0xffU & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q));
                        __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v0 
                            = (0xffU & (vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
                                        >> 3U));
                        __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v0 = 1U;
                    }
                    if ((2U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                        __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v1 
                            = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                                >> 8U)));
                        __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v1 
                            = (0xffU & (vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
                                        >> 3U));
                        __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v1 = 1U;
                    }
                    if ((4U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                        __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v2 
                            = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                                >> 0x10U)));
                        __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v2 
                            = (0xffU & (vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
                                        >> 3U));
                        __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v2 = 1U;
                    }
                    if ((8U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                        __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v3 
                            = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                                >> 0x18U)));
                        __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v3 
                            = (0xffU & (vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
                                        >> 3U));
                        __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v3 = 1U;
                    }
                    if ((0x10U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                        __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v4 
                            = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                                >> 0x20U)));
                        __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v4 
                            = (0xffU & (vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
                                        >> 3U));
                        __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v4 = 1U;
                    }
                    if ((0x20U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                        __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v5 
                            = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                                >> 0x28U)));
                        __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v5 
                            = (0xffU & (vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
                                        >> 3U));
                        __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v5 = 1U;
                    }
                    if ((0x40U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                        __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v6 
                            = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                                >> 0x30U)));
                        __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v6 
                            = (0xffU & (vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
                                        >> 3U));
                        __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v6 = 1U;
                    }
                    if ((0x80U & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q))) {
                        __VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v7 
                            = (0xffU & (IData)((vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
                                                >> 0x38U)));
                        __VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v7 
                            = (0xffU & (vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
                                        >> 3U));
                        __VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v7 = 1U;
                    }
                }
            } else {
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_status_q = 4U;
                vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_data_q = 0ULL;
            }
        }
        if (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_pending_q) 
             & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_ready))) {
            __Vdly__tb_npu_axi_slave_frontend__DOT__l1_pending_q = 0U;
        }
    } else {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_command_count_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__reg_pending_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__l1_pending_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_have_low_q = 0U;
        __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_low_q = 0ULL;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_data = 0ULL;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_data_q = 0ULL;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_data_q = 0ULL;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_status_q = 0U;
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_status_q = 0U;
    }
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_low_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_low_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_have_low_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__cfe_have_low_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_pending_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__reg_pending_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_pending_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__l1_pending_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_data 
        = ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q))
            ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem
           [([&]() {
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__base 
                    = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_rptr_q;
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__value 
                    = ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__base));
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__Vfuncout 
                    = (0xfU & vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__value);
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__Vfuncout))]
            : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem
           [vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_rptr_q]);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_valid 
        = ((2U <= (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q)) 
           & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q)) 
              | (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q))));
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v0) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v0] 
            = ((0xffffffffffffff00ULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v0]) 
               | (IData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v0)));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v1) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v1] 
            = ((0xffffffffffff00ffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v1]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v1)) 
                  << 8U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v2) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v2] 
            = ((0xffffffffff00ffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v2]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v2)) 
                  << 0x10U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v3) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v3] 
            = ((0xffffffff00ffffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v3]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v3)) 
                  << 0x18U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v4) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v4] 
            = ((0xffffff00ffffffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v4]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v4)) 
                  << 0x20U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v5) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v5] 
            = ((0xffff00ffffffffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v5]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v5)) 
                  << 0x28U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v6) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v6] 
            = ((0xff00ffffffffffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v6]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v6)) 
                  << 0x30U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__csr_mem__v7) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v7] 
            = ((0xffffffffffffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__csr_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__csr_mem__v7]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__csr_mem__v7)) 
                  << 0x38U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v0) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v0] 
            = ((0xffffffffffffff00ULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v0]) 
               | (IData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v0)));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v1) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v1] 
            = ((0xffffffffffff00ffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v1]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v1)) 
                  << 8U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v2) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v2] 
            = ((0xffffffffff00ffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v2]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v2)) 
                  << 0x10U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v3) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v3] 
            = ((0xffffffff00ffffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v3]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v3)) 
                  << 0x18U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v4) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v4] 
            = ((0xffffff00ffffffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v4]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v4)) 
                  << 0x20U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v5) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v5] 
            = ((0xffff00ffffffffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v5]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v5)) 
                  << 0x28U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v6) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v6] 
            = ((0xff00ffffffffffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v6]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v6)) 
                  << 0x30U));
    }
    if (__VdlySet__tb_npu_axi_slave_frontend__DOT__l1_mem__v7) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem[__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v7] 
            = ((0xffffffffffffffULL & vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_mem
                [__VdlyDim0__tb_npu_axi_slave_frontend__DOT__l1_mem__v7]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_axi_slave_frontend__DOT__l1_mem__v7)) 
                  << 0x38U));
    }
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q 
        = __Vdly__tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_ready 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_pending_q)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_ready 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_pending_q)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_first 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_valid) 
           & (0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_last 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_valid) 
           & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q)));
    if ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q))) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr 
            = (0xfff8U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_addr_q);
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
            = (0xffff8U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_addr_q);
    } else {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr 
            = (0xfff8U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q);
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
            = (0xffff8U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q);
    }
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_ready 
        = (((4U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
            & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q))) 
           | ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_ready 
        = (((4U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
            & (2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q))) 
           | ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & (2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__fifo_status_w 
        = (QData)((IData)(((((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error) 
                             << 0x13U) | ((8U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q)) 
                                          << 0x12U)) 
                           | (((0x10U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q)) 
                               << 0x11U) | ((((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
                                              & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q)) 
                                             << 0x10U) 
                                            | (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q) 
                                                << 8U) 
                                               | (0xffU 
                                                  & ((IData)(0x10U) 
                                                     - (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q)))))))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_valid 
        = (((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
            & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_sent_q)) 
               & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)))) 
           | ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_req_sent_q)) 
                 & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q)))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_valid 
        = (((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
            & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_sent_q)) 
               & (2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)))) 
           | ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_req_sent_q)) 
                 & (2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q)))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready 
        = ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
           | ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
              | (5U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q))));
}
