// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core__Syms.h"
#include "Vtb_npu_single_core___024root.h"

extern const VlWide<64>/*2047:0*/ Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0;

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__8(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__8\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<64>/*2047:0*/ tb_npu_single_core__DOT__complex_desc;
    VL_ZERO_W(2048, tb_npu_single_core__DOT__complex_desc);
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__825__condition;
    __Vtask_tb_npu_single_core__DOT__check__825__condition = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__address;
    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__address = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index;
    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value;
    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address;
    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address = 0;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__acknowledge_task__827__command_id;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__827__command_id = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__acknowledge_task__827__result;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__827__result = 0;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__query_task__828__command_id;
    __Vtask_tb_npu_single_core__DOT__query_task__828__command_id = 0;
    CData/*2:0*/ __Vtask_tb_npu_single_core__DOT__query_task__828__selector;
    __Vtask_tb_npu_single_core__DOT__query_task__828__selector = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__query_task__828__result;
    __Vtask_tb_npu_single_core__DOT__query_task__828__result = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__829__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__829__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__829__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__829__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__829__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__829__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__830__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__830__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__830__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__830__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__830__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__831__condition;
    __Vtask_tb_npu_single_core__DOT__check__831__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__831__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__832__condition;
    __Vtask_tb_npu_single_core__DOT__check__832__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__832__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__833__condition;
    __Vtask_tb_npu_single_core__DOT__check__833__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__833__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__834__condition;
    __Vtask_tb_npu_single_core__DOT__check__834__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__834__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__835__condition;
    __Vtask_tb_npu_single_core__DOT__check__835__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__835__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__836__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__836__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__836__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__836__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__836__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__837__condition;
    __Vtask_tb_npu_single_core__DOT__check__837__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__837__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__838__condition;
    __Vtask_tb_npu_single_core__DOT__check__838__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__838__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__839__condition;
    __Vtask_tb_npu_single_core__DOT__check__839__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__839__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__840__condition;
    __Vtask_tb_npu_single_core__DOT__check__840__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__840__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__841__condition;
    __Vtask_tb_npu_single_core__DOT__check__841__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__841__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__842__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__842__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__842__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__842__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__842__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__843__condition;
    __Vtask_tb_npu_single_core__DOT__check__843__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__843__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__844__condition;
    __Vtask_tb_npu_single_core__DOT__check__844__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__844__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__845__condition;
    __Vtask_tb_npu_single_core__DOT__check__845__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__845__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__846__condition;
    __Vtask_tb_npu_single_core__DOT__check__846__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__846__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__847__condition;
    __Vtask_tb_npu_single_core__DOT__check__847__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__847__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__848__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__848__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__848__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__848__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__848__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__848__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__848__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__848__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__848__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__848__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__849__condition;
    __Vtask_tb_npu_single_core__DOT__check__849__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__849__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__850__condition;
    __Vtask_tb_npu_single_core__DOT__check__850__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__850__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__851__condition;
    __Vtask_tb_npu_single_core__DOT__check__851__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__851__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__852__condition;
    __Vtask_tb_npu_single_core__DOT__check__852__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__852__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__853__condition;
    __Vtask_tb_npu_single_core__DOT__check__853__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__853__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__854__condition;
    __Vtask_tb_npu_single_core__DOT__check__854__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__854__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__855__condition;
    __Vtask_tb_npu_single_core__DOT__check__855__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__855__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__856__condition;
    __Vtask_tb_npu_single_core__DOT__check__856__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__856__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__857__condition;
    __Vtask_tb_npu_single_core__DOT__check__857__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__857__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__858__condition;
    __Vtask_tb_npu_single_core__DOT__check__858__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__858__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__859__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__859__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__859__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__859__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__859__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__860__condition;
    __Vtask_tb_npu_single_core__DOT__check__860__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__860__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__861__condition;
    __Vtask_tb_npu_single_core__DOT__check__861__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__861__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__862__condition;
    __Vtask_tb_npu_single_core__DOT__check__862__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__862__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__863__condition;
    __Vtask_tb_npu_single_core__DOT__check__863__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__863__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__864__condition;
    __Vtask_tb_npu_single_core__DOT__check__864__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__864__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__865__condition;
    __Vtask_tb_npu_single_core__DOT__check__865__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__865__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__866__condition;
    __Vtask_tb_npu_single_core__DOT__check__866__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__866__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__query_task__867__command_id;
    __Vtask_tb_npu_single_core__DOT__query_task__867__command_id = 0;
    CData/*2:0*/ __Vtask_tb_npu_single_core__DOT__query_task__867__selector;
    __Vtask_tb_npu_single_core__DOT__query_task__867__selector = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__query_task__867__result;
    __Vtask_tb_npu_single_core__DOT__query_task__867__result = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__868__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__868__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__868__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__868__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__868__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__868__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__869__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__869__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__869__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__869__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__869__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__870__condition;
    __Vtask_tb_npu_single_core__DOT__check__870__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__870__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__871__condition;
    __Vtask_tb_npu_single_core__DOT__check__871__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__871__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__872__condition;
    __Vtask_tb_npu_single_core__DOT__check__872__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__872__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__873__condition;
    __Vtask_tb_npu_single_core__DOT__check__873__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__873__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__874__condition;
    __Vtask_tb_npu_single_core__DOT__check__874__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__874__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__875__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__875__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__875__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__875__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__875__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__876__condition;
    __Vtask_tb_npu_single_core__DOT__check__876__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__876__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__877__condition;
    __Vtask_tb_npu_single_core__DOT__check__877__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__877__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__878__condition;
    __Vtask_tb_npu_single_core__DOT__check__878__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__878__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__879__condition;
    __Vtask_tb_npu_single_core__DOT__check__879__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__879__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__880__condition;
    __Vtask_tb_npu_single_core__DOT__check__880__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__880__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__881__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__881__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__881__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__881__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__881__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__882__condition;
    __Vtask_tb_npu_single_core__DOT__check__882__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__882__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__883__condition;
    __Vtask_tb_npu_single_core__DOT__check__883__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__883__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__884__condition;
    __Vtask_tb_npu_single_core__DOT__check__884__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__884__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__885__condition;
    __Vtask_tb_npu_single_core__DOT__check__885__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__885__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__886__condition;
    __Vtask_tb_npu_single_core__DOT__check__886__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__886__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__887__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__887__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__887__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__887__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__887__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__887__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__887__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__887__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__887__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__887__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__888__condition;
    __Vtask_tb_npu_single_core__DOT__check__888__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__888__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__889__condition;
    __Vtask_tb_npu_single_core__DOT__check__889__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__889__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__890__condition;
    __Vtask_tb_npu_single_core__DOT__check__890__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__890__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__891__condition;
    __Vtask_tb_npu_single_core__DOT__check__891__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__891__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__892__condition;
    __Vtask_tb_npu_single_core__DOT__check__892__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__892__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__893__condition;
    __Vtask_tb_npu_single_core__DOT__check__893__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__893__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__894__condition;
    __Vtask_tb_npu_single_core__DOT__check__894__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__894__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__895__condition;
    __Vtask_tb_npu_single_core__DOT__check__895__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__895__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__896__condition;
    __Vtask_tb_npu_single_core__DOT__check__896__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__896__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__897__condition;
    __Vtask_tb_npu_single_core__DOT__check__897__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__897__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__898__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__898__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__898__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__898__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__898__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__899__condition;
    __Vtask_tb_npu_single_core__DOT__check__899__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__899__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__900__condition;
    __Vtask_tb_npu_single_core__DOT__check__900__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__900__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__901__condition;
    __Vtask_tb_npu_single_core__DOT__check__901__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__901__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__902__condition;
    __Vtask_tb_npu_single_core__DOT__check__902__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__902__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__903__condition;
    __Vtask_tb_npu_single_core__DOT__check__903__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__903__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__904__condition;
    __Vtask_tb_npu_single_core__DOT__check__904__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__904__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__905__condition;
    __Vtask_tb_npu_single_core__DOT__check__905__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__905__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__906__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__906__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__906__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__906__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__906__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__906__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__907__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__907__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__907__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__907__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__907__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__908__condition;
    __Vtask_tb_npu_single_core__DOT__check__908__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__908__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__909__condition;
    __Vtask_tb_npu_single_core__DOT__check__909__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__909__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__910__condition;
    __Vtask_tb_npu_single_core__DOT__check__910__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__910__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__911__condition;
    __Vtask_tb_npu_single_core__DOT__check__911__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__911__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__912__condition;
    __Vtask_tb_npu_single_core__DOT__check__912__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__912__message;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__init_common__913__engine;
    __Vtask_tb_npu_single_core__DOT__init_common__913__engine = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__init_common__913__bytes;
    __Vtask_tb_npu_single_core__DOT__init_common__913__bytes = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__913__src0;
    __Vtask_tb_npu_single_core__DOT__init_common__913__src0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__913__src1;
    __Vtask_tb_npu_single_core__DOT__init_common__913__src1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__913__src2;
    __Vtask_tb_npu_single_core__DOT__init_common__913__src2 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__913__dst;
    __Vtask_tb_npu_single_core__DOT__init_common__913__dst = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__init_common__913__numeric;
    __Vtask_tb_npu_single_core__DOT__init_common__913__numeric = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__916__offset;
    __Vtask_tb_npu_single_core__DOT__put_u16__916__offset = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__916__value;
    __Vtask_tb_npu_single_core__DOT__put_u16__916__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__921__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__921__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__921__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__921__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__922__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__922__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__922__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__922__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__923__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__923__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__923__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__923__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__924__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__924__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__924__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__924__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__925__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__925__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__925__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__925__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__926__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__926__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__926__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__926__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__927__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__927__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__927__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__927__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__928__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__928__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__928__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__928__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__929__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__929__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__929__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__929__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__930__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__930__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__930__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__930__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__931__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__931__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__931__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__931__value = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__932__address;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__932__address = 0;
    VlWide<64>/*2047:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__932__desc;
    VL_ZERO_W(2048, __Vtask_tb_npu_single_core__DOT__store_descriptor__932__desc);
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__932__bytes;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__932__bytes = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__address;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__address = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__value;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__value = 0;
    // Body
    __Vtask_tb_npu_single_core__DOT__check__825__condition 
        = (0x8877665544332211ULL == ([&]() {
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__address = 0x3100ULL;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index = 0;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value = 0;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address = 0;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value = 0ULL;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index = 0U;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                    = __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__address;
                if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)) {
                    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value 
                        = ((0xffffffffffffff00ULL & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value) 
                           | (IData)((IData)((0xffU 
                                              & (IData)(
                                                        (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                         [
                                                         (0x7ffU 
                                                          & (IData)(
                                                                    (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                                                                     >> 3U)))] 
                                                         >> 
                                                         (0x3fU 
                                                          & VL_SHIFTL_III(6,32,32, 
                                                                          (7U 
                                                                           & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)), 3U))))))));
                }
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index = 1U;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                    = (1ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__address);
                if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)) {
                    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value 
                        = ((0xffffffffffff00ffULL & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value) 
                           | ((QData)((IData)((0xffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                          [
                                                          (0x7ffU 
                                                           & (IData)(
                                                                     (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                                                                      >> 3U)))] 
                                                          >> 
                                                          (0x3fU 
                                                           & VL_SHIFTL_III(6,32,32, 
                                                                           (7U 
                                                                            & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)), 3U))))))) 
                              << 8U));
                }
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index = 2U;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                    = (2ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__address);
                if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)) {
                    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value 
                        = ((0xffffffffff00ffffULL & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value) 
                           | ((QData)((IData)((0xffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                          [
                                                          (0x7ffU 
                                                           & (IData)(
                                                                     (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                                                                      >> 3U)))] 
                                                          >> 
                                                          (0x3fU 
                                                           & VL_SHIFTL_III(6,32,32, 
                                                                           (7U 
                                                                            & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)), 3U))))))) 
                              << 0x10U));
                }
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index = 3U;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                    = (3ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__address);
                if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)) {
                    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value 
                        = ((0xffffffff00ffffffULL & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value) 
                           | ((QData)((IData)((0xffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                          [
                                                          (0x7ffU 
                                                           & (IData)(
                                                                     (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                                                                      >> 3U)))] 
                                                          >> 
                                                          (0x3fU 
                                                           & VL_SHIFTL_III(6,32,32, 
                                                                           (7U 
                                                                            & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)), 3U))))))) 
                              << 0x18U));
                }
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index = 4U;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                    = (4ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__address);
                if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)) {
                    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value 
                        = ((0xffffff00ffffffffULL & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value) 
                           | ((QData)((IData)((0xffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                          [
                                                          (0x7ffU 
                                                           & (IData)(
                                                                     (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                                                                      >> 3U)))] 
                                                          >> 
                                                          (0x3fU 
                                                           & VL_SHIFTL_III(6,32,32, 
                                                                           (7U 
                                                                            & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)), 3U))))))) 
                              << 0x20U));
                }
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index = 5U;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                    = (5ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__address);
                if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)) {
                    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value 
                        = ((0xffff00ffffffffffULL & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value) 
                           | ((QData)((IData)((0xffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                          [
                                                          (0x7ffU 
                                                           & (IData)(
                                                                     (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                                                                      >> 3U)))] 
                                                          >> 
                                                          (0x3fU 
                                                           & VL_SHIFTL_III(6,32,32, 
                                                                           (7U 
                                                                            & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)), 3U))))))) 
                              << 0x28U));
                }
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index = 6U;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                    = (6ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__address);
                if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)) {
                    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value 
                        = ((0xff00ffffffffffffULL & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value) 
                           | ((QData)((IData)((0xffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                          [
                                                          (0x7ffU 
                                                           & (IData)(
                                                                     (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                                                                      >> 3U)))] 
                                                          >> 
                                                          (0x3fU 
                                                           & VL_SHIFTL_III(6,32,32, 
                                                                           (7U 
                                                                            & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)), 3U))))))) 
                              << 0x30U));
                }
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index = 7U;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                    = (7ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__address);
                if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)) {
                    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value 
                        = ((0xffffffffffffffULL & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value) 
                           | ((QData)((IData)((0xffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                          [
                                                          (0x7ffU 
                                                           & (IData)(
                                                                     (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address 
                                                                      >> 3U)))] 
                                                          >> 
                                                          (0x3fU 
                                                           & VL_SHIFTL_III(6,32,32, 
                                                                           (7U 
                                                                            & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__byte_address)), 3U))))))) 
                              << 0x38U));
                }
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__unnamedblk3__DOT__index = 8U;
                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__Vfuncout 
                    = __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__value;
            }(), __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__826__Vfuncout));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__825__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__825__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__827__command_id = 0x109U;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__827__result = 0;
    __Vtask_tb_npu_single_core__DOT__query_task__828__selector = 4U;
    __Vtask_tb_npu_single_core__DOT__query_task__828__command_id 
        = __Vtask_tb_npu_single_core__DOT__acknowledge_task__827__command_id;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__argument1 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__828__selector));
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__argument0 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__828__command_id));
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__operation = 2U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__829__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__830__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__830__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__830__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__830__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__831__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__831__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__831__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__831__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__832__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__832__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__830__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__832__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__832__message));
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
    __Vtask_tb_npu_single_core__DOT__check__833__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__833__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__833__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__833__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__834__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__834__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__834__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__834__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__835__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__835__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__835__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__835__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__829__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__836__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__836__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__836__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__836__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__837__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__837__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__837__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__837__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__838__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__838__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__836__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__838__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__838__message));
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
    __Vtask_tb_npu_single_core__DOT__check__839__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__839__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__839__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__839__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__840__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__840__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__840__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__840__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__841__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__841__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__841__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__841__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__829__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__842__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__842__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__842__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__842__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__843__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__843__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__843__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__843__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__844__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__844__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__842__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__844__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__844__message));
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
    __Vtask_tb_npu_single_core__DOT__check__845__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__845__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__845__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__845__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__846__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__846__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__846__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__846__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__847__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__847__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__847__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__847__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__829__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__848__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__848__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__848__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__848__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__848__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__848__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__848__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__848__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__848__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__848__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__849__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__849__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__849__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__849__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__850__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__850__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__848__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__848__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__850__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__850__message));
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
            __Vtask_tb_npu_single_core__DOT__check__851__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__851__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__851__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__851__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__852__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__852__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__852__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__852__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__853__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__853__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__853__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__853__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__854__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__854__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__854__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__854__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__848__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__829__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__848__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__829__status 
                               >> 1U)))) {
                goto __Vlabel0;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__829__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__829__poll_count);
        }
        __Vlabel0: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__855__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__855__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__829__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__855__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__855__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__856__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__856__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__829__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__856__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__856__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__857__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__857__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__829__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__857__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__857__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__858__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__858__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__829__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__858__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__858__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__859__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__860__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__860__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__860__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__860__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__861__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__861__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__859__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__859__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__861__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__861__message));
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
    __Vtask_tb_npu_single_core__DOT__check__862__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__862__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__862__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__862__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__863__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__863__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__863__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__863__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__864__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__864__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__864__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__864__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__865__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__865__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__865__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__865__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__859__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__829__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__859__data;
    __Vtask_tb_npu_single_core__DOT__query_task__828__result 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__829__result;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__827__result 
        = __Vtask_tb_npu_single_core__DOT__query_task__828__result;
    __Vtask_tb_npu_single_core__DOT__check__866__message = 
        std::string{"task ACK failed"};
    __Vtask_tb_npu_single_core__DOT__check__866__condition 
        = (0ULL == __Vtask_tb_npu_single_core__DOT__acknowledge_task__827__result);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__866__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__866__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__query_task__867__selector = 0U;
    __Vtask_tb_npu_single_core__DOT__query_task__867__command_id = 0x109U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__argument1 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__867__selector));
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__argument0 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__867__command_id));
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__operation = 2U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__868__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__869__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__869__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__869__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__869__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__870__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__870__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__870__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__870__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__871__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__871__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__869__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__871__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__871__message));
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
    __Vtask_tb_npu_single_core__DOT__check__872__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__872__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__872__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__872__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__873__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__873__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__873__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__873__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__874__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__874__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__874__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__874__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__868__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__875__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__875__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__875__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__875__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__876__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__876__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__876__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__876__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__877__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__877__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__875__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__877__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__877__message));
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
    __Vtask_tb_npu_single_core__DOT__check__878__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__878__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__878__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__878__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__879__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__879__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__879__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__879__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__880__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__880__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__880__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__880__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__868__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__881__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__881__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__881__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__881__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__882__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__882__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__882__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__882__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__883__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__883__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__881__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__883__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__883__message));
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
    __Vtask_tb_npu_single_core__DOT__check__884__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__884__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__884__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__884__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__885__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__885__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__885__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__885__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__886__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__886__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__886__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__886__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__868__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__887__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__887__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__887__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__887__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__887__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__887__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__887__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__887__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__887__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__887__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__888__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__888__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__888__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__888__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__889__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__889__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__887__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__887__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__889__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__889__message));
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
            __Vtask_tb_npu_single_core__DOT__check__890__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__890__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__890__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__890__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__891__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__891__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__891__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__891__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__892__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__892__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__892__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__892__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__893__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__893__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__893__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__893__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__887__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__868__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__887__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__868__status 
                               >> 1U)))) {
                goto __Vlabel1;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__868__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__868__poll_count);
        }
        __Vlabel1: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__894__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__894__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__868__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__894__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__894__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__895__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__895__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__868__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__895__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__895__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__896__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__896__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__868__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__896__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__896__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__897__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__897__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__868__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__897__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__897__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__898__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__899__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__899__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__899__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__899__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__900__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__900__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__898__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__898__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__900__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__900__message));
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
    __Vtask_tb_npu_single_core__DOT__check__901__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__901__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__901__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__901__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__902__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__902__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__902__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__902__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__903__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__903__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__903__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__903__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__904__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__904__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__904__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__904__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__898__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__868__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__898__data;
    __Vtask_tb_npu_single_core__DOT__query_task__867__result 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__868__result;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = __Vtask_tb_npu_single_core__DOT__query_task__867__result;
    __Vtask_tb_npu_single_core__DOT__check__905__message = 
        std::string{"L1-to-system DMA ACK did not release its task slot"};
    __Vtask_tb_npu_single_core__DOT__check__905__condition 
        = (IData)((0x810ULL == (0xfffULL & vlSelfRef.tb_npu_single_core__DOT__ctl_data)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__905__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__905__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.tb_npu_single_core__DOT__system_dma_write_check_q = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__906__strobe = 0xfU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__906__data = 0x400fffcULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__906__address = 0x700U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__906__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__906__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__906__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__907__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__907__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__907__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__907__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__908__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__908__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__908__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__908__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__909__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__909__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__907__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__909__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__909__message));
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
    __Vtask_tb_npu_single_core__DOT__check__910__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__910__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__910__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__910__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__911__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__911__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__911__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__911__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__912__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__912__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__912__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__912__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__init_common__913__numeric = 0x13055U;
    __Vtask_tb_npu_single_core__DOT__init_common__913__dst = 0x800ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__913__src2 = 0ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__913__src1 = 0ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__913__src0 = 0x700ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__913__bytes = 0x100U;
    __Vtask_tb_npu_single_core__DOT__init_common__913__engine = 4U;
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        tb_npu_single_core__DOT__complex_desc[__Vilp1] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, tb_npu_single_core__DOT__complex_desc, 0U, 1U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, tb_npu_single_core__DOT__complex_desc, 1U, (IData)(__Vtask_tb_npu_single_core__DOT__init_common__913__engine));
    __Vtask_tb_npu_single_core__DOT__put_u16__916__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__913__bytes;
    __Vtask_tb_npu_single_core__DOT__put_u16__916__offset = 2U;
    VL_ASSIGNSEL_WI(2048, 16, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u16__916__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u16__916__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__complex_desc, 8U, __Vtask_tb_npu_single_core__DOT__init_common__913__src0);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__complex_desc, 0x10U, __Vtask_tb_npu_single_core__DOT__init_common__913__src1);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__complex_desc, 0x18U, __Vtask_tb_npu_single_core__DOT__init_common__913__src2);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__complex_desc, 0x20U, __Vtask_tb_npu_single_core__DOT__init_common__913__dst);
    __Vtask_tb_npu_single_core__DOT__put_u32__921__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__913__numeric;
    __Vtask_tb_npu_single_core__DOT__put_u32__921__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__921__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u32__921__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__922__value = 1U;
    __Vtask_tb_npu_single_core__DOT__put_u32__922__offset = 0x40U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__922__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u32__922__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__923__value = 4U;
    __Vtask_tb_npu_single_core__DOT__put_u32__923__offset = 0x44U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__923__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u32__923__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__924__value = 4U;
    __Vtask_tb_npu_single_core__DOT__put_u32__924__offset = 0x48U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__924__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u32__924__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__925__value = 1U;
    __Vtask_tb_npu_single_core__DOT__put_u32__925__offset = 0x4cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__925__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u32__925__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__926__value = 4U;
    __Vtask_tb_npu_single_core__DOT__put_u32__926__offset = 0x50U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__926__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u32__926__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__927__value = 4U;
    __Vtask_tb_npu_single_core__DOT__put_u32__927__offset = 0x5cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__927__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u32__927__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__928__value = 0x3f800000U;
    __Vtask_tb_npu_single_core__DOT__put_u32__928__offset = 0x70U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__928__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u32__928__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__929__value = 0x3f800000U;
    __Vtask_tb_npu_single_core__DOT__put_u32__929__offset = 0x74U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__929__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u32__929__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__930__value = 0x3f800000U;
    __Vtask_tb_npu_single_core__DOT__put_u32__930__offset = 0x78U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__930__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u32__930__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__931__value = 0x3f800000U;
    __Vtask_tb_npu_single_core__DOT__put_u32__931__offset = 0x7cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__931__offset), 3U)), tb_npu_single_core__DOT__complex_desc, __Vtask_tb_npu_single_core__DOT__put_u32__931__value);
    __Vtask_tb_npu_single_core__DOT__store_descriptor__932__bytes = 0x100U;
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x3fU)) {
        __Vtask_tb_npu_single_core__DOT__store_descriptor__932__desc[__Vilp2] 
            = tb_npu_single_core__DOT__complex_desc[__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    __Vtask_tb_npu_single_core__DOT__store_descriptor__932__address = 0x1300ULL;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index = 0;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index 
            < __Vtask_tb_npu_single_core__DOT__store_descriptor__932__bytes)) {
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__value 
            = (0xffU & (((0U == (0x1fU & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index, 3U)))
                          ? 0U : (__Vtask_tb_npu_single_core__DOT__store_descriptor__932__desc[
                                  (((IData)(7U) + (0x7ffU 
                                                   & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index, 3U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index, 3U))))) 
                        | (__Vtask_tb_npu_single_core__DOT__store_descriptor__932__desc[
                           (0x3fU & (VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index, 3U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index, 3U)))));
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__address 
            = (__Vtask_tb_npu_single_core__DOT__store_descriptor__932__address 
               + (QData)((IData)(__Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index)));
        if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__address)))) {
            VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__address);
            VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
        }
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                      & (IData)(
                                                                                (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__address 
                                                                                >> 3U)))] 
            = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                      (7U 
                                                       & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__address)), 3U)))) 
                & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__address 
                                    >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__value)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, 
                                                                   (7U 
                                                                    & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__933__address)), 3U))));
        __Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__store_descriptor__932__unnamedblk1__DOT__index);
    }
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[0U] = 0x1a0080U;
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[1U] = 0x80U;
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[2U] = 0x70U;
}

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__9(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__9\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__compact_opcode;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command_id;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__dtype;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__payload;
    VL_ZERO_W(80, __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__payload);
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__wait0;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__wait0 = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__wait1;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__wait1 = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__signal_event;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__signal_event = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command);
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__command_count;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__command_count = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__unnamedblk3__DOT__word_index;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__observed_response = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__beat_count;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__beat_count = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__936__condition;
    __Vtask_tb_npu_single_core__DOT__check__936__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__936__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__937__condition;
    __Vtask_tb_npu_single_core__DOT__check__937__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__937__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__938__condition;
    __Vtask_tb_npu_single_core__DOT__check__938__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__938__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__939__expected_command_id;
    __Vtask_tb_npu_single_core__DOT__read_command_response__939__expected_command_id = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__939__expected_status;
    __Vtask_tb_npu_single_core__DOT__read_command_response__939__expected_status = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__939__response;
    __Vtask_tb_npu_single_core__DOT__read_command_response__939__response = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__940__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__940__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__940__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__940__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__940__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__941__condition;
    __Vtask_tb_npu_single_core__DOT__check__941__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__941__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__942__condition;
    __Vtask_tb_npu_single_core__DOT__check__942__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__942__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__943__condition;
    __Vtask_tb_npu_single_core__DOT__check__943__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__943__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__944__condition;
    __Vtask_tb_npu_single_core__DOT__check__944__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__944__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__945__condition;
    __Vtask_tb_npu_single_core__DOT__check__945__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__945__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__946__condition;
    __Vtask_tb_npu_single_core__DOT__check__946__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__946__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__947__condition;
    __Vtask_tb_npu_single_core__DOT__check__947__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__947__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__948__condition;
    __Vtask_tb_npu_single_core__DOT__check__948__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__948__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__949__condition;
    __Vtask_tb_npu_single_core__DOT__check__949__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__949__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__950__condition;
    __Vtask_tb_npu_single_core__DOT__check__950__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__950__message;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__951__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__951__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__951__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__951__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__951__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__951__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__952__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__952__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__952__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__952__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__952__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__953__condition;
    __Vtask_tb_npu_single_core__DOT__check__953__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__953__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__954__condition;
    __Vtask_tb_npu_single_core__DOT__check__954__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__954__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__955__condition;
    __Vtask_tb_npu_single_core__DOT__check__955__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__955__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__956__condition;
    __Vtask_tb_npu_single_core__DOT__check__956__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__956__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__957__condition;
    __Vtask_tb_npu_single_core__DOT__check__957__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__957__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__958__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__958__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__958__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__958__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__958__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__959__condition;
    __Vtask_tb_npu_single_core__DOT__check__959__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__959__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__960__condition;
    __Vtask_tb_npu_single_core__DOT__check__960__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__960__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__961__condition;
    __Vtask_tb_npu_single_core__DOT__check__961__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__961__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__962__condition;
    __Vtask_tb_npu_single_core__DOT__check__962__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__962__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__963__condition;
    __Vtask_tb_npu_single_core__DOT__check__963__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__963__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__964__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__964__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__964__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__964__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__964__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__965__condition;
    __Vtask_tb_npu_single_core__DOT__check__965__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__965__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__966__condition;
    __Vtask_tb_npu_single_core__DOT__check__966__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__966__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__967__condition;
    __Vtask_tb_npu_single_core__DOT__check__967__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__967__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__968__condition;
    __Vtask_tb_npu_single_core__DOT__check__968__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__968__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__969__condition;
    __Vtask_tb_npu_single_core__DOT__check__969__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__969__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__970__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__970__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__970__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__970__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__970__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__970__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__970__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__970__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__970__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__970__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__971__condition;
    __Vtask_tb_npu_single_core__DOT__check__971__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__971__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__972__condition;
    __Vtask_tb_npu_single_core__DOT__check__972__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__972__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__973__condition;
    __Vtask_tb_npu_single_core__DOT__check__973__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__973__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__974__condition;
    __Vtask_tb_npu_single_core__DOT__check__974__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__974__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__975__condition;
    __Vtask_tb_npu_single_core__DOT__check__975__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__975__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__976__condition;
    __Vtask_tb_npu_single_core__DOT__check__976__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__976__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__977__condition;
    __Vtask_tb_npu_single_core__DOT__check__977__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__977__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__978__condition;
    __Vtask_tb_npu_single_core__DOT__check__978__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__978__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__979__condition;
    __Vtask_tb_npu_single_core__DOT__check__979__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__979__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__980__condition;
    __Vtask_tb_npu_single_core__DOT__check__980__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__980__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__981__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__981__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__981__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__981__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__981__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__982__condition;
    __Vtask_tb_npu_single_core__DOT__check__982__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__982__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__983__condition;
    __Vtask_tb_npu_single_core__DOT__check__983__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__983__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__984__condition;
    __Vtask_tb_npu_single_core__DOT__check__984__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__984__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__985__condition;
    __Vtask_tb_npu_single_core__DOT__check__985__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__985__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__986__condition;
    __Vtask_tb_npu_single_core__DOT__check__986__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__986__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__987__condition;
    __Vtask_tb_npu_single_core__DOT__check__987__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__987__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__988__condition;
    __Vtask_tb_npu_single_core__DOT__check__988__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__988__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__query_task__989__command_id;
    __Vtask_tb_npu_single_core__DOT__query_task__989__command_id = 0;
    CData/*2:0*/ __Vtask_tb_npu_single_core__DOT__query_task__989__selector;
    __Vtask_tb_npu_single_core__DOT__query_task__989__selector = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__query_task__989__result;
    __Vtask_tb_npu_single_core__DOT__query_task__989__result = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__990__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__990__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__990__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__990__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__990__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__990__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__991__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__991__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__991__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__991__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__991__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__992__condition;
    __Vtask_tb_npu_single_core__DOT__check__992__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__992__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__993__condition;
    __Vtask_tb_npu_single_core__DOT__check__993__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__993__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__994__condition;
    __Vtask_tb_npu_single_core__DOT__check__994__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__994__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__995__condition;
    __Vtask_tb_npu_single_core__DOT__check__995__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__995__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__996__condition;
    __Vtask_tb_npu_single_core__DOT__check__996__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__996__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__997__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__997__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__997__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__997__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__997__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__998__condition;
    __Vtask_tb_npu_single_core__DOT__check__998__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__998__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__999__condition;
    __Vtask_tb_npu_single_core__DOT__check__999__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__999__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1000__condition;
    __Vtask_tb_npu_single_core__DOT__check__1000__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1000__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1001__condition;
    __Vtask_tb_npu_single_core__DOT__check__1001__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1001__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1002__condition;
    __Vtask_tb_npu_single_core__DOT__check__1002__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1002__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1004__condition;
    __Vtask_tb_npu_single_core__DOT__check__1004__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1004__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1005__condition;
    __Vtask_tb_npu_single_core__DOT__check__1005__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1005__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1006__condition;
    __Vtask_tb_npu_single_core__DOT__check__1006__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1006__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1007__condition;
    __Vtask_tb_npu_single_core__DOT__check__1007__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1007__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1008__condition;
    __Vtask_tb_npu_single_core__DOT__check__1008__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1008__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1010__condition;
    __Vtask_tb_npu_single_core__DOT__check__1010__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1010__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1011__condition;
    __Vtask_tb_npu_single_core__DOT__check__1011__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1011__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1012__condition;
    __Vtask_tb_npu_single_core__DOT__check__1012__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1012__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1013__condition;
    __Vtask_tb_npu_single_core__DOT__check__1013__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1013__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1014__condition;
    __Vtask_tb_npu_single_core__DOT__check__1014__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1014__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1015__condition;
    __Vtask_tb_npu_single_core__DOT__check__1015__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1015__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1016__condition;
    __Vtask_tb_npu_single_core__DOT__check__1016__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1016__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1017__condition;
    __Vtask_tb_npu_single_core__DOT__check__1017__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1017__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1018__condition;
    __Vtask_tb_npu_single_core__DOT__check__1018__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1018__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1019__condition;
    __Vtask_tb_npu_single_core__DOT__check__1019__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1019__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1021__condition;
    __Vtask_tb_npu_single_core__DOT__check__1021__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1021__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1022__condition;
    __Vtask_tb_npu_single_core__DOT__check__1022__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1022__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1023__condition;
    __Vtask_tb_npu_single_core__DOT__check__1023__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1023__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1024__condition;
    __Vtask_tb_npu_single_core__DOT__check__1024__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1024__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1025__condition;
    __Vtask_tb_npu_single_core__DOT__check__1025__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1025__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1026__condition;
    __Vtask_tb_npu_single_core__DOT__check__1026__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1026__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1027__condition;
    __Vtask_tb_npu_single_core__DOT__check__1027__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1027__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_read_word__1028__address;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1028__address = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1029__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1029__address = 0;
    // Body
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__signal_event = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__wait1 = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__wait0 = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__payload[0U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__payload[1U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__payload[2U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[2U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__dtype = 1U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command_id = 0x104U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__compact_opcode = 0x19U;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command);
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[0U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[1U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[2U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[3U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[3U] 
        = ((0xffU & __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[3U]) 
           | (0xffffff00U & (0x80000000U | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__934__compact_opcode) 
                                             << 0x1aU) 
                                            | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command_id) 
                                                << 0x10U) 
                                               | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__934__wait0) 
                                                  << 8U))))));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[2U] 
        = ((0xffffffU & __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[2U]) 
           | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__934__signal_event) 
              << 0x18U));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[3U] 
        = ((0xffffff00U & __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[3U]) 
           | (0xffffffU & ((0xffffffU & (IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__934__wait1)) 
                           | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__934__signal_event) 
                              >> 8U))));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__payload[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__payload[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[2U]) 
           | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__934__dtype) 
               << 0x10U) | __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__payload[2U]));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__Vfuncout[0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__Vfuncout[1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__Vfuncout[2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[2U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__Vfuncout[3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__command[3U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__Vfuncout[0U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__Vfuncout[1U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__Vfuncout[2U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__934__Vfuncout[3U];
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__command_count = 1U;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__observed_response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__beat_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__beat_count 
        = VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__command_count, 1U);
    __Vtask_tb_npu_single_core__DOT__check__936__message = 
        std::string{"invalid command burst count"};
    __Vtask_tb_npu_single_core__DOT__check__936__condition 
        = ((1U <= __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__command_count) 
           & (8U >= __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__command_count));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__936__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__936__message));
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
        = (0xffU & (__Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__beat_count 
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
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index 
            < __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__command_count)) {
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0U;
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             647);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
            = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index)][1U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                            [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index)][0U])));
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i = 0xffU;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i 
            = (((IData)(1U) + VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index, 1U)) 
               == __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__beat_count);
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
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 1U;
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             647);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
            = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index)][3U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                            [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index)][2U])));
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i = 0xffU;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i 
            = (((IData)(2U) + VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index, 1U)) 
               == __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__beat_count);
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
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 2U;
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__unnamedblk2__DOT__command_index);
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
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         662);
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         662);
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__937__message = 
        std::string{"command burst response was not held"};
    __Vtask_tb_npu_single_core__DOT__check__937__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_submit_commands__935__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__937__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__937__message));
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
    __Vtask_tb_npu_single_core__DOT__check__938__message = 
        std::string{"FIXED command burst failed"};
    __Vtask_tb_npu_single_core__DOT__check__938__condition 
        = ((0x63U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q)) 
           & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__938__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__938__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         670);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__939__expected_status = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__939__expected_command_id = 0x104U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__939__response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__address = 0x20008U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__940__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__941__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__941__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__941__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__941__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__942__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__942__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__940__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__940__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__942__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__942__message));
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
    __Vtask_tb_npu_single_core__DOT__check__943__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__943__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__943__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__943__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__944__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__944__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__944__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__944__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__945__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__945__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__945__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__945__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__946__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__946__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__946__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__946__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__940__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__939__response 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__940__data;
    __Vtask_tb_npu_single_core__DOT__check__947__message = 
        std::string{"CFE response returned the wrong command_id"};
    __Vtask_tb_npu_single_core__DOT__check__947__condition 
        = ((0xfffU & (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__939__response)) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__939__expected_command_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__947__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__947__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__948__message = 
        std::string{"CFE response returned the wrong status"};
    __Vtask_tb_npu_single_core__DOT__check__948__condition 
        = ((0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__939__response 
                             >> 0xcU))) == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__939__expected_status));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__948__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__948__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__949__message = 
        std::string{"CFE response fifo_free_entries exceeds the configured depth"};
    __Vtask_tb_npu_single_core__DOT__check__949__condition 
        = (8U >= (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__939__response 
                                   >> 0x14U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__949__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__949__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__950__message = 
        std::string{"CFE response reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__950__condition 
        = (0ULL == (__Vtask_tb_npu_single_core__DOT__read_command_response__939__response 
                    >> 0x1cU));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__950__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__950__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__argument1 = 0xc350ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__argument0 = 8ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__operation = 3U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__951__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__952__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__952__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__952__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__952__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__953__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__953__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__953__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__953__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__954__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__954__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__952__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__954__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__954__message));
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
    __Vtask_tb_npu_single_core__DOT__check__955__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__955__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__955__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__955__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__956__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__956__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__956__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__956__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__957__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__957__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__957__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__957__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__951__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__958__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__958__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__958__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__958__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__959__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__959__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__959__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__959__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__960__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__960__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__958__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__960__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__960__message));
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
    __Vtask_tb_npu_single_core__DOT__check__961__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__961__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__961__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__961__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__962__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__962__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__962__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__962__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__963__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__963__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__963__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__963__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__951__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__964__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__964__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__964__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__964__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__965__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__965__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__965__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__965__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__966__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__966__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__964__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__966__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__966__message));
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
    __Vtask_tb_npu_single_core__DOT__check__967__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__967__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__967__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__967__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__968__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__968__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__968__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__968__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__969__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__969__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__969__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__969__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__951__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__970__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__970__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__970__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__970__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__970__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__970__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__970__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__970__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__970__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__970__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__971__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__971__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__971__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__971__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__972__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__972__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__970__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__970__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__972__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__972__message));
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
            __Vtask_tb_npu_single_core__DOT__check__973__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__973__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__973__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__973__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__974__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__974__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__974__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__974__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__975__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__975__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__975__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__975__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__976__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__976__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__976__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__976__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__970__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__951__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__970__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__951__status 
                               >> 1U)))) {
                goto __Vlabel0;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__951__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__951__poll_count);
        }
        __Vlabel0: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__977__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__977__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__951__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__977__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__977__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__978__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__978__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__951__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__978__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__978__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__979__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__979__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__951__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__979__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__979__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__980__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__980__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__951__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__980__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__980__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__981__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__982__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__982__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__982__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__982__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__983__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__983__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__981__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__981__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__983__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__983__message));
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
    __Vtask_tb_npu_single_core__DOT__check__984__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__984__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__984__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__984__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__985__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__985__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__985__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__985__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__986__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__986__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__986__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__986__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__987__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__987__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__987__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__987__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__981__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__951__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__981__data;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = __Vtask_tb_npu_single_core__DOT__ctl_request__951__result;
    __Vtask_tb_npu_single_core__DOT__check__988__message = 
        std::string{"Complex FENCE returned a failure"};
    __Vtask_tb_npu_single_core__DOT__check__988__condition 
        = (0U == (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__ctl_data)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__988__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__988__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__query_task__989__selector = 3U;
    __Vtask_tb_npu_single_core__DOT__query_task__989__command_id = 0x104U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__argument1 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__989__selector));
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__argument0 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__989__command_id));
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__operation = 2U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__990__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__991__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__991__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__991__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__991__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__992__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__992__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__992__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__992__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__993__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__993__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__991__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__993__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__993__message));
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
    __Vtask_tb_npu_single_core__DOT__check__994__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__994__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__994__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__994__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__995__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__995__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__995__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__995__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__996__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__996__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__996__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__996__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__990__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__997__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__997__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__997__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__997__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__998__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__998__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__998__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__998__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__999__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__999__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__997__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__999__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__999__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1000__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1000__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1000__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1000__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1001__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1001__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1001__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1001__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1002__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1002__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1002__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1002__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__990__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1003__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1004__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1004__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1004__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1004__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1005__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1005__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1003__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1005__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1005__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1006__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1006__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1006__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1006__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1007__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1007__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1007__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1007__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1008__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1008__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1008__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1008__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__990__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__1010__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1010__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1010__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1010__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1011__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1011__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1009__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1011__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1011__message));
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
            __Vtask_tb_npu_single_core__DOT__check__1012__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__1012__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1012__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1012__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1013__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__1013__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1013__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1013__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1014__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__1014__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1014__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1014__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1015__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__1015__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1015__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1015__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__990__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1009__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__990__status 
                               >> 1U)))) {
                goto __Vlabel1;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__990__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__990__poll_count);
        }
        __Vlabel1: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__1016__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__1016__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__990__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1016__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1016__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1017__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__1017__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__990__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1017__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1017__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1018__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__1018__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__990__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1018__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1018__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1019__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__1019__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__990__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1019__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1019__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1021__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1021__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1021__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1021__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1022__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1022__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1020__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1022__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1022__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1023__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1023__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1023__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1023__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1024__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1024__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1024__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1024__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1025__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1025__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1025__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1025__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1026__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1026__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1026__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1026__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__990__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1020__data;
    __Vtask_tb_npu_single_core__DOT__query_task__989__result 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__990__result;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = __Vtask_tb_npu_single_core__DOT__query_task__989__result;
    __Vtask_tb_npu_single_core__DOT__check__1027__message = 
        std::string{"Complex progress is not four outputs"};
    __Vtask_tb_npu_single_core__DOT__check__1027__condition 
        = (4ULL == vlSelfRef.tb_npu_single_core__DOT__ctl_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1027__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1027__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1028__address = 0x800U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1029__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_read_word__1028__address));
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1029__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15543176584279282921ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1029__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 280692285995097203ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1029__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8249901906508452967ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1029__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
}
