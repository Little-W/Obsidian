// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core__Syms.h"
#include "Vtb_npu_single_core___024root.h"

extern const VlWide<64>/*2047:0*/ Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0;

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__10(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__10\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<64>/*2047:0*/ tb_npu_single_core__DOT__int16_vector_desc;
    VL_ZERO_W(2048, tb_npu_single_core__DOT__int16_vector_desc);
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_read_word__1028__data;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1028__data = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1029__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1029__data = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1030__condition;
    __Vtask_tb_npu_single_core__DOT__check__1030__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1030__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1031__condition;
    __Vtask_tb_npu_single_core__DOT__check__1031__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1031__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1032__condition;
    __Vtask_tb_npu_single_core__DOT__check__1032__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1032__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1033__condition;
    __Vtask_tb_npu_single_core__DOT__check__1033__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1033__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1034__condition;
    __Vtask_tb_npu_single_core__DOT__check__1034__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1034__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1035__condition;
    __Vtask_tb_npu_single_core__DOT__check__1035__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1035__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1036__condition;
    __Vtask_tb_npu_single_core__DOT__check__1036__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1036__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__acknowledge_task__1037__command_id;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__1037__command_id = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__acknowledge_task__1037__result;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__1037__result = 0;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1038__command_id;
    __Vtask_tb_npu_single_core__DOT__query_task__1038__command_id = 0;
    CData/*2:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1038__selector;
    __Vtask_tb_npu_single_core__DOT__query_task__1038__selector = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1038__result;
    __Vtask_tb_npu_single_core__DOT__query_task__1038__result = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1039__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1039__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1039__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1039__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1039__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1039__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1041__condition;
    __Vtask_tb_npu_single_core__DOT__check__1041__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1041__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1042__condition;
    __Vtask_tb_npu_single_core__DOT__check__1042__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1042__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1043__condition;
    __Vtask_tb_npu_single_core__DOT__check__1043__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1043__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1044__condition;
    __Vtask_tb_npu_single_core__DOT__check__1044__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1044__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1045__condition;
    __Vtask_tb_npu_single_core__DOT__check__1045__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1045__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1047__condition;
    __Vtask_tb_npu_single_core__DOT__check__1047__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1047__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1048__condition;
    __Vtask_tb_npu_single_core__DOT__check__1048__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1048__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1049__condition;
    __Vtask_tb_npu_single_core__DOT__check__1049__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1049__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1050__condition;
    __Vtask_tb_npu_single_core__DOT__check__1050__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1050__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1051__condition;
    __Vtask_tb_npu_single_core__DOT__check__1051__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1051__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1053__condition;
    __Vtask_tb_npu_single_core__DOT__check__1053__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1053__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1054__condition;
    __Vtask_tb_npu_single_core__DOT__check__1054__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1054__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1055__condition;
    __Vtask_tb_npu_single_core__DOT__check__1055__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1055__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1056__condition;
    __Vtask_tb_npu_single_core__DOT__check__1056__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1056__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1057__condition;
    __Vtask_tb_npu_single_core__DOT__check__1057__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1057__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1059__condition;
    __Vtask_tb_npu_single_core__DOT__check__1059__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1059__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1060__condition;
    __Vtask_tb_npu_single_core__DOT__check__1060__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1060__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1061__condition;
    __Vtask_tb_npu_single_core__DOT__check__1061__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1061__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1062__condition;
    __Vtask_tb_npu_single_core__DOT__check__1062__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1062__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1063__condition;
    __Vtask_tb_npu_single_core__DOT__check__1063__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1063__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1064__condition;
    __Vtask_tb_npu_single_core__DOT__check__1064__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1064__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1065__condition;
    __Vtask_tb_npu_single_core__DOT__check__1065__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1065__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1066__condition;
    __Vtask_tb_npu_single_core__DOT__check__1066__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1066__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1067__condition;
    __Vtask_tb_npu_single_core__DOT__check__1067__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1067__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1068__condition;
    __Vtask_tb_npu_single_core__DOT__check__1068__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1068__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1070__condition;
    __Vtask_tb_npu_single_core__DOT__check__1070__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1070__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1071__condition;
    __Vtask_tb_npu_single_core__DOT__check__1071__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1071__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1072__condition;
    __Vtask_tb_npu_single_core__DOT__check__1072__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1072__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1073__condition;
    __Vtask_tb_npu_single_core__DOT__check__1073__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1073__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1074__condition;
    __Vtask_tb_npu_single_core__DOT__check__1074__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1074__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1075__condition;
    __Vtask_tb_npu_single_core__DOT__check__1075__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1075__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1076__condition;
    __Vtask_tb_npu_single_core__DOT__check__1076__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1076__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1079__condition;
    __Vtask_tb_npu_single_core__DOT__check__1079__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1079__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1080__condition;
    __Vtask_tb_npu_single_core__DOT__check__1080__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1080__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1081__condition;
    __Vtask_tb_npu_single_core__DOT__check__1081__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1081__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1082__condition;
    __Vtask_tb_npu_single_core__DOT__check__1082__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1082__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1083__condition;
    __Vtask_tb_npu_single_core__DOT__check__1083__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1083__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1086__condition;
    __Vtask_tb_npu_single_core__DOT__check__1086__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1086__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1087__condition;
    __Vtask_tb_npu_single_core__DOT__check__1087__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1087__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1088__condition;
    __Vtask_tb_npu_single_core__DOT__check__1088__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1088__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1089__condition;
    __Vtask_tb_npu_single_core__DOT__check__1089__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1089__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1090__condition;
    __Vtask_tb_npu_single_core__DOT__check__1090__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1090__message;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1091__engine;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__engine = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1091__bytes;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__bytes = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1091__src0;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__src0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1091__src1;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__src1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1091__src2;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__src2 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1091__dst;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__dst = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1091__numeric;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__numeric = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__1094__offset;
    __Vtask_tb_npu_single_core__DOT__put_u16__1094__offset = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__1094__value;
    __Vtask_tb_npu_single_core__DOT__put_u16__1094__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1099__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1099__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1099__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1099__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1100__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1100__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1100__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1100__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1101__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1101__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1101__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1101__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1102__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1102__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1102__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1102__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1103__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1103__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1103__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1103__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1104__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1104__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1104__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1104__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1105__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1105__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1105__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1105__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1106__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1106__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1106__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1106__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1107__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1107__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1107__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1107__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1108__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1108__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1108__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1108__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1109__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1109__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1109__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1109__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1110__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1110__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1110__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1110__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1111__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1111__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1111__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1111__value = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__address;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__address = 0;
    VlWide<64>/*2047:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__desc;
    VL_ZERO_W(2048, __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__desc);
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__bytes;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__bytes = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__address;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__address = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__value;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__value = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__compact_opcode;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command_id;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__dtype;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__payload;
    VL_ZERO_W(80, __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__payload);
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__wait0;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__wait0 = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__wait1;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__wait1 = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__signal_event;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__signal_event = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command);
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__command_count;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__command_count = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__unnamedblk3__DOT__word_index;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__observed_response = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__beat_count;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__beat_count = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1116__condition;
    __Vtask_tb_npu_single_core__DOT__check__1116__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1116__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1117__condition;
    __Vtask_tb_npu_single_core__DOT__check__1117__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1117__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1118__condition;
    __Vtask_tb_npu_single_core__DOT__check__1118__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1118__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1119__expected_command_id;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1119__expected_command_id = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1119__expected_status;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1119__expected_status = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1119__response;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1119__response = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1121__condition;
    __Vtask_tb_npu_single_core__DOT__check__1121__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1121__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1122__condition;
    __Vtask_tb_npu_single_core__DOT__check__1122__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1122__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1123__condition;
    __Vtask_tb_npu_single_core__DOT__check__1123__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1123__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1124__condition;
    __Vtask_tb_npu_single_core__DOT__check__1124__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1124__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1125__condition;
    __Vtask_tb_npu_single_core__DOT__check__1125__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1125__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1126__condition;
    __Vtask_tb_npu_single_core__DOT__check__1126__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1126__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1127__condition;
    __Vtask_tb_npu_single_core__DOT__check__1127__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1127__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1128__condition;
    __Vtask_tb_npu_single_core__DOT__check__1128__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1128__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1129__condition;
    __Vtask_tb_npu_single_core__DOT__check__1129__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1129__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1130__condition;
    __Vtask_tb_npu_single_core__DOT__check__1130__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1130__message;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1131__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1131__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1131__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1131__argument1 = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1133__condition;
    __Vtask_tb_npu_single_core__DOT__check__1133__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1133__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1134__condition;
    __Vtask_tb_npu_single_core__DOT__check__1134__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1134__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1135__condition;
    __Vtask_tb_npu_single_core__DOT__check__1135__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1135__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1136__condition;
    __Vtask_tb_npu_single_core__DOT__check__1136__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1136__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1137__condition;
    __Vtask_tb_npu_single_core__DOT__check__1137__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1137__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__strobe = 0;
    // Body
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
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1029__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1029__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1029__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1029__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1029__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1030__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1030__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1030__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1030__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1031__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1031__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1029__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1029__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1031__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1031__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1032__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1032__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1032__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1032__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1033__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1033__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1033__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1033__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1034__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1034__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1034__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1034__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1035__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1035__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1035__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1035__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1029__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1028__data 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1029__data;
    vlSelfRef.tb_npu_single_core__DOT__read_data = __Vtask_tb_npu_single_core__DOT__l1_read_word__1028__data;
    __Vtask_tb_npu_single_core__DOT__check__1036__message = 
        std::string{"Complex ACT result is incorrect"};
    __Vtask_tb_npu_single_core__DOT__check__1036__condition 
        = (0x100ffffULL == (0xffffffffULL & vlSelfRef.tb_npu_single_core__DOT__read_data));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1036__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1036__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__1037__command_id = 0x104U;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__1037__result = 0;
    __Vtask_tb_npu_single_core__DOT__query_task__1038__selector = 4U;
    __Vtask_tb_npu_single_core__DOT__query_task__1038__command_id 
        = __Vtask_tb_npu_single_core__DOT__acknowledge_task__1037__command_id;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__argument1 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__1038__selector));
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__argument0 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__1038__command_id));
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__operation = 2U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1039__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1040__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1041__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1041__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1041__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1041__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1042__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1042__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1040__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1042__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1042__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1043__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1043__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1043__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1043__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1044__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1044__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1044__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1044__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1045__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1045__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1045__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1045__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1039__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1046__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1047__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1047__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1047__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1047__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1048__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1048__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1046__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1048__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1048__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1049__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1049__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1049__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1049__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1050__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1050__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1050__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1050__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1051__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1051__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1051__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1051__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__1039__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1052__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1053__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1053__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1053__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1053__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1054__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1054__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1052__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1054__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1054__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1055__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1055__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1055__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1055__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1056__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1056__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1056__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1056__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1057__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1057__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1057__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1057__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__1039__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__1059__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1059__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1059__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1059__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1060__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1060__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1058__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1060__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1060__message));
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
            __Vtask_tb_npu_single_core__DOT__check__1061__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__1061__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1061__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1061__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1062__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__1062__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1062__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1062__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1063__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__1063__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1063__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1063__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1064__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__1064__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1064__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1064__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__1039__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1058__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__1039__status 
                               >> 1U)))) {
                goto __Vlabel0;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__1039__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__1039__poll_count);
        }
        __Vlabel0: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__1065__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__1065__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__1039__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1065__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1065__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1066__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__1066__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__1039__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1066__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1066__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1067__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__1067__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__1039__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1067__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1067__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1068__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__1068__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__1039__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1068__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1068__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1070__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1070__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1070__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1070__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1071__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1071__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1069__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1071__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1071__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1072__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1072__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1072__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1072__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1073__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1073__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1073__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1073__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1074__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1074__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1074__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1074__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1075__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1075__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1075__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1075__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1039__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1069__data;
    __Vtask_tb_npu_single_core__DOT__query_task__1038__result 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1039__result;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__1037__result 
        = __Vtask_tb_npu_single_core__DOT__query_task__1038__result;
    __Vtask_tb_npu_single_core__DOT__check__1076__message = 
        std::string{"task ACK failed"};
    __Vtask_tb_npu_single_core__DOT__check__1076__condition 
        = (0ULL == __Vtask_tb_npu_single_core__DOT__acknowledge_task__1037__result);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1076__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1076__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__data = 0xfc70012cfffe0001ULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__address = 0xa00U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__1077__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1078__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1079__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1079__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1079__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1079__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1080__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1080__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1078__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1080__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1080__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1081__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1081__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1081__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1081__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1082__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1082__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1082__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1082__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1083__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1083__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1083__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1083__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__data = 0x8fff900060005ULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__address = 0xa10U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__1084__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1085__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1086__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1086__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1086__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1086__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1087__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1087__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1085__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1087__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1087__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1088__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1088__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1088__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1088__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1089__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1089__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1089__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1089__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1090__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1090__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1090__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1090__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__numeric = 0xffU;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__dst = 0xa20ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__src2 = 0ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__src1 = 0xa10ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__src0 = 0xa00ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__bytes = 0xc0U;
    __Vtask_tb_npu_single_core__DOT__init_common__1091__engine = 3U;
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        tb_npu_single_core__DOT__int16_vector_desc[__Vilp1] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, tb_npu_single_core__DOT__int16_vector_desc, 0U, 1U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, tb_npu_single_core__DOT__int16_vector_desc, 1U, (IData)(__Vtask_tb_npu_single_core__DOT__init_common__1091__engine));
    __Vtask_tb_npu_single_core__DOT__put_u16__1094__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__1091__bytes;
    __Vtask_tb_npu_single_core__DOT__put_u16__1094__offset = 2U;
    VL_ASSIGNSEL_WI(2048, 16, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u16__1094__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u16__1094__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__int16_vector_desc, 8U, __Vtask_tb_npu_single_core__DOT__init_common__1091__src0);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__int16_vector_desc, 0x10U, __Vtask_tb_npu_single_core__DOT__init_common__1091__src1);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__int16_vector_desc, 0x18U, __Vtask_tb_npu_single_core__DOT__init_common__1091__src2);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, tb_npu_single_core__DOT__int16_vector_desc, 0x20U, __Vtask_tb_npu_single_core__DOT__init_common__1091__dst);
    __Vtask_tb_npu_single_core__DOT__put_u32__1099__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__1091__numeric;
    __Vtask_tb_npu_single_core__DOT__put_u32__1099__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1099__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1099__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1100__value = 1U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1100__offset = 0x40U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1100__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1100__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1101__value = 4U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1101__offset = 0x44U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1101__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1101__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1102__value = 4U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1102__offset = 0x48U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1102__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1102__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1103__value = 0U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1103__offset = 0x4cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1103__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1103__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1104__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1104__offset = 0x50U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1104__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1104__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1105__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1105__offset = 0x54U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1105__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1105__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1106__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1106__offset = 0x58U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1106__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1106__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1107__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1107__offset = 0x5cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1107__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1107__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1108__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1108__offset = 0x60U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1108__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1108__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1109__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1109__offset = 0x64U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1109__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1109__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1110__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1110__offset = 0x68U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1110__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1110__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1111__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1111__offset = 0x6cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1111__offset), 3U)), tb_npu_single_core__DOT__int16_vector_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1111__value);
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__bytes = 0xc0U;
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x3fU)) {
        __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__desc[__Vilp2] 
            = tb_npu_single_core__DOT__int16_vector_desc[__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__address = 0x1400ULL;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index = 0;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index 
            < __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__bytes)) {
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__value 
            = (0xffU & (((0U == (0x1fU & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index, 3U)))
                          ? 0U : (__Vtask_tb_npu_single_core__DOT__store_descriptor__1112__desc[
                                  (((IData)(7U) + (0x7ffU 
                                                   & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index, 3U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index, 3U))))) 
                        | (__Vtask_tb_npu_single_core__DOT__store_descriptor__1112__desc[
                           (0x3fU & (VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index, 3U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index, 3U)))));
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__address 
            = (__Vtask_tb_npu_single_core__DOT__store_descriptor__1112__address 
               + (QData)((IData)(__Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index)));
        if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__address)))) {
            VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__address);
            VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
        }
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                      & (IData)(
                                                                                (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__address 
                                                                                >> 3U)))] 
            = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                      (7U 
                                                       & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__address)), 3U)))) 
                & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__address 
                                    >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__value)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, 
                                                                   (7U 
                                                                    & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1113__address)), 3U))));
        __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__store_descriptor__1112__unnamedblk1__DOT__index);
    }
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__vector_l1_before_int16 
        = vlSelfRef.tb_npu_single_core__DOT__vector_l1_handshakes_q;
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[0U] = 0xa200c0U;
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[1U] = 0xa10000U;
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[2U] = 0xa0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__signal_event = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__wait1 = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__wait0 = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__payload[0U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__payload[1U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__payload[2U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[2U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__dtype = 3U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command_id = 0x105U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__compact_opcode = 0xfU;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command);
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[0U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[1U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[2U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[3U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[3U] 
        = ((0xffU & __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[3U]) 
           | (0xffffff00U & (0x80000000U | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__compact_opcode) 
                                             << 0x1aU) 
                                            | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command_id) 
                                                << 0x10U) 
                                               | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__wait0) 
                                                  << 8U))))));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[2U] 
        = ((0xffffffU & __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[2U]) 
           | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__signal_event) 
              << 0x18U));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[3U] 
        = ((0xffffff00U & __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[3U]) 
           | (0xffffffU & ((0xffffffU & (IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__wait1)) 
                           | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__signal_event) 
                              >> 8U))));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__payload[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__payload[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[2U]) 
           | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__dtype) 
               << 0x10U) | __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__payload[2U]));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__Vfuncout[0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__Vfuncout[1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__Vfuncout[2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[2U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__Vfuncout[3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__command[3U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__Vfuncout[0U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__Vfuncout[1U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__Vfuncout[2U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1114__Vfuncout[3U];
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__command_count = 1U;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__observed_response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__beat_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__beat_count 
        = VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__command_count, 1U);
    __Vtask_tb_npu_single_core__DOT__check__1116__message = 
        std::string{"invalid command burst count"};
    __Vtask_tb_npu_single_core__DOT__check__1116__condition 
        = ((1U <= __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__command_count) 
           & (8U >= __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__command_count));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1116__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1116__message));
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
        = (0xffU & (__Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__beat_count 
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
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index 
            < __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__command_count)) {
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0U;
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             647);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
            = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index)][1U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                            [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index)][0U])));
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i = 0xffU;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i 
            = (((IData)(1U) + VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index, 1U)) 
               == __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__beat_count);
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
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 1U;
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             647);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
            = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index)][3U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                            [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index)][2U])));
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i = 0xffU;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i 
            = (((IData)(2U) + VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index, 1U)) 
               == __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__beat_count);
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
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 2U;
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__unnamedblk2__DOT__command_index);
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
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         662);
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         662);
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1117__message = 
        std::string{"command burst response was not held"};
    __Vtask_tb_npu_single_core__DOT__check__1117__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_submit_commands__1115__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1117__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1117__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1118__message = 
        std::string{"FIXED command burst failed"};
    __Vtask_tb_npu_single_core__DOT__check__1118__condition 
        = ((0x63U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q)) 
           & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1118__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1118__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         670);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1119__expected_status = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1119__expected_command_id = 0x105U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1119__response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__address = 0x20008U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1121__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1121__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1121__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1121__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1122__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1122__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1120__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1122__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1122__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1123__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1123__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1123__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1123__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1124__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1124__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1124__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1124__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1125__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1125__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1125__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1125__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1126__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1126__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1126__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1126__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1119__response 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1120__data;
    __Vtask_tb_npu_single_core__DOT__check__1127__message = 
        std::string{"CFE response returned the wrong command_id"};
    __Vtask_tb_npu_single_core__DOT__check__1127__condition 
        = ((0xfffU & (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1119__response)) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1119__expected_command_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1127__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1127__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1128__message = 
        std::string{"CFE response returned the wrong status"};
    __Vtask_tb_npu_single_core__DOT__check__1128__condition 
        = ((0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__1119__response 
                             >> 0xcU))) == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1119__expected_status));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1128__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1128__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1129__message = 
        std::string{"CFE response fifo_free_entries exceeds the configured depth"};
    __Vtask_tb_npu_single_core__DOT__check__1129__condition 
        = (8U >= (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__1119__response 
                                   >> 0x14U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1129__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1129__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1130__message = 
        std::string{"CFE response reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__1130__condition 
        = (0ULL == (__Vtask_tb_npu_single_core__DOT__read_command_response__1119__response 
                    >> 0x1cU));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1130__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1130__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__ctl_request__1131__argument1 = 0xc350ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1131__argument0 = 4ULL;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__operation = 3U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1131__status = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2812388709021036570ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1131__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1131__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1132__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1133__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1133__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1133__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1133__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1134__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1134__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1132__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1134__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1134__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1135__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1135__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1135__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1135__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1136__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1136__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1136__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1136__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1137__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1137__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1137__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1137__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1131__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__address = 0x20028U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1138__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12809048700735337155ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1138__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12432113057625963753ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1138__strobe;
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
}

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__11(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__11\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1131__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1131__result = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1139__condition;
    __Vtask_tb_npu_single_core__DOT__check__1139__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1139__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1140__condition;
    __Vtask_tb_npu_single_core__DOT__check__1140__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1140__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1141__condition;
    __Vtask_tb_npu_single_core__DOT__check__1141__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1141__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1142__condition;
    __Vtask_tb_npu_single_core__DOT__check__1142__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1142__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1143__condition;
    __Vtask_tb_npu_single_core__DOT__check__1143__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1143__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1145__condition;
    __Vtask_tb_npu_single_core__DOT__check__1145__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1145__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1146__condition;
    __Vtask_tb_npu_single_core__DOT__check__1146__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1146__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1147__condition;
    __Vtask_tb_npu_single_core__DOT__check__1147__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1147__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1148__condition;
    __Vtask_tb_npu_single_core__DOT__check__1148__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1148__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1149__condition;
    __Vtask_tb_npu_single_core__DOT__check__1149__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1149__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1151__condition;
    __Vtask_tb_npu_single_core__DOT__check__1151__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1151__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1152__condition;
    __Vtask_tb_npu_single_core__DOT__check__1152__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1152__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1153__condition;
    __Vtask_tb_npu_single_core__DOT__check__1153__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1153__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1154__condition;
    __Vtask_tb_npu_single_core__DOT__check__1154__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1154__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1155__condition;
    __Vtask_tb_npu_single_core__DOT__check__1155__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1155__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1156__condition;
    __Vtask_tb_npu_single_core__DOT__check__1156__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1156__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1157__condition;
    __Vtask_tb_npu_single_core__DOT__check__1157__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1157__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1158__condition;
    __Vtask_tb_npu_single_core__DOT__check__1158__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1158__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1159__condition;
    __Vtask_tb_npu_single_core__DOT__check__1159__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1159__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1160__condition;
    __Vtask_tb_npu_single_core__DOT__check__1160__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1160__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1162__condition;
    __Vtask_tb_npu_single_core__DOT__check__1162__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1162__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1163__condition;
    __Vtask_tb_npu_single_core__DOT__check__1163__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1163__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1164__condition;
    __Vtask_tb_npu_single_core__DOT__check__1164__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1164__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1165__condition;
    __Vtask_tb_npu_single_core__DOT__check__1165__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1165__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1166__condition;
    __Vtask_tb_npu_single_core__DOT__check__1166__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1166__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1167__condition;
    __Vtask_tb_npu_single_core__DOT__check__1167__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1167__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1168__condition;
    __Vtask_tb_npu_single_core__DOT__check__1168__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1168__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1169__command_id;
    __Vtask_tb_npu_single_core__DOT__query_task__1169__command_id = 0;
    CData/*2:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1169__selector;
    __Vtask_tb_npu_single_core__DOT__query_task__1169__selector = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1169__result;
    __Vtask_tb_npu_single_core__DOT__query_task__1169__result = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1170__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1170__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1170__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1170__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1170__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1170__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1172__condition;
    __Vtask_tb_npu_single_core__DOT__check__1172__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1172__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1173__condition;
    __Vtask_tb_npu_single_core__DOT__check__1173__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1173__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1174__condition;
    __Vtask_tb_npu_single_core__DOT__check__1174__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1174__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1175__condition;
    __Vtask_tb_npu_single_core__DOT__check__1175__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1175__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1176__condition;
    __Vtask_tb_npu_single_core__DOT__check__1176__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1176__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1178__condition;
    __Vtask_tb_npu_single_core__DOT__check__1178__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1178__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1179__condition;
    __Vtask_tb_npu_single_core__DOT__check__1179__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1179__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1180__condition;
    __Vtask_tb_npu_single_core__DOT__check__1180__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1180__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1181__condition;
    __Vtask_tb_npu_single_core__DOT__check__1181__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1181__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1182__condition;
    __Vtask_tb_npu_single_core__DOT__check__1182__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1182__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1184__condition;
    __Vtask_tb_npu_single_core__DOT__check__1184__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1184__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1185__condition;
    __Vtask_tb_npu_single_core__DOT__check__1185__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1185__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1186__condition;
    __Vtask_tb_npu_single_core__DOT__check__1186__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1186__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1187__condition;
    __Vtask_tb_npu_single_core__DOT__check__1187__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1187__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1188__condition;
    __Vtask_tb_npu_single_core__DOT__check__1188__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1188__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1190__condition;
    __Vtask_tb_npu_single_core__DOT__check__1190__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1190__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1191__condition;
    __Vtask_tb_npu_single_core__DOT__check__1191__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1191__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1192__condition;
    __Vtask_tb_npu_single_core__DOT__check__1192__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1192__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1193__condition;
    __Vtask_tb_npu_single_core__DOT__check__1193__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1193__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1194__condition;
    __Vtask_tb_npu_single_core__DOT__check__1194__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1194__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1195__condition;
    __Vtask_tb_npu_single_core__DOT__check__1195__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1195__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1196__condition;
    __Vtask_tb_npu_single_core__DOT__check__1196__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1196__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1197__condition;
    __Vtask_tb_npu_single_core__DOT__check__1197__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1197__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1198__condition;
    __Vtask_tb_npu_single_core__DOT__check__1198__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1198__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1199__condition;
    __Vtask_tb_npu_single_core__DOT__check__1199__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1199__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1201__condition;
    __Vtask_tb_npu_single_core__DOT__check__1201__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1201__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1202__condition;
    __Vtask_tb_npu_single_core__DOT__check__1202__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1202__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1203__condition;
    __Vtask_tb_npu_single_core__DOT__check__1203__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1203__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1204__condition;
    __Vtask_tb_npu_single_core__DOT__check__1204__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1204__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1205__condition;
    __Vtask_tb_npu_single_core__DOT__check__1205__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1205__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1206__condition;
    __Vtask_tb_npu_single_core__DOT__check__1206__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1206__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1207__condition;
    __Vtask_tb_npu_single_core__DOT__check__1207__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1207__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1208__command_id;
    __Vtask_tb_npu_single_core__DOT__query_task__1208__command_id = 0;
    CData/*2:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1208__selector;
    __Vtask_tb_npu_single_core__DOT__query_task__1208__selector = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1209__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1209__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1209__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1209__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1209__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1209__argument1 = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1209__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1209__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1211__condition;
    __Vtask_tb_npu_single_core__DOT__check__1211__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1211__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1212__condition;
    __Vtask_tb_npu_single_core__DOT__check__1212__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1212__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1213__condition;
    __Vtask_tb_npu_single_core__DOT__check__1213__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1213__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1214__condition;
    __Vtask_tb_npu_single_core__DOT__check__1214__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1214__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1215__condition;
    __Vtask_tb_npu_single_core__DOT__check__1215__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1215__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1217__condition;
    __Vtask_tb_npu_single_core__DOT__check__1217__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1217__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1218__condition;
    __Vtask_tb_npu_single_core__DOT__check__1218__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1218__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1219__condition;
    __Vtask_tb_npu_single_core__DOT__check__1219__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1219__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1220__condition;
    __Vtask_tb_npu_single_core__DOT__check__1220__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1220__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1221__condition;
    __Vtask_tb_npu_single_core__DOT__check__1221__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1221__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1223__condition;
    __Vtask_tb_npu_single_core__DOT__check__1223__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1223__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1224__condition;
    __Vtask_tb_npu_single_core__DOT__check__1224__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1224__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1225__condition;
    __Vtask_tb_npu_single_core__DOT__check__1225__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1225__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1226__condition;
    __Vtask_tb_npu_single_core__DOT__check__1226__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1226__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1227__condition;
    __Vtask_tb_npu_single_core__DOT__check__1227__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1227__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1229__condition;
    __Vtask_tb_npu_single_core__DOT__check__1229__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1229__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1230__condition;
    __Vtask_tb_npu_single_core__DOT__check__1230__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1230__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1231__condition;
    __Vtask_tb_npu_single_core__DOT__check__1231__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1231__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1232__condition;
    __Vtask_tb_npu_single_core__DOT__check__1232__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1232__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1233__condition;
    __Vtask_tb_npu_single_core__DOT__check__1233__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1233__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1234__condition;
    __Vtask_tb_npu_single_core__DOT__check__1234__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1234__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1235__condition;
    __Vtask_tb_npu_single_core__DOT__check__1235__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1235__message;
    // Body
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
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1138__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1138__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1138__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1138__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1139__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1139__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1139__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1139__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1140__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1140__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1138__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1140__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1140__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1141__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1141__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1141__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1141__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1142__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1142__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1142__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1142__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1143__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1143__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1143__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1143__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__data 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1144__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1145__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1145__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1145__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1145__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1146__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1146__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1144__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1146__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1146__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1147__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1147__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1147__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1147__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1148__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1148__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1148__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1148__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1149__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1149__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1149__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1149__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__status = 0ULL;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__poll_count = 0U;
    {
        while ((0x4e20U > vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__1151__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1151__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1151__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1151__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1152__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1152__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1150__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1152__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1152__message));
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
            __Vtask_tb_npu_single_core__DOT__check__1153__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__1153__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1153__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1153__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1154__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__1154__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1154__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1154__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1155__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__1155__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1155__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1155__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1156__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__1156__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1156__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1156__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1150__data;
            if ((1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__status 
                               >> 1U)))) {
                goto __Vlabel0;
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__poll_count 
                = ((IData)(1U) + vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__poll_count);
        }
        __Vlabel0: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__1157__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__1157__condition 
        = (1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1157__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1157__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1158__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__1158__condition 
        = (1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1158__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1158__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1159__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__1159__condition 
        = (0U == (0xffU & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1159__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1159__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1160__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__1160__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1131__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1160__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1160__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1162__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1162__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1162__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1162__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1163__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1163__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1161__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1163__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1163__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1164__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1164__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1164__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1164__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1165__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1165__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1165__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1165__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1166__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1166__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1166__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1166__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1167__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1167__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1167__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1167__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1131__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1161__data;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = __Vtask_tb_npu_single_core__DOT__ctl_request__1131__result;
    __Vtask_tb_npu_single_core__DOT__check__1168__message = 
        std::string{"INT16 Vector FENCE returned a failure"};
    __Vtask_tb_npu_single_core__DOT__check__1168__condition 
        = (0U == (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__ctl_data)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1168__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1168__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__query_task__1169__selector = 0U;
    __Vtask_tb_npu_single_core__DOT__query_task__1169__command_id = 0x105U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__argument1 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__1169__selector));
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__argument0 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__1169__command_id));
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__operation = 2U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1170__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1171__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1172__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1172__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1172__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1172__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1173__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1173__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1171__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1173__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1173__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1174__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1174__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1174__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1174__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1175__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1175__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1175__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1175__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1176__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1176__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1176__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1176__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1170__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1177__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1178__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1178__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1178__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1178__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1179__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1179__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1177__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1179__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1179__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1180__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1180__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1180__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1180__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1181__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1181__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1181__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1181__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1182__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1182__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1182__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1182__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__1170__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1183__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1184__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1184__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1184__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1184__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1185__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1185__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1183__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1185__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1185__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1186__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1186__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1186__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1186__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1187__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1187__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1187__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1187__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1188__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1188__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1188__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1188__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__1170__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__1190__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1190__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1190__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1190__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1191__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1191__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1189__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1191__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1191__message));
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
            __Vtask_tb_npu_single_core__DOT__check__1192__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__1192__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1192__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1192__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1193__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__1193__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1193__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1193__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1194__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__1194__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1194__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1194__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1195__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__1195__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1195__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1195__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__1170__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1189__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__1170__status 
                               >> 1U)))) {
                goto __Vlabel1;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__1170__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__1170__poll_count);
        }
        __Vlabel1: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__1196__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__1196__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__1170__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1196__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1196__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1197__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__1197__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__1170__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1197__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1197__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1198__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__1198__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__1170__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1198__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1198__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1199__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__1199__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__1170__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1199__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1199__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1201__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1201__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1201__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1201__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1202__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1202__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1200__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1202__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1202__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1203__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1203__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1203__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1203__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1204__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1204__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1204__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1204__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1205__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1205__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1205__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1205__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1206__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1206__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1206__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1206__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1170__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1200__data;
    __Vtask_tb_npu_single_core__DOT__query_task__1169__result 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1170__result;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = __Vtask_tb_npu_single_core__DOT__query_task__1169__result;
    __Vtask_tb_npu_single_core__DOT__check__1207__message = 
        std::string{"INT16 Vector task status is incorrect"};
    __Vtask_tb_npu_single_core__DOT__check__1207__condition 
        = (IData)((3ULL == (0xfffULL & vlSelfRef.tb_npu_single_core__DOT__ctl_data)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1207__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1207__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__query_task__1208__selector = 3U;
    __Vtask_tb_npu_single_core__DOT__query_task__1208__command_id = 0x105U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1209__argument1 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__1208__selector));
    __Vtask_tb_npu_single_core__DOT__ctl_request__1209__argument0 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__1208__command_id));
    __Vtask_tb_npu_single_core__DOT__ctl_request__1209__operation = 2U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1209__status = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16269969706795683616ull);
    __Vtask_tb_npu_single_core__DOT__ctl_request__1209__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1209__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1210__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1211__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1211__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1211__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1211__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1212__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1212__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1210__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1212__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1212__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1213__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1213__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1213__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1213__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1214__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1214__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1214__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1214__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1215__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1215__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1215__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1215__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1209__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1216__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1217__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1217__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1217__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1217__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1218__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1218__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1216__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1218__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1218__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1219__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1219__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1219__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1219__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1220__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1220__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1220__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1220__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1221__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1221__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1221__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1221__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__1209__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1222__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1223__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1223__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1223__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1223__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1224__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1224__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1222__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1224__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1224__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1225__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1225__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1225__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1225__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1226__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1226__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1226__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1226__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1227__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1227__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1227__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1227__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1209__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1209__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__1209__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__1229__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1229__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1229__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1229__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1230__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1230__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1228__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1230__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1230__message));
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
            __Vtask_tb_npu_single_core__DOT__check__1231__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__1231__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1231__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1231__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1232__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__1232__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1232__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1232__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1233__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__1233__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1233__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1233__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1234__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__1234__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1234__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1234__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1209__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1228__data;
            if ((1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1209__status 
                               >> 1U)))) {
                goto __Vlabel2;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__1209__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__1209__poll_count);
        }
        __Vlabel2: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__1235__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__1235__condition 
        = (1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1209__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1235__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1235__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1236__message = 
        std::string{"control request stayed busy after completion"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1236__condition 
        = (1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1209__status)));
}
