// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core__Syms.h"
#include "Vtb_npu_single_core___024root.h"

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__12(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__12\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1208__result;
    __Vtask_tb_npu_single_core__DOT__query_task__1208__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1209__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1209__result = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1237__condition;
    __Vtask_tb_npu_single_core__DOT__check__1237__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1237__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1238__condition;
    __Vtask_tb_npu_single_core__DOT__check__1238__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1238__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1240__condition;
    __Vtask_tb_npu_single_core__DOT__check__1240__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1240__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1241__condition;
    __Vtask_tb_npu_single_core__DOT__check__1241__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1241__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1242__condition;
    __Vtask_tb_npu_single_core__DOT__check__1242__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1242__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1243__condition;
    __Vtask_tb_npu_single_core__DOT__check__1243__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1243__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1244__condition;
    __Vtask_tb_npu_single_core__DOT__check__1244__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1244__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1245__condition;
    __Vtask_tb_npu_single_core__DOT__check__1245__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1245__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1246__condition;
    __Vtask_tb_npu_single_core__DOT__check__1246__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1246__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_read_word__1247__address;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1247__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_read_word__1247__data;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1247__data = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1249__condition;
    __Vtask_tb_npu_single_core__DOT__check__1249__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1249__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1250__condition;
    __Vtask_tb_npu_single_core__DOT__check__1250__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1250__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1251__condition;
    __Vtask_tb_npu_single_core__DOT__check__1251__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1251__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1252__condition;
    __Vtask_tb_npu_single_core__DOT__check__1252__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1252__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1253__condition;
    __Vtask_tb_npu_single_core__DOT__check__1253__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1253__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1254__condition;
    __Vtask_tb_npu_single_core__DOT__check__1254__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1254__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1255__condition;
    __Vtask_tb_npu_single_core__DOT__check__1255__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1255__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1256__condition;
    __Vtask_tb_npu_single_core__DOT__check__1256__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1256__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__acknowledge_task__1257__command_id;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__1257__command_id = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__acknowledge_task__1257__result;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__1257__result = 0;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1258__command_id;
    __Vtask_tb_npu_single_core__DOT__query_task__1258__command_id = 0;
    CData/*2:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1258__selector;
    __Vtask_tb_npu_single_core__DOT__query_task__1258__selector = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__query_task__1258__result;
    __Vtask_tb_npu_single_core__DOT__query_task__1258__result = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1259__operation;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__operation = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1259__argument0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__argument0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1259__argument1;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__argument1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1259__result;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__result = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1259__status;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__status = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__ctl_request__1259__poll_count;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__poll_count = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1261__condition;
    __Vtask_tb_npu_single_core__DOT__check__1261__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1261__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1262__condition;
    __Vtask_tb_npu_single_core__DOT__check__1262__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1262__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1263__condition;
    __Vtask_tb_npu_single_core__DOT__check__1263__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1263__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1264__condition;
    __Vtask_tb_npu_single_core__DOT__check__1264__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1264__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1265__condition;
    __Vtask_tb_npu_single_core__DOT__check__1265__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1265__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1267__condition;
    __Vtask_tb_npu_single_core__DOT__check__1267__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1267__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1268__condition;
    __Vtask_tb_npu_single_core__DOT__check__1268__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1268__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1269__condition;
    __Vtask_tb_npu_single_core__DOT__check__1269__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1269__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1270__condition;
    __Vtask_tb_npu_single_core__DOT__check__1270__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1270__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1271__condition;
    __Vtask_tb_npu_single_core__DOT__check__1271__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1271__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1273__condition;
    __Vtask_tb_npu_single_core__DOT__check__1273__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1273__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1274__condition;
    __Vtask_tb_npu_single_core__DOT__check__1274__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1274__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1275__condition;
    __Vtask_tb_npu_single_core__DOT__check__1275__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1275__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1276__condition;
    __Vtask_tb_npu_single_core__DOT__check__1276__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1276__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1277__condition;
    __Vtask_tb_npu_single_core__DOT__check__1277__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1277__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1279__condition;
    __Vtask_tb_npu_single_core__DOT__check__1279__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1279__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1280__condition;
    __Vtask_tb_npu_single_core__DOT__check__1280__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1280__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1281__condition;
    __Vtask_tb_npu_single_core__DOT__check__1281__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1281__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1282__condition;
    __Vtask_tb_npu_single_core__DOT__check__1282__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1282__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1283__condition;
    __Vtask_tb_npu_single_core__DOT__check__1283__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1283__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1284__condition;
    __Vtask_tb_npu_single_core__DOT__check__1284__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1284__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1285__condition;
    __Vtask_tb_npu_single_core__DOT__check__1285__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1285__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1286__condition;
    __Vtask_tb_npu_single_core__DOT__check__1286__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1286__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1287__condition;
    __Vtask_tb_npu_single_core__DOT__check__1287__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1287__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1288__condition;
    __Vtask_tb_npu_single_core__DOT__check__1288__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1288__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1290__condition;
    __Vtask_tb_npu_single_core__DOT__check__1290__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1290__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1291__condition;
    __Vtask_tb_npu_single_core__DOT__check__1291__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1291__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1292__condition;
    __Vtask_tb_npu_single_core__DOT__check__1292__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1292__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1293__condition;
    __Vtask_tb_npu_single_core__DOT__check__1293__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1293__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1294__condition;
    __Vtask_tb_npu_single_core__DOT__check__1294__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1294__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1295__condition;
    __Vtask_tb_npu_single_core__DOT__check__1295__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1295__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1296__condition;
    __Vtask_tb_npu_single_core__DOT__check__1296__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1296__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1299__condition;
    __Vtask_tb_npu_single_core__DOT__check__1299__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1299__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1300__condition;
    __Vtask_tb_npu_single_core__DOT__check__1300__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1300__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1301__condition;
    __Vtask_tb_npu_single_core__DOT__check__1301__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1301__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1302__condition;
    __Vtask_tb_npu_single_core__DOT__check__1302__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1302__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1303__condition;
    __Vtask_tb_npu_single_core__DOT__check__1303__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1303__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1306__condition;
    __Vtask_tb_npu_single_core__DOT__check__1306__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1306__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1307__condition;
    __Vtask_tb_npu_single_core__DOT__check__1307__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1307__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1308__condition;
    __Vtask_tb_npu_single_core__DOT__check__1308__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1308__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1309__condition;
    __Vtask_tb_npu_single_core__DOT__check__1309__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1309__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1310__condition;
    __Vtask_tb_npu_single_core__DOT__check__1310__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1310__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1313__condition;
    __Vtask_tb_npu_single_core__DOT__check__1313__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1313__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1314__condition;
    __Vtask_tb_npu_single_core__DOT__check__1314__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1314__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1315__condition;
    __Vtask_tb_npu_single_core__DOT__check__1315__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1315__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1316__condition;
    __Vtask_tb_npu_single_core__DOT__check__1316__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1316__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1317__condition;
    __Vtask_tb_npu_single_core__DOT__check__1317__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1317__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1320__condition;
    __Vtask_tb_npu_single_core__DOT__check__1320__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1320__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1321__condition;
    __Vtask_tb_npu_single_core__DOT__check__1321__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1321__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1322__condition;
    __Vtask_tb_npu_single_core__DOT__check__1322__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1322__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1323__condition;
    __Vtask_tb_npu_single_core__DOT__check__1323__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1323__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1324__condition;
    __Vtask_tb_npu_single_core__DOT__check__1324__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1324__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1327__condition;
    __Vtask_tb_npu_single_core__DOT__check__1327__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1327__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1328__condition;
    __Vtask_tb_npu_single_core__DOT__check__1328__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1328__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1329__condition;
    __Vtask_tb_npu_single_core__DOT__check__1329__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1329__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1330__condition;
    __Vtask_tb_npu_single_core__DOT__check__1330__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1330__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1331__condition;
    __Vtask_tb_npu_single_core__DOT__check__1331__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1331__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__strobe = 0;
    // Body
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1236__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1236__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1237__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__1237__condition 
        = (0U == (0xffU & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1209__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1237__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1237__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1238__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__1238__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1209__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1238__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1238__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1240__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1240__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1240__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1240__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1241__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1241__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1239__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1241__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1241__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1242__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1242__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1242__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1242__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1243__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1243__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1243__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1243__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1244__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1244__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1244__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1244__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1245__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1245__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1245__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1245__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1209__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1239__data;
    __Vtask_tb_npu_single_core__DOT__query_task__1208__result 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1209__result;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = __Vtask_tb_npu_single_core__DOT__query_task__1208__result;
    __Vtask_tb_npu_single_core__DOT__check__1246__message = 
        std::string{"INT16 Vector progress is not four outputs"};
    __Vtask_tb_npu_single_core__DOT__check__1246__condition 
        = (4ULL == vlSelfRef.tb_npu_single_core__DOT__ctl_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1246__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1246__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1247__address = 0xa20U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_read_word__1247__address));
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1249__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1249__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1249__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1249__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1250__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1250__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1248__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1250__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1250__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1251__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1251__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1251__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1251__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1252__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1252__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1252__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1252__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1253__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1253__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1253__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1253__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1254__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1254__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1254__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1254__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1247__data 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1248__data;
    vlSelfRef.tb_npu_single_core__DOT__read_data = __Vtask_tb_npu_single_core__DOT__l1_read_word__1247__data;
    __Vtask_tb_npu_single_core__DOT__check__1255__message = 
        std::string{"INT16 Vector result is incorrect"};
    __Vtask_tb_npu_single_core__DOT__check__1255__condition 
        = (0xfc78012500040006ULL == vlSelfRef.tb_npu_single_core__DOT__read_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1255__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1255__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1256__message = 
        std::string{"INT16 Vector request count is incorrect"};
    __Vtask_tb_npu_single_core__DOT__check__1256__condition 
        = (vlSelfRef.tb_npu_single_core__DOT__vector_l1_handshakes_q 
           == ((IData)(0xcU) + vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__vector_l1_before_int16));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1256__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1256__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__1257__command_id = 0x105U;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__1257__result = 0;
    __Vtask_tb_npu_single_core__DOT__query_task__1258__selector = 4U;
    __Vtask_tb_npu_single_core__DOT__query_task__1258__command_id 
        = __Vtask_tb_npu_single_core__DOT__acknowledge_task__1257__command_id;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__argument1 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__1258__selector));
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__argument0 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__query_task__1258__command_id));
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__operation = 2U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__status = 0;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__poll_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1259__argument0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1260__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1261__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1261__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1261__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1261__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1262__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1262__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1260__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1262__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1262__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1263__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1263__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1263__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1263__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1264__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1264__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1264__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1264__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1265__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1265__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1265__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1265__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__data 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1259__argument1;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1266__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1267__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1267__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1267__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1267__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1268__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1268__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1266__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1268__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1268__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1269__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1269__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1269__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1269__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1270__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1270__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1270__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1270__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1271__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1271__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1271__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1271__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__data 
        = (QData)((IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__1259__operation));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1272__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1273__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1273__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1273__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1273__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1274__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1274__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1272__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1274__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1274__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1275__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1275__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1275__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1275__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1276__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1276__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1276__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1276__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1277__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1277__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1277__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1277__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__status = 0ULL;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__poll_count = 0U;
    {
        while ((0x4e20U > __Vtask_tb_npu_single_core__DOT__ctl_request__1259__poll_count)) {
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__address = 0x20038U;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__observed_data = 0;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__observed_response = 0;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__address;
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
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            __Vtask_tb_npu_single_core__DOT__check__1279__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1279__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1279__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1279__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1280__message = 
                std::string{"AXI Slave changed read response during host stall"};
            __Vtask_tb_npu_single_core__DOT__check__1280__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1278__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1280__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1280__message));
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
            __Vtask_tb_npu_single_core__DOT__check__1281__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            __Vtask_tb_npu_single_core__DOT__check__1281__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1281__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1281__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1282__message = 
                std::string{"AXI Slave returned the wrong RID"};
            __Vtask_tb_npu_single_core__DOT__check__1282__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1282__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1282__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1283__message = 
                std::string{"AXI Slave single read failed"};
            __Vtask_tb_npu_single_core__DOT__check__1283__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1283__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1283__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__check__1284__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            __Vtask_tb_npu_single_core__DOT__check__1284__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1284__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(__Vtask_tb_npu_single_core__DOT__check__1284__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            __Vtask_tb_npu_single_core__DOT__ctl_request__1259__status 
                = __Vtask_tb_npu_single_core__DOT__axi_read_single__1278__data;
            if ((1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__1259__status 
                               >> 1U)))) {
                goto __Vlabel0;
            }
            __Vtask_tb_npu_single_core__DOT__ctl_request__1259__poll_count 
                = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__ctl_request__1259__poll_count);
        }
        __Vlabel0: ;
    }
    __Vtask_tb_npu_single_core__DOT__check__1285__message = 
        std::string{"control request polling timed out"};
    __Vtask_tb_npu_single_core__DOT__check__1285__condition 
        = (1U & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__1259__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1285__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1285__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1286__message = 
        std::string{"control request stayed busy after completion"};
    __Vtask_tb_npu_single_core__DOT__check__1286__condition 
        = (1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__ctl_request__1259__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1286__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1286__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1287__message = 
        std::string{"control window reported an internal failure"};
    __Vtask_tb_npu_single_core__DOT__check__1287__condition 
        = (0U == (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__ctl_request__1259__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1287__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1287__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1288__message = 
        std::string{"control window status reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__1288__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & __Vtask_tb_npu_single_core__DOT__ctl_request__1259__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1288__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1288__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__address = 0x20040U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1290__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1290__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1290__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1290__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1291__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1291__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1289__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1291__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1291__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1292__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1292__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1292__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1292__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1293__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1293__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1293__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1293__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1294__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1294__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1294__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1294__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1295__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1295__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1295__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1295__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__ctl_request__1259__result 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1289__data;
    __Vtask_tb_npu_single_core__DOT__query_task__1258__result 
        = __Vtask_tb_npu_single_core__DOT__ctl_request__1259__result;
    __Vtask_tb_npu_single_core__DOT__acknowledge_task__1257__result 
        = __Vtask_tb_npu_single_core__DOT__query_task__1258__result;
    __Vtask_tb_npu_single_core__DOT__check__1296__message = 
        std::string{"task ACK failed"};
    __Vtask_tb_npu_single_core__DOT__check__1296__condition 
        = (0ULL == __Vtask_tb_npu_single_core__DOT__acknowledge_task__1257__result);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1296__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1296__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__data = 0xffff000300020001ULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__address = 0xb00U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__1297__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1298__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1299__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1299__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1299__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1299__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1300__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1300__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1298__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1300__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1300__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1301__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1301__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1301__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1301__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1302__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1302__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1302__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1302__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1303__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1303__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1303__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1303__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__strobe = 0xfU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__data = 0x20004ULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__address = 0xb08U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__1304__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1305__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1306__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1306__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1306__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1306__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1307__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1307__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1305__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1307__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1307__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1308__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1308__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1308__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1308__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1309__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1309__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1309__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1309__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1310__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1310__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1310__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1310__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__data = 0x10003ffff0002ULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__address = 0xb20U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__1311__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1312__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1313__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1313__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1313__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1313__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1314__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1314__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1312__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1314__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1314__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1315__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1315__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1315__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1315__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1316__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1316__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1316__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1316__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1317__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1317__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1317__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1317__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__strobe = 0xfU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__data = 0x4fffeULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__address = 0xb28U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__1318__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1319__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1320__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1320__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1320__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1320__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1321__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1321__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1319__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1321__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1321__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1322__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1322__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1322__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1322__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1323__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1323__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1323__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1323__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1324__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1324__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1324__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1324__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__strobe = 0xfU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__data = 0xffff0002ULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__address = 0xb40U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__1325__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1326__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1327__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1327__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1327__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1327__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1328__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1328__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1326__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1328__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1328__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1329__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1329__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1329__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1329__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1330__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1330__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1330__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1330__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1331__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1331__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1331__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1331__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__strobe = 0xfU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__data = 0x10003ULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__address = 0xb50U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__1332__address));
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1333__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5058203106927728054ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1333__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12951894277213677867ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1333__strobe;
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
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1333__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1333__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1333__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
}

extern const VlWide<64>/*2047:0*/ Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0;

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__13(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__13\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<64>/*2047:0*/ tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0;
    VL_ZERO_W(2048, tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0);
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1334__condition;
    __Vtask_tb_npu_single_core__DOT__check__1334__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1334__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1335__condition;
    __Vtask_tb_npu_single_core__DOT__check__1335__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1335__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1336__condition;
    __Vtask_tb_npu_single_core__DOT__check__1336__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1336__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1337__condition;
    __Vtask_tb_npu_single_core__DOT__check__1337__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1337__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1338__condition;
    __Vtask_tb_npu_single_core__DOT__check__1338__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1338__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__address;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__data;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__strobe;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__strobe = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1341__condition;
    __Vtask_tb_npu_single_core__DOT__check__1341__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1341__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1342__condition;
    __Vtask_tb_npu_single_core__DOT__check__1342__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1342__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1343__condition;
    __Vtask_tb_npu_single_core__DOT__check__1343__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1343__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1344__condition;
    __Vtask_tb_npu_single_core__DOT__check__1344__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1344__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1345__condition;
    __Vtask_tb_npu_single_core__DOT__check__1345__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1345__message;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1346__engine;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__engine = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1346__bytes;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__bytes = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1346__src0;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__src0 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1346__src1;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__src1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1346__src2;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__src2 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1346__dst;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__dst = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__init_common__1346__numeric;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__numeric = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__1349__offset;
    __Vtask_tb_npu_single_core__DOT__put_u16__1349__offset = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u16__1349__value;
    __Vtask_tb_npu_single_core__DOT__put_u16__1349__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1354__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1354__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1354__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1354__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1355__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1355__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1355__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1355__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1356__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1356__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1356__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1356__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1357__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1357__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1357__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1357__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1358__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1358__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1358__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1358__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1359__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1359__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1359__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1359__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1360__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1360__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1360__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1360__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1361__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1361__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1361__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1361__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1362__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1362__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1362__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1362__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1363__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1363__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1363__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1363__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1364__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1364__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1364__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1364__value = 0;
    SData/*15:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1365__offset;
    __Vtask_tb_npu_single_core__DOT__put_u32__1365__offset = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__put_u32__1365__value;
    __Vtask_tb_npu_single_core__DOT__put_u32__1365__value = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__address;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__address = 0;
    VlWide<64>/*2047:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__desc;
    VL_ZERO_W(2048, __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__desc);
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__bytes;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__bytes = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__value;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__value = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1371__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_command__1371__Vfuncout);
    QData/*47:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1371__descriptor_address;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__descriptor_address = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1371__command_id;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__command_id = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1371__engine;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__engine = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1371__opcode;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__opcode = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1371__wait0;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__wait0 = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1371__wait1;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__wait1 = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1371__signal_event;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__signal_event = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1371__low_word;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__low_word = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1371__high_word;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__high_word = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__Vfuncout);
    CData/*4:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__compact_opcode;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__compact_opcode = 0;
    SData/*9:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command_id;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command_id = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__dtype;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__dtype = 0;
    VlWide<3>/*79:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__payload;
    VL_ZERO_W(80, __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__payload);
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__wait0;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__wait0 = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__wait1;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__wait1 = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__signal_event;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__signal_event = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command);
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__address;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__address = 0;
    VlWide<64>/*2047:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc;
    VL_ZERO_W(2048, __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc);
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__bytes;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__bytes = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__address;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__address = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__value;
    __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__value = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1377__Vfuncout;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_command__1377__Vfuncout);
    QData/*47:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1377__descriptor_address;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__descriptor_address = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1377__command_id;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__command_id = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1377__engine;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__engine = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1377__opcode;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__opcode = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1377__wait0;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__wait0 = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1377__wait1;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__wait1 = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1377__signal_event;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__signal_event = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1377__low_word;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__low_word = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__make_command__1377__high_word;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__high_word = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__command_count;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__command_count = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__unnamedblk3__DOT__word_index;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__observed_response = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__beat_count;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__beat_count = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1379__condition;
    __Vtask_tb_npu_single_core__DOT__check__1379__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1379__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1380__condition;
    __Vtask_tb_npu_single_core__DOT__check__1380__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1380__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1381__condition;
    __Vtask_tb_npu_single_core__DOT__check__1381__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1381__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1382__expected_command_id;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1382__expected_command_id = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1382__expected_status;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1382__expected_status = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1382__response;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1382__response = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1384__condition;
    __Vtask_tb_npu_single_core__DOT__check__1384__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1384__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1385__condition;
    __Vtask_tb_npu_single_core__DOT__check__1385__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1385__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1386__condition;
    __Vtask_tb_npu_single_core__DOT__check__1386__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1386__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1387__condition;
    __Vtask_tb_npu_single_core__DOT__check__1387__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1387__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1388__condition;
    __Vtask_tb_npu_single_core__DOT__check__1388__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1388__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1389__condition;
    __Vtask_tb_npu_single_core__DOT__check__1389__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1389__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1390__condition;
    __Vtask_tb_npu_single_core__DOT__check__1390__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1390__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1391__condition;
    __Vtask_tb_npu_single_core__DOT__check__1391__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1391__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1392__condition;
    __Vtask_tb_npu_single_core__DOT__check__1392__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1392__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1393__condition;
    __Vtask_tb_npu_single_core__DOT__check__1393__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1393__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1394__expected_command_id;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1394__expected_command_id = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1394__expected_status;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1394__expected_status = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1394__response;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1394__response = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1396__condition;
    __Vtask_tb_npu_single_core__DOT__check__1396__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1396__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1397__condition;
    __Vtask_tb_npu_single_core__DOT__check__1397__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1397__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1398__condition;
    __Vtask_tb_npu_single_core__DOT__check__1398__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1398__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1399__condition;
    __Vtask_tb_npu_single_core__DOT__check__1399__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1399__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1400__condition;
    __Vtask_tb_npu_single_core__DOT__check__1400__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1400__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1401__condition;
    __Vtask_tb_npu_single_core__DOT__check__1401__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1401__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1402__condition;
    __Vtask_tb_npu_single_core__DOT__check__1402__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1402__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1403__condition;
    __Vtask_tb_npu_single_core__DOT__check__1403__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1403__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1404__condition;
    __Vtask_tb_npu_single_core__DOT__check__1404__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1404__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1405__condition;
    __Vtask_tb_npu_single_core__DOT__check__1405__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1405__message;
    SData/*11:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1406__expected_command_id;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1406__expected_command_id = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1406__expected_status;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1406__expected_status = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__read_command_response__1406__response;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1406__response = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1408__condition;
    __Vtask_tb_npu_single_core__DOT__check__1408__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1408__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1409__condition;
    __Vtask_tb_npu_single_core__DOT__check__1409__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1409__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1410__condition;
    __Vtask_tb_npu_single_core__DOT__check__1410__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1410__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1411__condition;
    __Vtask_tb_npu_single_core__DOT__check__1411__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1411__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1412__condition;
    __Vtask_tb_npu_single_core__DOT__check__1412__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1412__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1413__condition;
    __Vtask_tb_npu_single_core__DOT__check__1413__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1413__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1414__condition;
    __Vtask_tb_npu_single_core__DOT__check__1414__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1414__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1415__condition;
    __Vtask_tb_npu_single_core__DOT__check__1415__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1415__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1416__condition;
    __Vtask_tb_npu_single_core__DOT__check__1416__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1416__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1417__condition;
    __Vtask_tb_npu_single_core__DOT__check__1417__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1417__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1419__condition;
    __Vtask_tb_npu_single_core__DOT__check__1419__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1419__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1420__condition;
    __Vtask_tb_npu_single_core__DOT__check__1420__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1420__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1421__condition;
    __Vtask_tb_npu_single_core__DOT__check__1421__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1421__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1422__condition;
    __Vtask_tb_npu_single_core__DOT__check__1422__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1422__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1423__condition;
    __Vtask_tb_npu_single_core__DOT__check__1423__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1423__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1425__condition;
    __Vtask_tb_npu_single_core__DOT__check__1425__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1425__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1426__condition;
    __Vtask_tb_npu_single_core__DOT__check__1426__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1426__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1427__condition;
    __Vtask_tb_npu_single_core__DOT__check__1427__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1427__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1428__condition;
    __Vtask_tb_npu_single_core__DOT__check__1428__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1428__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1429__condition;
    __Vtask_tb_npu_single_core__DOT__check__1429__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1429__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1431__condition;
    __Vtask_tb_npu_single_core__DOT__check__1431__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1431__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1432__condition;
    __Vtask_tb_npu_single_core__DOT__check__1432__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1432__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1433__condition;
    __Vtask_tb_npu_single_core__DOT__check__1433__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1433__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1434__condition;
    __Vtask_tb_npu_single_core__DOT__check__1434__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1434__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1435__condition;
    __Vtask_tb_npu_single_core__DOT__check__1435__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1435__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__address;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__data = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__strobe = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1437__condition;
    __Vtask_tb_npu_single_core__DOT__check__1437__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1437__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1438__condition;
    __Vtask_tb_npu_single_core__DOT__check__1438__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1438__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1439__condition;
    __Vtask_tb_npu_single_core__DOT__check__1439__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1439__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1440__condition;
    __Vtask_tb_npu_single_core__DOT__check__1440__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1440__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1441__condition;
    __Vtask_tb_npu_single_core__DOT__check__1441__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1441__message;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1442__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1442__address = 0;
    VlWide<64>/*2047:0*/ __Vtemp_2;
    // Body
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1333__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1334__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1334__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1334__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1334__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1335__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1335__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1333__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1335__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1335__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1336__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1336__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1336__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1336__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1337__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1337__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1337__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1337__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1338__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1338__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1338__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1338__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__strobe = 0xfU;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__data = 0x4fffeULL;
    __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__address = 0xb60U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__strobe 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__strobe;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__data 
        = __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__data;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_write_word__1339__address));
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1340__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1341__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1341__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1341__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1341__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1342__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1342__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1340__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1342__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1342__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1343__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1343__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1343__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1343__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1344__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1344__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1344__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1344__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1345__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1345__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1345__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1345__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__numeric = 0xafU;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__dst = 0xc00ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__src2 = 0ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__src1 = 0xb20ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__src0 = 0xb00ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__bytes = 0x100U;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__engine = 2U;
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb_npu_single_core__DOT__matrix_desc[__Vilp1] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0U, 1U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 1U, (IData)(__Vtask_tb_npu_single_core__DOT__init_common__1346__engine));
    __Vtask_tb_npu_single_core__DOT__put_u16__1349__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__1346__bytes;
    __Vtask_tb_npu_single_core__DOT__put_u16__1349__offset = 2U;
    VL_ASSIGNSEL_WI(2048, 16, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u16__1349__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u16__1349__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 8U, __Vtask_tb_npu_single_core__DOT__init_common__1346__src0);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x10U, __Vtask_tb_npu_single_core__DOT__init_common__1346__src1);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x18U, __Vtask_tb_npu_single_core__DOT__init_common__1346__src2);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x20U, __Vtask_tb_npu_single_core__DOT__init_common__1346__dst);
    __Vtask_tb_npu_single_core__DOT__put_u32__1354__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__1346__numeric;
    __Vtask_tb_npu_single_core__DOT__put_u32__1354__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1354__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1354__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1355__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1355__offset = 0x40U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1355__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1355__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1356__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1356__offset = 0x44U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1356__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1356__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1357__value = 3U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1357__offset = 0x48U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1357__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1357__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1358__value = 1U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1358__offset = 0x4cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1358__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1358__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1359__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1359__offset = 0x50U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1359__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1359__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1360__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1360__offset = 0x54U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1360__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1360__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1361__value = 3U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1361__offset = 0x58U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1361__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1361__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1362__value = 0x80U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1362__offset = 0x5cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1362__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1362__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1363__value = 6U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1363__offset = 0x60U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1363__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1363__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1364__value = 4U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1364__offset = 0x64U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1364__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1364__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1365__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1365__offset = 0x68U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1365__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1365__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x90U, 5U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x91U, 5U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x92U, 4U);
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x3fU)) {
        tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[__Vilp2] 
            = vlSelfRef.tb_npu_single_core__DOT__matrix_desc[__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][1U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[1U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][2U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[2U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][3U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[3U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][4U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[4U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][5U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[5U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][6U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[6U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][7U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[7U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][8U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[8U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][9U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[9U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0xaU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xaU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0xbU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xbU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0xcU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xcU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0xdU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xdU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0xeU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xeU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0xfU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xfU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x10U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x10U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x11U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x11U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x12U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x12U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x13U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x13U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x14U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x14U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x15U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x15U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x16U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x16U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x17U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x17U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x18U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x18U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x19U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x19U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x1aU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1aU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x1bU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1bU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x1cU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1cU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x1dU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1dU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x1eU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1eU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x1fU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1fU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x20U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x20U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x21U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x21U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x22U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x22U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x23U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x23U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x24U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x24U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x25U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x25U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x26U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x26U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x27U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x27U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x28U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x28U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x29U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x29U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x2aU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2aU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x2bU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2bU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x2cU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2cU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x2dU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2dU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x2eU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2eU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x2fU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2fU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x30U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x30U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x31U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x31U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x32U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x32U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x33U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x33U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x34U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x34U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x35U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x35U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x36U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x36U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x37U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x37U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x38U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x38U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x39U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x39U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x3aU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3aU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x3bU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3bU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x3cU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3cU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x3dU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3dU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x3eU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3eU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[0U][0x3fU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3fU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__bytes = 0x100U;
    IData/*31:0*/ __Vilp3;
    __Vilp3 = 0U;
    while ((__Vilp3 <= 0x3fU)) {
        __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__desc[__Vilp3] 
            = vlSelfRef.tb_npu_single_core__DOT__matrix_desc[__Vilp3];
        __Vilp3 = ((IData)(1U) + __Vilp3);
    }
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__address = 0x1500ULL;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index = 0;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index 
            < __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__bytes)) {
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__value 
            = (0xffU & (((0U == (0x1fU & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index, 3U)))
                          ? 0U : (__Vtask_tb_npu_single_core__DOT__store_descriptor__1369__desc[
                                  (((IData)(7U) + (0x7ffU 
                                                   & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index, 3U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index, 3U))))) 
                        | (__Vtask_tb_npu_single_core__DOT__store_descriptor__1369__desc[
                           (0x3fU & (VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index, 3U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index, 3U)))));
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address 
            = (__Vtask_tb_npu_single_core__DOT__store_descriptor__1369__address 
               + (QData)((IData)(__Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index)));
        if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address)))) {
            VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address);
            VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
        }
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                      & (IData)(
                                                                                (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address 
                                                                                >> 3U)))] 
            = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                      (7U 
                                                       & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address)), 3U)))) 
                & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address 
                                    >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__value)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, 
                                                                   (7U 
                                                                    & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address)), 3U))));
        __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index);
    }
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__signal_event = 0xfffU;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__wait1 = 0xfffU;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__wait0 = 0xfffU;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__opcode = 0x40U;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__engine = 2U;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__command_id = 0x106U;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__descriptor_address = 0x1500ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__low_word = 0;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__high_word = 0;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__low_word = 0ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__high_word = 0ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__low_word 
        = (((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1371__engine)) 
            << 0x3cU) | (((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1371__command_id)) 
                          << 0x30U) | __Vfunc_tb_npu_single_core__DOT__make_command__1371__descriptor_address));
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__high_word 
        = ((0xffffffffffffff00ULL & __Vfunc_tb_npu_single_core__DOT__make_command__1371__high_word) 
           | (IData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1371__opcode)));
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__high_word 
        = ((0xfffffULL & __Vfunc_tb_npu_single_core__DOT__make_command__1371__high_word) 
           | (((QData)((IData)((0x1000000U | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1371__signal_event) 
                                               << 0xcU) 
                                              | (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1371__wait1))))) 
               << 0x20U) | ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1371__wait0)) 
                            << 0x14U)));
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__Vfuncout[0U] 
        = (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1371__low_word);
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__Vfuncout[1U] 
        = (IData)((__Vfunc_tb_npu_single_core__DOT__make_command__1371__low_word 
                   >> 0x20U));
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__Vfuncout[2U] 
        = (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1371__high_word);
    __Vfunc_tb_npu_single_core__DOT__make_command__1371__Vfuncout[3U] 
        = (IData)((__Vfunc_tb_npu_single_core__DOT__make_command__1371__high_word 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__1371__Vfuncout[0U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__1371__Vfuncout[1U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__1371__Vfuncout[2U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[0U][3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__1371__Vfuncout[3U];
    __Vtask_tb_npu_single_core__DOT__init_common__1346__numeric = 0xafU;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__dst = 0xc40ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__src2 = 0ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__src1 = 0xb40ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__src0 = 0xb00ULL;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__bytes = 0x100U;
    __Vtask_tb_npu_single_core__DOT__init_common__1346__engine = 2U;
    IData/*31:0*/ __Vilp4;
    __Vilp4 = 0U;
    while ((__Vilp4 <= 0x3fU)) {
        vlSelfRef.tb_npu_single_core__DOT__matrix_desc[__Vilp4] 
            = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp4];
        __Vilp4 = ((IData)(1U) + __Vilp4);
    }
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0U, 1U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 1U, (IData)(__Vtask_tb_npu_single_core__DOT__init_common__1346__engine));
    __Vtask_tb_npu_single_core__DOT__put_u16__1349__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__1346__bytes;
    __Vtask_tb_npu_single_core__DOT__put_u16__1349__offset = 2U;
    VL_ASSIGNSEL_WI(2048, 16, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u16__1349__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u16__1349__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 8U, __Vtask_tb_npu_single_core__DOT__init_common__1346__src0);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x10U, __Vtask_tb_npu_single_core__DOT__init_common__1346__src1);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x18U, __Vtask_tb_npu_single_core__DOT__init_common__1346__src2);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x20U, __Vtask_tb_npu_single_core__DOT__init_common__1346__dst);
    __Vtask_tb_npu_single_core__DOT__put_u32__1354__value 
        = __Vtask_tb_npu_single_core__DOT__init_common__1346__numeric;
    __Vtask_tb_npu_single_core__DOT__put_u32__1354__offset = 0x38U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1354__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1354__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1355__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1355__offset = 0x40U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1355__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1355__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1356__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1356__offset = 0x44U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1356__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1356__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1357__value = 3U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1357__offset = 0x48U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1357__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1357__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1358__value = 1U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1358__offset = 0x4cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1358__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1358__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1359__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1359__offset = 0x50U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1359__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1359__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1360__value = 2U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1360__offset = 0x54U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1360__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1360__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1361__value = 3U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1361__offset = 0x58U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1361__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1361__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1362__value = 0x80U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1362__offset = 0x5cU;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1362__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1362__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1363__value = 6U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1363__offset = 0x60U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1363__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1363__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1364__value = 4U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1364__offset = 0x64U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1364__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1364__value);
    __Vtask_tb_npu_single_core__DOT__put_u32__1365__value = 8U;
    __Vtask_tb_npu_single_core__DOT__put_u32__1365__offset = 0x68U;
    VL_ASSIGNSEL_WI(2048, 32, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(__Vtask_tb_npu_single_core__DOT__put_u32__1365__offset), 3U)), vlSelfRef.tb_npu_single_core__DOT__matrix_desc, __Vtask_tb_npu_single_core__DOT__put_u32__1365__value);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x90U, 5U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x91U, 6U);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, vlSelfRef.tb_npu_single_core__DOT__matrix_desc, 0x92U, 4U);
    IData/*31:0*/ __Vilp5;
    __Vilp5 = 0U;
    while ((__Vilp5 <= 0x3fU)) {
        tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[__Vilp5] 
            = vlSelfRef.tb_npu_single_core__DOT__matrix_desc[__Vilp5];
        __Vilp5 = ((IData)(1U) + __Vilp5);
    }
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][1U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[1U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][2U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[2U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][3U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[3U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][4U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[4U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][5U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[5U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][6U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[6U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][7U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[7U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][8U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[8U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][9U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[9U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0xaU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xaU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0xbU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xbU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0xcU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xcU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0xdU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xdU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0xeU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xeU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0xfU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0xfU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x10U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x10U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x11U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x11U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x12U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x12U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x13U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x13U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x14U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x14U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x15U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x15U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x16U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x16U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x17U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x17U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x18U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x18U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x19U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x19U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x1aU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1aU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x1bU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1bU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x1cU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1cU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x1dU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1dU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x1eU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1eU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x1fU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x1fU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x20U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x20U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x21U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x21U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x22U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x22U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x23U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x23U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x24U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x24U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x25U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x25U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x26U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x26U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x27U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x27U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x28U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x28U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x29U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x29U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x2aU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2aU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x2bU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2bU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x2cU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2cU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x2dU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2dU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x2eU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2eU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x2fU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x2fU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x30U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x30U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x31U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x31U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x32U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x32U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x33U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x33U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x34U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x34U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x35U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x35U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x36U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x36U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x37U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x37U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x38U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x38U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x39U] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x39U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x3aU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3aU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x3bU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3bU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x3cU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3cU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x3dU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3dU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x3eU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3eU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[1U][0x3fU] 
        = tb_npu_single_core__DOT____Vlvbound_h6c99b38f__0[0x3fU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__bytes = 0x100U;
    IData/*31:0*/ __Vilp6;
    __Vilp6 = 0U;
    while ((__Vilp6 <= 0x3fU)) {
        __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__desc[__Vilp6] 
            = vlSelfRef.tb_npu_single_core__DOT__matrix_desc[__Vilp6];
        __Vilp6 = ((IData)(1U) + __Vilp6);
    }
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__address = 0x1600ULL;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index = 0;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index 
            < __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__bytes)) {
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__value 
            = (0xffU & (((0U == (0x1fU & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index, 3U)))
                          ? 0U : (__Vtask_tb_npu_single_core__DOT__store_descriptor__1369__desc[
                                  (((IData)(7U) + (0x7ffU 
                                                   & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index, 3U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index, 3U))))) 
                        | (__Vtask_tb_npu_single_core__DOT__store_descriptor__1369__desc[
                           (0x3fU & (VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index, 3U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index, 3U)))));
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address 
            = (__Vtask_tb_npu_single_core__DOT__store_descriptor__1369__address 
               + (QData)((IData)(__Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index)));
        if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address)))) {
            VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address);
            VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
        }
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                      & (IData)(
                                                                                (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address 
                                                                                >> 3U)))] 
            = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                      (7U 
                                                       & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address)), 3U)))) 
                & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address 
                                    >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__value)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, 
                                                                   (7U 
                                                                    & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1370__address)), 3U))));
        __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__store_descriptor__1369__unnamedblk1__DOT__index);
    }
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[0U] = 0x104261U;
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[1U] = 0x2d00c40U;
    vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[2U] = 0xb0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__signal_event = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__wait1 = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__wait0 = 0xffU;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__payload[0U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__payload[1U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__payload[2U] 
        = vlSelfRef.tb_npu_single_core__DOT__unnamedblk4__DOT__v2_payload[2U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__dtype = 3U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command_id = 0x107U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__compact_opcode = 0xbU;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command);
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[0U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[1U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[2U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[3U] = 0U;
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[3U] 
        = ((0xffU & __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[3U]) 
           | (0xffffff00U & (0x80000000U | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__compact_opcode) 
                                             << 0x1aU) 
                                            | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command_id) 
                                                << 0x10U) 
                                               | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__wait0) 
                                                  << 8U))))));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[2U] 
        = ((0xffffffU & __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[2U]) 
           | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__signal_event) 
              << 0x18U));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[3U] 
        = ((0xffffff00U & __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[3U]) 
           | (0xffffffU & ((0xffffffU & (IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__wait1)) 
                           | ((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__signal_event) 
                              >> 8U))));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__payload[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__payload[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[2U] 
        = ((0xfffc0000U & __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[2U]) 
           | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__dtype) 
               << 0x10U) | __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__payload[2U]));
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__Vfuncout[0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[0U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__Vfuncout[1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[1U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__Vfuncout[2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[2U];
    __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__Vfuncout[3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__command[3U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__Vfuncout[0U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__Vfuncout[1U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__Vfuncout[2U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[1U][3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_v2_command__1372__Vfuncout[3U];
    __Vtemp_2[1U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][1U];
    __Vtemp_2[2U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][2U];
    __Vtemp_2[3U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][3U];
    __Vtemp_2[4U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][4U];
    __Vtemp_2[5U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][5U];
    __Vtemp_2[6U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][6U];
    __Vtemp_2[7U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][7U];
    __Vtemp_2[8U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][8U];
    __Vtemp_2[9U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][9U];
    __Vtemp_2[0xaU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0xaU];
    __Vtemp_2[0xbU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0xbU];
    __Vtemp_2[0xcU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0xcU];
    __Vtemp_2[0xdU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0xdU];
    __Vtemp_2[0xeU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0xeU];
    __Vtemp_2[0xfU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0xfU];
    __Vtemp_2[0x10U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x10U];
    __Vtemp_2[0x11U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x11U];
    __Vtemp_2[0x12U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x12U];
    __Vtemp_2[0x13U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x13U];
    __Vtemp_2[0x14U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x14U];
    __Vtemp_2[0x15U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x15U];
    __Vtemp_2[0x16U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x16U];
    __Vtemp_2[0x17U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x17U];
    __Vtemp_2[0x18U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x18U];
    __Vtemp_2[0x19U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x19U];
    __Vtemp_2[0x1aU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x1aU];
    __Vtemp_2[0x1bU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x1bU];
    __Vtemp_2[0x1cU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x1cU];
    __Vtemp_2[0x1dU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x1dU];
    __Vtemp_2[0x1eU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x1eU];
    __Vtemp_2[0x1fU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x1fU];
    __Vtemp_2[0x20U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x20U];
    __Vtemp_2[0x21U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x21U];
    __Vtemp_2[0x22U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x22U];
    __Vtemp_2[0x23U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x23U];
    __Vtemp_2[0x24U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x24U];
    __Vtemp_2[0x25U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x25U];
    __Vtemp_2[0x26U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x26U];
    __Vtemp_2[0x27U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x27U];
    __Vtemp_2[0x28U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x28U];
    __Vtemp_2[0x29U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x29U];
    __Vtemp_2[0x2aU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x2aU];
    __Vtemp_2[0x2bU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x2bU];
    __Vtemp_2[0x2cU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x2cU];
    __Vtemp_2[0x2dU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x2dU];
    __Vtemp_2[0x2eU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x2eU];
    __Vtemp_2[0x2fU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x2fU];
    __Vtemp_2[0x30U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x30U];
    __Vtemp_2[0x31U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x31U];
    __Vtemp_2[0x32U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x32U];
    __Vtemp_2[0x33U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x33U];
    __Vtemp_2[0x34U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x34U];
    __Vtemp_2[0x35U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x35U];
    __Vtemp_2[0x36U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x36U];
    __Vtemp_2[0x37U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x37U];
    __Vtemp_2[0x38U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x38U];
    __Vtemp_2[0x39U] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x39U];
    __Vtemp_2[0x3aU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x3aU];
    __Vtemp_2[0x3bU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x3bU];
    __Vtemp_2[0x3cU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x3cU];
    __Vtemp_2[0x3dU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x3dU];
    __Vtemp_2[0x3eU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x3eU];
    __Vtemp_2[0x3fU] = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0x3fU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [0U][0U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][1U] 
        = __Vtemp_2[1U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][2U] 
        = __Vtemp_2[2U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][3U] 
        = __Vtemp_2[3U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][4U] 
        = __Vtemp_2[4U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][5U] 
        = __Vtemp_2[5U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][6U] 
        = __Vtemp_2[6U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][7U] 
        = __Vtemp_2[7U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][8U] 
        = __Vtemp_2[8U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][9U] 
        = __Vtemp_2[9U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0xaU] 
        = __Vtemp_2[0xaU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0xbU] 
        = __Vtemp_2[0xbU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0xcU] 
        = __Vtemp_2[0xcU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0xdU] 
        = __Vtemp_2[0xdU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0xeU] 
        = __Vtemp_2[0xeU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0xfU] 
        = __Vtemp_2[0xfU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x10U] 
        = __Vtemp_2[0x10U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x11U] 
        = __Vtemp_2[0x11U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x12U] 
        = __Vtemp_2[0x12U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x13U] 
        = __Vtemp_2[0x13U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x14U] 
        = __Vtemp_2[0x14U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x15U] 
        = __Vtemp_2[0x15U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x16U] 
        = __Vtemp_2[0x16U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x17U] 
        = __Vtemp_2[0x17U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x18U] 
        = __Vtemp_2[0x18U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x19U] 
        = __Vtemp_2[0x19U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x1aU] 
        = __Vtemp_2[0x1aU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x1bU] 
        = __Vtemp_2[0x1bU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x1cU] 
        = __Vtemp_2[0x1cU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x1dU] 
        = __Vtemp_2[0x1dU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x1eU] 
        = __Vtemp_2[0x1eU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x1fU] 
        = __Vtemp_2[0x1fU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x20U] 
        = __Vtemp_2[0x20U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x21U] 
        = __Vtemp_2[0x21U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x22U] 
        = __Vtemp_2[0x22U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x23U] 
        = __Vtemp_2[0x23U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x24U] 
        = __Vtemp_2[0x24U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x25U] 
        = __Vtemp_2[0x25U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x26U] 
        = __Vtemp_2[0x26U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x27U] 
        = __Vtemp_2[0x27U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x28U] 
        = __Vtemp_2[0x28U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x29U] 
        = __Vtemp_2[0x29U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x2aU] 
        = __Vtemp_2[0x2aU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x2bU] 
        = __Vtemp_2[0x2bU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x2cU] 
        = __Vtemp_2[0x2cU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x2dU] 
        = __Vtemp_2[0x2dU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x2eU] 
        = __Vtemp_2[0x2eU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x2fU] 
        = __Vtemp_2[0x2fU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x30U] 
        = __Vtemp_2[0x30U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x31U] 
        = __Vtemp_2[0x31U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x32U] 
        = __Vtemp_2[0x32U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x33U] 
        = __Vtemp_2[0x33U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x34U] 
        = __Vtemp_2[0x34U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x35U] 
        = __Vtemp_2[0x35U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x36U] 
        = __Vtemp_2[0x36U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x37U] 
        = __Vtemp_2[0x37U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x38U] 
        = __Vtemp_2[0x38U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x39U] 
        = __Vtemp_2[0x39U];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x3aU] 
        = __Vtemp_2[0x3aU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x3bU] 
        = __Vtemp_2[0x3bU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x3cU] 
        = __Vtemp_2[0x3cU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x3dU] 
        = __Vtemp_2[0x3dU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x3eU] 
        = __Vtemp_2[0x3eU];
    vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc[2U][0x3fU] 
        = __Vtemp_2[0x3fU];
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(vlSymsp, 
                                                               vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
                                                               [2U], 0x20U, 0xc40ULL);
    vlSelfRef.__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(vlSymsp, 
                                                              vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
                                                              [2U], 0x90U, 7U);
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__bytes = 0x100U;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[1U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][1U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[2U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][2U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[3U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][3U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[4U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][4U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[5U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][5U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[6U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][6U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[7U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][7U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[8U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][8U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[9U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][9U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0xaU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0xaU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0xbU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0xbU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0xcU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0xcU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0xdU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0xdU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0xeU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0xeU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0xfU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0xfU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x10U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x10U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x11U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x11U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x12U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x12U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x13U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x13U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x14U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x14U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x15U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x15U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x16U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x16U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x17U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x17U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x18U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x18U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x19U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x19U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x1aU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x1aU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x1bU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x1bU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x1cU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x1cU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x1dU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x1dU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x1eU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x1eU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x1fU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x1fU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x20U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x20U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x21U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x21U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x22U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x22U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x23U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x23U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x24U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x24U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x25U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x25U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x26U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x26U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x27U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x27U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x28U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x28U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x29U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x29U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x2aU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x2aU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x2bU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x2bU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x2cU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x2cU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x2dU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x2dU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x2eU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x2eU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x2fU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x2fU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x30U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x30U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x31U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x31U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x32U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x32U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x33U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x33U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x34U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x34U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x35U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x35U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x36U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x36U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x37U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x37U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x38U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x38U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x39U] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x39U];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x3aU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x3aU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x3bU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x3bU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x3cU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x3cU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x3dU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x3dU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x3eU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x3eU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[0x3fU] 
        = vlSelfRef.tb_npu_single_core__DOT__int16_matrix_desc
        [2U][0x3fU];
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__address = 0x1700ULL;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index = 0;
    __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index 
            < __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__bytes)) {
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__value 
            = (0xffU & (((0U == (0x1fU & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index, 3U)))
                          ? 0U : (__Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[
                                  (((IData)(7U) + (0x7ffU 
                                                   & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index, 3U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index, 3U))))) 
                        | (__Vtask_tb_npu_single_core__DOT__store_descriptor__1375__desc[
                           (0x3fU & (VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index, 3U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(11,32,32, __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index, 3U)))));
        __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__address 
            = (__Vtask_tb_npu_single_core__DOT__store_descriptor__1375__address 
               + (QData)((IData)(__Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index)));
        if (VL_UNLIKELY(((0x4000ULL <= __Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__address)))) {
            VL_WRITEF_NX("[%0t] %%Fatal: tb_axi_memory_model.sv:98: Assertion failed in %Ntb_npu_single_core.u_system_memory.write_byte: system-bus memory preload address 0x%0x is outside the model\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),64,__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__address);
            VL_STOP_MT("tb/tb_axi_memory_model.sv", 98, "", false);
        }
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[(0x7ffU 
                                                                      & (IData)(
                                                                                (__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__address 
                                                                                >> 3U)))] 
            = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, 
                                                      (7U 
                                                       & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__address)), 3U)))) 
                & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [(0x7ffU & (IData)((__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__address 
                                    >> 3U)))]) | ((QData)((IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__value)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, 
                                                                   (7U 
                                                                    & (IData)(__Vtask_tb_npu_single_core__DOT__u_system_memory__DOT__write_byte__1376__address)), 3U))));
        __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__store_descriptor__1375__unnamedblk1__DOT__index);
    }
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__signal_event = 0xfffU;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__wait1 = 0xfffU;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__wait0 = 0xfffU;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__opcode = 0x40U;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__engine = 2U;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__command_id = 0x108U;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__descriptor_address = 0x1700ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__low_word = 0;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__high_word = 0;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__low_word = 0ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__high_word = 0ULL;
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__low_word 
        = (((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1377__engine)) 
            << 0x3cU) | (((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1377__command_id)) 
                          << 0x30U) | __Vfunc_tb_npu_single_core__DOT__make_command__1377__descriptor_address));
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__high_word 
        = ((0xffffffffffffff00ULL & __Vfunc_tb_npu_single_core__DOT__make_command__1377__high_word) 
           | (IData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1377__opcode)));
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__high_word 
        = ((0xfffffULL & __Vfunc_tb_npu_single_core__DOT__make_command__1377__high_word) 
           | (((QData)((IData)((0x1000000U | (((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1377__signal_event) 
                                               << 0xcU) 
                                              | (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1377__wait1))))) 
               << 0x20U) | ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1377__wait0)) 
                            << 0x14U)));
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__Vfuncout[0U] 
        = (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1377__low_word);
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__Vfuncout[1U] 
        = (IData)((__Vfunc_tb_npu_single_core__DOT__make_command__1377__low_word 
                   >> 0x20U));
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__Vfuncout[2U] 
        = (IData)(__Vfunc_tb_npu_single_core__DOT__make_command__1377__high_word);
    __Vfunc_tb_npu_single_core__DOT__make_command__1377__Vfuncout[3U] 
        = (IData)((__Vfunc_tb_npu_single_core__DOT__make_command__1377__high_word 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__command_words[2U][0U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__1377__Vfuncout[0U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[2U][1U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__1377__Vfuncout[1U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[2U][2U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__1377__Vfuncout[2U];
    vlSelfRef.tb_npu_single_core__DOT__command_words[2U][3U] 
        = __Vfunc_tb_npu_single_core__DOT__make_command__1377__Vfuncout[3U];
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__command_count = 3U;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__observed_response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__beat_count = 0;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__beat_count 
        = VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__command_count, 1U);
    __Vtask_tb_npu_single_core__DOT__check__1379__message = 
        std::string{"invalid command burst count"};
    __Vtask_tb_npu_single_core__DOT__check__1379__condition 
        = ((1U <= __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__command_count) 
           & (8U >= __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__command_count));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1379__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1379__message));
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
        = (0xffU & (__Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__beat_count 
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
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index = 0U;
    while ((__Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index 
            < __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__command_count)) {
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 0U;
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             647);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
            = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index)][1U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                            [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index)][0U])));
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i = 0xffU;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i 
            = (((IData)(1U) + VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index, 1U)) 
               == __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__beat_count);
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
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 1U;
        co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             647);
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
            = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index)][3U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__command_words
                                            [(7U & __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index)][2U])));
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i = 0xffU;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i 
            = (((IData)(2U) + VL_SHIFTL_III(32,32,32, __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index, 1U)) 
               == __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__beat_count);
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
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__unnamedblk3__DOT__word_index = 2U;
        __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index 
            = ((IData)(1U) + __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__unnamedblk2__DOT__command_index);
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
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         662);
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         662);
    __Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__tb_npu_single_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1380__message = 
        std::string{"command burst response was not held"};
    __Vtask_tb_npu_single_core__DOT__check__1380__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_submit_commands__1378__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1380__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1380__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1381__message = 
        std::string{"FIXED command burst failed"};
    __Vtask_tb_npu_single_core__DOT__check__1381__condition 
        = ((0x63U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q)) 
           & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1381__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1381__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         670);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1382__expected_status = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1382__expected_command_id = 0x106U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1382__response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__address = 0x20008U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1384__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1384__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1384__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1384__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1385__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1385__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1383__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1385__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1385__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1386__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1386__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1386__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1386__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1387__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1387__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1387__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1387__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1388__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1388__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1388__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1388__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1389__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1389__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1389__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1389__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1382__response 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1383__data;
    __Vtask_tb_npu_single_core__DOT__check__1390__message = 
        std::string{"CFE response returned the wrong command_id"};
    __Vtask_tb_npu_single_core__DOT__check__1390__condition 
        = ((0xfffU & (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1382__response)) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1382__expected_command_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1390__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1390__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1391__message = 
        std::string{"CFE response returned the wrong status"};
    __Vtask_tb_npu_single_core__DOT__check__1391__condition 
        = ((0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__1382__response 
                             >> 0xcU))) == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1382__expected_status));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1391__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1391__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1392__message = 
        std::string{"CFE response fifo_free_entries exceeds the configured depth"};
    __Vtask_tb_npu_single_core__DOT__check__1392__condition 
        = (8U >= (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__1382__response 
                                   >> 0x14U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1392__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1392__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1393__message = 
        std::string{"CFE response reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__1393__condition 
        = (0ULL == (__Vtask_tb_npu_single_core__DOT__read_command_response__1382__response 
                    >> 0x1cU));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1393__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1393__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__read_command_response__1394__expected_status = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1394__expected_command_id = 0x107U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1394__response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__address = 0x20008U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1396__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1396__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1396__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1396__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1397__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1397__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1395__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1397__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1397__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1398__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1398__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1398__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1398__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1399__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1399__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1399__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1399__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1400__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1400__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1400__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1400__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1401__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1401__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1401__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1401__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1394__response 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1395__data;
    __Vtask_tb_npu_single_core__DOT__check__1402__message = 
        std::string{"CFE response returned the wrong command_id"};
    __Vtask_tb_npu_single_core__DOT__check__1402__condition 
        = ((0xfffU & (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1394__response)) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1394__expected_command_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1402__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1402__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1403__message = 
        std::string{"CFE response returned the wrong status"};
    __Vtask_tb_npu_single_core__DOT__check__1403__condition 
        = ((0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__1394__response 
                             >> 0xcU))) == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1394__expected_status));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1403__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1403__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1404__message = 
        std::string{"CFE response fifo_free_entries exceeds the configured depth"};
    __Vtask_tb_npu_single_core__DOT__check__1404__condition 
        = (8U >= (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__1394__response 
                                   >> 0x14U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1404__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1404__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1405__message = 
        std::string{"CFE response reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__1405__condition 
        = (0ULL == (__Vtask_tb_npu_single_core__DOT__read_command_response__1394__response 
                    >> 0x1cU));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1405__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1405__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__read_command_response__1406__expected_status = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1406__expected_command_id = 0x108U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1406__response = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__address = 0x20008U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1408__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1408__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1408__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1408__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1409__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1409__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1407__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1409__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1409__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1410__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1410__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1410__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1410__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1411__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1411__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1411__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1411__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1412__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1412__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1412__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1412__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1413__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1413__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1413__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1413__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__read_command_response__1406__response 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1407__data;
    __Vtask_tb_npu_single_core__DOT__check__1414__message = 
        std::string{"CFE response returned the wrong command_id"};
    __Vtask_tb_npu_single_core__DOT__check__1414__condition 
        = ((0xfffU & (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1406__response)) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1406__expected_command_id));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1414__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1414__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1415__message = 
        std::string{"CFE response returned the wrong status"};
    __Vtask_tb_npu_single_core__DOT__check__1415__condition 
        = ((0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__1406__response 
                             >> 0xcU))) == (IData)(__Vtask_tb_npu_single_core__DOT__read_command_response__1406__expected_status));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1415__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1415__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1416__message = 
        std::string{"CFE response fifo_free_entries exceeds the configured depth"};
    __Vtask_tb_npu_single_core__DOT__check__1416__condition 
        = (8U >= (0xffU & (IData)((__Vtask_tb_npu_single_core__DOT__read_command_response__1406__response 
                                   >> 0x14U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1416__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1416__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1417__message = 
        std::string{"CFE response reserved bits are nonzero"};
    __Vtask_tb_npu_single_core__DOT__check__1417__condition 
        = (0ULL == (__Vtask_tb_npu_single_core__DOT__read_command_response__1406__response 
                    >> 0x1cU));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1417__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1417__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__data = 2ULL;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__address = 0x20020U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1418__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1419__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1419__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1419__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1419__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1420__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1420__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1418__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1420__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1420__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1421__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1421__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1421__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1421__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1422__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1422__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1422__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1422__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1423__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1423__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1423__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1423__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__data = 0xc350ULL;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__address = 0x20028U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1424__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1425__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1425__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1425__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1425__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1426__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1426__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1424__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1426__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1426__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1427__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1427__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1427__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1427__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1428__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1428__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1428__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1428__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1429__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1429__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1429__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1429__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__data = 3ULL;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__address = 0x20030U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1430__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1431__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1431__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1431__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1431__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1432__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1432__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1430__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1432__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1432__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1433__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1433__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1433__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1433__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1434__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1434__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1434__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1434__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1435__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1435__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1435__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1435__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__strobe = 0xffU;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__data = 1ULL;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__address = 0x20048U;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__address;
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
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__strobe;
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
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    __Vtask_tb_npu_single_core__DOT__axi_write_single__1436__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1437__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1437__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1437__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1437__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1438__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1438__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(__Vtask_tb_npu_single_core__DOT__axi_write_single__1436__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1438__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1438__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1439__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1439__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1439__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1439__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1440__message = 
        std::string{"AXI Slave returned the wrong BID"};
    __Vtask_tb_npu_single_core__DOT__check__1440__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1440__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1440__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1441__message = 
        std::string{"AXI Slave single write failed"};
    __Vtask_tb_npu_single_core__DOT__check__1441__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1441__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1441__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1442__address = 0x20038U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1442__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7675291348466921329ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1442__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16333090747718319729ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1442__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11735194639436292507ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1442__address;
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
}
