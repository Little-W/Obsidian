// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core__Syms.h"
#include "Vtb_npu_single_core___024root.h"

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__18(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__18\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_read_word__1614__address;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1614__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_read_word__1614__data;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1614__data = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1616__condition;
    __Vtask_tb_npu_single_core__DOT__check__1616__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1616__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1617__condition;
    __Vtask_tb_npu_single_core__DOT__check__1617__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1617__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1618__condition;
    __Vtask_tb_npu_single_core__DOT__check__1618__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1618__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1619__condition;
    __Vtask_tb_npu_single_core__DOT__check__1619__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1619__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1620__condition;
    __Vtask_tb_npu_single_core__DOT__check__1620__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1620__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1621__condition;
    __Vtask_tb_npu_single_core__DOT__check__1621__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1621__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1622__condition;
    __Vtask_tb_npu_single_core__DOT__check__1622__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1622__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_read_word__1623__address;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1623__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_read_word__1623__data;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1623__data = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1625__condition;
    __Vtask_tb_npu_single_core__DOT__check__1625__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1625__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1626__condition;
    __Vtask_tb_npu_single_core__DOT__check__1626__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1626__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1627__condition;
    __Vtask_tb_npu_single_core__DOT__check__1627__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1627__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1628__condition;
    __Vtask_tb_npu_single_core__DOT__check__1628__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1628__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1629__condition;
    __Vtask_tb_npu_single_core__DOT__check__1629__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1629__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1630__condition;
    __Vtask_tb_npu_single_core__DOT__check__1630__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1630__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1631__condition;
    __Vtask_tb_npu_single_core__DOT__check__1631__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1631__message;
    IData/*19:0*/ __Vtask_tb_npu_single_core__DOT__l1_read_word__1632__address;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1632__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__l1_read_word__1632__data;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1632__data = 0;
    IData/*23:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__address;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__address = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__data = 0;
    IData/*31:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    QData/*63:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__observed_data;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__observed_data = 0;
    CData/*1:0*/ __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__observed_response;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__observed_response = 0;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1634__condition;
    __Vtask_tb_npu_single_core__DOT__check__1634__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1634__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1635__condition;
    __Vtask_tb_npu_single_core__DOT__check__1635__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1635__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1636__condition;
    __Vtask_tb_npu_single_core__DOT__check__1636__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1636__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1637__condition;
    __Vtask_tb_npu_single_core__DOT__check__1637__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1637__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1638__condition;
    __Vtask_tb_npu_single_core__DOT__check__1638__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1638__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1639__condition;
    __Vtask_tb_npu_single_core__DOT__check__1639__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1639__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1640__condition;
    __Vtask_tb_npu_single_core__DOT__check__1640__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1640__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1641__condition;
    __Vtask_tb_npu_single_core__DOT__check__1641__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1641__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1642__condition;
    __Vtask_tb_npu_single_core__DOT__check__1642__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1642__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1643__condition;
    __Vtask_tb_npu_single_core__DOT__check__1643__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1643__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1644__condition;
    __Vtask_tb_npu_single_core__DOT__check__1644__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1644__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1645__condition;
    __Vtask_tb_npu_single_core__DOT__check__1645__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1645__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1646__condition;
    __Vtask_tb_npu_single_core__DOT__check__1646__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1646__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1647__condition;
    __Vtask_tb_npu_single_core__DOT__check__1647__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1647__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1648__condition;
    __Vtask_tb_npu_single_core__DOT__check__1648__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1648__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1649__condition;
    __Vtask_tb_npu_single_core__DOT__check__1649__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1649__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1650__condition;
    __Vtask_tb_npu_single_core__DOT__check__1650__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1650__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1651__condition;
    __Vtask_tb_npu_single_core__DOT__check__1651__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1651__message;
    CData/*0:0*/ __Vtask_tb_npu_single_core__DOT__check__1652__condition;
    __Vtask_tb_npu_single_core__DOT__check__1652__condition = 0;
    std::string __Vtask_tb_npu_single_core__DOT__check__1652__message;
    // Body
    {
        while ((0x4e20U > vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__poll_count)) {
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__address = 0x20038U;
            const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3402767623919169640ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14454354453382195889ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6985855388382305058ull);
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__address;
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
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1596__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1596__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1596__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1596__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1597__message = 
                std::string{"AXI Slave changed read response during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1597__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1597__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1597__message));
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
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1598__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1598__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1598__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1598__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1599__message = 
                std::string{"AXI Slave returned the wrong RID"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1599__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1599__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1599__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1600__message = 
                std::string{"AXI Slave single read failed"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1600__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1600__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1600__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1601__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1601__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1601__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1601__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__data;
            if ((1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status 
                               >> 1U)))) {
                goto __Vlabel0;
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__poll_count 
                = ((IData)(1U) + vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__poll_count);
        }
        __Vlabel0: ;
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1602__message = 
        std::string{"control request polling timed out"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1602__condition 
        = (1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1602__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1602__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1603__message = 
        std::string{"control request stayed busy after completion"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1603__condition 
        = (1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1603__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1603__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1604__message = 
        std::string{"control window reported an internal failure"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1604__condition 
        = (0U == (0xffU & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1604__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1604__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1605__message = 
        std::string{"control window status reserved bits are nonzero"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1605__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1605__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1605__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__address = 0x20040U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11066262605308097167ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14349498641428824955ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7912393072372769947ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__address;
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
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1607__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1607__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1607__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1607__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1608__message = 
        std::string{"AXI Slave changed read response during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1608__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1608__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1608__message));
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
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1609__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1609__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1609__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1609__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1610__message = 
        std::string{"AXI Slave returned the wrong RID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1610__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1610__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1610__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1611__message = 
        std::string{"AXI Slave single read failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1611__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1611__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1611__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1612__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1612__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1612__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1612__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__data;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__result;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__acknowledge_task__1574__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__result;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1613__message = 
        std::string{"task ACK failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1613__condition 
        = (0ULL == vlSelfRef.__Vtask_tb_npu_single_core__DOT__acknowledge_task__1574__result);
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1613__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1613__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1614__address = 0xc00U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_read_word__1614__address));
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1616__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1616__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1616__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1616__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1617__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1617__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1615__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1617__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1617__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1618__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1618__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1618__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1618__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1619__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1619__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1619__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1619__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1620__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1620__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1620__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1620__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1621__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1621__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1621__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1621__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1614__data 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1615__data;
    vlSelfRef.tb_npu_single_core__DOT__read_data = __Vtask_tb_npu_single_core__DOT__l1_read_word__1614__data;
    __Vtask_tb_npu_single_core__DOT__check__1622__message = 
        std::string{"linear INT16 Matrix result row zero is incorrect"};
    __Vtask_tb_npu_single_core__DOT__check__1622__condition 
        = (0xd00000002ULL == vlSelfRef.tb_npu_single_core__DOT__read_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1622__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1622__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1623__address = 0xc08U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_read_word__1623__address));
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1625__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1625__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1625__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1625__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1626__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1626__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1624__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1626__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1626__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1627__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1627__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1627__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1627__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1628__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1628__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1628__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1628__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1629__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1629__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1629__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1629__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1630__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1630__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1630__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1630__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1623__data 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1624__data;
    vlSelfRef.tb_npu_single_core__DOT__read_data = __Vtask_tb_npu_single_core__DOT__l1_read_word__1623__data;
    __Vtask_tb_npu_single_core__DOT__check__1631__message = 
        std::string{"linear INT16 Matrix result row one is incorrect"};
    __Vtask_tb_npu_single_core__DOT__check__1631__condition 
        = (0xd00000006ULL == vlSelfRef.tb_npu_single_core__DOT__read_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1631__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1631__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1632__address = 0xc40U;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__address 
        = (0xffffffU & ((IData)(0x100000U) + __Vtask_tb_npu_single_core__DOT__l1_read_word__1632__address));
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__observed_data = 0;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__observed_response = 0;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__address;
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
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    __Vtask_tb_npu_single_core__DOT__check__1634__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1634__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1634__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1634__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1635__message = 
        std::string{"AXI Slave changed read response during host stall"};
    __Vtask_tb_npu_single_core__DOT__check__1635__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(__Vtask_tb_npu_single_core__DOT__axi_read_single__1633__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1635__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1635__message));
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
    __Vtask_tb_npu_single_core__DOT__check__1636__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    __Vtask_tb_npu_single_core__DOT__check__1636__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1636__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1636__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1637__message = 
        std::string{"AXI Slave returned the wrong RID"};
    __Vtask_tb_npu_single_core__DOT__check__1637__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1637__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1637__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1638__message = 
        std::string{"AXI Slave single read failed"};
    __Vtask_tb_npu_single_core__DOT__check__1638__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1638__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1638__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1639__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    __Vtask_tb_npu_single_core__DOT__check__1639__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1639__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1639__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    __Vtask_tb_npu_single_core__DOT__l1_read_word__1632__data 
        = __Vtask_tb_npu_single_core__DOT__axi_read_single__1633__data;
    vlSelfRef.tb_npu_single_core__DOT__read_data = __Vtask_tb_npu_single_core__DOT__l1_read_word__1632__data;
    __Vtask_tb_npu_single_core__DOT__check__1640__message = 
        std::string{"tiled INT16 Matrix inline output scaling result is incorrect"};
    __Vtask_tb_npu_single_core__DOT__check__1640__condition 
        = (0x7000300070001ULL == vlSelfRef.tb_npu_single_core__DOT__read_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1640__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1640__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1641__message = 
        std::string{"linear INT16 Matrix task did not access L1"};
    __Vtask_tb_npu_single_core__DOT__check__1641__condition 
        = (0U != vlSelfRef.tb_npu_single_core__DOT__matrix_pack5_l1_handshakes_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1641__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1641__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1642__message = 
        std::string{"inline Matrix output scaling issued an unexpected L1 request"};
    __Vtask_tb_npu_single_core__DOT__check__1642__condition 
        = (0x1cU == vlSelfRef.tb_npu_single_core__DOT__matrix_pack6_l1_handshakes_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1642__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1642__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1643__message = 
        std::string{"reserved Matrix pack issued an L1 request"};
    __Vtask_tb_npu_single_core__DOT__check__1643__condition 
        = (0U == vlSelfRef.tb_npu_single_core__DOT__matrix_pack7_l1_handshakes_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1643__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1643__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         1228);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         1228);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         1228);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         1228);
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         1228);
    VL_WRITEF_NX("TB_SYSTEM_COUNTS desc_reads=%0# system_reads=%0# system_writes=%0#\n",0,
                 32,vlSelfRef.tb_npu_single_core__DOT__desc_read_count_q,
                 32,vlSelfRef.tb_npu_single_core__DOT__system_bus_read_handshakes,
                 32,vlSelfRef.tb_npu_single_core__DOT__system_bus_write_handshakes);
    __Vtask_tb_npu_single_core__DOT__check__1644__message = 
        std::string{"descriptor read count is incorrect"};
    __Vtask_tb_npu_single_core__DOT__check__1644__condition 
        = (0x78U == vlSelfRef.tb_npu_single_core__DOT__desc_read_count_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1644__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1644__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1645__message = 
        std::string{"system-bus read count does not include 120 descriptor and 8 DMA reads"};
    __Vtask_tb_npu_single_core__DOT__check__1645__condition 
        = (0x80U == vlSelfRef.tb_npu_single_core__DOT__system_bus_read_handshakes);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1645__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1645__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1646__message = 
        std::string{"system-bus write count does not include eight DMA writes"};
    __Vtask_tb_npu_single_core__DOT__check__1646__condition 
        = (8U == vlSelfRef.tb_npu_single_core__DOT__system_bus_write_handshakes);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1646__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1646__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1647__message = 
        std::string{"system-bus AXI model detected a protocol error"};
    __Vtask_tb_npu_single_core__DOT__check__1647__condition 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_bus_protocol_error)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1647__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1647__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1648__message = 
        std::string{"CFE did not receive nine command low words"};
    __Vtask_tb_npu_single_core__DOT__check__1648__condition 
        = (9U == vlSelfRef.tb_npu_single_core__DOT__cfe_low_word_count_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1648__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1648__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1649__message = 
        std::string{"CFE did not receive nine command high words"};
    __Vtask_tb_npu_single_core__DOT__check__1649__condition 
        = (9U == vlSelfRef.tb_npu_single_core__DOT__cfe_high_word_count_q);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1649__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1649__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1650__message = 
        std::string{"CFE ended with an unmatched low word"};
    __Vtask_tb_npu_single_core__DOT__check__1650__condition 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__cfe_expect_high_q)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1650__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1650__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1651__message = 
        std::string{"watchdog unexpectedly requested reset"};
    __Vtask_tb_npu_single_core__DOT__check__1651__condition 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__timeout_q)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1651__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1651__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    __Vtask_tb_npu_single_core__DOT__check__1652__message = 
        std::string{"masked interrupt unexpectedly asserted"};
    __Vtask_tb_npu_single_core__DOT__check__1652__condition 
        = (1U & (~ ((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_mask_q)) 
                      & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q)) 
                     | ((~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_mask_q) 
                            >> 1U)) & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q) 
                                       >> 1U))) | (
                                                   (~ 
                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_mask_q) 
                                                     >> 2U)) 
                                                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q) 
                                                      >> 2U)))));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_npu_single_core__DOT__check__1652__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(__Vtask_tb_npu_single_core__DOT__check__1652__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    VL_WRITEF_NX("TB_SYSTEM_PASS commands=9 desc_reads=%0# system_reads=%0# system_writes=%0# matrix_l1=%0# vector_l1=%0#\n",0,
                 32,vlSelfRef.tb_npu_single_core__DOT__desc_read_count_q,
                 32,vlSelfRef.tb_npu_single_core__DOT__system_bus_read_handshakes,
                 32,vlSelfRef.tb_npu_single_core__DOT__system_bus_write_handshakes,
                 32,vlSelfRef.tb_npu_single_core__DOT__matrix_l1_handshakes_q,
                 32,vlSelfRef.tb_npu_single_core__DOT__vector_l1_handshakes_q);
    VL_FINISH_MT("tb/tb_npu_single_core.sv", 1257, "");
}

