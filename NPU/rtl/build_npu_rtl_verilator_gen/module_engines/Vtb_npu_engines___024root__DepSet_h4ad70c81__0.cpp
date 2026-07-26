// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_engines.h for the primary calling header

#include "Vtb_npu_engines__pch.h"
#include "Vtb_npu_engines__Syms.h"
#include "Vtb_npu_engines___024root.h"

extern const VlWide<64>/*2047:0*/ Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0;

VL_INLINE_OPT VlCoroutine Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__0(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ tb_npu_engines__DOT__read_word;
    tb_npu_engines__DOT__read_word = 0;
    IData/*31:0*/ tb_npu_engines__DOT__handshakes_before_bad_numeric;
    tb_npu_engines__DOT__handshakes_before_bad_numeric = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__0__condition;
    __Vtask_tb_npu_engines__DOT__check__0__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__0__message;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__init_common__1__engine;
    __Vtask_tb_npu_engines__DOT__init_common__1__engine = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__init_common__1__bytes;
    __Vtask_tb_npu_engines__DOT__init_common__1__bytes = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__1__src0;
    __Vtask_tb_npu_engines__DOT__init_common__1__src0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__1__src1;
    __Vtask_tb_npu_engines__DOT__init_common__1__src1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__1__src2;
    __Vtask_tb_npu_engines__DOT__init_common__1__src2 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__1__dst;
    __Vtask_tb_npu_engines__DOT__init_common__1__dst = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__init_common__1__numeric;
    __Vtask_tb_npu_engines__DOT__init_common__1__numeric = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__2__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__2__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__2__value;
    __Vtask_tb_npu_engines__DOT__put_u8__2__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__3__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__3__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__3__value;
    __Vtask_tb_npu_engines__DOT__put_u8__3__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u16__4__offset;
    __Vtask_tb_npu_engines__DOT__put_u16__4__offset = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u16__4__value;
    __Vtask_tb_npu_engines__DOT__put_u16__4__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__5__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__5__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__5__value;
    __Vtask_tb_npu_engines__DOT__put_u64__5__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__6__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__6__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__6__value;
    __Vtask_tb_npu_engines__DOT__put_u64__6__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__7__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__7__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__7__value;
    __Vtask_tb_npu_engines__DOT__put_u64__7__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__8__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__8__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__8__value;
    __Vtask_tb_npu_engines__DOT__put_u64__8__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__9__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__9__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__9__value;
    __Vtask_tb_npu_engines__DOT__put_u32__9__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__10__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__10__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__10__value;
    __Vtask_tb_npu_engines__DOT__put_u8__10__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__11__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__11__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__11__value;
    __Vtask_tb_npu_engines__DOT__put_u8__11__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__12__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__12__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__12__value;
    __Vtask_tb_npu_engines__DOT__put_u8__12__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__13__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__13__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__13__value;
    __Vtask_tb_npu_engines__DOT__put_u8__13__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__14__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__14__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__14__value;
    __Vtask_tb_npu_engines__DOT__put_u8__14__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__15__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__15__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__15__value;
    __Vtask_tb_npu_engines__DOT__put_u8__15__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__16__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__16__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__16__value;
    __Vtask_tb_npu_engines__DOT__put_u32__16__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__17__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__17__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__17__value;
    __Vtask_tb_npu_engines__DOT__put_u64__17__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__18__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__18__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__18__value;
    __Vtask_tb_npu_engines__DOT__put_u64__18__value = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__20__condition;
    __Vtask_tb_npu_engines__DOT__check__20__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__20__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__21__condition;
    __Vtask_tb_npu_engines__DOT__check__21__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__21__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__22__condition;
    __Vtask_tb_npu_engines__DOT__check__22__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__22__message;
    IData/*19:0*/ __Vtask_tb_npu_engines__DOT__l1_read_word__23__addr;
    __Vtask_tb_npu_engines__DOT__l1_read_word__23__addr = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__l1_read_word__23__data;
    __Vtask_tb_npu_engines__DOT__l1_read_word__23__data = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__24__condition;
    __Vtask_tb_npu_engines__DOT__check__24__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__24__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__25__condition;
    __Vtask_tb_npu_engines__DOT__check__25__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__25__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__26__condition;
    __Vtask_tb_npu_engines__DOT__check__26__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__26__message;
    IData/*19:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__27__addr;
    __Vtask_tb_npu_engines__DOT__l1_write_word__27__addr = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__27__data;
    __Vtask_tb_npu_engines__DOT__l1_write_word__27__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__27__strb;
    __Vtask_tb_npu_engines__DOT__l1_write_word__27__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__28__condition;
    __Vtask_tb_npu_engines__DOT__check__28__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__28__message;
    IData/*19:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__29__addr;
    __Vtask_tb_npu_engines__DOT__l1_write_word__29__addr = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__29__data;
    __Vtask_tb_npu_engines__DOT__l1_write_word__29__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__29__strb;
    __Vtask_tb_npu_engines__DOT__l1_write_word__29__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__30__condition;
    __Vtask_tb_npu_engines__DOT__check__30__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__30__message;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__init_common__31__engine;
    __Vtask_tb_npu_engines__DOT__init_common__31__engine = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__init_common__31__bytes;
    __Vtask_tb_npu_engines__DOT__init_common__31__bytes = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__31__src0;
    __Vtask_tb_npu_engines__DOT__init_common__31__src0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__31__src1;
    __Vtask_tb_npu_engines__DOT__init_common__31__src1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__31__src2;
    __Vtask_tb_npu_engines__DOT__init_common__31__src2 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__31__dst;
    __Vtask_tb_npu_engines__DOT__init_common__31__dst = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__init_common__31__numeric;
    __Vtask_tb_npu_engines__DOT__init_common__31__numeric = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__32__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__32__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__32__value;
    __Vtask_tb_npu_engines__DOT__put_u8__32__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__33__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__33__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__33__value;
    __Vtask_tb_npu_engines__DOT__put_u8__33__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u16__34__offset;
    __Vtask_tb_npu_engines__DOT__put_u16__34__offset = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u16__34__value;
    __Vtask_tb_npu_engines__DOT__put_u16__34__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__35__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__35__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__35__value;
    __Vtask_tb_npu_engines__DOT__put_u64__35__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__36__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__36__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__36__value;
    __Vtask_tb_npu_engines__DOT__put_u64__36__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__37__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__37__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__37__value;
    __Vtask_tb_npu_engines__DOT__put_u64__37__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__38__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__38__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__38__value;
    __Vtask_tb_npu_engines__DOT__put_u64__38__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__39__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__39__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__39__value;
    __Vtask_tb_npu_engines__DOT__put_u32__39__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__40__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__40__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__40__value;
    __Vtask_tb_npu_engines__DOT__put_u32__40__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__41__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__41__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__41__value;
    __Vtask_tb_npu_engines__DOT__put_u32__41__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__42__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__42__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__42__value;
    __Vtask_tb_npu_engines__DOT__put_u32__42__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__43__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__43__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__43__value;
    __Vtask_tb_npu_engines__DOT__put_u32__43__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__44__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__44__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__44__value;
    __Vtask_tb_npu_engines__DOT__put_u32__44__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__45__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__45__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__45__value;
    __Vtask_tb_npu_engines__DOT__put_u32__45__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__46__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__46__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__46__value;
    __Vtask_tb_npu_engines__DOT__put_u32__46__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__47__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__47__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__47__value;
    __Vtask_tb_npu_engines__DOT__put_u32__47__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__48__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__48__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__48__value;
    __Vtask_tb_npu_engines__DOT__put_u32__48__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__49__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__49__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__49__value;
    __Vtask_tb_npu_engines__DOT__put_u32__49__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__50__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__50__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__50__value;
    __Vtask_tb_npu_engines__DOT__put_u32__50__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__51__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__51__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__51__value;
    __Vtask_tb_npu_engines__DOT__put_u8__51__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__52__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__52__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__52__value;
    __Vtask_tb_npu_engines__DOT__put_u8__52__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__53__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__53__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__53__value;
    __Vtask_tb_npu_engines__DOT__put_u8__53__value = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__55__condition;
    __Vtask_tb_npu_engines__DOT__check__55__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__55__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__56__condition;
    __Vtask_tb_npu_engines__DOT__check__56__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__56__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__57__condition;
    __Vtask_tb_npu_engines__DOT__check__57__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__57__message;
    IData/*19:0*/ __Vtask_tb_npu_engines__DOT__l1_read_word__58__addr;
    __Vtask_tb_npu_engines__DOT__l1_read_word__58__addr = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__l1_read_word__58__data;
    __Vtask_tb_npu_engines__DOT__l1_read_word__58__data = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__59__condition;
    __Vtask_tb_npu_engines__DOT__check__59__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__59__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__60__condition;
    __Vtask_tb_npu_engines__DOT__check__60__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__60__message;
    IData/*19:0*/ __Vtask_tb_npu_engines__DOT__l1_read_word__61__addr;
    __Vtask_tb_npu_engines__DOT__l1_read_word__61__addr = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__l1_read_word__61__data;
    __Vtask_tb_npu_engines__DOT__l1_read_word__61__data = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__62__condition;
    __Vtask_tb_npu_engines__DOT__check__62__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__62__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__63__condition;
    __Vtask_tb_npu_engines__DOT__check__63__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__63__message;
    IData/*19:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__64__addr;
    __Vtask_tb_npu_engines__DOT__l1_write_word__64__addr = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__64__data;
    __Vtask_tb_npu_engines__DOT__l1_write_word__64__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__64__strb;
    __Vtask_tb_npu_engines__DOT__l1_write_word__64__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__65__condition;
    __Vtask_tb_npu_engines__DOT__check__65__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__65__message;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__init_common__66__engine;
    __Vtask_tb_npu_engines__DOT__init_common__66__engine = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__init_common__66__bytes;
    __Vtask_tb_npu_engines__DOT__init_common__66__bytes = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__66__src0;
    __Vtask_tb_npu_engines__DOT__init_common__66__src0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__66__src1;
    __Vtask_tb_npu_engines__DOT__init_common__66__src1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__66__src2;
    __Vtask_tb_npu_engines__DOT__init_common__66__src2 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__66__dst;
    __Vtask_tb_npu_engines__DOT__init_common__66__dst = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__init_common__66__numeric;
    __Vtask_tb_npu_engines__DOT__init_common__66__numeric = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__67__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__67__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__67__value;
    __Vtask_tb_npu_engines__DOT__put_u8__67__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__68__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__68__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__68__value;
    __Vtask_tb_npu_engines__DOT__put_u8__68__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u16__69__offset;
    __Vtask_tb_npu_engines__DOT__put_u16__69__offset = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u16__69__value;
    __Vtask_tb_npu_engines__DOT__put_u16__69__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__70__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__70__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__70__value;
    __Vtask_tb_npu_engines__DOT__put_u64__70__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__71__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__71__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__71__value;
    __Vtask_tb_npu_engines__DOT__put_u64__71__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__72__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__72__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__72__value;
    __Vtask_tb_npu_engines__DOT__put_u64__72__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__73__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__73__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__73__value;
    __Vtask_tb_npu_engines__DOT__put_u64__73__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__74__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__74__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__74__value;
    __Vtask_tb_npu_engines__DOT__put_u32__74__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__75__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__75__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__75__value;
    __Vtask_tb_npu_engines__DOT__put_u32__75__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__76__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__76__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__76__value;
    __Vtask_tb_npu_engines__DOT__put_u32__76__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__77__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__77__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__77__value;
    __Vtask_tb_npu_engines__DOT__put_u32__77__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__78__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__78__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__78__value;
    __Vtask_tb_npu_engines__DOT__put_u32__78__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__79__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__79__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__79__value;
    __Vtask_tb_npu_engines__DOT__put_u32__79__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__80__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__80__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__80__value;
    __Vtask_tb_npu_engines__DOT__put_u32__80__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__81__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__81__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__81__value;
    __Vtask_tb_npu_engines__DOT__put_u32__81__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__82__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__82__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__82__value;
    __Vtask_tb_npu_engines__DOT__put_u32__82__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__83__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__83__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__83__value;
    __Vtask_tb_npu_engines__DOT__put_u32__83__value = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__85__condition;
    __Vtask_tb_npu_engines__DOT__check__85__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__85__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__86__condition;
    __Vtask_tb_npu_engines__DOT__check__86__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__86__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__87__condition;
    __Vtask_tb_npu_engines__DOT__check__87__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__87__message;
    IData/*19:0*/ __Vtask_tb_npu_engines__DOT__l1_read_word__88__addr;
    __Vtask_tb_npu_engines__DOT__l1_read_word__88__addr = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__l1_read_word__88__data;
    __Vtask_tb_npu_engines__DOT__l1_read_word__88__data = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__89__condition;
    __Vtask_tb_npu_engines__DOT__check__89__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__89__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__90__condition;
    __Vtask_tb_npu_engines__DOT__check__90__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__90__message;
    IData/*19:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__91__addr;
    __Vtask_tb_npu_engines__DOT__l1_write_word__91__addr = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__91__data;
    __Vtask_tb_npu_engines__DOT__l1_write_word__91__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__l1_write_word__91__strb;
    __Vtask_tb_npu_engines__DOT__l1_write_word__91__strb = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__92__condition;
    __Vtask_tb_npu_engines__DOT__check__92__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__92__message;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__init_common__93__engine;
    __Vtask_tb_npu_engines__DOT__init_common__93__engine = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__init_common__93__bytes;
    __Vtask_tb_npu_engines__DOT__init_common__93__bytes = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__93__src0;
    __Vtask_tb_npu_engines__DOT__init_common__93__src0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__93__src1;
    __Vtask_tb_npu_engines__DOT__init_common__93__src1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__93__src2;
    __Vtask_tb_npu_engines__DOT__init_common__93__src2 = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__init_common__93__dst;
    __Vtask_tb_npu_engines__DOT__init_common__93__dst = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__init_common__93__numeric;
    __Vtask_tb_npu_engines__DOT__init_common__93__numeric = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__94__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__94__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__94__value;
    __Vtask_tb_npu_engines__DOT__put_u8__94__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u8__95__offset;
    __Vtask_tb_npu_engines__DOT__put_u8__95__offset = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__put_u8__95__value;
    __Vtask_tb_npu_engines__DOT__put_u8__95__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u16__96__offset;
    __Vtask_tb_npu_engines__DOT__put_u16__96__offset = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u16__96__value;
    __Vtask_tb_npu_engines__DOT__put_u16__96__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__97__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__97__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__97__value;
    __Vtask_tb_npu_engines__DOT__put_u64__97__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__98__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__98__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__98__value;
    __Vtask_tb_npu_engines__DOT__put_u64__98__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__99__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__99__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__99__value;
    __Vtask_tb_npu_engines__DOT__put_u64__99__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u64__100__offset;
    __Vtask_tb_npu_engines__DOT__put_u64__100__offset = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__put_u64__100__value;
    __Vtask_tb_npu_engines__DOT__put_u64__100__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__101__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__101__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__101__value;
    __Vtask_tb_npu_engines__DOT__put_u32__101__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__102__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__102__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__102__value;
    __Vtask_tb_npu_engines__DOT__put_u32__102__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__103__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__103__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__103__value;
    __Vtask_tb_npu_engines__DOT__put_u32__103__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__104__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__104__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__104__value;
    __Vtask_tb_npu_engines__DOT__put_u32__104__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__105__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__105__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__105__value;
    __Vtask_tb_npu_engines__DOT__put_u32__105__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__106__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__106__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__106__value;
    __Vtask_tb_npu_engines__DOT__put_u32__106__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__107__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__107__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__107__value;
    __Vtask_tb_npu_engines__DOT__put_u32__107__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__108__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__108__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__108__value;
    __Vtask_tb_npu_engines__DOT__put_u32__108__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__109__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__109__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__109__value;
    __Vtask_tb_npu_engines__DOT__put_u32__109__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__110__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__110__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__110__value;
    __Vtask_tb_npu_engines__DOT__put_u32__110__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__111__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__111__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__111__value;
    __Vtask_tb_npu_engines__DOT__put_u32__111__value = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__113__condition;
    __Vtask_tb_npu_engines__DOT__check__113__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__113__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__114__condition;
    __Vtask_tb_npu_engines__DOT__check__114__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__114__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__115__condition;
    __Vtask_tb_npu_engines__DOT__check__115__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__115__message;
    IData/*19:0*/ __Vtask_tb_npu_engines__DOT__l1_read_word__116__addr;
    __Vtask_tb_npu_engines__DOT__l1_read_word__116__addr = 0;
    QData/*63:0*/ __Vtask_tb_npu_engines__DOT__l1_read_word__116__data;
    __Vtask_tb_npu_engines__DOT__l1_read_word__116__data = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__117__condition;
    __Vtask_tb_npu_engines__DOT__check__117__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__117__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__118__condition;
    __Vtask_tb_npu_engines__DOT__check__118__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__118__message;
    SData/*15:0*/ __Vtask_tb_npu_engines__DOT__put_u32__119__offset;
    __Vtask_tb_npu_engines__DOT__put_u32__119__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_engines__DOT__put_u32__119__value;
    __Vtask_tb_npu_engines__DOT__put_u32__119__value = 0;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__121__condition;
    __Vtask_tb_npu_engines__DOT__check__121__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__121__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__122__condition;
    __Vtask_tb_npu_engines__DOT__check__122__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__122__message;
    CData/*0:0*/ __Vtask_tb_npu_engines__DOT__check__123__condition;
    __Vtask_tb_npu_engines__DOT__check__123__condition = 0;
    std::string __Vtask_tb_npu_engines__DOT__check__123__message;
    // Body
    vlSelfRef.tb_npu_engines__DOT__clk_i = 0U;
    vlSelfRef.tb_npu_engines__DOT__reset_n = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_addr = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata = 0ULL;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 0U;
    vlSelfRef.tb_npu_engines__DOT__dma_task_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__dma_opcode = 0x20U;
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb_npu_engines__DOT__dma_desc[__Vilp1] 
            = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    vlSelfRef.tb_npu_engines__DOT__matrix_task_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__matrix_opcode = 0x40U;
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x3fU)) {
        vlSelfRef.tb_npu_engines__DOT__matrix_desc[__Vilp2] 
            = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    vlSelfRef.tb_npu_engines__DOT__vector_task_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__vector_opcode = 0x60U;
    IData/*31:0*/ __Vilp3;
    __Vilp3 = 0U;
    while ((__Vilp3 <= 0x3fU)) {
        vlSelfRef.tb_npu_engines__DOT__vector_desc[__Vilp3] 
            = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp3];
        __Vilp3 = ((IData)(1U) + __Vilp3);
    }
    vlSelfRef.tb_npu_engines__DOT__complex_task_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__complex_opcode = 0x80U;
    IData/*31:0*/ __Vilp4;
    __Vilp4 = 0U;
    while ((__Vilp4 <= 0x3fU)) {
        vlSelfRef.tb_npu_engines__DOT__complex_desc[__Vilp4] 
            = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp4];
        __Vilp4 = ((IData)(1U) + __Vilp4);
    }
    vlSelfRef.tb_npu_engines__DOT__byte_index = 0U;
    while (VL_GTS_III(32, 0x2000U, vlSelfRef.tb_npu_engines__DOT__byte_index)) {
        vlSelfRef.tb_npu_engines__DOT__system_mem[(0x1fffU 
                                                   & vlSelfRef.tb_npu_engines__DOT__byte_index)] = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__byte_index = 
            ((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__byte_index);
    }
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         544);
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         544);
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         544);
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         544);
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         544);
    vlSelfRef.tb_npu_engines__DOT__reset_n = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         546);
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         546);
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         546);
    __Vtask_tb_npu_engines__DOT__check__0__message = 
        std::string{"L1 did not become idle after reset"};
    __Vtask_tb_npu_engines__DOT__check__0__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__0__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__0__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    vlSelfRef.tb_npu_engines__DOT__system_mem[0x1000U] = 0xa07030100fffcf8ULL;
    __Vtask_tb_npu_engines__DOT__init_common__1__numeric = 0x55U;
    __Vtask_tb_npu_engines__DOT__init_common__1__dst = 0x300ULL;
    __Vtask_tb_npu_engines__DOT__init_common__1__src2 = 0ULL;
    __Vtask_tb_npu_engines__DOT__init_common__1__src1 = 0ULL;
    __Vtask_tb_npu_engines__DOT__init_common__1__src0 = 0x8000ULL;
    __Vtask_tb_npu_engines__DOT__init_common__1__bytes = 0x100U;
    __Vtask_tb_npu_engines__DOT__init_common__1__engine = 1U;
    IData/*31:0*/ __Vilp5;
    __Vilp5 = 0U;
    while ((__Vilp5 <= 0x3fU)) {
        vlSelfRef.tb_npu_engines__DOT__dma_desc[__Vilp5] 
            = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp5];
        __Vilp5 = ((IData)(1U) + __Vilp5);
    }
    __Vtask_tb_npu_engines__DOT__put_u8__2__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u8__2__offset = 0U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__2__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u8__2__value);
    __Vtask_tb_npu_engines__DOT__put_u8__3__value = __Vtask_tb_npu_engines__DOT__init_common__1__engine;
    __Vtask_tb_npu_engines__DOT__put_u8__3__offset = 1U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__3__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u8__3__value);
    __Vtask_tb_npu_engines__DOT__put_u16__4__value 
        = __Vtask_tb_npu_engines__DOT__init_common__1__bytes;
    __Vtask_tb_npu_engines__DOT__put_u16__4__offset = 2U;
    VL_ASSIGNSEL_WI(2048, 16, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u16__4__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u16__4__value);
    __Vtask_tb_npu_engines__DOT__put_u64__5__value 
        = __Vtask_tb_npu_engines__DOT__init_common__1__src0;
    __Vtask_tb_npu_engines__DOT__put_u64__5__offset = 8U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__5__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u64__5__value);
    __Vtask_tb_npu_engines__DOT__put_u64__6__value 
        = __Vtask_tb_npu_engines__DOT__init_common__1__src1;
    __Vtask_tb_npu_engines__DOT__put_u64__6__offset = 0x10U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__6__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u64__6__value);
    __Vtask_tb_npu_engines__DOT__put_u64__7__value 
        = __Vtask_tb_npu_engines__DOT__init_common__1__src2;
    __Vtask_tb_npu_engines__DOT__put_u64__7__offset = 0x18U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__7__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u64__7__value);
    __Vtask_tb_npu_engines__DOT__put_u64__8__value 
        = __Vtask_tb_npu_engines__DOT__init_common__1__dst;
    __Vtask_tb_npu_engines__DOT__put_u64__8__offset = 0x20U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__8__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u64__8__value);
    __Vtask_tb_npu_engines__DOT__put_u32__9__value 
        = __Vtask_tb_npu_engines__DOT__init_common__1__numeric;
    __Vtask_tb_npu_engines__DOT__put_u32__9__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__9__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u32__9__value);
    __Vtask_tb_npu_engines__DOT__put_u8__10__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u8__10__offset = 0x40U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__10__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u8__10__value);
    __Vtask_tb_npu_engines__DOT__put_u8__11__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u8__11__offset = 0x41U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__11__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u8__11__value);
    __Vtask_tb_npu_engines__DOT__put_u8__12__value = 0U;
    __Vtask_tb_npu_engines__DOT__put_u8__12__offset = 0x42U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__12__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u8__12__value);
    __Vtask_tb_npu_engines__DOT__put_u8__13__value = 0U;
    __Vtask_tb_npu_engines__DOT__put_u8__13__offset = 0x43U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__13__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u8__13__value);
    __Vtask_tb_npu_engines__DOT__put_u8__14__value = 0xfU;
    __Vtask_tb_npu_engines__DOT__put_u8__14__offset = 0x44U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__14__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u8__14__value);
    __Vtask_tb_npu_engines__DOT__put_u8__15__value = 8U;
    __Vtask_tb_npu_engines__DOT__put_u8__15__offset = 0x45U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__15__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u8__15__value);
    __Vtask_tb_npu_engines__DOT__put_u32__16__value = 8U;
    __Vtask_tb_npu_engines__DOT__put_u32__16__offset = 0x48U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__16__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u32__16__value);
    __Vtask_tb_npu_engines__DOT__put_u64__17__value = 8ULL;
    __Vtask_tb_npu_engines__DOT__put_u64__17__offset = 0x98U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__17__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u64__17__value);
    __Vtask_tb_npu_engines__DOT__put_u64__18__value = 8ULL;
    __Vtask_tb_npu_engines__DOT__put_u64__18__offset = 0xa0U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__18__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__dma_desc, __Vtask_tb_npu_engines__DOT__put_u64__18__value);
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         470);
    while ((0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             470);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         471);
    vlSelfRef.tb_npu_engines__DOT__dma_task_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         473);
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         474);
    vlSelfRef.tb_npu_engines__DOT__dma_task_valid = 0U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         565);
    while ((0xaU != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             565);
    }
    __Vtask_tb_npu_engines__DOT__check__20__message = 
        std::string{"DMA returned a failure status"};
    __Vtask_tb_npu_engines__DOT__check__20__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__20__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__20__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__check__21__message = 
        std::string{"DMA reported an unexpected fault"};
    __Vtask_tb_npu_engines__DOT__check__21__condition 
        = (0ULL == vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__21__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__21__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__check__22__message = 
        std::string{"DMA progress byte count mismatch"};
    __Vtask_tb_npu_engines__DOT__check__22__condition 
        = (8ULL == vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__progress_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__22__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__22__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__l1_read_word__23__addr = 0x300U;
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         450);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_addr = __Vtask_tb_npu_engines__DOT__l1_read_word__23__addr;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata = 0ULL;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         456);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             456);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         457);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         460);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             460);
    }
    __Vtask_tb_npu_engines__DOT__l1_read_word__23__data 
        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
        [0U];
    __Vtask_tb_npu_engines__DOT__check__24__message = 
        std::string{"L1 BFM read failed"};
    __Vtask_tb_npu_engines__DOT__check__24__condition 
        = (0U == vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
           [0U]);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__24__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__24__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         463);
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 0U;
    tb_npu_engines__DOT__read_word = __Vtask_tb_npu_engines__DOT__l1_read_word__23__data;
    __Vtask_tb_npu_engines__DOT__check__25__message = 
        std::string{"DMA_COPY_1D numeric result mismatch"};
    __Vtask_tb_npu_engines__DOT__check__25__condition 
        = (0xa07030100fffcf8ULL == tb_npu_engines__DOT__read_word);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__25__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__25__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__check__26__message = 
        std::string{"DMA did not issue one acknowledged read per element"};
    __Vtask_tb_npu_engines__DOT__check__26__condition 
        = (8U == vlSelfRef.tb_npu_engines__DOT__mif_handshakes_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__26__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__26__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__l1_write_word__27__strb = 0x3fU;
    __Vtask_tb_npu_engines__DOT__l1_write_word__27__data = 0x204ff030201ULL;
    __Vtask_tb_npu_engines__DOT__l1_write_word__27__addr = 0x100U;
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         428);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_addr = __Vtask_tb_npu_engines__DOT__l1_write_word__27__addr;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata = __Vtask_tb_npu_engines__DOT__l1_write_word__27__data;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb = __Vtask_tb_npu_engines__DOT__l1_write_word__27__strb;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_write = 1U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         434);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             434);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         435);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         438);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             438);
    }
    __Vtask_tb_npu_engines__DOT__check__28__message = 
        std::string{"L1 BFM write failed"};
    __Vtask_tb_npu_engines__DOT__check__28__condition 
        = (0U == vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
           [0U]);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__28__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__28__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         440);
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 0U;
    __Vtask_tb_npu_engines__DOT__l1_write_word__29__strb = 0x3fU;
    __Vtask_tb_npu_engines__DOT__l1_write_word__29__data = 0x4fe0103ff02ULL;
    __Vtask_tb_npu_engines__DOT__l1_write_word__29__addr = 0x200U;
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         428);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_addr = __Vtask_tb_npu_engines__DOT__l1_write_word__29__addr;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata = __Vtask_tb_npu_engines__DOT__l1_write_word__29__data;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb = __Vtask_tb_npu_engines__DOT__l1_write_word__29__strb;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_write = 1U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         434);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             434);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         435);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         438);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             438);
    }
    __Vtask_tb_npu_engines__DOT__check__30__message = 
        std::string{"L1 BFM write failed"};
    __Vtask_tb_npu_engines__DOT__check__30__condition 
        = (0U == vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
           [0U]);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__30__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__30__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         440);
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 0U;
    __Vtask_tb_npu_engines__DOT__init_common__31__numeric = 0xa5U;
    __Vtask_tb_npu_engines__DOT__init_common__31__dst = 0x600ULL;
    __Vtask_tb_npu_engines__DOT__init_common__31__src2 = 0ULL;
    __Vtask_tb_npu_engines__DOT__init_common__31__src1 = 0x200ULL;
    __Vtask_tb_npu_engines__DOT__init_common__31__src0 = 0x100ULL;
    __Vtask_tb_npu_engines__DOT__init_common__31__bytes = 0x100U;
    __Vtask_tb_npu_engines__DOT__init_common__31__engine = 2U;
    IData/*31:0*/ __Vilp6;
    __Vilp6 = 0U;
    while ((__Vilp6 <= 0x3fU)) {
        vlSelfRef.tb_npu_engines__DOT__matrix_desc[__Vilp6] 
            = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp6];
        __Vilp6 = ((IData)(1U) + __Vilp6);
    }
    __Vtask_tb_npu_engines__DOT__put_u8__32__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u8__32__offset = 0U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__32__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u8__32__value);
    __Vtask_tb_npu_engines__DOT__put_u8__33__value 
        = __Vtask_tb_npu_engines__DOT__init_common__31__engine;
    __Vtask_tb_npu_engines__DOT__put_u8__33__offset = 1U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__33__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u8__33__value);
    __Vtask_tb_npu_engines__DOT__put_u16__34__value 
        = __Vtask_tb_npu_engines__DOT__init_common__31__bytes;
    __Vtask_tb_npu_engines__DOT__put_u16__34__offset = 2U;
    VL_ASSIGNSEL_WI(2048, 16, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u16__34__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u16__34__value);
    __Vtask_tb_npu_engines__DOT__put_u64__35__value 
        = __Vtask_tb_npu_engines__DOT__init_common__31__src0;
    __Vtask_tb_npu_engines__DOT__put_u64__35__offset = 8U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__35__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u64__35__value);
    __Vtask_tb_npu_engines__DOT__put_u64__36__value 
        = __Vtask_tb_npu_engines__DOT__init_common__31__src1;
    __Vtask_tb_npu_engines__DOT__put_u64__36__offset = 0x10U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__36__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u64__36__value);
    __Vtask_tb_npu_engines__DOT__put_u64__37__value 
        = __Vtask_tb_npu_engines__DOT__init_common__31__src2;
    __Vtask_tb_npu_engines__DOT__put_u64__37__offset = 0x18U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__37__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u64__37__value);
    __Vtask_tb_npu_engines__DOT__put_u64__38__value 
        = __Vtask_tb_npu_engines__DOT__init_common__31__dst;
    __Vtask_tb_npu_engines__DOT__put_u64__38__offset = 0x20U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__38__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u64__38__value);
    __Vtask_tb_npu_engines__DOT__put_u32__39__value 
        = __Vtask_tb_npu_engines__DOT__init_common__31__numeric;
    __Vtask_tb_npu_engines__DOT__put_u32__39__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__39__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__39__value);
    __Vtask_tb_npu_engines__DOT__put_u32__40__value = 2U;
    __Vtask_tb_npu_engines__DOT__put_u32__40__offset = 0x40U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__40__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__40__value);
    __Vtask_tb_npu_engines__DOT__put_u32__41__value = 2U;
    __Vtask_tb_npu_engines__DOT__put_u32__41__offset = 0x44U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__41__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__41__value);
    __Vtask_tb_npu_engines__DOT__put_u32__42__value = 3U;
    __Vtask_tb_npu_engines__DOT__put_u32__42__offset = 0x48U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__42__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__42__value);
    __Vtask_tb_npu_engines__DOT__put_u32__43__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u32__43__offset = 0x4cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__43__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__43__value);
    __Vtask_tb_npu_engines__DOT__put_u32__44__value = 2U;
    __Vtask_tb_npu_engines__DOT__put_u32__44__offset = 0x50U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__44__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__44__value);
    __Vtask_tb_npu_engines__DOT__put_u32__45__value = 2U;
    __Vtask_tb_npu_engines__DOT__put_u32__45__offset = 0x54U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__45__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__45__value);
    __Vtask_tb_npu_engines__DOT__put_u32__46__value = 3U;
    __Vtask_tb_npu_engines__DOT__put_u32__46__offset = 0x58U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__46__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__46__value);
    __Vtask_tb_npu_engines__DOT__put_u32__47__value = 0x80U;
    __Vtask_tb_npu_engines__DOT__put_u32__47__offset = 0x5cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__47__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__47__value);
    __Vtask_tb_npu_engines__DOT__put_u32__48__value = 3U;
    __Vtask_tb_npu_engines__DOT__put_u32__48__offset = 0x60U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__48__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__48__value);
    __Vtask_tb_npu_engines__DOT__put_u32__49__value = 2U;
    __Vtask_tb_npu_engines__DOT__put_u32__49__offset = 0x64U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__49__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__49__value);
    __Vtask_tb_npu_engines__DOT__put_u32__50__value = 8U;
    __Vtask_tb_npu_engines__DOT__put_u32__50__offset = 0x68U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__50__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u32__50__value);
    __Vtask_tb_npu_engines__DOT__put_u8__51__value = 0U;
    __Vtask_tb_npu_engines__DOT__put_u8__51__offset = 0x90U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__51__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u8__51__value);
    __Vtask_tb_npu_engines__DOT__put_u8__52__value = 0U;
    __Vtask_tb_npu_engines__DOT__put_u8__52__offset = 0x91U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__52__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u8__52__value);
    __Vtask_tb_npu_engines__DOT__put_u8__53__value = 4U;
    __Vtask_tb_npu_engines__DOT__put_u8__53__offset = 0x92U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__53__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__matrix_desc, __Vtask_tb_npu_engines__DOT__put_u8__53__value);
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         481);
    while ((0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             481);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         482);
    vlSelfRef.tb_npu_engines__DOT__matrix_task_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         484);
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         485);
    vlSelfRef.tb_npu_engines__DOT__matrix_task_valid = 0U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         597);
    while ((0x13U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             597);
    }
    __Vtask_tb_npu_engines__DOT__check__55__message = 
        std::string{"GEMM returned a failure status"};
    __Vtask_tb_npu_engines__DOT__check__55__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__55__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__55__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__check__56__message = 
        std::string{"GEMM reported an unexpected fault"};
    __Vtask_tb_npu_engines__DOT__check__56__condition 
        = (0ULL == vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__56__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__56__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__check__57__message = 
        std::string{"GEMM progress element count mismatch"};
    __Vtask_tb_npu_engines__DOT__check__57__condition 
        = (4ULL == vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__progress_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__57__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__57__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__l1_read_word__58__addr = 0x600U;
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         450);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_addr = __Vtask_tb_npu_engines__DOT__l1_read_word__58__addr;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata = 0ULL;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         456);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             456);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         457);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         460);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             460);
    }
    __Vtask_tb_npu_engines__DOT__l1_read_word__58__data 
        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
        [0U];
    __Vtask_tb_npu_engines__DOT__check__59__message = 
        std::string{"L1 BFM read failed"};
    __Vtask_tb_npu_engines__DOT__check__59__condition 
        = (0U == vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
           [0U]);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__59__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__59__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         463);
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 0U;
    tb_npu_engines__DOT__read_word = __Vtask_tb_npu_engines__DOT__l1_read_word__58__data;
    __Vtask_tb_npu_engines__DOT__check__60__message = 
        std::string{"GEMM output row 0 mismatch"};
    __Vtask_tb_npu_engines__DOT__check__60__condition 
        = (0xd00000002ULL == tb_npu_engines__DOT__read_word);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__60__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__60__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__l1_read_word__61__addr = 0x608U;
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         450);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_addr = __Vtask_tb_npu_engines__DOT__l1_read_word__61__addr;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata = 0ULL;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         456);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             456);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         457);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         460);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             460);
    }
    __Vtask_tb_npu_engines__DOT__l1_read_word__61__data 
        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
        [0U];
    __Vtask_tb_npu_engines__DOT__check__62__message = 
        std::string{"L1 BFM read failed"};
    __Vtask_tb_npu_engines__DOT__check__62__condition 
        = (0U == vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
           [0U]);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__62__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__62__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         463);
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 0U;
    tb_npu_engines__DOT__read_word = __Vtask_tb_npu_engines__DOT__l1_read_word__61__data;
    __Vtask_tb_npu_engines__DOT__check__63__message = 
        std::string{"GEMM output row 1 mismatch"};
    __Vtask_tb_npu_engines__DOT__check__63__condition 
        = (0xd00000006ULL == tb_npu_engines__DOT__read_word);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__63__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__63__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__l1_write_word__64__strb = 0xffU;
    __Vtask_tb_npu_engines__DOT__l1_write_word__64__data = 0x101010101010101ULL;
    __Vtask_tb_npu_engines__DOT__l1_write_word__64__addr = 0x400U;
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         428);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_addr = __Vtask_tb_npu_engines__DOT__l1_write_word__64__addr;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata = __Vtask_tb_npu_engines__DOT__l1_write_word__64__data;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb = __Vtask_tb_npu_engines__DOT__l1_write_word__64__strb;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_write = 1U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         434);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             434);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         435);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         438);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             438);
    }
    __Vtask_tb_npu_engines__DOT__check__65__message = 
        std::string{"L1 BFM write failed"};
    __Vtask_tb_npu_engines__DOT__check__65__condition 
        = (0U == vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
           [0U]);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__65__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__65__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         440);
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 0U;
    __Vtask_tb_npu_engines__DOT__init_common__66__numeric = 0x55U;
    __Vtask_tb_npu_engines__DOT__init_common__66__dst = 0x500ULL;
    __Vtask_tb_npu_engines__DOT__init_common__66__src2 = 0ULL;
    __Vtask_tb_npu_engines__DOT__init_common__66__src1 = 0x400ULL;
    __Vtask_tb_npu_engines__DOT__init_common__66__src0 = 0x300ULL;
    __Vtask_tb_npu_engines__DOT__init_common__66__bytes = 0xc0U;
    __Vtask_tb_npu_engines__DOT__init_common__66__engine = 3U;
    IData/*31:0*/ __Vilp7;
    __Vilp7 = 0U;
    while ((__Vilp7 <= 0x3fU)) {
        vlSelfRef.tb_npu_engines__DOT__vector_desc[__Vilp7] 
            = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp7];
        __Vilp7 = ((IData)(1U) + __Vilp7);
    }
    __Vtask_tb_npu_engines__DOT__put_u8__67__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u8__67__offset = 0U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__67__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u8__67__value);
    __Vtask_tb_npu_engines__DOT__put_u8__68__value 
        = __Vtask_tb_npu_engines__DOT__init_common__66__engine;
    __Vtask_tb_npu_engines__DOT__put_u8__68__offset = 1U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__68__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u8__68__value);
    __Vtask_tb_npu_engines__DOT__put_u16__69__value 
        = __Vtask_tb_npu_engines__DOT__init_common__66__bytes;
    __Vtask_tb_npu_engines__DOT__put_u16__69__offset = 2U;
    VL_ASSIGNSEL_WI(2048, 16, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u16__69__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u16__69__value);
    __Vtask_tb_npu_engines__DOT__put_u64__70__value 
        = __Vtask_tb_npu_engines__DOT__init_common__66__src0;
    __Vtask_tb_npu_engines__DOT__put_u64__70__offset = 8U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__70__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u64__70__value);
    __Vtask_tb_npu_engines__DOT__put_u64__71__value 
        = __Vtask_tb_npu_engines__DOT__init_common__66__src1;
    __Vtask_tb_npu_engines__DOT__put_u64__71__offset = 0x10U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__71__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u64__71__value);
    __Vtask_tb_npu_engines__DOT__put_u64__72__value 
        = __Vtask_tb_npu_engines__DOT__init_common__66__src2;
    __Vtask_tb_npu_engines__DOT__put_u64__72__offset = 0x18U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__72__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u64__72__value);
    __Vtask_tb_npu_engines__DOT__put_u64__73__value 
        = __Vtask_tb_npu_engines__DOT__init_common__66__dst;
    __Vtask_tb_npu_engines__DOT__put_u64__73__offset = 0x20U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__73__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u64__73__value);
    __Vtask_tb_npu_engines__DOT__put_u32__74__value 
        = __Vtask_tb_npu_engines__DOT__init_common__66__numeric;
    __Vtask_tb_npu_engines__DOT__put_u32__74__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__74__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u32__74__value);
    __Vtask_tb_npu_engines__DOT__put_u32__75__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u32__75__offset = 0x40U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__75__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u32__75__value);
    __Vtask_tb_npu_engines__DOT__put_u32__76__value = 8U;
    __Vtask_tb_npu_engines__DOT__put_u32__76__offset = 0x44U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__76__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u32__76__value);
    __Vtask_tb_npu_engines__DOT__put_u32__77__value = 8U;
    __Vtask_tb_npu_engines__DOT__put_u32__77__offset = 0x48U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__77__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u32__77__value);
    __Vtask_tb_npu_engines__DOT__put_u32__78__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u32__78__offset = 0x50U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__78__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u32__78__value);
    __Vtask_tb_npu_engines__DOT__put_u32__79__value = 8U;
    __Vtask_tb_npu_engines__DOT__put_u32__79__offset = 0x54U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__79__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u32__79__value);
    __Vtask_tb_npu_engines__DOT__put_u32__80__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u32__80__offset = 0x58U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__80__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u32__80__value);
    __Vtask_tb_npu_engines__DOT__put_u32__81__value = 8U;
    __Vtask_tb_npu_engines__DOT__put_u32__81__offset = 0x5cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__81__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u32__81__value);
    __Vtask_tb_npu_engines__DOT__put_u32__82__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u32__82__offset = 0x68U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__82__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u32__82__value);
    __Vtask_tb_npu_engines__DOT__put_u32__83__value = 8U;
    __Vtask_tb_npu_engines__DOT__put_u32__83__offset = 0x6cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__83__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u32__83__value);
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         492);
    while ((0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             492);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         493);
    vlSelfRef.tb_npu_engines__DOT__vector_task_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         495);
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         496);
    vlSelfRef.tb_npu_engines__DOT__vector_task_valid = 0U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         626);
    while ((0x11U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             626);
    }
    __Vtask_tb_npu_engines__DOT__check__85__message = 
        std::string{"VADD returned a failure status"};
    __Vtask_tb_npu_engines__DOT__check__85__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__85__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__85__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__check__86__message = 
        std::string{"VADD reported an unexpected fault"};
    __Vtask_tb_npu_engines__DOT__check__86__condition 
        = (0ULL == vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__86__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__86__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__check__87__message = 
        std::string{"VADD progress element count mismatch"};
    __Vtask_tb_npu_engines__DOT__check__87__condition 
        = (8ULL == vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__progress_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__87__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__87__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__l1_read_word__88__addr = 0x500U;
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         450);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_addr = __Vtask_tb_npu_engines__DOT__l1_read_word__88__addr;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata = 0ULL;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         456);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             456);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         457);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         460);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             460);
    }
    __Vtask_tb_npu_engines__DOT__l1_read_word__88__data 
        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
        [0U];
    __Vtask_tb_npu_engines__DOT__check__89__message = 
        std::string{"L1 BFM read failed"};
    __Vtask_tb_npu_engines__DOT__check__89__condition 
        = (0U == vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
           [0U]);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__89__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__89__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         463);
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 0U;
    tb_npu_engines__DOT__read_word = __Vtask_tb_npu_engines__DOT__l1_read_word__88__data;
    __Vtask_tb_npu_engines__DOT__check__90__message = 
        std::string{"VADD numeric result mismatch"};
    __Vtask_tb_npu_engines__DOT__check__90__condition 
        = (0xb0804020100fdf9ULL == tb_npu_engines__DOT__read_word);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__90__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__90__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__l1_write_word__91__strb = 0xfU;
    __Vtask_tb_npu_engines__DOT__l1_write_word__91__data = 0x400fffcULL;
    __Vtask_tb_npu_engines__DOT__l1_write_word__91__addr = 0x700U;
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         428);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_addr = __Vtask_tb_npu_engines__DOT__l1_write_word__91__addr;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata = __Vtask_tb_npu_engines__DOT__l1_write_word__91__data;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb = __Vtask_tb_npu_engines__DOT__l1_write_word__91__strb;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_write = 1U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         434);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             434);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         435);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         438);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             438);
    }
    __Vtask_tb_npu_engines__DOT__check__92__message = 
        std::string{"L1 BFM write failed"};
    __Vtask_tb_npu_engines__DOT__check__92__condition 
        = (0U == vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
           [0U]);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__92__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__92__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         440);
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 0U;
    __Vtask_tb_npu_engines__DOT__init_common__93__numeric = 0x13055U;
    __Vtask_tb_npu_engines__DOT__init_common__93__dst = 0x800ULL;
    __Vtask_tb_npu_engines__DOT__init_common__93__src2 = 0ULL;
    __Vtask_tb_npu_engines__DOT__init_common__93__src1 = 0ULL;
    __Vtask_tb_npu_engines__DOT__init_common__93__src0 = 0x700ULL;
    __Vtask_tb_npu_engines__DOT__init_common__93__bytes = 0x100U;
    __Vtask_tb_npu_engines__DOT__init_common__93__engine = 4U;
    IData/*31:0*/ __Vilp8;
    __Vilp8 = 0U;
    while ((__Vilp8 <= 0x3fU)) {
        vlSelfRef.tb_npu_engines__DOT__complex_desc[__Vilp8] 
            = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp8];
        __Vilp8 = ((IData)(1U) + __Vilp8);
    }
    __Vtask_tb_npu_engines__DOT__put_u8__94__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u8__94__offset = 0U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__94__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u8__94__value);
    __Vtask_tb_npu_engines__DOT__put_u8__95__value 
        = __Vtask_tb_npu_engines__DOT__init_common__93__engine;
    __Vtask_tb_npu_engines__DOT__put_u8__95__offset = 1U;
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u8__95__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u8__95__value);
    __Vtask_tb_npu_engines__DOT__put_u16__96__value 
        = __Vtask_tb_npu_engines__DOT__init_common__93__bytes;
    __Vtask_tb_npu_engines__DOT__put_u16__96__offset = 2U;
    VL_ASSIGNSEL_WI(2048, 16, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u16__96__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u16__96__value);
    __Vtask_tb_npu_engines__DOT__put_u64__97__value 
        = __Vtask_tb_npu_engines__DOT__init_common__93__src0;
    __Vtask_tb_npu_engines__DOT__put_u64__97__offset = 8U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__97__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u64__97__value);
    __Vtask_tb_npu_engines__DOT__put_u64__98__value 
        = __Vtask_tb_npu_engines__DOT__init_common__93__src1;
    __Vtask_tb_npu_engines__DOT__put_u64__98__offset = 0x10U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__98__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u64__98__value);
    __Vtask_tb_npu_engines__DOT__put_u64__99__value 
        = __Vtask_tb_npu_engines__DOT__init_common__93__src2;
    __Vtask_tb_npu_engines__DOT__put_u64__99__offset = 0x18U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__99__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u64__99__value);
    __Vtask_tb_npu_engines__DOT__put_u64__100__value 
        = __Vtask_tb_npu_engines__DOT__init_common__93__dst;
    __Vtask_tb_npu_engines__DOT__put_u64__100__offset = 0x20U;
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u64__100__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u64__100__value);
    __Vtask_tb_npu_engines__DOT__put_u32__101__value 
        = __Vtask_tb_npu_engines__DOT__init_common__93__numeric;
    __Vtask_tb_npu_engines__DOT__put_u32__101__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__101__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u32__101__value);
    __Vtask_tb_npu_engines__DOT__put_u32__102__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u32__102__offset = 0x40U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__102__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u32__102__value);
    __Vtask_tb_npu_engines__DOT__put_u32__103__value = 4U;
    __Vtask_tb_npu_engines__DOT__put_u32__103__offset = 0x44U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__103__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u32__103__value);
    __Vtask_tb_npu_engines__DOT__put_u32__104__value = 4U;
    __Vtask_tb_npu_engines__DOT__put_u32__104__offset = 0x48U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__104__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u32__104__value);
    __Vtask_tb_npu_engines__DOT__put_u32__105__value = 1U;
    __Vtask_tb_npu_engines__DOT__put_u32__105__offset = 0x4cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__105__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u32__105__value);
    __Vtask_tb_npu_engines__DOT__put_u32__106__value = 4U;
    __Vtask_tb_npu_engines__DOT__put_u32__106__offset = 0x50U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__106__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u32__106__value);
    __Vtask_tb_npu_engines__DOT__put_u32__107__value = 4U;
    __Vtask_tb_npu_engines__DOT__put_u32__107__offset = 0x5cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__107__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u32__107__value);
    __Vtask_tb_npu_engines__DOT__put_u32__108__value = 0x3f800000U;
    __Vtask_tb_npu_engines__DOT__put_u32__108__offset = 0x70U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__108__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u32__108__value);
    __Vtask_tb_npu_engines__DOT__put_u32__109__value = 0x3f800000U;
    __Vtask_tb_npu_engines__DOT__put_u32__109__offset = 0x74U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__109__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u32__109__value);
    __Vtask_tb_npu_engines__DOT__put_u32__110__value = 0x3f800000U;
    __Vtask_tb_npu_engines__DOT__put_u32__110__offset = 0x78U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__110__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u32__110__value);
    __Vtask_tb_npu_engines__DOT__put_u32__111__value = 0x3f800000U;
    __Vtask_tb_npu_engines__DOT__put_u32__111__offset = 0x7cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__111__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__complex_desc, __Vtask_tb_npu_engines__DOT__put_u32__111__value);
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         503);
    while ((0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             503);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         504);
    vlSelfRef.tb_npu_engines__DOT__complex_task_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         506);
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         507);
    vlSelfRef.tb_npu_engines__DOT__complex_task_valid = 0U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         653);
    while ((0x14U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             653);
    }
    __Vtask_tb_npu_engines__DOT__check__113__message = 
        std::string{"Complex ACT returned a failure status"};
    __Vtask_tb_npu_engines__DOT__check__113__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__113__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__113__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__check__114__message = 
        std::string{"Complex ACT reported an unexpected fault"};
    __Vtask_tb_npu_engines__DOT__check__114__condition 
        = (0ULL == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__114__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__114__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__check__115__message = 
        std::string{"Complex ACT progress element count mismatch"};
    __Vtask_tb_npu_engines__DOT__check__115__condition 
        = (4ULL == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__progress_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__115__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__115__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__l1_read_word__116__addr = 0x800U;
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         450);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_addr = __Vtask_tb_npu_engines__DOT__l1_read_word__116__addr;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata = 0ULL;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         456);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             456);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         457);
    vlSelfRef.tb_npu_engines__DOT__bfm_req_valid = 0U;
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         460);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             460);
    }
    __Vtask_tb_npu_engines__DOT__l1_read_word__116__data 
        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
        [0U];
    __Vtask_tb_npu_engines__DOT__check__117__message = 
        std::string{"L1 BFM read failed"};
    __Vtask_tb_npu_engines__DOT__check__117__condition 
        = (0U == vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
           [0U]);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__117__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__117__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         463);
    vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready = 0U;
    tb_npu_engines__DOT__read_word = __Vtask_tb_npu_engines__DOT__l1_read_word__116__data;
    __Vtask_tb_npu_engines__DOT__check__118__message = 
        std::string{"Complex Tanh numeric result mismatch"};
    __Vtask_tb_npu_engines__DOT__check__118__condition 
        = (0x100ffffULL == (0xffffffffULL & tb_npu_engines__DOT__read_word));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__118__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__118__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    tb_npu_engines__DOT__handshakes_before_bad_numeric 
        = vlSelfRef.tb_npu_engines__DOT__l1_engine_handshakes_q;
    __Vtask_tb_npu_engines__DOT__put_u32__119__value = 0x155U;
    __Vtask_tb_npu_engines__DOT__put_u32__119__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_engines__DOT__put_u32__119__offset), 3U)), vlSelfRef.tb_npu_engines__DOT__vector_desc, __Vtask_tb_npu_engines__DOT__put_u32__119__value);
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         492);
    while ((0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             492);
    }
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         493);
    vlSelfRef.tb_npu_engines__DOT__vector_task_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         495);
    co_await vlSelfRef.__VtrigSched_h358e9218__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         496);
    vlSelfRef.tb_npu_engines__DOT__vector_task_valid = 0U;
    co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_engines.clk_i)", 
                                                         "tb/tb_npu_engines.sv", 
                                                         669);
    while ((0x11U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_h358e9255__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_engines.clk_i)", 
                                                             "tb/tb_npu_engines.sv", 
                                                             669);
    }
    __Vtask_tb_npu_engines__DOT__check__121__message = 
        std::string{"invalid numeric configuration did not return BAD_DESC"};
    __Vtask_tb_npu_engines__DOT__check__121__condition 
        = (2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__121__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__121__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__check__122__message = 
        std::string{"invalid numeric configuration reported nonzero progress"};
    __Vtask_tb_npu_engines__DOT__check__122__condition 
        = (0ULL == vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__progress_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__122__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__122__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    __Vtask_tb_npu_engines__DOT__check__123__message = 
        std::string{"invalid numeric configuration issued an L1 request"};
    __Vtask_tb_npu_engines__DOT__check__123__condition 
        = (vlSelfRef.tb_npu_engines__DOT__l1_engine_handshakes_q 
           == tb_npu_engines__DOT__handshakes_before_bad_numeric);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_engines__DOT__check__123__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:363: Assertion failed in %Ntb_npu_engines.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_engines__DOT__check__123__message));
        VL_STOP_MT("tb/tb_npu_engines.sv", 363, "", false);
    }
    VL_WRITEF_NX("TB_MODULE_ENGINES_PASS l1_handshakes=%0# mif_handshakes=%0#\n",0,
                 32,vlSelfRef.tb_npu_engines__DOT__l1_engine_handshakes_q,
                 32,vlSelfRef.tb_npu_engines__DOT__mif_handshakes_q);
    VL_FINISH_MT("tb/tb_npu_engines.sv", 681, "");
}

