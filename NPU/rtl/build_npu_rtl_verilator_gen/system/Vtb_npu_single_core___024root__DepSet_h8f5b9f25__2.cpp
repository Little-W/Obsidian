// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core__Syms.h"
#include "Vtb_npu_single_core___024root.h"

extern const VlWide<64>/*2047:0*/ Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0;

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__4(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__4\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_npu_single_core__DOT__unnamedblk4__DOT__desc_reads_after_dependency;
    tb_npu_single_core__DOT__unnamedblk4__DOT__desc_reads_after_dependency = 0;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__acknowledge_task__417__command_id;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__417__command_id = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__acknowledge_task__417__result;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__417__result = 0;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__query_task__418__command_id;
    __Vtask_tb_npu_single_core__DOT__query_task__418__command_id = 0;
    CData/*2:0*/ __Vtask_tb_npu_single_core__DOT__query_task__418__selector;
    __Vtask_tb_npu_single_core__DOT__query_task__418__selector = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__query_task__418__result;
    __Vtask_tb_npu_single_core__DOT__query_task__418__result = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__419__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__419__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__419__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__419__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__419__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__419__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__420__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__420__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__420__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__420__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__420__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__421__condition;
    __Vtask_tb_npu_single_core__DOT__check__421__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__421__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__422__condition;
    __Vtask_tb_npu_single_core__DOT__check__422__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__422__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__423__condition;
    __Vtask_tb_npu_single_core__DOT__check__423__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__423__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__424__condition;
    __Vtask_tb_npu_single_core__DOT__check__424__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__424__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__425__condition;
    __Vtask_tb_npu_single_core__DOT__check__425__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__425__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__426__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__426__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__426__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__426__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__426__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__427__condition;
    __Vtask_tb_npu_single_core__DOT__check__427__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__427__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__428__condition;
    __Vtask_tb_npu_single_core__DOT__check__428__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__428__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__429__condition;
    __Vtask_tb_npu_single_core__DOT__check__429__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__429__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__430__condition;
    __Vtask_tb_npu_single_core__DOT__check__430__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__430__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__431__condition;
    __Vtask_tb_npu_single_core__DOT__check__431__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__431__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__432__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__432__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__432__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__432__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__432__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__433__condition;
    __Vtask_tb_npu_single_core__DOT__check__433__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__433__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__434__condition;
    __Vtask_tb_npu_single_core__DOT__check__434__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__434__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__435__condition;
    __Vtask_tb_npu_single_core__DOT__check__435__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__435__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__436__condition;
    __Vtask_tb_npu_single_core__DOT__check__436__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__436__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__437__condition;
    __Vtask_tb_npu_single_core__DOT__check__437__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__437__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__438__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__438__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__438__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__438__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__438__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__438__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__438__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__438__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__438__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__438__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__439__condition;
    __Vtask_tb_npu_single_core__DOT__check__439__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__439__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__440__condition;
    __Vtask_tb_npu_single_core__DOT__check__440__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__440__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__441__condition;
    __Vtask_tb_npu_single_core__DOT__check__441__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__441__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__442__condition;
    __Vtask_tb_npu_single_core__DOT__check__442__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__442__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__443__condition;
    __Vtask_tb_npu_single_core__DOT__check__443__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__443__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__444__condition;
    __Vtask_tb_npu_single_core__DOT__check__444__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__444__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__445__condition;
    __Vtask_tb_npu_single_core__DOT__check__445__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__445__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__446__condition;
    __Vtask_tb_npu_single_core__DOT__check__446__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__446__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__447__condition;
    __Vtask_tb_npu_single_core__DOT__check__447__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__447__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__448__condition;
    __Vtask_tb_npu_single_core__DOT__check__448__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__448__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__449__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__449__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__449__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__449__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__449__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__450__condition;
    __Vtask_tb_npu_single_core__DOT__check__450__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__450__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__451__condition;
    __Vtask_tb_npu_single_core__DOT__check__451__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__451__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__452__condition;
    __Vtask_tb_npu_single_core__DOT__check__452__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__452__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__453__condition;
    __Vtask_tb_npu_single_core__DOT__check__453__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__453__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__454__condition;
    __Vtask_tb_npu_single_core__DOT__check__454__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__454__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__455__condition;
    __Vtask_tb_npu_single_core__DOT__check__455__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__455__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__456__condition;
    __Vtask_tb_npu_single_core__DOT__check__456__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__456__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__query_task__457__command_id;
    __Vtask_tb_npu_single_core__DOT__query_task__457__command_id = 0;
    CData/*2:0*/ __Vtask_tb_npu_single_core__DOT__query_task__457__selector;
    __Vtask_tb_npu_single_core__DOT__query_task__457__selector = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__query_task__457__result;
    __Vtask_tb_npu_single_core__DOT__query_task__457__result = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__458__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__458__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__458__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__458__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__458__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__458__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__459__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__459__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__459__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__459__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__459__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__460__condition;
    __Vtask_tb_npu_single_core__DOT__check__460__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__460__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__461__condition;
    __Vtask_tb_npu_single_core__DOT__check__461__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__461__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__462__condition;
    __Vtask_tb_npu_single_core__DOT__check__462__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__462__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__463__condition;
    __Vtask_tb_npu_single_core__DOT__check__463__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__463__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__464__condition;
    __Vtask_tb_npu_single_core__DOT__check__464__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__464__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__465__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__465__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__465__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__465__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__465__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__466__condition;
    __Vtask_tb_npu_single_core__DOT__check__466__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__466__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__467__condition;
    __Vtask_tb_npu_single_core__DOT__check__467__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__467__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__468__condition;
    __Vtask_tb_npu_single_core__DOT__check__468__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__468__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__469__condition;
    __Vtask_tb_npu_single_core__DOT__check__469__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__469__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__470__condition;
    __Vtask_tb_npu_single_core__DOT__check__470__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__470__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__471__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__471__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__471__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__471__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__471__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__472__condition;
    __Vtask_tb_npu_single_core__DOT__check__472__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__472__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__473__condition;
    __Vtask_tb_npu_single_core__DOT__check__473__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__473__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__474__condition;
    __Vtask_tb_npu_single_core__DOT__check__474__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__474__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__475__condition;
    __Vtask_tb_npu_single_core__DOT__check__475__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__475__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__476__condition;
    __Vtask_tb_npu_single_core__DOT__check__476__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__476__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__477__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__477__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__477__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__477__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__477__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__477__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__477__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__477__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__477__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__477__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__478__condition;
    __Vtask_tb_npu_single_core__DOT__check__478__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__478__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__479__condition;
    __Vtask_tb_npu_single_core__DOT__check__479__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__479__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__480__condition;
    __Vtask_tb_npu_single_core__DOT__check__480__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__480__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__481__condition;
    __Vtask_tb_npu_single_core__DOT__check__481__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__481__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__482__condition;
    __Vtask_tb_npu_single_core__DOT__check__482__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__482__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__483__condition;
    __Vtask_tb_npu_single_core__DOT__check__483__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__483__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__484__condition;
    __Vtask_tb_npu_single_core__DOT__check__484__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__484__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__485__condition;
    __Vtask_tb_npu_single_core__DOT__check__485__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__485__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__486__condition;
    __Vtask_tb_npu_single_core__DOT__check__486__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__486__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__487__condition;
    __Vtask_tb_npu_single_core__DOT__check__487__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__487__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__488__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__488__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__488__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__488__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__488__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__489__condition;
    __Vtask_tb_npu_single_core__DOT__check__489__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__489__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__490__condition;
    __Vtask_tb_npu_single_core__DOT__check__490__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__490__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__491__condition;
    __Vtask_tb_npu_single_core__DOT__check__491__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__491__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__492__condition;
    __Vtask_tb_npu_single_core__DOT__check__492__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__492__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__493__condition;
    __Vtask_tb_npu_single_core__DOT__check__493__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__493__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__494__condition;
    __Vtask_tb_npu_single_core__DOT__check__494__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__494__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__495__condition;
    __Vtask_tb_npu_single_core__DOT__check__495__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__495__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__496__condition;
    __Vtask_tb_npu_single_core__DOT__check__496__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__496__message;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__address;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__value;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__value = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__init_common__499__engine;
    __Vtask_tb_npu_single_core__DOT__init_common__499__engine = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__init_common__499__bytes;
    __Vtask_tb_npu_single_core__DOT__init_common__499__bytes = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__499__src0;
    __Vtask_tb_npu_single_core__DOT__init_common__499__src0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__499__src1;
    __Vtask_tb_npu_single_core__DOT__init_common__499__src1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__499__src2;
    __Vtask_tb_npu_single_core__DOT__init_common__499__src2 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__499__dst;
    __Vtask_tb_npu_single_core__DOT__init_common__499__dst = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__init_common__499__numeric;
    __Vtask_tb_npu_single_core__DOT__init_common__499__numeric = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__502__offset;
    __Vtask_tb_npu_single_core__DOT__put_u16__502__offset = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__502__value;
    __Vtask_tb_npu_single_core__DOT__put_u16__502__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__507__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__507__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__507__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__507__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__514__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__514__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__514__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__514__value = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__517__address;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__517__address = 0;
    VlWide<64>/*2047:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__517__desc;
    VL_ZERO_W(2048, __Vtask_tb_npu_single_core__DOT__store_descriptor__517__desc);
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__517__bytes;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__517__bytes = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__address;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__address = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__value;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__value = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__compact_opcode;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command_id;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__dtype;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__payload;
    VL_ZERO_W(80, __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__payload);
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__wait0;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__wait0 = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__wait1;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__wait1 = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__signal_event;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__signal_event = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command);
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__521__condition;
    __Vtask_tb_npu_single_core__DOT__check__521__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__521__message;
    // Body
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__417__command_id = 0x102U;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__417__result = 0;
    __Vtask_tb_npu_single_core__DOT__query_task__418__selector = 4U;
    __Vtask_tb_npu_single_core__DOT__query_task__418__command_id 
        = __Vtask_tb_npu_single_core__DOT__acknowledge_task__417__command_id;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__argument1 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__418__selector));
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__argument0 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__418__command_id));
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__operation = 2U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__419__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__420__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__420__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__420__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__420__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__421__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__421__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__421__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__421__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__422__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__422__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__420__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__422__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__422__message));
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
    __Vtask_tb_npu_single_core__DOT__check__423__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__423__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__423__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__423__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__424__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__424__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__424__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__424__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__425__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__425__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__425__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__425__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__419__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__426__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__426__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__426__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__426__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__427__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__427__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__427__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__427__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__428__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__428__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__426__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__428__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__428__message));
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
    __Vtask_tb_npu_single_core__DOT__check__429__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__429__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__429__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__429__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__430__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__430__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__430__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__430__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__431__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__431__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__431__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__431__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__419__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__432__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__432__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__432__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__432__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__433__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__433__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__433__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__433__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__434__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__434__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__432__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__434__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__434__message));
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
    __Vtask_tb_npu_single_core__DOT__check__435__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__435__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__435__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__435__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__436__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__436__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__436__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__436__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__437__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__437__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__437__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__437__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__419__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__438__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__438__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__438__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__438__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__438__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__438__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__438__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__438__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__438__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__438__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__439__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__439__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__439__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__439__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__440__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__440__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__438__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__438__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__440__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__440__message));
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
            __Vtask_tb_npu_single_core__DOT__check__441__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__441__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__441__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__441__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__442__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__442__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__442__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__442__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__443__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__443__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__443__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__443__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__444__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__444__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__444__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__444__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__438__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__419__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__438__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__419__status 
                               >> 1U)))) {
                goto __Vlabel0;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__419__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__419__poll_count);
        }
        __Vlabel0: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__445__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__445__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__419__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__445__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__445__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__446__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__446__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__419__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__446__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__446__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__447__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__447__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__419__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__447__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__447__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__448__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__448__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__419__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__448__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__448__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__449__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__450__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__450__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__450__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__450__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__451__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__451__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__449__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__449__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__451__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__451__message));
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
    __Vtask_tb_npu_single_core__DOT__check__452__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__452__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__452__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__452__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__453__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__453__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__453__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__453__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__454__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__454__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__454__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__454__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__455__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__455__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__455__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__455__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__449__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__419__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__449__data;
    __Vtask_tb_npu_single_core__DOT__query_task__418__result 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__419__result;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__417__result 
        = __Vtask_tb_npu_single_core__DOT__query_task__418__result;
    __Vtask_tb_npu_single_core__DOT__check__456__message = 
        std::string{"task ACK failed"};
    __Vtask_tb_npu_single_core__DOT__check__456__condition 
        = (0ULL == __Vtask_tb_npu_single_core__DOT__acknowledge_task__417__result);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__456__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__456__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__query_task__457__selector = 0U;
    __Vtask_tb_npu_single_core__DOT__query_task__457__command_id = 0x101U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__argument1 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__457__selector));
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__argument0 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__457__command_id));
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__operation = 2U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__458__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__459__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__459__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__459__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__459__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__460__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__460__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__460__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__460__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__461__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__461__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__459__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__461__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__461__message));
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
    __Vtask_tb_npu_single_core__DOT__check__462__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__462__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__462__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__462__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__463__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__463__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__463__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__463__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__464__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__464__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__464__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__464__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__458__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__465__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__465__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__465__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__465__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__466__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__466__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__466__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__466__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__467__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__467__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__465__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__467__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__467__message));
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
    __Vtask_tb_npu_single_core__DOT__check__468__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__468__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__468__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__468__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__469__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__469__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__469__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__469__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__470__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__470__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__470__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__470__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__458__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__471__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__471__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__471__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__471__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__472__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__472__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__472__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__472__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__473__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__473__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__471__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__473__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__473__message));
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
    __Vtask_tb_npu_single_core__DOT__check__474__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__474__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__474__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__474__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__475__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__475__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__475__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__475__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__476__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__476__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__476__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__476__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__458__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__477__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__477__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__477__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__477__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__477__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__477__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__477__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__477__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__477__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__477__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__478__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__478__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__478__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__478__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__479__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__479__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__477__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__477__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__479__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__479__message));
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
            __Vtask_tb_npu_single_core__DOT__check__480__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__480__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__480__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__480__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__481__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__481__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__481__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__481__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__482__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__482__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__482__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__482__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__483__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__483__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__483__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__483__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__477__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__458__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__477__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__458__status 
                               >> 1U)))) {
                goto __Vlabel1;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__458__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__458__poll_count);
        }
        __Vlabel1: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__484__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__484__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__458__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__484__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__484__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__485__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__485__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__458__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__485__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__485__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__486__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__486__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__458__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__486__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__486__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__487__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__487__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__458__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__487__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__487__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__488__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__489__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__489__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__489__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__489__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__490__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__490__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__488__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__488__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__490__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__490__message));
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
    __Vtask_tb_npu_single_core__DOT__check__491__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__491__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__491__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__491__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__492__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__492__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__492__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__492__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__493__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__493__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__493__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__493__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__494__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__494__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__494__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__494__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__488__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__458__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__488__data;
    __Vtask_tb_npu_single_core__DOT__query_task__457__result 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__458__result;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = __Vtask_tb_npu_single_core__DOT__query_task__457__result;
    __Vtask_tb_npu_single_core__DOT__check__495__message = 
        std::string{"ACK did not release the Matrix task slot"};
    __Vtask_tb_npu_single_core__DOT__check__495__condition 
        = (IData)((0x810ULL == (0xfffULL & vlSelfRef.tb_npu_single_core__DOT__ctl_data)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__495__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__495__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    tb_npu_single_core__DOT__unnamedblk4__DOT__desc_reads_after_dependency 
        = vlSelfRef.tb_npu_single_core__DOT__desc_read_count_q;
    __Vtask_tb_npu_single_core__DOT__check__496__message = 
        std::string{"descriptor fetch did not read 32+24 ordered beats"};
    __Vtask_tb_npu_single_core__DOT__check__496__condition 
        = (0x38U == tb_npu_single_core__DOT__unnamedblk4__DOT__desc_reads_after_dependency);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__496__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__496__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__value = 0xa07030100fffcf8ULL;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__address = 0x3000ULL;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index = 0;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index = 0U;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value 
        = (0xffU & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__value));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
        = __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__address;
    if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address);
        VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
    }
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                  & (IData)(
                                                                            (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                                                             >> 3U)))] 
        = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                  (7U 
                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U)))) 
            & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
            [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value)) 
                                              << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, 
                                                                  (7U 
                                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U))));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index = 1U;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value 
        = (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__value 
                            >> 8U)));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
        = (1ULL + __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__address);
    if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address);
        VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
    }
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                  & (IData)(
                                                                            (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                                                             >> 3U)))] 
        = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                  (7U 
                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U)))) 
            & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
            [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value)) 
                                              << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, 
                                                                  (7U 
                                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U))));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index = 2U;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value 
        = (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__value 
                            >> 0x10U)));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
        = (2ULL + __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__address);
    if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address);
        VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
    }
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                  & (IData)(
                                                                            (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                                                             >> 3U)))] 
        = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                  (7U 
                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U)))) 
            & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
            [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value)) 
                                              << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, 
                                                                  (7U 
                                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U))));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index = 3U;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value 
        = (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__value 
                            >> 0x18U)));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
        = (3ULL + __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__address);
    if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address);
        VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
    }
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                  & (IData)(
                                                                            (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                                                             >> 3U)))] 
        = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                  (7U 
                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U)))) 
            & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
            [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value)) 
                                              << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, 
                                                                  (7U 
                                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U))));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index = 4U;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value 
        = (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__value 
                            >> 0x20U)));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
        = (4ULL + __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__address);
    if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address);
        VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
    }
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                  & (IData)(
                                                                            (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                                                             >> 3U)))] 
        = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                  (7U 
                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U)))) 
            & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
            [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value)) 
                                              << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, 
                                                                  (7U 
                                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U))));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index = 5U;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value 
        = (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__value 
                            >> 0x28U)));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
        = (5ULL + __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__address);
    if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address);
        VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
    }
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                  & (IData)(
                                                                            (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                                                             >> 3U)))] 
        = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                  (7U 
                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U)))) 
            & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
            [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value)) 
                                              << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, 
                                                                  (7U 
                                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U))));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index = 6U;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value 
        = (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__value 
                            >> 0x30U)));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
        = (6ULL + __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__address);
    if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address);
        VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
    }
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                  & (IData)(
                                                                            (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                                                             >> 3U)))] 
        = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                  (7U 
                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U)))) 
            & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
            [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value)) 
                                              << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, 
                                                                  (7U 
                                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U))));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index = 7U;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value 
        = (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__value 
                            >> 0x38U)));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
        = (7ULL + __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__address);
    if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address);
        VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
    }
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                  & (IData)(
                                                                            (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                                                             >> 3U)))] 
        = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                  (7U 
                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U)))) 
            & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
            [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address 
                                >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__value)) 
                                              << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, 
                                                                  (7U 
                                                                   & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__498__address)), 3U))));
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_u64__497__unnamedblk2__DOT__index = 8U;
    __Vtask_tb_npu_single_core__DOT__init_common__499__numeric = 0x55U;
    __Vtask_tb_npu_single_core__DOT__init_common__499__dst = 0x900ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__499__src2 = 0ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__499__src1 = 0ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__499__src0 = 0x3000ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__499__bytes = 0x100U;
    __Vtask_tb_npu_single_core__DOT__init_common__499__engine = 1U;
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb_npu_single_core__DOT__dma_desc[__Vilp1] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0U, 1U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 1U, (IData)(__Vtask_tb_npu_single_core__DOT__init_common__499__engine));
    __Vtask_tb_npu_single_core__DOT__put_u16__502__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__499__bytes;
    __Vtask_tb_npu_single_core__DOT__put_u16__502__offset = 2U;
    VL_ASSIGNSEL_WI(2048, 16, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u16__502__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__dma_desc, __Vtask_tb_npu_single_core__DOT__put_u16__502__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 8U, __Vtask_tb_npu_single_core__DOT__init_common__499__src0);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0x10U, __Vtask_tb_npu_single_core__DOT__init_common__499__src1);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0x18U, __Vtask_tb_npu_single_core__DOT__init_common__499__src2);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0x20U, __Vtask_tb_npu_single_core__DOT__init_common__499__dst);
    __Vtask_tb_npu_single_core__DOT__put_u32__507__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__499__numeric;
    __Vtask_tb_npu_single_core__DOT__put_u32__507__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__507__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__dma_desc, __Vtask_tb_npu_single_core__DOT__put_u32__507__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0x40U, 1U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0x41U, 1U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0x42U, 0U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0x43U, 0U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0x44U, 0xfU);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0x45U, 8U);
    __Vtask_tb_npu_single_core__DOT__put_u32__514__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__514__offset = 0x48U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__514__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__dma_desc, __Vtask_tb_npu_single_core__DOT__put_u32__514__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0x98U, 8ULL);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__dma_desc, 0xa0U, 8ULL);
    __Vtask_tb_npu_single_core__DOT__store_descriptor__517__bytes = 0x100U;
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x3fU)) {
        __Vtask_tb_npu_single_core__DOT__store_descriptor__517__desc[__Vilp2] 
            = vlSelfRef.tb_npu_single_core__DOT__dma_desc[__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    __Vtask_tb_npu_single_core__DOT__store_descriptor__517__address = 0x1200ULL;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index = 0;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index 
            < __Vtask_tb_npu_single_core__DOT__store_descriptor__517__bytes)) {
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__value 
            = (0xffU & (((0U == (0x1fU & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index, 3U)))
                          ? 0U : (__Vtask_tb_npu_single_core__DOT__store_descriptor__517__desc[
                                  (((IData)(7U) + (0x7ffU 
                                                   & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index, 3U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index, 3U))))) 
                        | (__Vtask_tb_npu_single_core__DOT__store_descriptor__517__desc[
                           (0x3fU & (VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index, 3U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index, 3U)))));
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__address 
            = (__Vtask_tb_npu_single_core__DOT__store_descriptor__517__address 
               + (QData)((IData)(__Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index)));
        if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__address)))) {
            VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__address);
            VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
        }
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                      & (IData)(
                                                                                (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__address 
                                                                                >> 3U)))] 
            = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                      (7U 
                                                       & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__address)), 3U)))) 
                & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__address 
                                    >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__value)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, 
                                                                   (7U 
                                                                    & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__518__address)), 3U))));
        __Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__store_descriptor__517__unnamedblk1__DOT__index);
    }
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[0U] = 0x84U;
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[1U] = 9U;
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[2U] = 0x8003U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__signal_event = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__wait1 = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__wait0 = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__payload[0U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__payload[1U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__payload[2U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[2U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__dtype = 1U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command_id = 0x103U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__compact_opcode = 5U;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command);
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[0U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[1U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[2U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[3U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[3U] 
        = ((0xffU & __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[3U]) 
           | (0xffffff00U & (0x80000000U | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__519__compact_opcode) 
                                             << 0x1aU) 
                                            | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command_id) 
                                                << 0x10U) 
                                               | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__519__wait0) 
                                                  << 8U))))));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[2U] 
        = ((0xffffffU & __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[2U]) 
           | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__519__signal_event) 
              << 0x18U));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[3U] 
        = ((0xffffff00U & __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[3U]) 
           | (0xffffffU & ((0xffffffU & (IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__519__wait1)) 
                           | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__519__signal_event) 
                              >> 8U))));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__payload[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__payload[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[2U]) 
           | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__519__dtype) 
               << 0x10U) | __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__payload[2U]));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__Vfuncout[0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__Vfuncout[1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__Vfuncout[2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[2U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__Vfuncout[3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__command[3U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__Vfuncout[0U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__Vfuncout[1U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__Vfuncout[2U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__519__Vfuncout[3U];
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__command_count = 1U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__command_index = 0;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10207719713406918725ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2955086174631513409ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__beat_count = 0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__beat_count 
        = VL_SHIFTL_III(32,32,32, vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__command_count, 1U);
    __Vtask_tb_npu_single_core__DOT__check__521__message = 
        std::string{"invalid command burst count"};
    __Vtask_tb_npu_single_core__DOT__check__521__condition 
        = ((1U <= vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__command_count) 
           & (8U >= vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__command_count));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__521__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__521__message));
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
        = (0xffU & (vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__beat_count 
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
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__command_index = 0U;
}

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__5(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__5\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__522__condition;
    __Vtask_tb_npu_single_core__DOT__check__522__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__522__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__523__condition;
    __Vtask_tb_npu_single_core__DOT__check__523__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__523__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__524__expected_command_id;
    __Vtask_tb_npu_single_core__DOT__read_command_response__524__expected_command_id = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__524__expected_status;
    __Vtask_tb_npu_single_core__DOT__read_command_response__524__expected_status = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__524__response;
    __Vtask_tb_npu_single_core__DOT__read_command_response__524__response = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__525__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__525__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__525__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__525__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__525__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__526__condition;
    __Vtask_tb_npu_single_core__DOT__check__526__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__526__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__527__condition;
    __Vtask_tb_npu_single_core__DOT__check__527__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__527__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__528__condition;
    __Vtask_tb_npu_single_core__DOT__check__528__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__528__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__529__condition;
    __Vtask_tb_npu_single_core__DOT__check__529__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__529__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__530__condition;
    __Vtask_tb_npu_single_core__DOT__check__530__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__530__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__531__condition;
    __Vtask_tb_npu_single_core__DOT__check__531__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__531__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__532__condition;
    __Vtask_tb_npu_single_core__DOT__check__532__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__532__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__533__condition;
    __Vtask_tb_npu_single_core__DOT__check__533__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__533__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__534__condition;
    __Vtask_tb_npu_single_core__DOT__check__534__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__534__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__535__condition;
    __Vtask_tb_npu_single_core__DOT__check__535__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__535__message;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__536__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__536__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__536__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__536__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__536__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__536__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__537__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__537__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__537__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__537__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__538__condition;
    __Vtask_tb_npu_single_core__DOT__check__538__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__538__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__539__condition;
    __Vtask_tb_npu_single_core__DOT__check__539__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__539__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__540__condition;
    __Vtask_tb_npu_single_core__DOT__check__540__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__540__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__541__condition;
    __Vtask_tb_npu_single_core__DOT__check__541__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__541__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__542__condition;
    __Vtask_tb_npu_single_core__DOT__check__542__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__542__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__543__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__543__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__543__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__543__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__544__condition;
    __Vtask_tb_npu_single_core__DOT__check__544__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__544__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__545__condition;
    __Vtask_tb_npu_single_core__DOT__check__545__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__545__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__546__condition;
    __Vtask_tb_npu_single_core__DOT__check__546__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__546__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__547__condition;
    __Vtask_tb_npu_single_core__DOT__check__547__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__547__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__548__condition;
    __Vtask_tb_npu_single_core__DOT__check__548__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__548__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__549__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__549__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__549__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__549__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__550__condition;
    __Vtask_tb_npu_single_core__DOT__check__550__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__550__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__551__condition;
    __Vtask_tb_npu_single_core__DOT__check__551__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__551__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__552__condition;
    __Vtask_tb_npu_single_core__DOT__check__552__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__552__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__553__condition;
    __Vtask_tb_npu_single_core__DOT__check__553__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__553__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__554__condition;
    __Vtask_tb_npu_single_core__DOT__check__554__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__554__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__555__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__555__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__555__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__555__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__555__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__555__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__555__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__555__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__556__condition;
    __Vtask_tb_npu_single_core__DOT__check__556__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__556__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__557__condition;
    __Vtask_tb_npu_single_core__DOT__check__557__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__557__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__558__condition;
    __Vtask_tb_npu_single_core__DOT__check__558__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__558__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__559__condition;
    __Vtask_tb_npu_single_core__DOT__check__559__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__559__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__560__condition;
    __Vtask_tb_npu_single_core__DOT__check__560__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__560__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__561__condition;
    __Vtask_tb_npu_single_core__DOT__check__561__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__561__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__562__condition;
    __Vtask_tb_npu_single_core__DOT__check__562__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__562__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__563__condition;
    __Vtask_tb_npu_single_core__DOT__check__563__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__563__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__564__condition;
    __Vtask_tb_npu_single_core__DOT__check__564__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__564__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__565__condition;
    __Vtask_tb_npu_single_core__DOT__check__565__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__565__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__566__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__566__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__566__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__566__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__567__condition;
    __Vtask_tb_npu_single_core__DOT__check__567__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__567__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__568__condition;
    __Vtask_tb_npu_single_core__DOT__check__568__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__568__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__569__condition;
    __Vtask_tb_npu_single_core__DOT__check__569__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__569__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__570__condition;
    __Vtask_tb_npu_single_core__DOT__check__570__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__570__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__571__condition;
    __Vtask_tb_npu_single_core__DOT__check__571__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__571__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__572__condition;
    __Vtask_tb_npu_single_core__DOT__check__572__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__572__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__573__condition;
    __Vtask_tb_npu_single_core__DOT__check__573__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__573__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__query_task__574__command_id;
    __Vtask_tb_npu_single_core__DOT__query_task__574__command_id = 0;
    CData/*2:0*/ __Vtask_tb_npu_single_core__DOT__query_task__574__selector;
    __Vtask_tb_npu_single_core__DOT__query_task__574__selector = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__query_task__574__result;
    __Vtask_tb_npu_single_core__DOT__query_task__574__result = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__575__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__575__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__575__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__575__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__575__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__575__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__576__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__576__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__576__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__576__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__576__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__577__condition;
    __Vtask_tb_npu_single_core__DOT__check__577__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__577__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__578__condition;
    __Vtask_tb_npu_single_core__DOT__check__578__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__578__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__579__condition;
    __Vtask_tb_npu_single_core__DOT__check__579__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__579__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__580__condition;
    __Vtask_tb_npu_single_core__DOT__check__580__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__580__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__581__condition;
    __Vtask_tb_npu_single_core__DOT__check__581__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__581__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__582__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__582__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__582__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__582__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__582__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__583__condition;
    __Vtask_tb_npu_single_core__DOT__check__583__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__583__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__584__condition;
    __Vtask_tb_npu_single_core__DOT__check__584__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__584__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__585__condition;
    __Vtask_tb_npu_single_core__DOT__check__585__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__585__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__586__condition;
    __Vtask_tb_npu_single_core__DOT__check__586__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__586__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__587__condition;
    __Vtask_tb_npu_single_core__DOT__check__587__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__587__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__588__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__588__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__588__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__588__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__588__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__589__condition;
    __Vtask_tb_npu_single_core__DOT__check__589__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__589__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__590__condition;
    __Vtask_tb_npu_single_core__DOT__check__590__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__590__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__591__condition;
    __Vtask_tb_npu_single_core__DOT__check__591__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__591__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__592__condition;
    __Vtask_tb_npu_single_core__DOT__check__592__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__592__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__593__condition;
    __Vtask_tb_npu_single_core__DOT__check__593__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__593__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__594__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__594__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__594__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__594__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__594__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__594__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__594__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__594__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__594__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__594__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__595__condition;
    __Vtask_tb_npu_single_core__DOT__check__595__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__595__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__596__condition;
    __Vtask_tb_npu_single_core__DOT__check__596__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__596__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__597__condition;
    __Vtask_tb_npu_single_core__DOT__check__597__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__597__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__598__condition;
    __Vtask_tb_npu_single_core__DOT__check__598__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__598__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__599__condition;
    __Vtask_tb_npu_single_core__DOT__check__599__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__599__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__600__condition;
    __Vtask_tb_npu_single_core__DOT__check__600__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__600__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__601__condition;
    __Vtask_tb_npu_single_core__DOT__check__601__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__601__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__602__condition;
    __Vtask_tb_npu_single_core__DOT__check__602__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__602__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__603__condition;
    __Vtask_tb_npu_single_core__DOT__check__603__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__603__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__604__condition;
    __Vtask_tb_npu_single_core__DOT__check__604__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__604__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__605__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__605__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__605__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__605__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__605__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__606__condition;
    __Vtask_tb_npu_single_core__DOT__check__606__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__606__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__607__condition;
    __Vtask_tb_npu_single_core__DOT__check__607__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__607__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__608__condition;
    __Vtask_tb_npu_single_core__DOT__check__608__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__608__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__609__condition;
    __Vtask_tb_npu_single_core__DOT__check__609__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__609__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__610__condition;
    __Vtask_tb_npu_single_core__DOT__check__610__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__610__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__611__condition;
    __Vtask_tb_npu_single_core__DOT__check__611__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__611__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__612__condition;
    __Vtask_tb_npu_single_core__DOT__check__612__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__612__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_read_word__613__address;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__613__address = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__614__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__address = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__614__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__614__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__614__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__615__condition;
    __Vtask_tb_npu_single_core__DOT__check__615__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__615__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__616__condition;
    __Vtask_tb_npu_single_core__DOT__check__616__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__616__message;
    // Body
    while ((vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__command_index 
            < vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__command_count)) {
        vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0U;
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             647);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
            = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                [(7U & vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__command_index)][1U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                            [(7U & vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__command_index)][0U])));
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i = 0xffU;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i 
            = (((IData)(1U) + VL_SHIFTL_III(32,32,32, vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__command_index, 1U)) 
               == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__beat_count);
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
        vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 1U;
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             647);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
            = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                [(7U & vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__command_index)][3U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                            [(7U & vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__command_index)][2U])));
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i = 0xffU;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i 
            = (((IData)(2U) + VL_SHIFTL_III(32,32,32, vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__command_index, 1U)) 
               == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__beat_count);
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
        vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 2U;
        vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__command_index 
            = ((IData)(1U) + vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__unnamedblk2__DOT__command_index);
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
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         662);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         662);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__522__message = 
        std::string{"command burst response was not held"};
    __Vtask_tb_npu_single_core__DOT__check__522__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
              == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_submit_commands__520__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__522__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__522__message));
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
    __Vtask_tb_npu_single_core__DOT__check__523__message = 
        std::string{"FIXED command burst failed"};
    __Vtask_tb_npu_single_core__DOT__check__523__condition 
        = ((0x63U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q)) 
           & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__523__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__523__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         670);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__524__expected_status = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__524__expected_command_id = 0x103U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__524__response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__address = 0x20008U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__525__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__526__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__526__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__526__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__526__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__527__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__527__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__525__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__525__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__527__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__527__message));
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
    __Vtask_tb_npu_single_core__DOT__check__528__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__528__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__528__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__528__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__529__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__529__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__529__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__529__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__530__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__530__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__530__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__530__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__531__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__531__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__531__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__531__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__525__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__524__response 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__525__data;
    __Vtask_tb_npu_single_core__DOT__check__532__message = 
        std::string{"CFE response returned the wrong command_id"};
    __Vtask_tb_npu_single_core__DOT__check__532__condition 
        = ((0xfffU & (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__524__response)) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__524__expected_command_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__532__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__532__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__533__message = 
        std::string{"CFE response returned the wrong status"};
    __Vtask_tb_npu_single_core__DOT__check__533__condition 
        = ((0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__524__response 
                             >> 0xcU))) == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__524__expected_status));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__533__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__533__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__534__message = 
        std::string{"CFE response fifo_free_entries exceeds the configured depth"};
    __Vtask_tb_npu_single_core__DOT__check__534__condition 
        = (8U >= (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__524__response 
                                   >> 0x14U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__534__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__534__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__535__message = 
        std::string{"CFE response reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__535__condition 
        = (0ULL == (__Vtask_tb_npu_single_core__DOT__read_command_response__524__response 
                    >> 0x1cU));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__535__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__535__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__argument1 = 0xc350ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__argument0 = 1ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__operation = 3U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__536__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__537__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__537__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__537__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__538__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__538__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__538__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__538__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__539__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__539__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__537__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__539__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__539__message));
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
    __Vtask_tb_npu_single_core__DOT__check__540__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__540__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__540__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__540__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__541__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__541__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__541__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__541__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__542__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__542__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__542__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__542__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__536__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__543__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__543__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__543__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__544__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__544__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__544__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__544__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__545__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__545__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__543__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__545__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__545__message));
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
    __Vtask_tb_npu_single_core__DOT__check__546__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__546__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__546__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__546__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__547__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__547__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__547__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__547__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__548__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__548__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__548__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__548__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__536__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__549__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__549__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__549__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__550__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__550__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__550__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__550__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__551__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__551__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__549__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__551__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__551__message));
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
    __Vtask_tb_npu_single_core__DOT__check__552__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__552__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__552__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__552__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__553__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__553__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__553__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__553__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__554__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__554__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__554__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__554__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__536__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__555__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__555__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__555__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__555__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__555__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__555__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__556__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__556__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__556__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__556__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__557__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__557__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__555__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__555__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__557__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__557__message));
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
            __Vtask_tb_npu_single_core__DOT__check__558__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__558__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__558__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__558__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__559__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__559__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__559__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__559__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__560__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__560__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__560__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__560__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__561__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__561__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__561__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__561__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__555__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__536__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__555__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__536__status 
                               >> 1U)))) {
                goto __Vlabel0;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__536__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__536__poll_count);
        }
        __Vlabel0: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__562__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__562__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__536__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__562__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__562__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__563__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__563__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__536__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__563__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__563__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__564__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__564__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__536__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__564__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__564__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__565__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__565__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__536__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__565__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__565__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__566__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__567__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__567__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__567__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__567__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__568__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__568__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__566__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__566__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__568__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__568__message));
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
    __Vtask_tb_npu_single_core__DOT__check__569__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__569__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__569__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__569__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__570__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__570__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__570__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__570__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__571__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__571__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__571__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__571__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__572__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__572__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__572__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__572__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__566__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__536__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__566__data;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = __Vtask_tb_npu_single_core__DOT__ctl_request__536__result;
    __Vtask_tb_npu_single_core__DOT__check__573__message = 
        std::string{"DMA FENCE returned a failure"};
    __Vtask_tb_npu_single_core__DOT__check__573__condition 
        = (0U == (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__ctl_data)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__573__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__573__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__query_task__574__selector = 3U;
    __Vtask_tb_npu_single_core__DOT__query_task__574__command_id = 0x103U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__argument1 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__574__selector));
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__argument0 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__574__command_id));
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__operation = 2U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__575__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__576__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__576__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__576__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__576__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__577__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__577__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__577__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__577__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__578__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__578__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__576__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__578__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__578__message));
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
    __Vtask_tb_npu_single_core__DOT__check__579__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__579__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__579__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__579__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__580__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__580__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__580__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__580__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__581__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__581__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__581__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__581__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__575__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__582__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__582__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__582__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__582__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__583__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__583__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__583__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__583__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__584__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__584__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__582__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__584__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__584__message));
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
    __Vtask_tb_npu_single_core__DOT__check__585__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__585__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__585__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__585__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__586__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__586__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__586__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__586__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__587__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__587__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__587__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__587__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__575__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__588__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__588__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__588__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__588__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__589__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__589__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__589__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__589__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__590__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__590__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__588__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__590__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__590__message));
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
    __Vtask_tb_npu_single_core__DOT__check__591__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__591__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__591__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__591__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__592__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__592__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__592__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__592__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__593__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__593__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__593__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__593__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__575__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__594__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__594__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__594__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__594__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__594__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__594__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__594__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__594__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__594__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__594__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__595__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__595__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__595__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__595__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__596__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__596__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__594__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__594__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__596__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__596__message));
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
            __Vtask_tb_npu_single_core__DOT__check__597__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__597__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__597__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__597__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__598__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__598__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__598__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__598__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__599__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__599__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__599__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__599__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__600__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__600__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__600__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__600__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__594__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__575__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__594__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__575__status 
                               >> 1U)))) {
                goto __Vlabel1;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__575__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__575__poll_count);
        }
        __Vlabel1: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__601__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__601__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__575__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__601__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__601__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__602__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__602__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__575__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__602__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__602__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__603__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__603__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__575__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__603__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__603__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__604__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__604__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__575__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__604__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__604__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__605__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__606__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__606__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__606__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__606__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__607__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__607__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__605__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__605__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__607__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__607__message));
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
    __Vtask_tb_npu_single_core__DOT__check__608__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__608__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__608__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__608__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__609__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__609__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__609__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__609__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__610__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__610__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__610__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__610__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__611__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__611__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__611__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__611__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__605__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__575__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__605__data;
    __Vtask_tb_npu_single_core__DOT__query_task__574__result 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__575__result;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = __Vtask_tb_npu_single_core__DOT__query_task__574__result;
    __Vtask_tb_npu_single_core__DOT__check__612__message = 
        std::string{"DMA progress is not eight bytes"};
    __Vtask_tb_npu_single_core__DOT__check__612__condition 
        = (8ULL == vlSelfRef.tb_npu_single_core__DOT__ctl_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__612__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__612__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__l1_read_word__613__address = 0x900U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_read_word__613__address));
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__614__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__614__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__615__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__615__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__615__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__615__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__616__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__616__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__614__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__614__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__616__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__616__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         612);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
}