VL_INLINE_OPT VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__1(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x4a817c800ULL, 
                                         nullptr, "tb/tb_npu_single_core.sv", 
                                         1261);
    VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:1262: Assertion failed in %Ntb_npu_single_core: single-core system test timed out\n",0,
                 64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
    VL_STOP_MT("tb/tb_npu_single_core.sv", 1262, "", false);
}

VL_INLINE_OPT VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__2(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "tb/tb_npu_single_core.sv", 
                                             214);
        vlSelfRef.tb_npu_single_core__DOT__core_clk_i 
            = (1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__core_clk_i)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_single_core___024root___dump_triggers__act(Vtb_npu_single_core___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_npu_single_core___024root___eval_triggers__act(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_triggers__act\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb_npu_single_core__DOT__core_clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_single_core__DOT__core_clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__reset_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_single_core__DOT__reset_n__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_single_core__DOT__dut__DOT__functional_reset_n__0)));
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__core_clk_i)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_single_core__DOT__core_clk_i__0)));
    vlSelfRef.__VactTriggered.setBit(4U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_single_core__DOT__core_clk_i__0 
        = vlSelfRef.tb_npu_single_core__DOT__core_clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_single_core__DOT__reset_n__0 
        = vlSelfRef.tb_npu_single_core__DOT__reset_n;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_single_core__DOT__dut__DOT__functional_reset_n__0 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_npu_single_core___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___act_comb__TOP__0(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___act_comb__TOP__0\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr = 0;
    SData/*8:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock = 0;
    IData/*24:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr = 0;
    SData/*8:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock = 0;
    IData/*24:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr = 0;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_requested 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_soft_reset_req_q) 
           | (IData)(vlSelfRef.tb_npu_single_core__DOT__soft_reset_req_i));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT____VdfgRegularize_h29da96d0_0_0 
        = ((1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i)))) 
           & ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i)) 
                 & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i)))));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_arready_i 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_pending_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__reset_n) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_rvalid_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_bus_backpressure)) 
                    | (2U != (3U & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_csr_format_w 
        = ((((((0x20000U > vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i) 
               & (1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i))))) 
              & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i))) 
             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i))) 
            & (3U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i))) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low 
                    = (7U & vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size 
                    = vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__Vfuncout 
                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size) 
                                 >> 2U))) && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size))
                                                   ? 
                                                  (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low))
                                                   : 
                                                  (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low))))
                                               : ((1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size))) 
                                                  || (1U 
                                                      & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low))))));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ar_csr_format_w 
        = ((((((0x20000U > vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
               & (1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i))))) 
              & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i))) 
             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i))) 
            & (3U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i))) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low 
                    = (7U & vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size 
                    = vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__Vfuncout 
                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size) 
                                 >> 2U))) && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size))
                                                   ? 
                                                  (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low))
                                                   : 
                                                  (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low))))
                                               : ((1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size))) 
                                                  || (1U 
                                                      & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low))))));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_pop_w 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_pop_rsp_q) 
              & (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_current_error_w 
        = (((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i) 
            != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_last_expected_w)) 
           | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
              & (0xffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i))));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_awready_i 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_valid_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__reset_n) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_bus_backpressure)) 
                    | (0U != (3U & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q))))));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_wready_i 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_valid_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__reset_n) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_bus_backpressure)) 
                    | (1U != (7U & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_cmd_format_w 
        = ((0x20000U == vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i) 
           & ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i)) 
              & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i)) 
                    & ((2U <= (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i)))) 
                       & ((~ ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i))) 
                          & (0x10U >= (0x1ffU & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i))))))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_quiesce 
        = ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)) 
           | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q) 
              | (IData)(vlSelfRef.tb_npu_single_core__DOT__power_down_req_i)));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats 
        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i)));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr 
        = (0x1ffffffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr 
                         + (((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats) 
                             - (IData)(1U)) << (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout 
        = ((((((((~ (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock)) 
                 & (1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst))) 
                & (3U >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size))) 
               & ([&]() {
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low 
                                    = (7U & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr);
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size 
                                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size;
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__Vfuncout 
                                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size) 
                                                 >> 2U))) 
                                       && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size))
                                                ? (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low))
                                                : (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low))))
                                            : ((1U 
                                                & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size))) 
                                               || (1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low))))));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__Vfuncout))) 
              & ((1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats)) 
                 | (3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size)))) 
             & (0x100000U <= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr)) 
            & (0x1fffffU >= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr)) 
           & ((0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr 
                         >> 0xcU)) == (0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr 
                                                 >> 0xcU))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_l1_format_w 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats 
        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i)));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr 
        = (0x1ffffffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr 
                         + (((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats) 
                             - (IData)(1U)) << (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout 
        = ((((((((~ (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock)) 
                 & (1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst))) 
                & (3U >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size))) 
               & ([&]() {
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low 
                                    = (7U & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr);
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size 
                                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size;
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__Vfuncout 
                                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size) 
                                                 >> 2U))) 
                                       && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size))
                                                ? (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low))
                                                : (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low))))
                                            : ((1U 
                                                & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size))) 
                                               || (1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low))))));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__Vfuncout))) 
              & ((1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats)) 
                 | (3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size)))) 
             & (0x100000U <= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr)) 
            & (0x1fffffU >= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr)) 
           & ((0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr 
                         >> 0xcU)) == (0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr 
                                                 >> 0xcU))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ar_l1_format_w 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__accept_new_cmd_o 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__start_q) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__power_down_req_i)) 
                 & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)))));
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) 
           & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)) 
                 & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
                    & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)) 
                       & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i)))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_rsp_ready 
        = ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q)) 
           & ((8U > (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q)) 
              | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_pop_w)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_complete_error_w 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q) 
           | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_current_error_w));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_awvalid_o) 
           & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_awready_i));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_wvalid_o) 
           & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_wready_i));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_ready = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_quiesce)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_ready 
            = ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)) 
               || (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)));
        if ((1U & (~ VL_ONEHOT_I((((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)) 
                                   << 1U) | (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q))))))) {
            if ((0U != (((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)) 
                         << 1U) | (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: npu_cmd_frontend.sv:134: Assertion failed in %Ntb_npu_single_core.dut.u_cmd_frontend: unique case, but multiple matches found for '3'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 3,(IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q));
                    VL_STOP_MT("control/npu_cmd_frontend.sv", 134, "");
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd_ready 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__accept_new_cmd_o) 
           & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_quiesce)) 
              & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found)));
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) 
           & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)) 
                 & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
                    & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)) 
                       & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_cmd_format_w)) 
                          | ((IData)(vlSelfRef.tb_npu_single_core__DOT__accept_new_cmd_o) 
                             & ((0x1ffU & ((IData)(0x10U) 
                                           - (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q))) 
                                >= (0x1ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i)))))))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_read_data 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_space)
            ? 0ULL : ((0x8000U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                       ? 0ULL : ((0x4000U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                  ? 0ULL : ((0x2000U 
                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                             ? 0ULL
                                             : ((0x1000U 
                                                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                 ? 0ULL
                                                 : 
                                                ((0x800U 
                                                  & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                  ? 0ULL
                                                  : 
                                                 ((0x400U 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                   ? 0ULL
                                                   : 
                                                  ((0x200U 
                                                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                    ? 
                                                   ((0x100U 
                                                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                     ? 0ULL
                                                     : 
                                                    ((0x80U 
                                                      & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                      ? 
                                                     ((0x40U 
                                                       & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                       ? 
                                                      ((0x20U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                        ? 0ULL
                                                        : 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__module_clk_enable_q))))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__wdt_timeout_cycles_q)))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__wdt_enable_q))))))))
                                                       : 0ULL)
                                                      : 0ULL))
                                                    : 
                                                   ((0x100U 
                                                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                     ? 0ULL
                                                     : 
                                                    ((0x80U 
                                                      & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                      ? 
                                                     ((0x40U 
                                                       & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                       ? 
                                                      ((0x20U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                        ? 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__l1_host_access_enable_q))))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_reason_q)))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_lock_q)))))))
                                                        : 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_limit_q)))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_base_q))))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q)
                                                              ? (QData)((IData)(
                                                                                (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_opcode_q) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_engine_q) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_status_q)))))
                                                              : 0ULL)))))))
                                                       : 
                                                      ((0x20U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                        ? 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q)
                                                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_addr_q
                                                              : 0ULL))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q)
                                                              ? (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_command_id_q))
                                                              : 0ULL)))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_mask_q)))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q)))))))
                                                        : 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(
                                                                               (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_substream_id_q) 
                                                                                << 0x10U) 
                                                                                | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_stream_id_q))))))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_limit_q)))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_base_q)))))))
                                                      : 
                                                     ((0x40U 
                                                       & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                       ? 
                                                      ((0x20U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                        ? 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__kv_base_q)))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__output_base_q))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__work_base_q)))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__weight_base_q)))))
                                                        : 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__input_base_q)))
                                                          : 0ULL)
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(
                                                                               ((((0U 
                                                                                != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)) 
                                                                                << 5U) 
                                                                                | ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle) 
                                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q)) 
                                                                                << 4U) 
                                                                                | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q) 
                                                                                << 3U))) 
                                                                                | (((IData)(vlSelfRef.tb_npu_single_core__DOT__accept_new_cmd_o) 
                                                                                << 2U) 
                                                                                | ((2U 
                                                                                & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)))))))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(
                                                                               (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__start_q))))))))))
                                                       : 
                                                      ((0x20U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                        ? 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x1000003fff04ULL))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x3ff08ULL)))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x7081008ULL)))))
                                                        : 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x21000100000ULL)))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x8283040ULL))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x100010001ULL)))))))))))))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_pop_w 
        = ((5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)) 
           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_rsp_ready));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_commit_w 
        = ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i) 
              & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_complete_error_w)) 
                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_last_expected_w)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__write_channels_done 
        = (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_done_q) 
            | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_handshake)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_done_q) 
              | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_handshake)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__input_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_ready) 
           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_valid));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd_ready) 
           & (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q)));
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__0(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__0\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q = 0;
    // Body
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__protocol_checks_enable)) 
                                   | ((~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_1_0)) 
                                      | ((3U == (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
                                         & (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_2_0 
                                            == (0x1aULL 
                                                | (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q 
                                                   << 0xeU))))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_npu_single_core.sv:233: Assertion failed in %Ntb_npu_single_core: 'assert' failed.\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/tb_npu_single_core.sv", 233, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__protocol_checks_enable)) 
                                   | ((~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_4_0)) 
                                      | ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_awvalid_o) 
                                         & (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_5_0 
                                            == (0x1aULL 
                                                | (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q 
                                                   << 0xeU))))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_npu_single_core.sv:244: Assertion failed in %Ntb_npu_single_core: 'assert' failed.\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/tb_npu_single_core.sv", 244, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__protocol_checks_enable)) 
                                   | ((~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_7_0)) 
                                      | ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_wvalid_o) 
                                         & (0U == (
                                                   ((vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_8_0[0U] 
                                                     ^ 
                                                     (1U 
                                                      | (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
                                                          << 9U) 
                                                         | ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q) 
                                                            << 1U)))) 
                                                    | (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_8_0[1U] 
                                                       ^ 
                                                       (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
                                                         >> 0x17U) 
                                                        | ((IData)(
                                                                   (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q 
                                                                    >> 0x20U)) 
                                                           << 9U)))) 
                                                   | (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_8_0[2U] 
                                                      ^ 
                                                      ((IData)(
                                                               (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q 
                                                                >> 0x20U)) 
                                                       >> 0x17U)))))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_npu_single_core.sv:252: Assertion failed in %Ntb_npu_single_core: 'assert' failed.\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/tb_npu_single_core.sv", 252, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__protocol_checks_enable)) 
                                   | ((~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_10_0)) 
                                      | ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_bvalid_o) 
                                         & ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_11_0) 
                                            == (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q) 
                                                 << 2U) 
                                                | (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_bresp_o))))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_npu_single_core.sv:259: Assertion failed in %Ntb_npu_single_core: 'assert' failed.\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/tb_npu_single_core.sv", 259, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__protocol_checks_enable)) 
                                   | ((~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_13_0)) 
                                      | ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rvalid_o) 
                                         & (0U == (
                                                   ((vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_14_0[0U] 
                                                     ^ 
                                                     (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rdata_o) 
                                                       << 3U) 
                                                      | (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rresp_o) 
                                                          << 1U) 
                                                         | (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rlast_o)))) 
                                                    | (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_14_0[1U] 
                                                       ^ 
                                                       (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rdata_o) 
                                                         >> 0x1dU) 
                                                        | ((IData)(
                                                                   (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rdata_o 
                                                                    >> 0x20U)) 
                                                           << 3U)))) 
                                                   | (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_14_0[2U] 
                                                      ^ 
                                                      (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rid_o) 
                                                        << 3U) 
                                                       | ((IData)(
                                                                  (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rdata_o 
                                                                   >> 0x20U)) 
                                                          >> 0x1dU))))))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_npu_single_core.sv:269: Assertion failed in %Ntb_npu_single_core: 'assert' failed.\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/tb_npu_single_core.sv", 269, "");
        }
    }
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_soft_reset_req_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_soft_reset_req_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_pulse 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_pulse;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_limit_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_limit_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_limit_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_limit_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__timeout_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__timeout_q;
    if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q))) {
        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__wdt_enable_q)) 
                   | (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__wdt_timeout_cycles_q)))) {
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q = 0U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__timeout_q = 0U;
        } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__wdt_kick) 
                    | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_accepted) 
                       | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found) 
                          | (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
                              & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_req_valid)) 
                             | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_rsp_ready) 
                                 & (7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q))) 
                                | (0U != ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))))))))) {
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q = 0U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__timeout_q = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__timeout_q)))) {
            if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q 
                 >= (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__wdt_timeout_cycles_q 
                     - (IData)(1U)))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__timeout_q = 1U;
            } else {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q 
                    = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q);
            }
        }
    } else {
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__timeout_q = 0U;
    }
    vlSelfRef.tb_npu_single_core__DOT___Vpast_2_0 = 
        (0x1aULL | (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q 
                    << 0xeU));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_5_0 = 
        (0x1aULL | (vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q 
                    << 0xeU));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_8_0[0U] 
        = (1U | (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
                  << 9U) | ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q) 
                            << 1U)));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_8_0[1U] 
        = (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
            >> 0x17U) | ((IData)((vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q 
                                  >> 0x20U)) << 9U));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_8_0[2U] 
        = ((IData)((vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q 
                    >> 0x20U)) >> 0x17U);
    vlSelfRef.tb_npu_single_core__DOT___Vpast_11_0 
        = (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q) 
            << 2U) | (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_bresp_o));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_14_0[0U] 
        = (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rdata_o) 
            << 3U) | (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rresp_o) 
                       << 1U) | (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rlast_o)));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_14_0[1U] 
        = (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rdata_o) 
            >> 0x1dU) | ((IData)((vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rdata_o 
                                  >> 0x20U)) << 3U));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_14_0[2U] 
        = (((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rid_o) 
            << 3U) | ((IData)((vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rdata_o 
                               >> 0x20U)) >> 0x1dU));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_1_0 = 
        ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__protocol_checks_enable) 
         & ((3U == (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
            & (~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_arready_i))));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_4_0 = 
        ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__protocol_checks_enable) 
         & ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_awvalid_o) 
            & (~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_awready_i))));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_7_0 = 
        ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__protocol_checks_enable) 
         & ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_wvalid_o) 
            & (~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_wready_i))));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_10_0 
        = ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__protocol_checks_enable) 
           & ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_bvalid_o) 
              & (~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_bready_i))));
    vlSelfRef.tb_npu_single_core__DOT___Vpast_13_0 
        = ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__protocol_checks_enable) 
           & ((IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rvalid_o) 
              & (~ (IData)(vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rready_i))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__counter_q;
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__1(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__1\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__tb_npu_single_core__DOT__system_w_handshakes_q;
    __Vdly__tb_npu_single_core__DOT__system_w_handshakes_q = 0;
    // Body
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_id_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_id_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_error_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_error_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_error_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_error_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_delay_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_delay_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_id_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_id_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_addr_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_addr_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_error_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_error_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__m_axi_rvalid_i 
        = vlSelfRef.tb_npu_single_core__DOT__m_axi_rvalid_i;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_pending_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_pending_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_valid_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_valid_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_valid_q 
        = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_valid_q;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7 = 0U;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__m_axi_bvalid_i 
        = vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i;
    __Vdly__tb_npu_single_core__DOT__system_w_handshakes_q 
        = vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__reset_n)
            ? (1U | (2U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q) 
                           << 1U))) : 0U);
    if (vlSelfRef.tb_npu_single_core__DOT__reset_n) {
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid) 
             & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready) 
                >> 2U))) {
            if ((0x106U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q))) {
                vlSelfRef.tb_npu_single_core__DOT__matrix_pack5_l1_handshakes_q 
                    = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__matrix_pack5_l1_handshakes_q);
            } else if ((0x107U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q))) {
                vlSelfRef.tb_npu_single_core__DOT__matrix_pack6_l1_handshakes_q 
                    = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__matrix_pack6_l1_handshakes_q);
            } else if ((0x108U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q))) {
                vlSelfRef.tb_npu_single_core__DOT__matrix_pack7_l1_handshakes_q 
                    = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__matrix_pack7_l1_handshakes_q);
            }
            vlSelfRef.tb_npu_single_core__DOT__matrix_l1_handshakes_q 
                = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__matrix_l1_handshakes_q);
            if ((1U & (~ VL_ONEHOT_I((((0x108U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q)) 
                                       << 2U) | (((0x107U 
                                                   == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q)) 
                                                  << 1U) 
                                                 | (0x106U 
                                                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q)))))))) {
                if ((0U != (((0x108U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q)) 
                             << 2U) | (((0x107U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q)) 
                                        << 1U) | (0x106U 
                                                  == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q)))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: tb_npu_single_core.sv:290: Assertion failed in %Ntb_npu_single_core: unique case, but multiple matches found for '12'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     12,(IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q));
                        VL_STOP_MT("tb/tb_npu_single_core.sv", 290, "");
                    }
                }
            }
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid) 
             & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready) 
                >> 3U))) {
            vlSelfRef.tb_npu_single_core__DOT__vector_l1_handshakes_q 
                = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__vector_l1_handshakes_q);
        }
        if (VL_UNLIKELY((((((IData)(vlSelfRef.tb_npu_single_core__DOT__dependency_check_enable_q) 
                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_task_valid)) 
                           & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) 
                          & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__matrix_dependency_done_q)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:313: Assertion failed in %Ntb_npu_single_core: dependent Vector task started before Matrix event\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb/tb_npu_single_core.sv", 313, "", false);
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_valid) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_ready))) {
            if (vlSelfRef.tb_npu_single_core__DOT__cfe_expect_high_q) {
                if (VL_UNLIKELY(((1U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_first) 
                                        | (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_last))))))) {
                    VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:326: Assertion failed in %Ntb_npu_single_core: CFE high word markers are incorrect\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name());
                    VL_STOP_MT("tb/tb_npu_single_core.sv", 326, "", false);
                }
                vlSelfRef.tb_npu_single_core__DOT__cfe_high_word_count_q 
                    = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__cfe_high_word_count_q);
                if ((1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_data 
                                   >> 0x3fU)))) {
                    if (VL_UNLIKELY((((0x1cU == (0x1fU 
                                                 & (IData)(
                                                           (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_data 
                                                            >> 0x3aU)))) 
                                      | (0x1eU == (0x1fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_data 
                                                              >> 0x3aU)))))))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:331: Assertion failed in %Ntb_npu_single_core: CFE V2 compact opcode is invalid\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name());
                        VL_STOP_MT("tb/tb_npu_single_core.sv", 331, "", false);
                    }
                } else if (VL_UNLIKELY(((IData)(((0x100000000000000ULL 
                                                  != 
                                                  (0xff00000000000000ULL 
                                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_data)) 
                                                 | (0U 
                                                    != (IData)(vlSelfRef.tb_npu_single_core__DOT__cfe_low_word_low_q))))))) {
                    VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:335: Assertion failed in %Ntb_npu_single_core: CFE V1 header is incorrect\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name());
                    VL_STOP_MT("tb/tb_npu_single_core.sv", 335, "", false);
                }
                vlSelfRef.tb_npu_single_core__DOT__cfe_expect_high_q = 0U;
            } else {
                if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_first)) 
                                        | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_last)))))) {
                    VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:319: Assertion failed in %Ntb_npu_single_core: CFE low word markers are incorrect\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name());
                    VL_STOP_MT("tb/tb_npu_single_core.sv", 319, "", false);
                }
                vlSelfRef.tb_npu_single_core__DOT__cfe_low_word_count_q 
                    = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__cfe_low_word_count_q);
                vlSelfRef.tb_npu_single_core__DOT__cfe_low_word_low_q 
                    = (0x3fU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_data));
                vlSelfRef.tb_npu_single_core__DOT__cfe_expect_high_q = 1U;
            }
        }
        if (((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_arready_i))) {
            if (VL_UNLIKELY(((0U != (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:351: Assertion failed in %Ntb_npu_single_core: NPU AXI Master emitted an invalid read\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("tb/tb_npu_single_core.sv", 351, "", false);
            }
            if (((0x1000ULL <= vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q) 
                 & (0x1900ULL > vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q))) {
                vlSelfRef.tb_npu_single_core__DOT__desc_read_count_q 
                    = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__desc_read_count_q);
            }
        }
        if ((((0x13U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)) 
              & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q)) 
             & (0x101U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__matrix_dependency_done_q = 1U;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_awvalid_o) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_awready_i))) {
            vlSelfRef.tb_npu_single_core__DOT__system_aw_handshakes_q 
                = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__system_aw_handshakes_q);
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_dma_write_check_q)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:358: Assertion failed in %Ntb_npu_single_core: unexpected NPU AXI write-address handshake\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("tb/tb_npu_single_core.sv", 358, "", false);
            }
            if (VL_UNLIKELY(((0x3100ULL != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q)))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:369: Assertion failed in %Ntb_npu_single_core: L1-to-system DMA AW fields are incorrect\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("tb/tb_npu_single_core.sv", 369, "", false);
            }
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_wvalid_o) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_wready_i))) {
            __Vdly__tb_npu_single_core__DOT__system_w_handshakes_q 
                = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q);
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_dma_write_check_q)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:376: Assertion failed in %Ntb_npu_single_core: L1-to-system DMA W handshake is incorrect\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("tb/tb_npu_single_core.sv", 376, "", false);
            }
            if (VL_LIKELY((((((((((0U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                                  | (1U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) 
                                 | (2U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) 
                                | (3U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) 
                               | (4U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) 
                              | (5U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) 
                             | (6U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) 
                            | (7U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q))))) {
                if ((0U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) {
                    if (VL_UNLIKELY((((0x11ULL != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
                                      | (1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q)))))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:382: Assertion failed in %Ntb_npu_single_core: DMA W beat zero is incorrect\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name());
                        VL_STOP_MT("tb/tb_npu_single_core.sv", 382, "", false);
                    }
                } else if ((1U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) {
                    if (VL_UNLIKELY((((0x2200ULL != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
                                      | (2U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q)))))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:386: Assertion failed in %Ntb_npu_single_core: DMA W beat one is incorrect\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name());
                        VL_STOP_MT("tb/tb_npu_single_core.sv", 386, "", false);
                    }
                } else if ((2U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) {
                    if (VL_UNLIKELY((((0x330000ULL 
                                       != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
                                      | (4U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q)))))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:390: Assertion failed in %Ntb_npu_single_core: DMA W beat two is incorrect\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name());
                        VL_STOP_MT("tb/tb_npu_single_core.sv", 390, "", false);
                    }
                } else if ((3U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) {
                    if (VL_UNLIKELY((((0x44000000ULL 
                                       != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
                                      | (8U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q)))))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:394: Assertion failed in %Ntb_npu_single_core: DMA W beat three is incorrect\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name());
                        VL_STOP_MT("tb/tb_npu_single_core.sv", 394, "", false);
                    }
                } else if ((4U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) {
                    if (VL_UNLIKELY((((0x5500000000ULL 
                                       != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
                                      | (0x10U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q)))))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:398: Assertion failed in %Ntb_npu_single_core: DMA W beat four is incorrect\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name());
                        VL_STOP_MT("tb/tb_npu_single_core.sv", 398, "", false);
                    }
                } else if ((5U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) {
                    if (VL_UNLIKELY((((0x660000000000ULL 
                                       != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
                                      | (0x20U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q)))))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:402: Assertion failed in %Ntb_npu_single_core: DMA W beat five is incorrect\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name());
                        VL_STOP_MT("tb/tb_npu_single_core.sv", 402, "", false);
                    }
                } else if ((6U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)) {
                    if (VL_UNLIKELY((((0x77000000000000ULL 
                                       != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
                                      | (0x40U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q)))))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:406: Assertion failed in %Ntb_npu_single_core: DMA W beat six is incorrect\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name());
                        VL_STOP_MT("tb/tb_npu_single_core.sv", 406, "", false);
                    }
                } else if (VL_UNLIKELY((((0x8800000000000000ULL 
                                          != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q) 
                                         | (0x80U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q)))))) {
                    VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:410: Assertion failed in %Ntb_npu_single_core: DMA W beat seven is incorrect\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name());
                    VL_STOP_MT("tb/tb_npu_single_core.sv", 410, "", false);
                }
            } else {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:412: Assertion failed in %Ntb_npu_single_core: L1-to-system DMA emitted extra W beats\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("tb/tb_npu_single_core.sv", 412, "", false);
            }
            if ((1U & (~ VL_ONEHOT_I((((((7U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                                         << 7U) | (
                                                   (6U 
                                                    == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                                                   << 6U)) 
                                       | (((5U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                                           << 5U) | 
                                          ((4U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                                           << 4U))) 
                                      | ((((3U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                                           << 3U) | 
                                          ((2U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                                           << 2U)) 
                                         | (((1U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                                             << 1U) 
                                            | (0U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)))))))) {
                if ((0U != (((((7U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                               << 7U) | ((6U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                                         << 6U)) | 
                             (((5U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                               << 5U) | ((4U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                                         << 4U))) | 
                            ((((3U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                               << 3U) | ((2U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                                         << 2U)) | 
                             (((1U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q) 
                               << 1U) | (0U == vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q)))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: tb_npu_single_core.sv:378: Assertion failed in %Ntb_npu_single_core: unique case, but multiple matches found for '32'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     32,vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q);
                        VL_STOP_MT("tb/tb_npu_single_core.sv", 378, "");
                    }
                }
            }
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i) 
             & (6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)))) {
            if (VL_UNLIKELY(((1U & (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_dma_write_check_q)) 
                                     | (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bid_i))) 
                                    | (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bresp_i))))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:421: Assertion failed in %Ntb_npu_single_core: L1-to-system DMA B response is incorrect\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("tb/tb_npu_single_core.sv", 421, "", false);
            }
            vlSelfRef.tb_npu_single_core__DOT__system_b_handshakes_q 
                = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__system_b_handshakes_q);
        }
    } else {
        vlSelfRef.tb_npu_single_core__DOT__matrix_l1_handshakes_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__vector_l1_handshakes_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__cfe_low_word_count_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__cfe_high_word_count_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__desc_read_count_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__system_aw_handshakes_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__system_b_handshakes_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__matrix_pack5_l1_handshakes_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__matrix_pack6_l1_handshakes_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__matrix_pack7_l1_handshakes_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__matrix_dependency_done_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__cfe_expect_high_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__cfe_low_word_low_q = 0U;
        __Vdly__tb_npu_single_core__DOT__system_w_handshakes_q = 0U;
    }
    vlSelfRef.tb_npu_single_core__DOT__system_w_handshakes_q 
        = __Vdly__tb_npu_single_core__DOT__system_w_handshakes_q;
}

extern const VlWide<64>/*2047:0*/ Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0;

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__2(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__2\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__data;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__data = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__size;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__size = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__addr_low;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__addr_low = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__mask = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__amount;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__amount = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__value = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__value = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__value = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__value = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1673__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1673__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1673__pointer;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1673__pointer = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1674__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1674__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1674__pointer;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1674__pointer = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1675__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1675__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1675__pointer;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1675__pointer = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1676__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1676__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1676__pointer;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1676__pointer = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1706__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1706__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1706__state;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1706__state = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__state;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__state = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1708__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1708__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1708__state;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1708__state = 0;
    CData/*0:0*/ __Vfunc_npu_event_ref_valid__1709__Vfuncout;
    __Vfunc_npu_event_ref_valid__1709__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_npu_event_ref_valid__1709__event_ref;
    __Vfunc_npu_event_ref_valid__1709__event_ref = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1711__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1711__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1711__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1711__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1712__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1712__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1712__state;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1712__state = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1713__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1713__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1713__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1713__opcode = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__status = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__opcode = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__unnamedblk1__DOT__slot;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__unnamedblk1__DOT__slot = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1718__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1718__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1718__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1718__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1719__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1719__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1719__state;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1719__state = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1720__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1720__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1720__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1720__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1721__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1721__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1721__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1721__status = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__status = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1723__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1723__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1723__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1723__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1724__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1724__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1724__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1724__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1725__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1725__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1725__state;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1725__state = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1726__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1726__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1726__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1726__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1727__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1727__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1727__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1727__status = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__status = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1729__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1729__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1729__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1729__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1730__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1730__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1730__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1730__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1731__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1731__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1731__state;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1731__state = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1732__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1732__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1732__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1732__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1733__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1733__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1733__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1733__status = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__status = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1735__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1735__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1735__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1735__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1736__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1736__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1736__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1736__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1737__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1737__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1737__state;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1737__state = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1738__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1738__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1738__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1738__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1739__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1739__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1739__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1739__status = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__status = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1741__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1741__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1741__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1741__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1742__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1742__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1742__status;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1742__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode = 0;
    CData/*1:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_single_core__DOT__s_axi_rvalid_o;
    __Vdly__tb_npu_single_core__DOT__s_axi_rvalid_o = 0;
    CData/*2:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 0;
    SData/*8:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q = 0;
    IData/*23:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q = 0;
    IData/*23:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q = 0;
    SData/*8:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q = 0;
    SData/*8:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q = 0;
    CData/*1:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q = 0;
    CData/*7:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q = 0;
    QData/*63:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_result_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_result_q = 0;
    CData/*7:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_id_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_id_q = 0;
    SData/*8:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_beats_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_beats_q = 0;
    CData/*2:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_size_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_size_q = 0;
    CData/*1:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q = 0;
    CData/*4:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q = 0;
    CData/*3:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q = 0;
    CData/*2:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q = 0;
    CData/*2:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q = 0;
    CData/*2:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 0;
    CData/*0:0*/ __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15 = 0;
    CData/*3:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15 = 0;
    QData/*63:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0 = 0;
    CData/*2:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0;
    VL_ZERO_W(128, __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0);
    CData/*2:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1;
    VL_ZERO_W(128, __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1);
    CData/*2:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v0;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v0;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v0 = 0;
    SData/*11:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v0;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v0;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v0 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v1;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v1;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v1 = 0;
    CData/*3:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v0;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v0;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v0 = 0;
    SData/*11:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v1;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v1;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v1 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v2;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v2 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v2;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v2 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v3;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v3 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v3;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v3 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v4;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v4 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v4;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v4 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v5;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v5 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v5;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v5 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v6;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v6 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v6;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v6 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v7;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v7 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v7;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v7 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v8;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v8 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v8;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v8 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v9;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v9 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v9;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v9 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v10;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v10 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v10;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v10 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v11;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v11 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v11;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v11 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v12;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v12 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v12;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v12 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v13;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v13 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v13;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v13 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v14;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v14 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v14;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v14 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v15;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v15 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v15;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v15 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v16;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v16 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v16;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v16 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v17;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v17 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v17;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v17 = 0;
    CData/*2:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v18;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v18 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v18;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v18 = 0;
    CData/*3:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v1;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v1;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v1 = 0;
    SData/*11:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v2;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v2 = 0;
    CData/*7:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v2;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0 = 0;
    CData/*3:0*/ __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0;
    __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1 = 0;
    CData/*3:0*/ __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1;
    __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2 = 0;
    CData/*3:0*/ __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2;
    __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3 = 0;
    CData/*3:0*/ __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3;
    __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4 = 0;
    CData/*3:0*/ __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4;
    __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5 = 0;
    CData/*3:0*/ __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5;
    __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6 = 0;
    CData/*3:0*/ __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6;
    __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7;
    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7 = 0;
    CData/*4:0*/ __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7;
    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7 = 0;
    CData/*3:0*/ __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7;
    __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7 = 0;
    // Body
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_valid_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_valid_q;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v0 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v1 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v2 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v0 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v1 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v2 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v3 = 0U;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7 = 0U;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_value_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_value_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_addr_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_addr_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__total_beats_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__total_beats_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__progress_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__progress_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sum_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sum_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sumsq_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sumsq_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_op_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_op_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg1_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg1_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v0 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v17 = 0U;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_active_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_active_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_q;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v12 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v2 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v3 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v4 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v5 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v6 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v7 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v8 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v9 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v10 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v11 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v19 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v20 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v21 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v22 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v23 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v24 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v25 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v26 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v11 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v6 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v8 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v10 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v12 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v14 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v16 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v18 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v20 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v24 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v25 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v26 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v27 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v13 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v11 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v13 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v2 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v3 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v5 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v7 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v9 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v11 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v13 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v15 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v17 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v19 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v32 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v33 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v34 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v35 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v36 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v37 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v38 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v39 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v0 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v1 = 0U;
    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v40 = 0U;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1 = 0U;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_cancel_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_cancel_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_pending_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_pending_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_result_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_result_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_inflight_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_inflight_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_id_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_id_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_beats_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_beats_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_size_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_size_q;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0 = 0U;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14 = 0U;
    __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15 = 0U;
    __Vdly__tb_npu_single_core__DOT__s_axi_rvalid_o 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q;
    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q;
    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q;
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) {
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_valid_q) 
             & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_valid_q = 0U;
        }
        if (((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__tbu_req_ready))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_valid_q = 1U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q 
                = (((0U == (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_addr_q))) 
                    & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_addr_q 
                        >= vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_base_q) 
                       & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_addr_q 
                           <= vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_limit_q) 
                          & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_limit_q 
                             >= vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_base_q))))
                    ? ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__stream_id_q) 
                         == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_stream_id_q)) 
                        & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__substream_id_q) 
                           == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_substream_id_q)))
                        ? 0U : 2U) : 1U);
        }
        if ((1U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q 
                = (0x3eU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q));
        }
        if ((2U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q 
                = (0x3dU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q));
        }
        if ((4U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q 
                = (0x3bU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q));
        }
        if ((8U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q 
                = (0x37U & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q));
        }
        if ((0x10U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                      & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q 
                = (0x2fU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q));
        }
        if ((0x20U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                      & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q 
                = (0x1fU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q));
        }
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_handshake) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h78273bf2__0 = 0ULL;
            if ((0U == (7U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr))) {
                if ((0xff8U >= vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr)) {
                    if ((1U & (~ ((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)) 
                                  && (1U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_write) 
                                            >> (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))))))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h78273bf2__1 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q
                            [(0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                      >> 3U))][(0x1fU 
                                                & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                                   >> 7U))];
                        if ((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))) {
                            vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v1 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h78273bf2__1;
                            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v1 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client;
                            vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v1 = 1U;
                        }
                    }
                    if (((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)) 
                         && (1U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_write) 
                                   >> (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))))) {
                        if (((0x2fU >= (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U))))))) {
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0 
                                = ((0x17fU >= (0x1ffU 
                                               & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))) 
                                                | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))))
                                    : 0U);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0 
                                = (0x1fU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                            >> 7U));
                            __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0 
                                = (0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                           >> 3U));
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(1U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(1U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))))))) {
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(8U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(8U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(8U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(8U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(8U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(8U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))))
                                    : 0U);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1 
                                = (0x1fU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                            >> 7U));
                            __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1 
                                = (0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                           >> 3U));
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(2U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(2U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))))))) {
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x10U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x10U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x10U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x10U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x10U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x10U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))))
                                    : 0U);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2 
                                = (0x1fU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                            >> 7U));
                            __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2 
                                = (0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                           >> 3U));
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(3U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(3U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))))))) {
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x18U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x18U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x18U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x18U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x18U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x18U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))))
                                    : 0U);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3 
                                = (0x1fU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                            >> 7U));
                            __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3 
                                = (0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                           >> 3U));
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(4U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(4U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))))))) {
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x20U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x20U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x20U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x20U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x20U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x20U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))))
                                    : 0U);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4 
                                = (0x1fU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                            >> 7U));
                            __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4 
                                = (0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                           >> 3U));
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(5U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(5U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))))))) {
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x28U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x28U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x28U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x28U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))))
                                    : 0U);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5 
                                = (0x1fU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                            >> 7U));
                            __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5 
                                = (0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                           >> 3U));
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(6U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(6U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))))))) {
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x30U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x30U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x30U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x30U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x30U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x30U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))))
                                    : 0U);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6 
                                = (0x1fU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                            >> 7U));
                            __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6 
                                = (0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                           >> 3U));
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(7U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(7U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 3U)))))))) {
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x38U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x38U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x38U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x38U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x38U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x38U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client), 6U))))))
                                    : 0U);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7 
                                = (0x1fU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                            >> 7U));
                            __VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7 
                                = (0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
                                           >> 3U));
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7 = 1U;
                        }
                    }
                }
            }
            if ((0U != (7U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h605c7b22__0 = 3U;
                if ((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))) {
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v0 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h605c7b22__0;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v0 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client;
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v0 = 1U;
                }
            } else if ((0xff8U < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h605c7b22__1 = 4U;
                if ((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))) {
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v1 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h605c7b22__1;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v1 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client;
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v1 = 1U;
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h605c7b22__2 = 0U;
                if ((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))) {
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h605c7b22__2;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client;
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v2 = 1U;
                }
            }
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h244b9fb6__0 = 1U;
            if ((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))) {
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v0 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h78273bf2__0;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v0 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v0 = 1U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q 
                    = (((~ ((IData)(1U) << (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))) 
                        & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q)) 
                       | (0x3fU & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h244b9fb6__0) 
                                   << (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))));
            }
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q 
                = ((5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))
                    ? 0U : (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))));
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_req_valid) 
             & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__last_grant_dma_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_dma_w;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__owner_dma_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_dma_w;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q = 1U;
        }
        if (((7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_rsp_ready))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q = 0U;
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_valid_q = 0U;
        vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q__v2 = 1U;
        vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q__v3 = 1U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__last_grant_dma_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__owner_dma_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q = 0U;
    }
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) {
        if ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q))) {
            if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_valid) 
                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_ready))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q))) {
            if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_valid) 
                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_ready))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q = 2U;
            }
        } else if ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q))) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_pop_w) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q = 0U;
            }
        } else {
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q = 0U;
        }
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_cancel_q = 0U;
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_clear) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error = 0U;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i))) {
            vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o = 0U;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i))) {
            __Vdly__tb_npu_single_core__DOT__s_axi_rvalid_o = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_pop_rsp_q = 0U;
            if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q))) {
                if (((0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q))) 
                     == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_beats_q))) {
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 0U;
                } else {
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q)));
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q 
                        = (0xffffffU & ((IData)(8U) 
                                        + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q));
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_req_sent_q = 0U;
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 1U;
                }
            } else if ((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 0U;
            }
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i;
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i;
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i)));
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q = 0U;
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_sent_q = 0U;
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_cmd_format_w) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q = 0U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 1U;
            } else if ((((0x20020U == vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i) 
                         | ((0x20028U == vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i) 
                            | ((0x20030U == vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i) 
                               | (0x20048U == vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i)))) 
                        & ((1U == (0x1ffU & ((IData)(1U) 
                                             + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i)))) 
                           & ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i)) 
                              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i)) 
                                 & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i))))))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q = 3U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 2U;
            } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_csr_format_w) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q = 1U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 2U;
            } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_l1_format_w) 
                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__l1_host_access_enable_q))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q = 2U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 2U;
            } else {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q = 0U;
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q = 1U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 5U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error = 1U;
            }
        }
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_pop_w) {
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__base 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_rptr_q;
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__value 
                = ((IData)(2U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__base));
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__Vfuncout 
                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__value);
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_rptr_q 
                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1664__Vfuncout;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o))) {
            if ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))) {
                __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0 
                    = vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i;
                __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0 
                    = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q));
                __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0 = 1U;
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_complete_error_w;
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_last_expected_w) {
                    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_complete_error_w) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error = 1U;
                        vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o = 2U;
                    } else {
                        if ((0U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0 
                                = ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [0U]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0 = 1U;
                        }
                        if ((1U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(1U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1 
                                = ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [1U]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1 = 1U;
                        }
                        if ((2U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(2U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2 
                                = ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [2U]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2 = 1U;
                        }
                        if ((3U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(3U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3 
                                = ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [3U]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3 = 1U;
                        }
                        if ((4U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(4U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4 
                                = ((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [4U]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4 = 1U;
                        }
                        if ((5U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(5U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5 
                                = ((5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [5U]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5 = 1U;
                        }
                        if ((6U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(6U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6 
                                = ((6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [6U]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6 = 1U;
                        }
                        if ((7U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(7U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7 
                                = ((7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [7U]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7 = 1U;
                        }
                        if ((8U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(8U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8 
                                = ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [8U]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8 = 1U;
                        }
                        if ((9U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(9U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9 
                                = ((9U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [9U]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9 = 1U;
                        }
                        if ((0xaU < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(0xaU) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10 
                                = ((0xaU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [0xaU]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10 = 1U;
                        }
                        if ((0xbU < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(0xbU) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11 
                                = ((0xbU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [0xbU]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11 = 1U;
                        }
                        if ((0xcU < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(0xcU) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12 
                                = ((0xcU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [0xcU]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12 = 1U;
                        }
                        if ((0xdU < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(0xdU) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13 
                                = ((0xdU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [0xdU]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13 = 1U;
                        }
                        if ((0xeU < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(0xeU) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14 
                                = ((0xeU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [0xeU]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14 = 1U;
                        }
                        if ((0xfU < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value 
                                = ((IData)(0xfU) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__base));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout 
                                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__value);
                            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15 
                                = ((0xfU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem
                                   [0xfU]);
                            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15 
                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1661__Vfuncout;
                            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15 = 1U;
                        }
                        vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o = 0U;
                    }
                    vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o = 1U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 0U;
                } else {
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q)));
                }
            } else if ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))) {
                if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q))) {
                    vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o = 0U;
                    vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o = 1U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 0U;
                    if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_complete_error_w) 
                         | (0xffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i)))) {
                        vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error = 1U;
                    } else {
                        if ((0x20020U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q)) {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q 
                                = vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i;
                        } else if ((0x20028U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q)) {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q 
                                = vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i;
                        } else if ((0x20030U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q)) {
                            if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q) 
                                  | (0ULL != (vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
                                              >> 2U))) 
                                 | (0U == (3U & (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i))))) {
                                vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o = 2U;
                            } else {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q 
                                    = (3U & (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i));
                                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q = 1U;
                                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q = 0U;
                                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q = 0U;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_pending_q = 1U;
                            }
                        } else if ((0x20048U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q)) {
                            if ((1U & (((1ULL != vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i) 
                                        | (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q))) 
                                       | (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q))))) {
                                vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o = 2U;
                            } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_pending_q) {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_pending_q = 0U;
                                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q = 0U;
                                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q = 1U;
                                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q = 0xaU;
                                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_result_q = 0xaULL;
                            } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_inflight_q) {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_cancel_q = 1U;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_inflight_q = 0U;
                                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q = 0U;
                                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q = 1U;
                                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q = 0xaU;
                                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_result_q = 0xaULL;
                            }
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o = 2U;
                        }
                        if ((1U & (~ VL_ONEHOT_I(((
                                                   ((0x20048U 
                                                     == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q) 
                                                    << 3U) 
                                                   | ((0x20030U 
                                                       == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q) 
                                                      << 2U)) 
                                                  | (((0x20028U 
                                                       == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q) 
                                                      << 1U) 
                                                     | (0x20020U 
                                                        == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q))))))) {
                            if ((0U != ((((0x20048U 
                                           == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q) 
                                          << 3U) | 
                                         ((0x20030U 
                                           == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q) 
                                          << 2U)) | 
                                        (((0x20028U 
                                           == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q) 
                                          << 1U) | 
                                         (0x20020U 
                                          == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q))))) {
                                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                                    VL_WRITEF_NX("[%0t] %%Error: npu_axi_slave_frontend.sv:638: Assertion failed in %Ntb_npu_single_core.dut.u_axi_slave_frontend: unique case, but multiple matches found for '24'h%x'\n",0,
                                                 64,
                                                 VL_TIME_UNITED_Q(1000),
                                                 -9,
                                                 vlSymsp->name(),
                                                 24,
                                                 vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q);
                                    VL_STOP_MT("top/npu_axi_slave_frontend.sv", 638, "");
                                }
                            }
                        }
                    }
                } else {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                        = vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q 
                        = vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_addr_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q;
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_complete_error_w;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_sent_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 3U;
                }
            } else if ((5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q = 1U;
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_current_error_w) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error = 1U;
                }
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_last_expected_w) {
                    vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o = 1U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 0U;
                } else {
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q)));
                }
            }
        }
        if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))) {
            if (((((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)) 
                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_valid)) 
                  & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_valid_q))) 
                 | (((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)) 
                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__fe_l1_req_valid)) 
                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_sent_q = 1U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 4U;
            }
        }
        if (((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
             & ((((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)) 
                  & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_valid_q)) 
                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_rsp_ready)) 
                | (((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)) 
                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q)) 
                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__fe_l1_rsp_ready))))) {
            if ((((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)) 
                  & (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q))) 
                 | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)) 
                    & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                       [0U])))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q = 1U;
            }
            if (((0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))) 
                 == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q))) {
                vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o 
                    = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q) 
                         | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)) 
                            & (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q)))) 
                        | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)) 
                           & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                              [0U]))) ? 2U : 0U);
                vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o = 1U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 0U;
            } else {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q)));
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q 
                    = (0xffffffU & ((IData)(8U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q));
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_sent_q = 0U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 2U;
            }
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o))) {
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i;
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q = 0U;
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_id_q 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i;
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_beats_q 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i)));
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_size_q 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_req_sent_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_pop_rsp_q = 0U;
            if (((0x20008U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT____VdfgRegularize_h29da96d0_0_0))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 4U;
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q = 0U;
            } else if (((0x20010U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT____VdfgRegularize_h29da96d0_0_0))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 3U;
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q = 0U;
                vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__fifo_status_w;
                vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o = 0U;
                vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o = 1U;
                __Vdly__tb_npu_single_core__DOT__s_axi_rvalid_o = 1U;
            } else if ((((0x20020U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
                         | ((0x20028U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
                            | ((0x20038U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
                               | (0x20040U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i)))) 
                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT____VdfgRegularize_h29da96d0_0_0))) {
                if ((1U & (~ VL_ONEHOT_I(((((0x20040U 
                                             == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
                                            << 3U) 
                                           | ((0x20038U 
                                               == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
                                              << 2U)) 
                                          | (((0x20028U 
                                               == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
                                              << 1U) 
                                             | (0x20020U 
                                                == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i))))))) {
                    if ((0U != ((((0x20040U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
                                  << 3U) | ((0x20038U 
                                             == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
                                            << 2U)) 
                                | (((0x20028U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
                                    << 1U) | (0x20020U 
                                              == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: npu_axi_slave_frontend.sv:758: Assertion failed in %Ntb_npu_single_core.dut.u_axi_slave_frontend: unique case, but multiple matches found for '24'h%x'\n",0,
                                         64,VL_TIME_UNITED_Q(1000),
                                         -9,vlSymsp->name(),
                                         24,vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i);
                            VL_STOP_MT("top/npu_axi_slave_frontend.sv", 758, "");
                        }
                    }
                }
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 3U;
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q = 0U;
                vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    = ((0x20020U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i)
                        ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q
                        : ((0x20028U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i)
                            ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q
                            : ((0x20038U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i)
                                ? (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q)) 
                                    << 8U) | (QData)((IData)(
                                                             (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q) 
                                                               << 1U) 
                                                              | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q)))))
                                : ((0x20040U == vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i)
                                    ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_result_q
                                    : 0ULL))));
                vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o = 0U;
                vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o = 1U;
                __Vdly__tb_npu_single_core__DOT__s_axi_rvalid_o = 1U;
            } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ar_csr_format_w) 
                        & ((~ (vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                               >> 0x10U)) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 1U;
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q = 1U;
            } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ar_l1_format_w) 
                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__l1_host_access_enable_q))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 1U;
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q = 2U;
            } else {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 3U;
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q = 0U;
                vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o = 0ULL;
                vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o = 2U;
                vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o = 1U;
                __Vdly__tb_npu_single_core__DOT__s_axi_rvalid_o = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error = 1U;
            }
        }
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_pop_w) {
            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0 
                = (QData)((IData)(((0xff00000U & (((IData)(8U) 
                                                   - (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q)) 
                                                  << 0x14U)) 
                                   | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__response_status_q) 
                                       << 0xcU) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))));
            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_wptr_q;
            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0 = 1U;
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__base 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_wptr_q;
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__value 
                = ((IData)(1U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__base));
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__Vfuncout 
                = (7U & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__value);
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_wptr_q 
                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1665__Vfuncout;
        }
        if ((((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
              & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o))) 
             & (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_id_q;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem
                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_rptr_q];
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o = 1U;
            __Vdly__tb_npu_single_core__DOT__s_axi_rvalid_o = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_pop_rsp_q = 1U;
        }
        if ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q))) {
            if (((((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q)) 
                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_valid)) 
                  & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_valid_q))) 
                 | (((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q)) 
                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__fe_l1_req_valid)) 
                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready)))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 2U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_req_sent_q = 1U;
            }
        }
        if (((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
             & ((((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q)) 
                  & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_valid_q)) 
                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_rsp_ready)) 
                | (((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q)) 
                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q)) 
                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__fe_l1_rsp_ready))))) {
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__addr_low 
                = (7U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q);
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__size 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_size_q;
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 3U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_id_q;
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__data 
                = ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q))
                    ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_data_q
                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                   [0U]);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o 
                = ((0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q))) 
                   == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_beats_q));
            __Vdly__tb_npu_single_core__DOT__s_axi_rvalid_o = 1U;
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__mask 
                = ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__size))
                    ? VL_SHIFTL_QQI(64,64,32, 0xffULL, 
                                    VL_SHIFTL_III(32,32,32, (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__addr_low), 3U))
                    : ((1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__size))
                        ? VL_SHIFTL_QQI(64,64,32, 0xffffULL, 
                                        VL_SHIFTL_III(32,32,32, (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__addr_low), 3U))
                        : ((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__size))
                            ? VL_SHIFTL_QQI(64,64,32, 0xffffffffULL, 
                                            VL_SHIFTL_III(32,32,32, (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__addr_low), 3U))
                            : 0xffffffffffffffffULL)));
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__Vfuncout 
                = (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__data 
                   & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__mask);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__narrow_read_data__1662__Vfuncout;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o 
                = ((((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q)) 
                     & (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q))) 
                    | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q)) 
                       & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                          [0U]))) ? 2U : 0U);
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_pending_q) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__ctl_req_ready))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_pending_q = 0U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_inflight_q = 1U;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_inflight_q))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_inflight_q = 0U;
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q = 0U;
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q = 1U;
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q = 0U;
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_result_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q;
        }
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_commit_w) {
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__amount 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q;
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__base 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q;
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__value 
                = ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__base) 
                   + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__amount);
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__Vfuncout 
                = (0xfU & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__value);
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q 
                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1663__Vfuncout;
        }
        if ((2U == (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_commit_w) 
                     << 1U) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_pop_w)))) {
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q 
                = (0x1fU & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q) 
                            + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q)));
        } else if ((1U == (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_commit_w) 
                            << 1U) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_pop_w)))) {
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q 
                = (0x1fU & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q) 
                            - (IData)(2U)));
        } else if ((3U == (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_commit_w) 
                            << 1U) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_pop_w)))) {
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q 
                = (0x1fU & (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q) 
                             + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q)) 
                            - (IData)(2U)));
        }
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_pop_w) {
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__base 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_rptr_q;
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__value 
                = ((IData)(1U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__base));
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__Vfuncout 
                = (7U & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__value);
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_rptr_q 
                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_ptr_add__1666__Vfuncout;
        }
        if ((2U == (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_pop_w) 
                     << 1U) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_pop_w)))) {
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q)));
        } else if ((1U == (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_pop_w) 
                            << 1U) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_pop_w)))) {
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q 
                = (0xfU & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q) 
                           - (IData)(1U)));
        }
    } else {
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_result_q = 0ULL;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_wptr_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_rptr_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_wptr_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_rptr_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_sent_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_addr_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_id_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_beats_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_size_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_req_sent_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_pop_rsp_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o = 0U;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o = 0U;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o = 0U;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o = 0U;
        vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o = 0U;
        __Vdly__tb_npu_single_core__DOT__s_axi_rvalid_o = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q = 0ULL;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_pending_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_inflight_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_cancel_q = 0U;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q[__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0][__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0] 
            = ((0xffffffffffffff00ULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q
                [__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0]
                [__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0]) 
               | (IData)((IData)(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v0)));
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q[__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1][__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1] 
            = ((0xffffffffffff00ffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q
                [__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1]
                [__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v1)) 
                  << 8U));
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q[__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2][__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2] 
            = ((0xffffffffff00ffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q
                [__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2]
                [__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v2)) 
                  << 0x10U));
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q[__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3][__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3] 
            = ((0xffffffff00ffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q
                [__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3]
                [__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v3)) 
                  << 0x18U));
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q[__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4][__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4] 
            = ((0xffffff00ffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q
                [__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4]
                [__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v4)) 
                  << 0x20U));
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q[__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5][__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5] 
            = ((0xffff00ffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q
                [__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5]
                [__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v5)) 
                  << 0x28U));
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q[__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6][__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6] 
            = ((0xff00ffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q
                [__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6]
                [__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v6)) 
                  << 0x30U));
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q[__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7][__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7] 
            = ((0xffffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q
                [__VdlyDim1__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7]
                [__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__sram_q__v7)) 
                  << 0x38U));
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_index_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_addr_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_busy_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_done_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_status_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_result_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_result_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_id_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_id_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_beats_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_beats_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_size_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_size_q;
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__staging_mem__v0;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_mem__v0;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q;
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v0;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v1;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v2;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v3;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v4;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v5;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v6;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v7;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v8;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v9;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v10;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v11;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v12;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v13;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v14;
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem__v15;
    }
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o 
        = __Vdly__tb_npu_single_core__DOT__s_axi_rvalid_o;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_last_expected_w 
        = ((0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))) 
           == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_valid 
        = ((2U <= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q)) 
           & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q)) 
              | (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q))));
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_accepted = 0U;
        if ((2U == (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now) 
                     << 1U) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake)))) {
            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0[0U] 
                = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q);
            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0[1U] 
                = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q 
                           >> 0x20U));
            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0[2U] 
                = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q);
            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0[3U] 
                = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                           >> 0x20U));
            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q;
            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0 = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q 
                = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
                   | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q))));
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1673__pointer 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q;
            {
                if ((7U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1673__pointer))) {
                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1673__Vfuncout = 0U;
                    goto __Vlabel0;
                }
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1673__Vfuncout 
                    = (7U & ((IData)(1U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1673__pointer)));
                __Vlabel0: ;
            }
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q 
                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1673__Vfuncout;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q)));
        } else if ((1U == (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now) 
                            << 1U) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q 
                = ((~ ((IData)(1U) << (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q))) 
                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q));
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1674__pointer 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q;
            {
                if ((7U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1674__pointer))) {
                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1674__Vfuncout = 0U;
                    goto __Vlabel1;
                }
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1674__Vfuncout 
                    = (7U & ((IData)(1U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1674__pointer)));
                __Vlabel1: ;
            }
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q 
                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1674__Vfuncout;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q 
                = (0xfU & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q) 
                           - (IData)(1U)));
        } else if ((3U == (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now) 
                            << 1U) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake)))) {
            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1[0U] 
                = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q);
            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1[1U] 
                = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q 
                           >> 0x20U));
            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1[2U] 
                = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q);
            __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1[3U] 
                = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                           >> 0x20U));
            __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q;
            __VdlySet__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1 = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q 
                = ((~ ((IData)(1U) << (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q))) 
                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q 
                = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
                   | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q))));
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1675__pointer 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q;
            {
                if ((7U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1675__pointer))) {
                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1675__Vfuncout = 0U;
                    goto __Vlabel2;
                }
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1675__Vfuncout 
                    = (7U & ((IData)(1U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1675__pointer)));
                __Vlabel2: ;
            }
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q 
                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1675__Vfuncout;
            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1676__pointer 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q;
            {
                if ((7U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1676__pointer))) {
                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1676__Vfuncout = 0U;
                    goto __Vlabel3;
                }
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1676__Vfuncout 
                    = (7U & ((IData)(1U) + (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1676__pointer)));
                __Vlabel3: ;
            }
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q 
                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__increment_ptr__1676__Vfuncout;
        }
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((3U 
                                                 == 
                                                 (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake))) 
                                                << 2U) 
                                               | (((1U 
                                                    == 
                                                    (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now) 
                                                      << 1U) 
                                                     | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now) 
                                                       << 1U) 
                                                      | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake))))))))))) {
            if ((0U != (((3U == (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now) 
                                  << 1U) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake))) 
                         << 2U) | (((1U == (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake))) 
                                    << 1U) | (2U == 
                                              (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now) 
                                                << 1U) 
                                               | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: npu_cmd_frontend.sv:160: Assertion failed in %Ntb_npu_single_core.dut.u_cmd_frontend: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now) 
                                     << 1U) | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake)));
                    VL_STOP_MT("control/npu_cmd_frontend.sv", 160, "");
                }
            }
        }
        if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q))) {
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 0U;
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q))) {
                if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_rsp_valid) 
                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_rsp_ready))) {
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 0U;
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__response_status_q = 0U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_accepted = 1U;
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q))) {
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__lookup_valid) {
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q = 1U;
                }
                if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q) 
                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__lookup_rsp_valid))) {
                    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_q) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__response_status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error = 1U;
                        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 5U;
                    } else if ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__response_status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error = 1U;
                        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 5U;
                    } else {
                        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 4U;
                    }
                }
            } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__header_format_valid) {
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__opcode_format_valid) {
                    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__response_status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error = 1U;
                        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 5U;
                    } else {
                        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q = 0U;
                        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 3U;
                    }
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__response_status_q = 1U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error = 1U;
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 5U;
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__response_status_q = 2U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error = 1U;
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 5U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q))) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__input_handshake) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_data;
                if (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_first)) 
                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_last))) {
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 2U;
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__response_status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error = 1U;
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 5U;
                }
            } else if ((0x1fU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__wait_high_count_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__response_status_q = 9U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error = 1U;
                __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 5U;
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__wait_high_count_q 
                    = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__wait_high_count_q)));
            }
        } else {
            __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q = 0U;
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__input_handshake) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_data;
                if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_first) 
                     & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_last)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__wait_high_count_q = 0U;
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 1U;
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__response_status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error = 1U;
                    __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 5U;
                }
            }
        }
    } else {
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__response_status_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__wait_high_count_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q = 0U;
        __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_accepted = 0U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_wr_ptr_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_first 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_valid) 
           & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_last 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_valid) 
           & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_data 
        = ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q))
            ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem
           [([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__base 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_rptr_q;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__value 
                    = ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__base));
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__Vfuncout 
                    = (0xfU & vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__value);
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__Vfuncout))]
            : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem
           [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_rptr_q]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q 
        = __Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q;
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0][0U] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0][1U] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0][2U] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0][3U] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v0[3U];
    }
    if (__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1][0U] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1[0U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1][1U] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1[1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1][2U] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1[2U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q[__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1][3U] 
            = __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q__v1[3U];
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_rsp_valid 
        = (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now 
        = (4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[0U] 
        = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[1U] 
        = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[2U] 
        = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[3U] 
        = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                   >> 0x20U));
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) {
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__lookup_valid) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__lookup_rsp_valid = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_comb;
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__lookup_rsp_valid = 0U;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_inflight_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 0U;
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_release_q) {
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v0 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_slot_q;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v0 = 1U;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v0 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v0 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v0 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v0 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v0 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_slot_q;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_release_q = 0U;
            }
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_pending_q) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__ctl_req_ready))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_op_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q 
                = (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg1_q 
                = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q);
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_release_q = 0U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_status_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_failure_seq_q = 0xffffffffffffffffULL;
            if ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                if ((((0U != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q 
                              >> 0xcU)) | (0U != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q 
                                                  >> 3U))) 
                     | (7U == (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                } else if ((1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q 
                                          >> 2U)))) {
                    if ((1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q 
                                       >> 1U)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q 
                            = ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q))
                                ? 2ULL : ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found)
                                           ? (QData)((IData)(
                                                             vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q
                                                             [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select]))
                                           : 0ULL));
                    } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q 
                            = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found)
                                ? (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q
                                                  [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select]))
                                : 0ULL);
                    } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found) {
                        if ((1U & ((~ ([&]() {
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1706__state 
                                                    = 
                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select];
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1706__Vfuncout 
                                                    = 
                                                    ((5U 
                                                      == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1706__state)) 
                                                     | (6U 
                                                        == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1706__state)));
                                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1706__Vfuncout))) 
                                   | vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
                                   [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select]))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 1ULL;
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_release_q = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 0ULL;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_slot_q 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select;
                        }
                    } else {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                    }
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q 
                        = ((1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q 
                                          >> 1U))) ? 
                           ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q))
                             ? ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found)
                                 ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q
                                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select]
                                 : 0ULL) : ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found)
                                             ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q
                                            [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select]
                                             : 0ULL))
                            : ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q))
                                ? ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found)
                                    ? (((QData)((IData)(
                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                                        [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                                                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select][0xfU])))
                                    : 0ULL) : ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found)
                                                ? (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                                                                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select])) 
                                                    << 0xcU) 
                                                   | (QData)((IData)(
                                                                     ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                                                                       [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select] 
                                                                       << 4U) 
                                                                      | ([&]() {
                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select];
                                                        {
                                                            if (
                                                                (0U 
                                                                 == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__state))) {
                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__Vfuncout = 0U;
                                                                goto __Vlabel4;
                                                            }
                                                            if (
                                                                (4U 
                                                                 == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__state))) {
                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__Vfuncout = 2U;
                                                                goto __Vlabel4;
                                                            }
                                                            if (
                                                                ([&]() {
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1708__state 
                                                                            = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__state;
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1708__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1708__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1708__state)));
                                                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1708__Vfuncout))) {
                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__Vfuncout = 3U;
                                                                goto __Vlabel4;
                                                            }
                                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__Vfuncout = 1U;
                                                            __Vlabel4: ;
                                                        }
                                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__software_task_state__1707__Vfuncout))))))
                                                : (0x810ULL 
                                                   | ((QData)((IData)(
                                                                      (0xfffU 
                                                                       & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q)))) 
                                                      << 0xcU)))));
                }
            } else if ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q))) {
                if ((1U & (((((0U != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q 
                                      >> 0xcU)) | (0U 
                                                   != (IData)(
                                                              (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q 
                                                               >> 0x20U)))) 
                             | (~ ([&]() {
                                                __Vfunc_npu_event_ref_valid__1709__event_ref 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                                                __Vfunc_npu_event_ref_valid__1709__Vfuncout 
                                                    = 
                                                    ((0xfffU 
                                                      == (IData)(__Vfunc_npu_event_ref_valid__1709__event_ref)) 
                                                     | (0xffU 
                                                        != 
                                                        (0xffU 
                                                         & (IData)(__Vfunc_npu_event_ref_valid__1709__event_ref))));
                                            }(), (IData)(__Vfunc_npu_event_ref_valid__1709__Vfuncout)))) 
                            | (0xfffU == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q)))) 
                           | (0xffU <= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q)))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                } else if (((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q)))
                               ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                              [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))]
                               : 0U) != (0xfU & (IData)(
                                                        (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q 
                                                         >> 8U)))) 
                            | (0U == ((0xfeU >= (0xffU 
                                                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q)))
                                       ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                      [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))]
                                       : 0U)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 0x81ULL;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                } else if (((2U == ((0xfeU >= (0xffU 
                                               & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q)))
                                     ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                    [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))]
                                     : 0U)) | (3U == 
                                               ((0xfeU 
                                                 >= 
                                                 (0xffU 
                                                  & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q)))
                                                 ? 
                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                                [(0xffU 
                                                  & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))]
                                                 : 0U)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q 
                        = (((QData)((IData)(((0xfeU 
                                              >= (0xffU 
                                                  & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q)))
                                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q
                                             [(0xffU 
                                               & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))]
                                              : 0U))) 
                            << 8U) | (QData)((IData)(
                                                     ((0xfeU 
                                                       >= 
                                                       (0xffU 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q)))
                                                       ? 
                                                      vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                                      [
                                                      (0xffU 
                                                       & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))]
                                                       : 0U))));
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                } else if ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 9ULL;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                } else {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q = 1U;
                }
            } else if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q))) {
                if (((0U != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q 
                             >> 4U)) | (0U != (IData)(
                                                      (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q 
                                                       >> 0x20U))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                } else {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_status_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_failure_seq_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq;
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v0 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U];
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v0 = 1U;
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v1 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U];
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U];
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v3 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U];
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v4 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U];
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v5 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U];
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v6 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U];
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v7 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U];
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q = 1U;
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
            }
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((3U 
                                                     == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q)) 
                                                    << 2U) 
                                                   | (((1U 
                                                        == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q)) 
                                                       << 1U) 
                                                      | (2U 
                                                         == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q)))))))))) {
                if ((0U != (((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q)) 
                             << 2U) | (((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q)) 
                                        << 1U) | (2U 
                                                  == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q)))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: npu_task_scheduler.sv:861: Assertion failed in %Ntb_npu_single_core.dut.u_task_scheduler: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q));
                        VL_STOP_MT("control/npu_task_scheduler.sv", 861, "");
                    }
                }
            }
        }
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q) {
            if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_cancel_q) 
                 & ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_op_q)) 
                    | (3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_op_q))))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q = 0U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q = 0U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q = 0U;
            } else if ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_op_q))) {
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_found) {
                    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_terminal) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q 
                            = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_producer)) 
                                << 8U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_state)));
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q = 0U;
                    } else if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q 
                                >= vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg1_q)) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 9ULL;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q = 0U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q 
                            = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q);
                    }
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 0x81ULL;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q = 0U;
                }
            } else if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_op_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_status_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_failure_seq_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq;
                if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
                     & (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                          [0U]) | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                   [0U] != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                                   [0U])) | ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                        [0U];
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)) 
                                           | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout))))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q 
                        = (0xfeU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q));
                }
                if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
                      >> 1U) & (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                  [1U]) | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                           [1U] != 
                                           vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                                           [1U])) | 
                                ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                        [1U];
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)) 
                                           | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout))))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q 
                        = (0xfdU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q));
                }
                if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
                      >> 2U) & (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                  [2U]) | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                           [2U] != 
                                           vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                                           [2U])) | 
                                ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                        [2U];
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)) 
                                           | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout))))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q 
                        = (0xfbU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q));
                }
                if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
                      >> 3U) & (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                  [3U]) | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                           [3U] != 
                                           vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                                           [3U])) | 
                                ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                        [3U];
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)) 
                                           | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout))))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q 
                        = (0xf7U & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q));
                }
                if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
                      >> 4U) & (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                  [4U]) | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                           [4U] != 
                                           vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                                           [4U])) | 
                                ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                        [4U];
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)) 
                                           | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout))))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q 
                        = (0xefU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q));
                }
                if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
                      >> 5U) & (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                  [5U]) | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                           [5U] != 
                                           vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                                           [5U])) | 
                                ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                        [5U];
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)) 
                                           | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout))))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q 
                        = (0xdfU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q));
                }
                if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
                      >> 6U) & (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                  [6U]) | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                           [6U] != 
                                           vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                                           [6U])) | 
                                ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                        [6U];
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)) 
                                           | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout))))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q 
                        = (0xbfU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q));
                }
                if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
                      >> 7U) & (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                  [7U]) | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                           [7U] != 
                                           vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                                           [7U])) | 
                                ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                        [7U];
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)) 
                                           | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__state)));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1710__Vfuncout))))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q 
                        = (0x7fU & (IData)(vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q));
                }
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending) {
                    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q 
                         >= vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg1_q)) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 9ULL;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q = 0U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q 
                            = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q);
                    }
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q 
                        = (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status));
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q = 0U;
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 1U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q = 0U;
            }
        }
        if (((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q)) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd_ready))) {
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v1 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v1 = 1U;
            if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
                 >> 0x1fU)) {
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q__v0 = 0ULL;
                IData/*31:0*/ __Vilp1;
                __Vilp1 = 0U;
                while ((__Vilp1 <= 0x3fU)) {
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[__Vilp1] 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[__Vilp1];
                    __Vilp1 = ((IData)(1U) + __Vilp1);
                }
            } else {
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q__v0 
                    = (0xffffffffffffULL & (((QData)((IData)(
                                                             vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[0U]))));
                IData/*31:0*/ __Vilp2;
                __Vilp2 = 0U;
                while ((__Vilp2 <= 0x3fU)) {
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1[__Vilp2] 
                        = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp2];
                    __Vilp2 = ((IData)(1U) + __Vilp2);
                }
            }
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_command_id;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_engine;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_opcode;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_header_flags;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0_resolved;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1_resolved;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__submit_seq_q;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v1 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v0 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v1 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_static_valid) {
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v1 
                    = ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
                        >> 0x1fU) ? 2U : 1U);
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q__v0 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v0 = 0U;
            } else {
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v1 = 6U;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q__v0 = 0xfffU;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v0 = 2U;
            }
            vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v1 
                = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_static_valid)
                    ? 0U : ([&]() {
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1711__opcode 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_opcode;
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1711__Vfuncout 
                            = (0x6002ff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1711__opcode));
                    }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1711__Vfuncout));
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v1 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v1 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v1 
                = (1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_static_valid)));
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v1 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__submit_seq_q 
                = (1ULL + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__submit_seq_q);
            if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_static_valid) 
                  & (0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved))) 
                 & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_is_inline_rearm)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h0a2df4ca__0 = 1U;
                if (VL_LIKELY(((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v0 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h0a2df4ca__0;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v0 
                        = (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved));
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v0, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v0));
                }
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h496575a3__0 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_command_id;
                if (VL_LIKELY(((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v0 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h496575a3__0;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v0 
                        = (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved));
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v0, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v0));
                }
            }
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_valid) 
             & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_active_q = 1U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select;
        }
        if (((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_active_q))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_active_q = 0U;
            if ((1U & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1712__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1712__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1712__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1712__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1712__Vfuncout))))) {
                if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__command_id_q) 
                     != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                     [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q])) {
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v2 = 1U;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v1 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v1 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q
                        [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q];
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v1 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1713__opcode 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                        [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q];
                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1713__Vfuncout 
                        = (0x2002ff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1713__opcode));
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v2 
                        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1713__Vfuncout;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v2 = 1U;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                } else if ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q))) {
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v3 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v3 = 1U;
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__fault_addr_q;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v3 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__opcode 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                        [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q];
                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__status 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q;
                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__Vfuncout 
                        = (0x2000ff00U | (((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__status) 
                                           << 0x10U) 
                                          | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__opcode)));
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v3 
                        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1714__Vfuncout;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v3 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v3 = 1U;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v3 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v3 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                } else {
                    IData/*31:0*/ __Vilp3;
                    __Vilp3 = 0U;
                    while ((__Vilp3 <= 0x3fU)) {
                        vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2[__Vilp3] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_flat_q[__Vilp3];
                        __Vilp3 = ((IData)(1U) + __Vilp3);
                    }
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2 = 1U;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v4 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
                }
            }
        }
        if ((2U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
             [0U])) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed
                [0U]) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v5 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [0U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v4 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v4 = 1U;
            } else if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success
                        [0U] & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                                [0U]))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v6 = 1U;
            }
        }
        if ((2U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
             [1U])) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed
                [1U]) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v7 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [1U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v5 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v5 = 1U;
            } else if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success
                        [1U] & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                                [1U]))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v8 = 1U;
            }
        }
        if ((2U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
             [2U])) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed
                [2U]) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v9 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [2U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v6 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v6 = 1U;
            } else if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success
                        [2U] & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                                [2U]))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v10 = 1U;
            }
        }
        if ((2U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
             [3U])) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed
                [3U]) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v11 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [3U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v7 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v7 = 1U;
            } else if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success
                        [3U] & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                                [3U]))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v12 = 1U;
            }
        }
        if ((2U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
             [4U])) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed
                [4U]) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v13 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [4U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v8 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v8 = 1U;
            } else if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success
                        [4U] & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                                [4U]))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v14 = 1U;
            }
        }
        if ((2U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
             [5U])) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed
                [5U]) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v15 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [5U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v9 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v9 = 1U;
            } else if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success
                        [5U] & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                                [5U]))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v16 = 1U;
            }
        }
        if ((2U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
             [6U])) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed
                [6U]) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v17 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [6U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v10 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v10 = 1U;
            } else if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success
                        [6U] & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                                [6U]))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v18 = 1U;
            }
        }
        if ((2U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
             [7U])) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed
                [7U]) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v19 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [7U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v11 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1715__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v11 = 1U;
            } else if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success
                        [7U] & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                                [7U]))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v20 = 1U;
            }
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found) 
             & (~ (0U != (0xfU & (- (IData)((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q))))))))) {
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v11 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
            vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v11 = 1U;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v12 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v12 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v12 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
            if ((2U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                 [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select])) {
                if (((((((0xffU > (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                   [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U])) 
                         & ((2U == ((0xfeU >= (0xffU 
                                               & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                               [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U]))
                                     ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                    [(0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U])]
                                     : 0U)) | (3U == 
                                               ((0xfeU 
                                                 >= 
                                                 (0xffU 
                                                  & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                                  [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U]))
                                                 ? 
                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                                [(0xffU 
                                                  & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                                  [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U])]
                                                 : 0U)))) 
                        & (((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                       [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U]))
                             ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                            [(0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                              [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U])]
                             : 0U) == (0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                               [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U] 
                                               >> 8U)))) 
                       & (~ ([&]() {
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref 
                                                = (0xfffU 
                                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                                   [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U]);
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__unnamedblk1__DOT__slot = 0;
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found = 0U;
                                            if ((0xfffU 
                                                 != (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref))) {
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                       [0U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state 
                                                                            = 
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                            [0U];
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)));
                                                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                         [0U] 
                                                         == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                            [0U] 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                              [0U] 
                                                              != 
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                              [0U]))))) {
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found = 1U;
                                                }
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                       [1U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state 
                                                                            = 
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                            [1U];
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)));
                                                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                         [1U] 
                                                         == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                            [1U] 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                              [1U] 
                                                              != 
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                              [1U]))))) {
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found = 1U;
                                                }
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                       [2U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state 
                                                                            = 
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                            [2U];
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)));
                                                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                         [2U] 
                                                         == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                            [2U] 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                              [2U] 
                                                              != 
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                              [2U]))))) {
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found = 1U;
                                                }
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                       [3U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state 
                                                                            = 
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                            [3U];
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)));
                                                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                         [3U] 
                                                         == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                            [3U] 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                              [3U] 
                                                              != 
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                              [3U]))))) {
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found = 1U;
                                                }
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                       [4U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state 
                                                                            = 
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                            [4U];
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)));
                                                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                         [4U] 
                                                         == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                            [4U] 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                              [4U] 
                                                              != 
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                              [4U]))))) {
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found = 1U;
                                                }
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                       [5U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state 
                                                                            = 
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                            [5U];
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)));
                                                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                         [5U] 
                                                         == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                            [5U] 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                              [5U] 
                                                              != 
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                              [5U]))))) {
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found = 1U;
                                                }
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                       [6U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state 
                                                                            = 
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                            [6U];
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)));
                                                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                         [6U] 
                                                         == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                            [6U] 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                              [6U] 
                                                              != 
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                              [6U]))))) {
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found = 1U;
                                                }
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                       [7U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state 
                                                                            = 
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                            [7U];
                                                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__state)));
                                                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1717__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                         [7U] 
                                                         == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                            [7U] 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__event_ref)) 
                                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                              [7U] 
                                                              != 
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                              [7U]))))) {
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found = 1U;
                                                }
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__unnamedblk1__DOT__slot = 8U;
                                            }
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__Vfuncout 
                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__found;
                                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1716__Vfuncout)))) 
                      & ((0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                          [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][8U]) 
                         == (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                             [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U]))) 
                     & ((0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                 [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][8U] 
                                 >> 8U)) == (0xfU & 
                                             ((IData)(1U) 
                                              + ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                                  [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U] 
                                                  << 0x18U) 
                                                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U] 
                                                    >> 8U))))))) {
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v11 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v11 = 1U;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v12 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v21 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h2233453d__0 = 0U;
                    if (VL_LIKELY(((0xfeU >= (0xffU 
                                              & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                              [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U]))))) {
                        __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v1 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h2233453d__0;
                        __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v1 
                            = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                               [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U]);
                        vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v1, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v1));
                    }
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h2fa16ab9__0 
                        = (0xfU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                   [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][8U] 
                                   >> 8U));
                    if (VL_LIKELY(((0xfeU >= (0xffU 
                                              & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                              [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U]))))) {
                        __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v0 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h2fa16ab9__0;
                        __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v0 
                            = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                               [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U]);
                        vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v0, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v0));
                    }
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_ha16e251e__0 = 0U;
                    if (VL_LIKELY(((0xfeU >= (0xffU 
                                              & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                                              [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U]))))) {
                        __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v1 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_ha16e251e__0;
                        __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v1 
                            = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                               [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select][2U]);
                        vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v1, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v1));
                    }
                } else {
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v12 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v12 = 1U;
                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1718__opcode 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                        [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select];
                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1718__Vfuncout 
                        = (0x4002ff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1718__opcode));
                    vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v13 
                        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1718__Vfuncout;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v13 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v13 = 1U;
                    vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v22 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
                }
            } else {
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v13 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v13 = 1U;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v14 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v23 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select;
            }
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_task_valid) 
             & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_q = 1U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v24 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select;
            vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v24 = 1U;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_task_valid) 
             & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q = 1U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v25 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select;
            vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v25 = 1U;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_task_valid) 
             & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_q = 1U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v26 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select;
            vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v26 = 1U;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_task_valid) 
             & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_q = 1U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select;
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v27 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select;
            vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v27 = 1U;
        }
        if (((0xaU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_q))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_q = 0U;
            if ((1U & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1719__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1719__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1719__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1719__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1719__Vfuncout))))) {
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14 
                    = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_active_id_q) 
                         == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q]) 
                        & ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1720__status 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q;
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1720__Vfuncout 
                                    = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1720__status));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1720__Vfuncout)))
                        ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q)
                        : 2U);
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14 = 1U;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v12 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v12 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v13 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__progress_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v13 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v15 
                    = (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_active_id_q) 
                          == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1721__status 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1721__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1721__status));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1721__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q)))
                        ? 0U : ([&]() {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__opcode 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q];
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__status 
                                = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_active_id_q) 
                                     == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                                     [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q]) 
                                    & ([&]() {
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1723__status 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q;
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1723__Vfuncout 
                                                = (0xdU 
                                                   >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1723__status));
                                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1723__Vfuncout)))
                                    ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q)
                                    : 2U);
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__Vfuncout 
                                = (0x4000ff00U | (((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__status) 
                                                   << 0x10U) 
                                                  | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__opcode)));
                        }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1722__Vfuncout));
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v15 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v13 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v28 
                    = (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_active_id_q) 
                          == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1724__status 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1724__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1724__status));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1724__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q)))
                        ? 5U : 6U);
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v28 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v13 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q;
            }
        }
        if (((0x13U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q = 0U;
            if ((1U & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1725__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1725__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1725__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1725__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1725__Vfuncout))))) {
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15 
                    = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q) 
                         == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q]) 
                        & ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1726__status 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q;
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1726__Vfuncout 
                                    = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1726__status));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1726__Vfuncout)))
                        ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q)
                        : 2U);
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15 = 1U;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v13 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v13 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v14 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__progress_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v14 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v16 
                    = (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q) 
                          == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1727__status 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1727__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1727__status));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1727__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q)))
                        ? 0U : ([&]() {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__opcode 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q];
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__status 
                                = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q) 
                                     == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                                     [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q]) 
                                    & ([&]() {
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1729__status 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q;
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1729__Vfuncout 
                                                = (0xdU 
                                                   >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1729__status));
                                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1729__Vfuncout)))
                                    ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q)
                                    : 2U);
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__Vfuncout 
                                = (0x4000ff00U | (((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__status) 
                                                   << 0x10U) 
                                                  | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__opcode)));
                        }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1728__Vfuncout));
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v16 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v14 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v29 
                    = (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q) 
                          == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1730__status 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1730__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1730__status));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1730__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q)))
                        ? 5U : 6U);
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v29 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v14 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q;
            }
        }
        if (((0x11U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_q))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_q = 0U;
            if ((1U & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1731__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1731__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1731__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1731__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1731__Vfuncout))))) {
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16 
                    = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_active_id_q) 
                         == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q]) 
                        & ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1732__status 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q;
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1732__Vfuncout 
                                    = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1732__status));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1732__Vfuncout)))
                        ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q)
                        : 2U);
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16 = 1U;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v14 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v14 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v15 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__progress_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v15 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v17 
                    = (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_active_id_q) 
                          == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1733__status 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1733__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1733__status));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1733__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q)))
                        ? 0U : ([&]() {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__opcode 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q];
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__status 
                                = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_active_id_q) 
                                     == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                                     [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q]) 
                                    & ([&]() {
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1735__status 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q;
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1735__Vfuncout 
                                                = (0xdU 
                                                   >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1735__status));
                                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1735__Vfuncout)))
                                    ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q)
                                    : 2U);
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__Vfuncout 
                                = (0x4000ff00U | (((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__status) 
                                                   << 0x10U) 
                                                  | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__opcode)));
                        }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1734__Vfuncout));
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v17 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v15 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v30 
                    = (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_active_id_q) 
                          == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1736__status 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1736__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1736__status));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1736__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q)))
                        ? 5U : 6U);
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v30 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v15 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q;
            }
        }
        if (((0x14U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_q))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_q = 0U;
            if ((1U & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1737__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1737__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1737__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1737__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1737__Vfuncout))))) {
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17 
                    = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_active_id_q) 
                         == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q]) 
                        & ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1738__status 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q;
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1738__Vfuncout 
                                    = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1738__status));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1738__Vfuncout)))
                        ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q)
                        : 2U);
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17 = 1U;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v15 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v15 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v16 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__progress_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v16 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v18 
                    = (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_active_id_q) 
                          == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1739__status 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1739__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1739__status));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1739__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q)))
                        ? 0U : ([&]() {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__opcode 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q];
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__status 
                                = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_active_id_q) 
                                     == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                                     [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q]) 
                                    & ([&]() {
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1741__status 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q;
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1741__Vfuncout 
                                                = (0xdU 
                                                   >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1741__status));
                                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1741__Vfuncout)))
                                    ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q)
                                    : 2U);
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__Vfuncout 
                                = (0x4000ff00U | (((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__status) 
                                                   << 0x10U) 
                                                  | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__opcode)));
                        }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1740__Vfuncout));
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v18 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v16 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q;
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v31 
                    = (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_active_id_q) 
                          == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1742__status 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1742__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1742__status));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_valid__1742__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q)))
                        ? 5U : 6U);
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v31 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q;
                vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v16 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q;
            }
        }
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found) {
            vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v17 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select;
            vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v17 = 1U;
        }
        if (((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
              [0U] & (0xfffU != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                      [0U])) & (~ ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                                    [0U]) & (2U == 
                                             vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                             [0U]))))) {
            if ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                 [0U])) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [0U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v2 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v2 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [0U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v2, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v2));
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [0U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v3 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v3 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [0U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v3, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v3));
                }
            }
        }
        if (((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
              [1U] & (0xfffU != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                      [1U])) & (~ ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                                    [1U]) & (2U == 
                                             vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                             [1U]))))) {
            if ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                 [1U])) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [1U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v4 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v4 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [1U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v4, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v4));
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [1U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v5 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v5 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [1U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v5, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v5));
                }
            }
        }
        if (((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
              [2U] & (0xfffU != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                      [2U])) & (~ ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                                    [2U]) & (2U == 
                                             vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                             [2U]))))) {
            if ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                 [2U])) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [2U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v6 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v6 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [2U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v6, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v6));
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [2U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v7 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v7 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [2U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v7, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v7));
                }
            }
        }
        if (((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
              [3U] & (0xfffU != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                      [3U])) & (~ ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                                    [3U]) & (2U == 
                                             vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                             [3U]))))) {
            if ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                 [3U])) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [3U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v8 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v8 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [3U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v8, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v8));
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [3U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v9 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v9 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [3U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v9, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v9));
                }
            }
        }
        if (((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
              [4U] & (0xfffU != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                      [4U])) & (~ ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                                    [4U]) & (2U == 
                                             vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                             [4U]))))) {
            if ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                 [4U])) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [4U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v10 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v10 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [4U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v10, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v10));
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [4U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v11 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v11 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [4U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v11, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v11));
                }
            }
        }
        if (((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
              [5U] & (0xfffU != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                      [5U])) & (~ ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                                    [5U]) & (2U == 
                                             vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                             [5U]))))) {
            if ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                 [5U])) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [5U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v12 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v12 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [5U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v12, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v12));
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [5U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v13 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v13 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [5U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v13, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v13));
                }
            }
        }
        if (((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
              [6U] & (0xfffU != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                      [6U])) & (~ ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                                    [6U]) & (2U == 
                                             vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                             [6U]))))) {
            if ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                 [6U])) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [6U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v14 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v14 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [6U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v14, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v14));
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [6U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v15 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v15 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [6U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v15, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v15));
                }
            }
        }
        if (((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
              [7U] & (0xfffU != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                      [7U])) & (~ ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                                    [7U]) & (2U == 
                                             vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                                             [7U]))))) {
            if ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                 [7U])) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [7U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v16 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__0;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v16 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [7U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v16, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v16));
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                                          [7U]))))) {
                    __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v17 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h046bb140__1;
                    __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v17 
                        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q
                           [7U]);
                    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v17, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v17));
                }
            }
        }
        if ((0U != (0xfU & (- (IData)((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q))))))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                  [0U]) & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [0U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout))))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v32 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [0U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout 
                    = (0x500aff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v19 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v19 = 1U;
            }
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                  [1U]) & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [1U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout))))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v33 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [1U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout 
                    = (0x500aff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v20 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v20 = 1U;
            }
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                  [2U]) & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [2U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout))))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v34 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [2U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout 
                    = (0x500aff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v21 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v21 = 1U;
            }
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                  [3U]) & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [3U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout))))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v35 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [3U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout 
                    = (0x500aff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v22 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v22 = 1U;
            }
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                  [4U]) & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [4U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout))))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v36 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [4U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout 
                    = (0x500aff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v23 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v23 = 1U;
            }
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                  [5U]) & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [5U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout))))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v37 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [5U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout 
                    = (0x500aff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v24 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v24 = 1U;
            }
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                  [6U]) & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [6U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout))))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v38 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [6U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout 
                    = (0x500aff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v25 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v25 = 1U;
            }
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                  [7U]) & (~ ([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                    [7U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)) 
                                       | (6U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__state)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1743__Vfuncout))))) {
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v39 = 1U;
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [7U];
                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout 
                    = (0x500aff00U | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__opcode));
                vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v26 
                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__make_error_info__1744__Vfuncout;
                vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v26 = 1U;
            }
        }
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__submit_seq_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_active_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__lookup_rsp_valid = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_op_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg1_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_data_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_release_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_ack_slot_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_status_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_failure_seq_q = 0xffffffffffffffffULL;
        vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v40 = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__unnamedblk13__DOT__event_idx = 0U;
        while ((0xffU > vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__unnamedblk13__DOT__event_idx)) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_ha0a524a9__0 = 0U;
            if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__unnamedblk13__DOT__event_idx))))) {
                __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v18 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_ha0a524a9__0;
                __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v18 
                    = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__unnamedblk13__DOT__event_idx);
                vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v18, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q__v18));
            }
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_haf1f49ed__0 = 0U;
            if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__unnamedblk13__DOT__event_idx))))) {
                __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v1 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_haf1f49ed__0;
                __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v1 
                    = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__unnamedblk13__DOT__event_idx);
                vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v1, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q__v1));
            }
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h1fd80602__0 = 0U;
            if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__unnamedblk13__DOT__event_idx))))) {
                __VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v2 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____Vlvbound_h1fd80602__0;
                __VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v2 
                    = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__unnamedblk13__DOT__event_idx);
                vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q.enqueue(__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v2, (IData)(__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q__v2));
            }
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__unnamedblk13__DOT__event_idx 
                = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__unnamedblk13__DOT__event_idx);
        }
    }
}