VL_INLINE_OPT VlCoroutine Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__1(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x77359400ULL, 
                                         nullptr, "tb/tb_npu_engines.sv", 
                                         685);
    VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:686: Assertion failed in %Ntb_npu_engines: engine module test timed out\n",0,
                 64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
    VL_STOP_MT("tb/tb_npu_engines.sv", 686, "", false);
}

VL_INLINE_OPT VlCoroutine Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__2(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "tb/tb_npu_engines.sv", 
                                             315);
        vlSelfRef.tb_npu_engines__DOT__clk_i = (1U 
                                                & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__clk_i)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_engines___024root___dump_triggers__act(Vtb_npu_engines___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_npu_engines___024root___eval_triggers__act(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_triggers__act\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb_npu_engines__DOT__clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_engines__DOT__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.tb_npu_engines__DOT__reset_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_engines__DOT__reset_n__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((~ (IData)(vlSelfRef.tb_npu_engines__DOT__clk_i)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_engines__DOT__clk_i__0)));
    vlSelfRef.__VactTriggered.setBit(3U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_engines__DOT__clk_i__0 
        = vlSelfRef.tb_npu_engines__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_engines__DOT__reset_n__0 
        = vlSelfRef.tb_npu_engines__DOT__reset_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_npu_engines___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_npu_engines___024root___nba_sequent__TOP__2(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___nba_sequent__TOP__2\n"); );
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
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v0) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q[vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v0][vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v0] 
            = ((0xffffffffffffff00ULL & vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q
                [vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v0]
                [vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v0]) 
               | (IData)((IData)(vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v0)));
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v1) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q[vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v1][vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v1] 
            = ((0xffffffffffff00ffULL & vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q
                [vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v1]
                [vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v1]) 
               | ((QData)((IData)(vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v1)) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v2) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q[vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v2][vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v2] 
            = ((0xffffffffff00ffffULL & vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q
                [vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v2]
                [vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v2]) 
               | ((QData)((IData)(vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v2)) 
                  << 0x10U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v3) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q[vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v3][vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v3] 
            = ((0xffffffff00ffffffULL & vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q
                [vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v3]
                [vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v3]) 
               | ((QData)((IData)(vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v3)) 
                  << 0x18U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v4) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q[vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v4][vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v4] 
            = ((0xffffff00ffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q
                [vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v4]
                [vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v4]) 
               | ((QData)((IData)(vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v4)) 
                  << 0x20U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v5) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q[vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v5][vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v5] 
            = ((0xffff00ffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q
                [vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v5]
                [vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v5]) 
               | ((QData)((IData)(vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v5)) 
                  << 0x28U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v6) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q[vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v6][vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v6] 
            = ((0xff00ffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q
                [vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v6]
                [vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v6]) 
               | ((QData)((IData)(vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v6)) 
                  << 0x30U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v7) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q[vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v7][vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v7] 
            = ((0xffffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q
                [vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v7]
                [vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v7]) 
               | ((QData)((IData)(vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v7)) 
                  << 0x38U));
    }
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_value_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__mask_value_q;
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q;
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__accum_q;
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q;
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__progress_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__progress_q;
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q;
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__linear_index_q;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_sum_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sum_q;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_max_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_max_q;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_sumsq_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sumsq_q;
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v0) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q[vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v0;
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v1) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q[vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v1] 
            = vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v1;
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v2) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q[0U] = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q[1U] = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q[2U] = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q[3U] = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q[4U] = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q[5U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v0) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q[vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v0;
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v1) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q[vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v1] 
            = vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v1;
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v2) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q[vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v2] 
            = vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v2;
    }
    if (vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v3) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q[0U] = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q[1U] = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q[2U] = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q[3U] = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q[4U] = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q[5U] = 0U;
    }
    vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__col_q;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__phase_q;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q 
        = vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__row_q;
    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_write = 0U;
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
    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_valid = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q) 
                  >> 4U)))) {
        if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                        vlSelfRef.tb_npu_engines__DOT__vector_l1_req_write = 1U;
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
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_high_nibble 
        = (IData)(((0U == (0xc0U & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU])) 
                   & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q 
                      ^ (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU] 
                         >> 0x10U))));
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
    vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 0U;
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
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_high_nibble 
        = ((0U == (3U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU])) 
           & ((1U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U])
               ? vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q
               : vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q));
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
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                        vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
                    }
                } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                    vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
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
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
            vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
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
    vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                          >> 2U)))) {
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
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid = 1U;
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
            vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid = 1U;
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
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
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_is_tiled 
        = ((2U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x24U] 
                            >> 8U))) | ((3U == (0xffU 
                                                & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x24U] 
                                                   >> 8U))) 
                                        | (6U == (0xffU 
                                                  & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x24U] 
                                                     >> 8U)))));
    if (vlSelfRef.tb_npu_engines__DOT__reset_n) {
        vlSelfRef.tb_npu_engines__DOT__cycle_count_q 
            = ((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__cycle_count_q);
        if ((0U != (0xfU & (((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
                             & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)) 
                            >> 1U)))) {
            vlSelfRef.tb_npu_engines__DOT__l1_engine_handshakes_q 
                = ((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__l1_engine_handshakes_q);
        }
        if (((IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_valid) 
             & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_ready))) {
            if (VL_UNLIKELY(((IData)((0ULL != (0xffffffff0007ULL 
                                               & vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_engines.sv:338: Assertion failed in %Ntb_npu_engines: DMA MIF model received an invalid address\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("tb/tb_npu_engines.sv", 338, "", false);
            }
            vlSelfRef.tb_npu_engines__DOT__mif_handshakes_q 
                = ((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__mif_handshakes_q);
            vlSelfRef.__Vdly__tb_npu_engines__DOT__system_mem_pending_q = 1U;
            vlSelfRef.tb_npu_engines__DOT__system_mem_rsp_status_q = 0U;
            vlSelfRef.tb_npu_engines__DOT__system_mem_rsp_data_q 
                = vlSelfRef.tb_npu_engines__DOT__system_mem
                [(0x1fffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                                     >> 3U)))];
            if (vlSelfRef.tb_npu_engines__DOT__dma_mif_req_write) {
                vlSelfRef.tb_npu_engines__DOT__byte_index = 8U;
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb))) {
                    vlSelfRef.__VdlyVal__tb_npu_engines__DOT__system_mem__v0 
                        = (0xffU & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata));
                    vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__system_mem__v0 
                        = (0x1fffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                                              >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v0 = 1U;
                }
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb))) {
                    vlSelfRef.__VdlyVal__tb_npu_engines__DOT__system_mem__v1 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata 
                                            >> 8U)));
                    vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__system_mem__v1 
                        = (0x1fffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                                              >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v1 = 1U;
                }
                if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb))) {
                    vlSelfRef.__VdlyVal__tb_npu_engines__DOT__system_mem__v2 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata 
                                            >> 0x10U)));
                    vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__system_mem__v2 
                        = (0x1fffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                                              >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v2 = 1U;
                }
                if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb))) {
                    vlSelfRef.__VdlyVal__tb_npu_engines__DOT__system_mem__v3 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata 
                                            >> 0x18U)));
                    vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__system_mem__v3 
                        = (0x1fffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                                              >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v3 = 1U;
                }
                if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb))) {
                    vlSelfRef.__VdlyVal__tb_npu_engines__DOT__system_mem__v4 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata 
                                            >> 0x20U)));
                    vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__system_mem__v4 
                        = (0x1fffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                                              >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v4 = 1U;
                }
                if ((0x20U & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb))) {
                    vlSelfRef.__VdlyVal__tb_npu_engines__DOT__system_mem__v5 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata 
                                            >> 0x28U)));
                    vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__system_mem__v5 
                        = (0x1fffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                                              >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v5 = 1U;
                }
                if ((0x40U & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb))) {
                    vlSelfRef.__VdlyVal__tb_npu_engines__DOT__system_mem__v6 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata 
                                            >> 0x30U)));
                    vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__system_mem__v6 
                        = (0x1fffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                                              >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v6 = 1U;
                }
                if ((0x80U & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb))) {
                    vlSelfRef.__VdlyVal__tb_npu_engines__DOT__system_mem__v7 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata 
                                            >> 0x38U)));
                    vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__system_mem__v7 
                        = (0x1fffU & (IData)((vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                                              >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v7 = 1U;
                }
            }
        }
        if (((IData)(vlSelfRef.tb_npu_engines__DOT__system_mem_pending_q) 
             & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_rsp_ready))) {
            vlSelfRef.__Vdly__tb_npu_engines__DOT__system_mem_pending_q = 0U;
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_engines__DOT__system_mem_pending_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__cycle_count_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__l1_engine_handshakes_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__mif_handshakes_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__system_mem_rsp_data_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__system_mem_rsp_status_q = 0U;
    }
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
    vlSelfRef.tb_npu_engines__DOT__dma_l1_req_write = 0U;
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
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_write = 1U;
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_valid = 1U;
        }
    }
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
    vlSelfRef.tb_npu_engines__DOT__complex_l1_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__complex_l1_rsp_ready = 0U;
    vlSelfRef.tb_npu_engines__DOT__complex_l1_req_valid = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_req_write = 1U;
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_req_valid = 1U;
                    }
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_rsp_ready = 1U;
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
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__norm_parameter_phase 
        = ((0x82U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
           & (5U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q)));
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
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_high_nibble 
        = ((0U == (3U & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU])) 
           & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q);
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_high_nibble 
        = (IData)(((0U == (0xcU & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU])) 
                   & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_high_nibble 
        = (IData)(((0U == (0x30U & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU])) 
                   & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q));
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
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_valid_length_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x31U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x30U]))) 
           + ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q)) 
              * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x32U]))));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_addr 
        = (0xffffffffffffULL & ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x19U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x18U]))) 
                                + (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q)) 
                                    * (QData)((IData)(
                                                      vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1aU]))) 
                                   + (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q)))));
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
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_dst_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[9U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[8U]))) 
           + ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q)) 
              * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x17U]))));
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
}
