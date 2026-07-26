// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core__Syms.h"
#include "Vtb_npu_single_core___024root.h"

extern const VlWide<64>/*2047:0*/ Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0;

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__0(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__0\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<64>/*2047:0*/ tb_npu_single_core__DOT__vector_desc;
    VL_ZERO_W(2048, tb_npu_single_core__DOT__vector_desc);
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__0__condition;
    __Vtask_tb_npu_single_core__DOT__check__0__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__0__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__2__condition;
    __Vtask_tb_npu_single_core__DOT__check__2__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__2__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__3__condition;
    __Vtask_tb_npu_single_core__DOT__check__3__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__3__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__4__condition;
    __Vtask_tb_npu_single_core__DOT__check__4__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__4__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__5__condition;
    __Vtask_tb_npu_single_core__DOT__check__5__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__5__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__6__condition;
    __Vtask_tb_npu_single_core__DOT__check__6__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__6__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__7__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__7__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__7__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__7__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__7__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__8__condition;
    __Vtask_tb_npu_single_core__DOT__check__8__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__8__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__9__condition;
    __Vtask_tb_npu_single_core__DOT__check__9__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__9__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__10__condition;
    __Vtask_tb_npu_single_core__DOT__check__10__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__10__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__11__condition;
    __Vtask_tb_npu_single_core__DOT__check__11__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__11__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__12__condition;
    __Vtask_tb_npu_single_core__DOT__check__12__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__12__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__13__condition;
    __Vtask_tb_npu_single_core__DOT__check__13__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__13__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__14__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__14__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__14__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__14__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__14__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__14__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__15__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__15__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__15__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__15__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__15__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__16__condition;
    __Vtask_tb_npu_single_core__DOT__check__16__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__16__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__17__condition;
    __Vtask_tb_npu_single_core__DOT__check__17__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__17__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__18__condition;
    __Vtask_tb_npu_single_core__DOT__check__18__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__18__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__19__condition;
    __Vtask_tb_npu_single_core__DOT__check__19__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__19__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__20__condition;
    __Vtask_tb_npu_single_core__DOT__check__20__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__20__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__21__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__21__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__21__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__21__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__21__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__21__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__22__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__22__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__22__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__22__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__22__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__23__condition;
    __Vtask_tb_npu_single_core__DOT__check__23__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__23__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__24__condition;
    __Vtask_tb_npu_single_core__DOT__check__24__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__24__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__25__condition;
    __Vtask_tb_npu_single_core__DOT__check__25__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__25__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__26__condition;
    __Vtask_tb_npu_single_core__DOT__check__26__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__26__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__27__condition;
    __Vtask_tb_npu_single_core__DOT__check__27__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__27__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__28__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__28__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__28__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__28__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__28__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__28__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__29__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__29__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__29__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__29__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__29__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__30__condition;
    __Vtask_tb_npu_single_core__DOT__check__30__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__30__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__31__condition;
    __Vtask_tb_npu_single_core__DOT__check__31__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__31__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__32__condition;
    __Vtask_tb_npu_single_core__DOT__check__32__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__32__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__33__condition;
    __Vtask_tb_npu_single_core__DOT__check__33__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__33__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__34__condition;
    __Vtask_tb_npu_single_core__DOT__check__34__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__34__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__35__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__35__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__35__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__35__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__35__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__35__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__36__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__36__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__36__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__36__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__36__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__37__condition;
    __Vtask_tb_npu_single_core__DOT__check__37__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__37__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__38__condition;
    __Vtask_tb_npu_single_core__DOT__check__38__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__38__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__39__condition;
    __Vtask_tb_npu_single_core__DOT__check__39__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__39__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__40__condition;
    __Vtask_tb_npu_single_core__DOT__check__40__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__40__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__41__condition;
    __Vtask_tb_npu_single_core__DOT__check__41__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__41__message;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__init_common__42__engine;
    __Vtask_tb_npu_single_core__DOT__init_common__42__engine = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__init_common__42__bytes;
    __Vtask_tb_npu_single_core__DOT__init_common__42__bytes = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__42__src0;
    __Vtask_tb_npu_single_core__DOT__init_common__42__src0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__42__src1;
    __Vtask_tb_npu_single_core__DOT__init_common__42__src1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__42__src2;
    __Vtask_tb_npu_single_core__DOT__init_common__42__src2 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__42__dst;
    __Vtask_tb_npu_single_core__DOT__init_common__42__dst = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__init_common__42__numeric;
    __Vtask_tb_npu_single_core__DOT__init_common__42__numeric = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__45__offset;
    __Vtask_tb_npu_single_core__DOT__put_u16__45__offset = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__45__value;
    __Vtask_tb_npu_single_core__DOT__put_u16__45__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__50__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__50__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__50__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__50__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__51__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__51__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__51__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__51__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__52__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__52__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__52__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__52__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__53__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__53__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__53__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__53__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__54__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__54__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__54__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__54__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__55__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__55__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__55__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__55__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__56__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__56__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__56__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__56__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__57__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__57__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__57__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__57__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__58__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__58__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__58__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__58__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__59__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__59__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__59__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__59__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__60__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__60__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__60__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__60__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__61__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__61__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__61__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__61__value = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__65__address;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__65__address = 0;
    VlWide<64>/*2047:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__65__desc;
    VL_ZERO_W(2048, __Vtask_tb_npu_single_core__DOT__store_descriptor__65__desc);
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__65__bytes;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__65__bytes = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__address;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__address = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__value;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__value = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__init_common__67__engine;
    __Vtask_tb_npu_single_core__DOT__init_common__67__engine = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__init_common__67__bytes;
    __Vtask_tb_npu_single_core__DOT__init_common__67__bytes = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__67__src0;
    __Vtask_tb_npu_single_core__DOT__init_common__67__src0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__67__src1;
    __Vtask_tb_npu_single_core__DOT__init_common__67__src1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__67__src2;
    __Vtask_tb_npu_single_core__DOT__init_common__67__src2 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__67__dst;
    __Vtask_tb_npu_single_core__DOT__init_common__67__dst = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__init_common__67__numeric;
    __Vtask_tb_npu_single_core__DOT__init_common__67__numeric = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__70__offset;
    __Vtask_tb_npu_single_core__DOT__put_u16__70__offset = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__70__value;
    __Vtask_tb_npu_single_core__DOT__put_u16__70__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__75__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__75__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__75__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__75__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__76__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__76__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__76__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__76__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__77__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__77__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__77__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__77__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__78__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__78__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__78__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__78__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__79__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__79__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__79__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__79__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__80__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__80__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__80__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__80__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__81__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__81__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__81__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__81__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__82__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__82__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__82__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__82__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__83__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__83__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__83__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__83__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__84__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__84__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__84__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__84__value = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__85__address;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__85__address = 0;
    VlWide<64>/*2047:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__85__desc;
    VL_ZERO_W(2048, __Vtask_tb_npu_single_core__DOT__store_descriptor__85__desc);
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__85__bytes;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__85__bytes = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__address;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__address = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__value;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__value = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__87__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_command__87__Vfuncout);
    QData/*47:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__87__descriptor_address;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__descriptor_address = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__87__command_id;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__command_id = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__87__engine;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__engine = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__87__opcode;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__opcode = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__87__wait0;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__wait0 = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__87__wait1;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__wait1 = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__87__signal_event;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__signal_event = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__87__low_word;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__low_word = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__87__high_word;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__high_word = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__88__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_command__88__Vfuncout);
    QData/*47:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__88__descriptor_address;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__descriptor_address = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__88__command_id;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__command_id = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__88__engine;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__engine = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__88__opcode;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__opcode = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__88__wait0;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__wait0 = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__88__wait1;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__wait1 = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__88__signal_event;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__signal_event = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__88__low_word;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__low_word = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__88__high_word;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__high_word = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__command_count;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__command_count = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__unnamedblk3__DOT__word_index;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__observed_response = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__beat_count;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__beat_count = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__90__condition;
    __Vtask_tb_npu_single_core__DOT__check__90__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__90__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__91__condition;
    __Vtask_tb_npu_single_core__DOT__check__91__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__91__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__92__condition;
    __Vtask_tb_npu_single_core__DOT__check__92__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__92__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__93__expected_command_id;
    __Vtask_tb_npu_single_core__DOT__read_command_response__93__expected_command_id = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__93__expected_status;
    __Vtask_tb_npu_single_core__DOT__read_command_response__93__expected_status = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__93__response;
    __Vtask_tb_npu_single_core__DOT__read_command_response__93__response = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__94__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__94__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__94__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__94__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__94__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__95__condition;
    __Vtask_tb_npu_single_core__DOT__check__95__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__95__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__96__condition;
    __Vtask_tb_npu_single_core__DOT__check__96__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__96__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__97__condition;
    __Vtask_tb_npu_single_core__DOT__check__97__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__97__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__98__condition;
    __Vtask_tb_npu_single_core__DOT__check__98__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__98__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__99__condition;
    __Vtask_tb_npu_single_core__DOT__check__99__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__99__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__100__condition;
    __Vtask_tb_npu_single_core__DOT__check__100__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__100__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__101__condition;
    __Vtask_tb_npu_single_core__DOT__check__101__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__101__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__102__condition;
    __Vtask_tb_npu_single_core__DOT__check__102__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__102__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__103__condition;
    __Vtask_tb_npu_single_core__DOT__check__103__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__103__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__104__condition;
    __Vtask_tb_npu_single_core__DOT__check__104__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__104__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__105__expected_command_id;
    __Vtask_tb_npu_single_core__DOT__read_command_response__105__expected_command_id = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__105__expected_status;
    __Vtask_tb_npu_single_core__DOT__read_command_response__105__expected_status = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__105__response;
    __Vtask_tb_npu_single_core__DOT__read_command_response__105__response = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__106__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__106__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__106__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__106__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__106__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__107__condition;
    __Vtask_tb_npu_single_core__DOT__check__107__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__107__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__108__condition;
    __Vtask_tb_npu_single_core__DOT__check__108__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__108__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__109__condition;
    __Vtask_tb_npu_single_core__DOT__check__109__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__109__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__110__condition;
    __Vtask_tb_npu_single_core__DOT__check__110__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__110__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__111__condition;
    __Vtask_tb_npu_single_core__DOT__check__111__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__111__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__112__condition;
    __Vtask_tb_npu_single_core__DOT__check__112__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__112__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__113__condition;
    __Vtask_tb_npu_single_core__DOT__check__113__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__113__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__114__condition;
    __Vtask_tb_npu_single_core__DOT__check__114__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__114__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__115__condition;
    __Vtask_tb_npu_single_core__DOT__check__115__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__115__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__116__condition;
    __Vtask_tb_npu_single_core__DOT__check__116__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__116__message;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__117__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__117__argument0 = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__118__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__118__address = 0;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__core_clk_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__reset_n = 0U;
    vlSelfRef.tb_npu_single_core__DOT__soft_reset_req_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__power_down_req_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__system_bus_backpressure = 1U;
    vlSelfRef.tb_npu_single_core__DOT__dependency_check_enable_q = 0U;
    vlSelfRef.tb_npu_single_core__DOT__protocol_checks_enable = 0U;
    vlSelfRef.tb_npu_single_core__DOT__system_dma_write_check_q = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i = 0ULL;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][0U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][1U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][2U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][3U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][0U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][1U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][2U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][3U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[2U][0U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[2U][1U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[2U][2U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[2U][3U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[3U][0U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[3U][1U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[3U][2U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[3U][3U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[4U][0U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[4U][1U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[4U][2U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[4U][3U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[5U][0U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[5U][1U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[5U][2U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[5U][3U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[6U][0U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[6U][1U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[6U][2U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[6U][3U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[7U][0U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[7U][1U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[7U][2U] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__command_words[7U][3U] = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         794);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         794);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         794);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         794);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         794);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         794);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         794);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         794);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         795);
    vlSelfRef.tb_npu_single_core__DOT__reset_n = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         797);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         797);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         797);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         797);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         797);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         797);
    vlSelfRef.tb_npu_single_core__DOT__protocol_checks_enable = 1U;
    __Vtask_tb_npu_single_core__DOT__check__0__message = 
        std::string{"NPU accepted commands before CORE_CONTROL.START"};
    __Vtask_tb_npu_single_core__DOT__check__0__condition 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__accept_new_cmd_o)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__0__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__0__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__data = 1ULL;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__address = 0x40U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__2__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__2__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__2__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__2__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__3__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__3__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__3__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__3__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__4__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__4__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__4__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__4__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__5__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__5__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__5__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__5__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__6__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__6__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__6__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__6__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__data = 1ULL;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__address = 0xf0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__7__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__7__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__7__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__7__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__8__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__8__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__8__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__8__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__9__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__9__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__7__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__9__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__9__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__10__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__10__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__10__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__10__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__11__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__11__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__11__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__11__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__12__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__12__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__12__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__12__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         804);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         804);
    __Vtask_tb_npu_single_core__DOT__check__13__message = 
        std::string{"NPU did not enter the running state"};
    __Vtask_tb_npu_single_core__DOT__check__13__condition 
        = vlSelfRef.tb_npu_single_core__DOT__accept_new_cmd_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__13__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__13__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__l1_write_word__14__strobe = 0x3fU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__14__data = 0x204ff030201ULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__14__address = 0x100U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__14__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__14__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__14__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__15__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__15__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__15__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__15__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__16__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__16__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__16__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__16__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__17__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__17__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__15__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__17__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__17__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__18__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__18__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__18__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__18__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__19__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__19__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__19__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__19__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__20__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__20__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__20__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__20__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__21__strobe = 0x3fU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__21__data = 0x4fe0103ff02ULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__21__address = 0x200U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__21__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__21__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__21__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__22__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__22__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__22__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__22__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__23__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__23__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__23__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__23__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__24__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__24__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__22__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__24__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__24__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__25__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__25__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__25__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__25__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__26__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__26__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__26__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__26__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__27__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__27__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__27__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__27__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__28__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__28__data = 0xa07030100fffcf8ULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__28__address = 0x300U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__28__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__28__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__28__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__29__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__29__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__29__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__29__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__30__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__30__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__30__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__30__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__31__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__31__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__29__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__31__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__31__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__32__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__32__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__32__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__32__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__33__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__33__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__33__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__33__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__34__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__34__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__34__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__34__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__35__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__35__data = 0x101010101010101ULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__35__address = 0x400U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__35__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__35__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__35__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__36__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__36__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__36__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__36__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__37__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__37__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__37__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__37__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__38__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__38__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__36__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__38__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__38__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__39__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__39__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__39__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__39__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__40__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__40__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__40__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__40__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__41__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__41__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__41__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__41__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__init_common__42__numeric = 0xa5U;
    __Vtask_tb_npu_single_core__DOT__init_common__42__dst = 0x600ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__42__src2 = 0ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__42__src1 = 0x200ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__42__src0 = 0x100ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__42__bytes = 0x100U;
    __Vtask_tb_npu_single_core__DOT__init_common__42__engine = 2U;
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb_npu_single_core__DOT__matrix_desc[__Vilp1] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0U, 1U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 1U, (IData)(__Vtask_tb_npu_single_core__DOT__init_common__42__engine));
    __Vtask_tb_npu_single_core__DOT__put_u16__45__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__42__bytes;
    __Vtask_tb_npu_single_core__DOT__put_u16__45__offset = 2U;
    VL_ASSIGNSEL_WI(2048, 16, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u16__45__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u16__45__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 8U, __Vtask_tb_npu_single_core__DOT__init_common__42__src0);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x10U, __Vtask_tb_npu_single_core__DOT__init_common__42__src1);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x18U, __Vtask_tb_npu_single_core__DOT__init_common__42__src2);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x20U, __Vtask_tb_npu_single_core__DOT__init_common__42__dst);
    __Vtask_tb_npu_single_core__DOT__put_u32__50__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__42__numeric;
    __Vtask_tb_npu_single_core__DOT__put_u32__50__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__50__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__50__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__51__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__51__offset = 0x40U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__51__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__51__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__52__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__52__offset = 0x44U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__52__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__52__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__53__value = 3U;
    __Vtask_tb_npu_single_core__DOT__put_u32__53__offset = 0x48U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__53__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__53__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__54__value = 1U;
    __Vtask_tb_npu_single_core__DOT__put_u32__54__offset = 0x4cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__54__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__54__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__55__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__55__offset = 0x50U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__55__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__55__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__56__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__56__offset = 0x54U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__56__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__56__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__57__value = 3U;
    __Vtask_tb_npu_single_core__DOT__put_u32__57__offset = 0x58U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__57__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__57__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__58__value = 0x80U;
    __Vtask_tb_npu_single_core__DOT__put_u32__58__offset = 0x5cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__58__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__58__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__59__value = 3U;
    __Vtask_tb_npu_single_core__DOT__put_u32__59__offset = 0x60U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__59__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__59__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__60__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__60__offset = 0x64U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__60__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__60__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__61__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__61__offset = 0x68U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__61__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__61__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x90U, 0U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x91U, 0U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x92U, 4U);
    __Vtask_tb_npu_single_core__DOT__store_descriptor__65__bytes = 0x100U;
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x3fU)) {
        __Vtask_tb_npu_single_core__DOT__store_descriptor__65__desc[__Vilp2] 
            = vlSelfRef.tb_npu_single_core__DOT__matrix_desc[__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    __Vtask_tb_npu_single_core__DOT__store_descriptor__65__address = 0x1000ULL;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index = 0;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index 
            < __Vtask_tb_npu_single_core__DOT__store_descriptor__65__bytes)) {
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__value 
            = (0xffU & (((0U == (0x1fU & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index, 3U)))
                          ? 0U : (__Vtask_tb_npu_single_core__DOT__store_descriptor__65__desc[
                                  (((IData)(7U) + (0x7ffU 
                                                   & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index, 3U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index, 3U))))) 
                        | (__Vtask_tb_npu_single_core__DOT__store_descriptor__65__desc[
                           (0x3fU & (VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index, 3U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index, 3U)))));
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__address 
            = (__Vtask_tb_npu_single_core__DOT__store_descriptor__65__address 
               + (QData)((IData)(__Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index)));
        if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__address)))) {
            VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__address);
            VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
        }
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                      & (IData)(
                                                                                (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__address 
                                                                                >> 3U)))] 
            = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                      (7U 
                                                       & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__address)), 3U)))) 
                & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__address 
                                    >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__value)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, 
                                                                   (7U 
                                                                    & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__66__address)), 3U))));
        __Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__store_descriptor__65__unnamedblk1__DOT__index);
    }
    __Vtask_tb_npu_single_core__DOT__init_common__67__numeric = 0x55U;
    __Vtask_tb_npu_single_core__DOT__init_common__67__dst = 0x500ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__67__src2 = 0ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__67__src1 = 0x400ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__67__src0 = 0x300ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__67__bytes = 0xc0U;
    __Vtask_tb_npu_single_core__DOT__init_common__67__engine = 3U;
    IData/*31:0*/ __Vilp3;
    __Vilp3 = 0U;
    while ((__Vilp3 <= 0x3fU)) {
        tb_npu_single_core__DOT__vector_desc[__Vilp3] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp3];
        __Vilp3 = ((IData)(1U) + __Vilp3);
    }
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, tb_npu_single_core__DOT__vector_desc, 0U, 1U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, tb_npu_single_core__DOT__vector_desc, 1U, (IData)(__Vtask_tb_npu_single_core__DOT__init_common__67__engine));
    __Vtask_tb_npu_single_core__DOT__put_u16__70__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__67__bytes;
    __Vtask_tb_npu_single_core__DOT__put_u16__70__offset = 2U;
    VL_ASSIGNSEL_WI(2048, 16, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u16__70__offset), 3U)), tb_npu_single_core__DOT__vector_desc, __Vtask_tb_npu_single_core__DOT__put_u16__70__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__vector_desc, 8U, __Vtask_tb_npu_single_core__DOT__init_common__67__src0);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__vector_desc, 0x10U, __Vtask_tb_npu_single_core__DOT__init_common__67__src1);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__vector_desc, 0x18U, __Vtask_tb_npu_single_core__DOT__init_common__67__src2);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__vector_desc, 0x20U, __Vtask_tb_npu_single_core__DOT__init_common__67__dst);
    __Vtask_tb_npu_single_core__DOT__put_u32__75__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__67__numeric;
    __Vtask_tb_npu_single_core__DOT__put_u32__75__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__75__offset), 3U)), tb_npu_single_core__DOT__vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__75__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__76__value = 1U;
    __Vtask_tb_npu_single_core__DOT__put_u32__76__offset = 0x40U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__76__offset), 3U)), tb_npu_single_core__DOT__vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__76__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__77__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__77__offset = 0x44U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__77__offset), 3U)), tb_npu_single_core__DOT__vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__77__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__78__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__78__offset = 0x48U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__78__offset), 3U)), tb_npu_single_core__DOT__vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__78__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__79__value = 1U;
    __Vtask_tb_npu_single_core__DOT__put_u32__79__offset = 0x50U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__79__offset), 3U)), tb_npu_single_core__DOT__vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__79__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__80__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__80__offset = 0x54U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__80__offset), 3U)), tb_npu_single_core__DOT__vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__80__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__81__value = 1U;
    __Vtask_tb_npu_single_core__DOT__put_u32__81__offset = 0x58U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__81__offset), 3U)), tb_npu_single_core__DOT__vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__81__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__82__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__82__offset = 0x5cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__82__offset), 3U)), tb_npu_single_core__DOT__vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__82__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__83__value = 1U;
    __Vtask_tb_npu_single_core__DOT__put_u32__83__offset = 0x68U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__83__offset), 3U)), tb_npu_single_core__DOT__vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__83__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__84__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__84__offset = 0x6cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__84__offset), 3U)), tb_npu_single_core__DOT__vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__84__value);
    __Vtask_tb_npu_single_core__DOT__store_descriptor__85__bytes = 0xc0U;
    IData/*31:0*/ __Vilp4;
    __Vilp4 = 0U;
    while ((__Vilp4 <= 0x3fU)) {
        __Vtask_tb_npu_single_core__DOT__store_descriptor__85__desc[__Vilp4] 
            = tb_npu_single_core__DOT__vector_desc[__Vilp4];
        __Vilp4 = ((IData)(1U) + __Vilp4);
    }
    __Vtask_tb_npu_single_core__DOT__store_descriptor__85__address = 0x1100ULL;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index = 0;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index 
            < __Vtask_tb_npu_single_core__DOT__store_descriptor__85__bytes)) {
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__value 
            = (0xffU & (((0U == (0x1fU & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index, 3U)))
                          ? 0U : (__Vtask_tb_npu_single_core__DOT__store_descriptor__85__desc[
                                  (((IData)(7U) + (0x7ffU 
                                                   & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index, 3U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index, 3U))))) 
                        | (__Vtask_tb_npu_single_core__DOT__store_descriptor__85__desc[
                           (0x3fU & (VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index, 3U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index, 3U)))));
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__address 
            = (__Vtask_tb_npu_single_core__DOT__store_descriptor__85__address 
               + (QData)((IData)(__Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index)));
        if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__address)))) {
            VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__address);
            VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
        }
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                      & (IData)(
                                                                                (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__address 
                                                                                >> 3U)))] 
            = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                      (7U 
                                                       & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__address)), 3U)))) 
                & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__address 
                                    >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__value)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, 
                                                                   (7U 
                                                                    & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__86__address)), 3U))));
        __Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__store_descriptor__85__unnamedblk1__DOT__index);
    }
    __Vfunc_tb_npu_single_core__DOT__make_command__87__signal_event = 1U;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__wait1 = 0xfffU;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__wait0 = 0xfffU;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__opcode = 0x40U;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__engine = 2U;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__command_id = 0x101U;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__descriptor_address = 0x1000ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__low_word = 0;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__high_word = 0;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__low_word = 0ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__high_word = 0ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__87__low_word 
        = (((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__87__engine)) 
            << 0x3cU) | (((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__87__command_id)) 
                          << 0x30U) | __Vfunc_tb_npu_single_core__DOT__make_command__87__descriptor_address));
    __Vfunc_tb_npu_single_core__DOT__make_command__87__high_word 
        = ((0xffffffffffffff00ULL & __Vfunc_tb_npu_single_core__DOT__make_command__87__high_word) 
           | (IData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__87__opcode)));
    __Vfunc_tb_npu_single_core__DOT__make_command__87__high_word 
        = ((0xfffffULL & __Vfunc_tb_npu_single_core__DOT__make_command__87__high_word) 
           | (((QData)((IData)((0x1000000U | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__87__signal_event) 
                                               << 0xcU) 
                                              | (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__87__wait1))))) 
               << 0x20U) | ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__87__wait0)) 
                            << 0x14U)));
    __Vfunc_tb_npu_single_core__DOT__make_command__87__Vfuncout[0U] 
        = (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__87__low_word);
    __Vfunc_tb_npu_single_core__DOT__make_command__87__Vfuncout[1U] 
        = (IData)((__Vfunc_tb_npu_single_core__DOT__make_command__87__low_word 
                   >> 0x20U));
    __Vfunc_tb_npu_single_core__DOT__make_command__87__Vfuncout[2U] 
        = (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__87__high_word);
    __Vfunc_tb_npu_single_core__DOT__make_command__87__Vfuncout[3U] 
        = (IData)((__Vfunc_tb_npu_single_core__DOT__make_command__87__high_word 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__87__Vfuncout[0U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__87__Vfuncout[1U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__87__Vfuncout[2U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__87__Vfuncout[3U];
    __Vfunc_tb_npu_single_core__DOT__make_command__88__signal_event = 0xfffU;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__wait1 = 0xfffU;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__wait0 = 1U;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__opcode = 0x60U;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__engine = 3U;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__command_id = 0x102U;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__descriptor_address = 0x1100ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__low_word = 0;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__high_word = 0;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__low_word = 0ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__high_word = 0ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__88__low_word 
        = (((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__88__engine)) 
            << 0x3cU) | (((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__88__command_id)) 
                          << 0x30U) | __Vfunc_tb_npu_single_core__DOT__make_command__88__descriptor_address));
    __Vfunc_tb_npu_single_core__DOT__make_command__88__high_word 
        = ((0xffffffffffffff00ULL & __Vfunc_tb_npu_single_core__DOT__make_command__88__high_word) 
           | (IData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__88__opcode)));
    __Vfunc_tb_npu_single_core__DOT__make_command__88__high_word 
        = ((0xfffffULL & __Vfunc_tb_npu_single_core__DOT__make_command__88__high_word) 
           | (((QData)((IData)((0x1000000U | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__88__signal_event) 
                                               << 0xcU) 
                                              | (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__88__wait1))))) 
               << 0x20U) | ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__88__wait0)) 
                            << 0x14U)));
    __Vfunc_tb_npu_single_core__DOT__make_command__88__Vfuncout[0U] 
        = (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__88__low_word);
    __Vfunc_tb_npu_single_core__DOT__make_command__88__Vfuncout[1U] 
        = (IData)((__Vfunc_tb_npu_single_core__DOT__make_command__88__low_word 
                   >> 0x20U));
    __Vfunc_tb_npu_single_core__DOT__make_command__88__Vfuncout[2U] 
        = (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__88__high_word);
    __Vfunc_tb_npu_single_core__DOT__make_command__88__Vfuncout[3U] 
        = (IData)((__Vfunc_tb_npu_single_core__DOT__make_command__88__high_word 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__88__Vfuncout[0U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__88__Vfuncout[1U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__88__Vfuncout[2U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__88__Vfuncout[3U];
    vlSelfRef.tb_npu_single_core__DOT__dependency_check_enable_q = 1U;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__command_count = 2U;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__observed_response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__beat_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__beat_count 
        = VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__command_count, 1U);
    __Vtask_tb_npu_single_core__DOT__check__90__message = 
        std::string{"invalid command burst count"};
    __Vtask_tb_npu_single_core__DOT__check__90__condition 
        = ((1U <= __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__command_count) 
           & (8U >= __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__command_count));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__90__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__90__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         631);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x63U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i = 0x20000U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i 
        = (0xffU & (__Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__beat_count 
                    - (IData)(1U)));
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         639);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             639);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         640);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index 
            < __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__command_count)) {
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0U;
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             647);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
            = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index)][1U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                            [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index)][0U])));
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i = 0xffU;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i 
            = (((IData)(1U) + VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index, 1U)) 
               == __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__beat_count);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             654);
        while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 654);
        }
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             655);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 1U;
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             647);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
            = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index)][3U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                            [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index)][2U])));
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i = 0xffU;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i 
            = (((IData)(2U) + VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index, 1U)) 
               == __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__beat_count);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             654);
        while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 654);
        }
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             655);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 2U;
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__unnamedblk2__DOT__command_index);
    }
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         660);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             660);
    }
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         662);
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         662);
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__91__message = 
        std::string{"command burst response was not held"};
    __Vtask_tb_npu_single_core__DOT__check__91__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_submit_commands__89__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__91__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__91__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         665);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         667);
    __Vtask_tb_npu_single_core__DOT__check__92__message = 
        std::string{"FIXED command burst failed"};
    __Vtask_tb_npu_single_core__DOT__check__92__condition 
        = ((0x63U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q)) 
           & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__92__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__92__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         670);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__93__expected_status = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__93__expected_command_id = 0x101U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__93__response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__address = 0x20008U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__94__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         600);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             600);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         601);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         604);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             604);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__95__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__95__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__95__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__95__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__96__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__96__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__94__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__94__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__96__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__96__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         612);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         614);
    __Vtask_tb_npu_single_core__DOT__check__97__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__97__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__97__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__97__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__98__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__98__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__98__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__98__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__99__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__99__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__99__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__99__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__100__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__100__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__100__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__100__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__94__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__93__response 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__94__data;
    __Vtask_tb_npu_single_core__DOT__check__101__message = 
        std::string{"CFE response returned the wrong command_id"};
    __Vtask_tb_npu_single_core__DOT__check__101__condition 
        = ((0xfffU & (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__93__response)) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__93__expected_command_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__101__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__101__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__102__message = 
        std::string{"CFE response returned the wrong status"};
    __Vtask_tb_npu_single_core__DOT__check__102__condition 
        = ((0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__93__response 
                             >> 0xcU))) == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__93__expected_status));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__102__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__102__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__103__message = 
        std::string{"CFE response fifo_free_entries exceeds the configured depth"};
    __Vtask_tb_npu_single_core__DOT__check__103__condition 
        = (8U >= (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__93__response 
                                   >> 0x14U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__103__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__103__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__104__message = 
        std::string{"CFE response reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__104__condition 
        = (0ULL == (__Vtask_tb_npu_single_core__DOT__read_command_response__93__response 
                    >> 0x1cU));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__104__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__104__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__read_command_response__105__expected_status = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__105__expected_command_id = 0x102U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__105__response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__address = 0x20008U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__106__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         600);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             600);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         601);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         604);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             604);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__107__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__107__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__107__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__107__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__108__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__108__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__106__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__106__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__108__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__108__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         612);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         614);
    __Vtask_tb_npu_single_core__DOT__check__109__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__109__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__109__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__109__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__110__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__110__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__110__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__110__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__111__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__111__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__111__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__111__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__112__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__112__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__112__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__112__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__106__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__105__response 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__106__data;
    __Vtask_tb_npu_single_core__DOT__check__113__message = 
        std::string{"CFE response returned the wrong command_id"};
    __Vtask_tb_npu_single_core__DOT__check__113__condition 
        = ((0xfffU & (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__105__response)) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__105__expected_command_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__113__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__113__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__114__message = 
        std::string{"CFE response returned the wrong status"};
    __Vtask_tb_npu_single_core__DOT__check__114__condition 
        = ((0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__105__response 
                             >> 0xcU))) == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__105__expected_status));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__114__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__114__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__115__message = 
        std::string{"CFE response fifo_free_entries exceeds the configured depth"};
    __Vtask_tb_npu_single_core__DOT__check__115__condition 
        = (8U >= (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__105__response 
                                   >> 0x14U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__115__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__115__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__116__message = 
        std::string{"CFE response reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__116__condition 
        = (0ULL == (__Vtask_tb_npu_single_core__DOT__read_command_response__105__response 
                    >> 0x1cU));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__116__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__116__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__argument1 = 0xc350ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__117__argument0 = 1ULL;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__operation = 1U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__117__status = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6846317767320301115ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__117__poll_count = 0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__118__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__118__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__117__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__118__address = 0x20020U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__118__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9436478287825158907ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__118__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12096266298165377149ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__118__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
}

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__1(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__1\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__117__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__117__result = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__119__condition;
    __Vtask_tb_npu_single_core__DOT__check__119__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__119__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__120__condition;
    __Vtask_tb_npu_single_core__DOT__check__120__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__120__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__121__condition;
    __Vtask_tb_npu_single_core__DOT__check__121__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__121__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__122__condition;
    __Vtask_tb_npu_single_core__DOT__check__122__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__122__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__123__condition;
    __Vtask_tb_npu_single_core__DOT__check__123__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__123__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__124__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__124__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__124__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__124__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__124__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__125__condition;
    __Vtask_tb_npu_single_core__DOT__check__125__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__125__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__126__condition;
    __Vtask_tb_npu_single_core__DOT__check__126__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__126__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__127__condition;
    __Vtask_tb_npu_single_core__DOT__check__127__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__127__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__128__condition;
    __Vtask_tb_npu_single_core__DOT__check__128__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__128__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__129__condition;
    __Vtask_tb_npu_single_core__DOT__check__129__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__129__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__130__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__130__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__130__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__130__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__130__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__131__condition;
    __Vtask_tb_npu_single_core__DOT__check__131__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__131__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__132__condition;
    __Vtask_tb_npu_single_core__DOT__check__132__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__132__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__133__condition;
    __Vtask_tb_npu_single_core__DOT__check__133__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__133__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__134__condition;
    __Vtask_tb_npu_single_core__DOT__check__134__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__134__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__135__condition;
    __Vtask_tb_npu_single_core__DOT__check__135__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__135__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__136__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__136__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__136__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__136__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__136__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__136__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__136__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__136__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__136__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__136__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__137__condition;
    __Vtask_tb_npu_single_core__DOT__check__137__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__137__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__138__condition;
    __Vtask_tb_npu_single_core__DOT__check__138__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__138__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__139__condition;
    __Vtask_tb_npu_single_core__DOT__check__139__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__139__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__140__condition;
    __Vtask_tb_npu_single_core__DOT__check__140__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__140__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__141__condition;
    __Vtask_tb_npu_single_core__DOT__check__141__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__141__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__142__condition;
    __Vtask_tb_npu_single_core__DOT__check__142__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__142__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__143__condition;
    __Vtask_tb_npu_single_core__DOT__check__143__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__143__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__144__condition;
    __Vtask_tb_npu_single_core__DOT__check__144__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__144__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__145__condition;
    __Vtask_tb_npu_single_core__DOT__check__145__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__145__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__146__condition;
    __Vtask_tb_npu_single_core__DOT__check__146__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__146__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__147__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__147__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__147__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__147__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__147__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__148__condition;
    __Vtask_tb_npu_single_core__DOT__check__148__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__148__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__149__condition;
    __Vtask_tb_npu_single_core__DOT__check__149__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__149__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__150__condition;
    __Vtask_tb_npu_single_core__DOT__check__150__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__150__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__151__condition;
    __Vtask_tb_npu_single_core__DOT__check__151__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__151__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__152__condition;
    __Vtask_tb_npu_single_core__DOT__check__152__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__152__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__153__condition;
    __Vtask_tb_npu_single_core__DOT__check__153__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__153__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__154__condition;
    __Vtask_tb_npu_single_core__DOT__check__154__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__154__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__155__condition;
    __Vtask_tb_npu_single_core__DOT__check__155__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__155__message;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__156__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__156__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__156__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__156__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__156__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__156__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__157__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__157__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__157__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__157__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__157__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__158__condition;
    __Vtask_tb_npu_single_core__DOT__check__158__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__158__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__159__condition;
    __Vtask_tb_npu_single_core__DOT__check__159__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__159__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__160__condition;
    __Vtask_tb_npu_single_core__DOT__check__160__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__160__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__161__condition;
    __Vtask_tb_npu_single_core__DOT__check__161__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__161__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__162__condition;
    __Vtask_tb_npu_single_core__DOT__check__162__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__162__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__163__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__163__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__163__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__163__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__163__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__164__condition;
    __Vtask_tb_npu_single_core__DOT__check__164__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__164__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__165__condition;
    __Vtask_tb_npu_single_core__DOT__check__165__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__165__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__166__condition;
    __Vtask_tb_npu_single_core__DOT__check__166__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__166__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__167__condition;
    __Vtask_tb_npu_single_core__DOT__check__167__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__167__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__168__condition;
    __Vtask_tb_npu_single_core__DOT__check__168__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__168__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__169__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__169__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__169__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__169__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__169__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__170__condition;
    __Vtask_tb_npu_single_core__DOT__check__170__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__170__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__171__condition;
    __Vtask_tb_npu_single_core__DOT__check__171__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__171__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__172__condition;
    __Vtask_tb_npu_single_core__DOT__check__172__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__172__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__173__condition;
    __Vtask_tb_npu_single_core__DOT__check__173__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__173__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__174__condition;
    __Vtask_tb_npu_single_core__DOT__check__174__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__174__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__175__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__175__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__175__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__175__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__175__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__175__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__175__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__175__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__175__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__175__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__176__condition;
    __Vtask_tb_npu_single_core__DOT__check__176__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__176__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__177__condition;
    __Vtask_tb_npu_single_core__DOT__check__177__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__177__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__178__condition;
    __Vtask_tb_npu_single_core__DOT__check__178__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__178__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__179__condition;
    __Vtask_tb_npu_single_core__DOT__check__179__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__179__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__180__condition;
    __Vtask_tb_npu_single_core__DOT__check__180__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__180__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__181__condition;
    __Vtask_tb_npu_single_core__DOT__check__181__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__181__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__182__condition;
    __Vtask_tb_npu_single_core__DOT__check__182__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__182__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__183__condition;
    __Vtask_tb_npu_single_core__DOT__check__183__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__183__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__184__condition;
    __Vtask_tb_npu_single_core__DOT__check__184__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__184__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__185__condition;
    __Vtask_tb_npu_single_core__DOT__check__185__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__185__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__186__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__186__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__186__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__186__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__186__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__187__condition;
    __Vtask_tb_npu_single_core__DOT__check__187__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__187__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__188__condition;
    __Vtask_tb_npu_single_core__DOT__check__188__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__188__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__189__condition;
    __Vtask_tb_npu_single_core__DOT__check__189__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__189__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__190__condition;
    __Vtask_tb_npu_single_core__DOT__check__190__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__190__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__191__condition;
    __Vtask_tb_npu_single_core__DOT__check__191__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__191__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__192__condition;
    __Vtask_tb_npu_single_core__DOT__check__192__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__192__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__193__condition;
    __Vtask_tb_npu_single_core__DOT__check__193__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__193__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__query_task__194__command_id;
    __Vtask_tb_npu_single_core__DOT__query_task__194__command_id = 0;
    CData/*2:0*/ __Vtask_tb_npu_single_core__DOT__query_task__194__selector;
    __Vtask_tb_npu_single_core__DOT__query_task__194__selector = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__195__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__195__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__195__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__195__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__195__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__195__argument1 = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__196__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__196__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__196__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__196__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__196__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__197__condition;
    __Vtask_tb_npu_single_core__DOT__check__197__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__197__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__198__condition;
    __Vtask_tb_npu_single_core__DOT__check__198__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__198__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__199__condition;
    __Vtask_tb_npu_single_core__DOT__check__199__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__199__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__200__condition;
    __Vtask_tb_npu_single_core__DOT__check__200__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__200__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__201__condition;
    __Vtask_tb_npu_single_core__DOT__check__201__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__201__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__202__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__202__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__202__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__202__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__202__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__203__condition;
    __Vtask_tb_npu_single_core__DOT__check__203__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__203__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__204__condition;
    __Vtask_tb_npu_single_core__DOT__check__204__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__204__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__205__condition;
    __Vtask_tb_npu_single_core__DOT__check__205__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__205__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__206__condition;
    __Vtask_tb_npu_single_core__DOT__check__206__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__206__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__207__condition;
    __Vtask_tb_npu_single_core__DOT__check__207__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__207__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__208__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__208__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__208__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__208__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__208__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__209__condition;
    __Vtask_tb_npu_single_core__DOT__check__209__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__209__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__210__condition;
    __Vtask_tb_npu_single_core__DOT__check__210__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__210__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__211__condition;
    __Vtask_tb_npu_single_core__DOT__check__211__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__211__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__212__condition;
    __Vtask_tb_npu_single_core__DOT__check__212__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__212__message;
    // Body
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__118__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__118__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__118__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__118__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__118__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__118__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__119__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__119__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__119__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__119__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__120__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__120__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__118__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__120__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__120__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__121__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__121__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__121__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__121__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__122__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__122__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__122__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__122__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__123__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__123__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__123__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__123__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__data 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__124__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__124__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__124__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__124__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__125__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__125__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__125__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__125__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__126__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__126__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__124__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__126__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__126__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__127__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__127__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__127__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__127__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__128__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__128__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__128__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__128__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__129__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__129__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__129__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__129__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__data 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__130__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__130__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__130__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__130__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__131__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__131__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__131__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__131__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__132__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__132__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__130__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__132__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__132__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__133__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__133__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__133__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__133__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__134__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__134__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__134__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__134__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__135__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__135__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__135__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__135__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__status = 0ULL;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__poll_count = 0U;
    {
        while ((0x4e20U > vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__136__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__136__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__136__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__136__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__136__address;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 600);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     600);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 601);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 604);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     604);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__136__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__136__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__136__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__136__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__136__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__137__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__137__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__137__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__137__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__138__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__138__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__136__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__136__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__138__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__138__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 612);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 614);
            __Vtask_tb_npu_single_core__DOT__check__139__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__139__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__139__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__139__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__140__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__140__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__140__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__140__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__141__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__141__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__141__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__141__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__142__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__142__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__142__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__142__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__136__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__136__data;
            if ((1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__status 
                               >> 1U)))) {
                goto __Vlabel0;
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__poll_count 
                = ((IData)(1U) + vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__poll_count);
        }
        __Vlabel0: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__143__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__143__condition 
        = (1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__143__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__143__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__144__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__144__condition 
        = (1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__144__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__144__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__145__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__145__condition 
        = (0U == (0xffU & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__145__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__145__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__146__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__146__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__117__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__146__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__146__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__147__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         600);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             600);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         601);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         604);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             604);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__148__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__148__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__148__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__148__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__149__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__149__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__147__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__147__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__149__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__149__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         612);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         614);
    __Vtask_tb_npu_single_core__DOT__check__150__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__150__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__150__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__150__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__151__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__151__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__151__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__151__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__152__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__152__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__152__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__152__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__153__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__153__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__153__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__153__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__147__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__117__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__147__data;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = __Vtask_tb_npu_single_core__DOT__ctl_request__117__result;
    __Vtask_tb_npu_single_core__DOT__check__154__message = 
        std::string{"WAIT did not return event success"};
    __Vtask_tb_npu_single_core__DOT__check__154__condition 
        = (2U == (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__ctl_data)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__154__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__154__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__155__message = 
        std::string{"WAIT returned the wrong producer command_id"};
    __Vtask_tb_npu_single_core__DOT__check__155__condition 
        = (0x101U == (0xfffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__ctl_data 
                                        >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__155__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__155__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__argument1 = 0xc350ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__argument0 = 0xfULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__operation = 3U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__156__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__157__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__157__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__157__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__157__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__158__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__158__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__158__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__158__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__159__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__159__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__157__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__159__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__159__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__160__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__160__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__160__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__160__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__161__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__161__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__161__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__161__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__162__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__162__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__162__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__162__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__156__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__163__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__163__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__163__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__163__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__164__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__164__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__164__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__164__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__165__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__165__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__163__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__165__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__165__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__166__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__166__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__166__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__166__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__167__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__167__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__167__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__167__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__168__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__168__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__168__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__168__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__156__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__169__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__169__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__169__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__169__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__170__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__170__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__170__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__170__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__171__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__171__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__169__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__171__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__171__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__172__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__172__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__172__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__172__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__173__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__173__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__173__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__173__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__174__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__174__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__174__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__174__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__156__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__175__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__175__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__175__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__175__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__175__address;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 600);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     600);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 601);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 604);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     604);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__175__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__175__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__175__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__175__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__175__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__176__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__176__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__176__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__176__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__177__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__177__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__175__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__175__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__177__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__177__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 612);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 614);
            __Vtask_tb_npu_single_core__DOT__check__178__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__178__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__178__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__178__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__179__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__179__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__179__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__179__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__180__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__180__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__180__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__180__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__181__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__181__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__181__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__181__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__175__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__156__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__175__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__156__status 
                               >> 1U)))) {
                goto __Vlabel1;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__156__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__156__poll_count);
        }
        __Vlabel1: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__182__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__182__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__156__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__182__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__182__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__183__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__183__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__156__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__183__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__183__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__184__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__184__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__156__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__184__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__184__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__185__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__185__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__156__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__185__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__185__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__186__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         600);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             600);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         601);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         604);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             604);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__187__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__187__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__187__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__187__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__188__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__188__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__186__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__186__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__188__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__188__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         612);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         614);
    __Vtask_tb_npu_single_core__DOT__check__189__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__189__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__189__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__189__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__190__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__190__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__190__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__190__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__191__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__191__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__191__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__191__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__192__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__192__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__192__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__192__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__186__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__156__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__186__data;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = __Vtask_tb_npu_single_core__DOT__ctl_request__156__result;
    __Vtask_tb_npu_single_core__DOT__check__193__message = 
        std::string{"FENCE returned a failure for valid tasks"};
    __Vtask_tb_npu_single_core__DOT__check__193__condition 
        = (0U == (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__ctl_data)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__193__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__193__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.tb_npu_single_core__DOT__dependency_check_enable_q = 0U;
    __Vtask_tb_npu_single_core__DOT__query_task__194__selector = 0U;
    __Vtask_tb_npu_single_core__DOT__query_task__194__command_id = 0x101U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__195__argument1 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__194__selector));
    __Vtask_tb_npu_single_core__DOT__ctl_request__195__argument0 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__194__command_id));
    __Vtask_tb_npu_single_core__DOT__ctl_request__195__operation = 2U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__195__status = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2703090029013146330ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__195__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__195__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__196__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__196__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__196__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__196__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__197__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__197__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__197__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__197__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__198__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__198__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__196__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__198__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__198__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__199__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__199__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__199__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__199__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__200__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__200__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__200__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__200__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__201__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__201__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__201__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__201__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__195__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__202__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__202__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__202__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__202__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__203__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__203__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__203__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__203__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__204__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__204__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__202__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__204__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__204__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__205__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__205__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__205__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__205__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__206__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__206__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__206__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__206__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__207__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__207__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__207__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__207__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__195__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__208__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__208__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__208__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__208__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__209__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__209__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__209__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__209__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__210__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__210__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__208__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__210__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__210__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    __Vtask_tb_npu_single_core__DOT__check__211__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__211__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__211__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__211__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__212__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__212__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__212__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__212__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
}
