// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_memory_smoke.h for the primary calling header

#include "Vtb_memory_smoke__pch.h"
#include "Vtb_memory_smoke__Syms.h"
#include "Vtb_memory_smoke___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__0(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*19:0*/ tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0;
    tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0 = 0;
    CData/*0:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__0__write_access;
    __Vtask_tb_memory_smoke__DOT__l1_access__0__write_access = 0;
    IData/*19:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__0__address;
    __Vtask_tb_memory_smoke__DOT__l1_access__0__address = 0;
    QData/*63:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__0__data;
    __Vtask_tb_memory_smoke__DOT__l1_access__0__data = 0;
    CData/*7:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__0__strobe;
    __Vtask_tb_memory_smoke__DOT__l1_access__0__strobe = 0;
    CData/*0:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__1__write_access;
    __Vtask_tb_memory_smoke__DOT__l1_access__1__write_access = 0;
    IData/*19:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__1__address;
    __Vtask_tb_memory_smoke__DOT__l1_access__1__address = 0;
    QData/*63:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__1__data;
    __Vtask_tb_memory_smoke__DOT__l1_access__1__data = 0;
    CData/*7:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__1__strobe;
    __Vtask_tb_memory_smoke__DOT__l1_access__1__strobe = 0;
    CData/*0:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__2__write_access;
    __Vtask_tb_memory_smoke__DOT__l1_access__2__write_access = 0;
    IData/*19:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__2__address;
    __Vtask_tb_memory_smoke__DOT__l1_access__2__address = 0;
    QData/*63:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__2__data;
    __Vtask_tb_memory_smoke__DOT__l1_access__2__data = 0;
    CData/*7:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__2__strobe;
    __Vtask_tb_memory_smoke__DOT__l1_access__2__strobe = 0;
    CData/*0:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__3__write_access;
    __Vtask_tb_memory_smoke__DOT__l1_access__3__write_access = 0;
    IData/*19:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__3__address;
    __Vtask_tb_memory_smoke__DOT__l1_access__3__address = 0;
    QData/*63:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__3__data;
    __Vtask_tb_memory_smoke__DOT__l1_access__3__data = 0;
    CData/*7:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__3__strobe;
    __Vtask_tb_memory_smoke__DOT__l1_access__3__strobe = 0;
    CData/*0:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__4__write_access;
    __Vtask_tb_memory_smoke__DOT__l1_access__4__write_access = 0;
    IData/*19:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__4__address;
    __Vtask_tb_memory_smoke__DOT__l1_access__4__address = 0;
    QData/*63:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__4__data;
    __Vtask_tb_memory_smoke__DOT__l1_access__4__data = 0;
    CData/*7:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__4__strobe;
    __Vtask_tb_memory_smoke__DOT__l1_access__4__strobe = 0;
    CData/*0:0*/ __Vtask_tb_memory_smoke__DOT__tbu_access__5__write_access;
    __Vtask_tb_memory_smoke__DOT__tbu_access__5__write_access = 0;
    QData/*47:0*/ __Vtask_tb_memory_smoke__DOT__tbu_access__5__address;
    __Vtask_tb_memory_smoke__DOT__tbu_access__5__address = 0;
    CData/*0:0*/ __Vtask_tb_memory_smoke__DOT__tbu_access__6__write_access;
    __Vtask_tb_memory_smoke__DOT__tbu_access__6__write_access = 0;
    QData/*47:0*/ __Vtask_tb_memory_smoke__DOT__tbu_access__6__address;
    __Vtask_tb_memory_smoke__DOT__tbu_access__6__address = 0;
    CData/*0:0*/ __Vtask_tb_memory_smoke__DOT__tbu_access__7__write_access;
    __Vtask_tb_memory_smoke__DOT__tbu_access__7__write_access = 0;
    QData/*47:0*/ __Vtask_tb_memory_smoke__DOT__tbu_access__7__address;
    __Vtask_tb_memory_smoke__DOT__tbu_access__7__address = 0;
    CData/*0:0*/ __Vtask_tb_memory_smoke__DOT__mif_access__8__write_access;
    __Vtask_tb_memory_smoke__DOT__mif_access__8__write_access = 0;
    QData/*47:0*/ __Vtask_tb_memory_smoke__DOT__mif_access__8__address;
    __Vtask_tb_memory_smoke__DOT__mif_access__8__address = 0;
    QData/*63:0*/ __Vtask_tb_memory_smoke__DOT__mif_access__8__data;
    __Vtask_tb_memory_smoke__DOT__mif_access__8__data = 0;
    CData/*0:0*/ __Vtask_tb_memory_smoke__DOT__mif_access__9__write_access;
    __Vtask_tb_memory_smoke__DOT__mif_access__9__write_access = 0;
    QData/*47:0*/ __Vtask_tb_memory_smoke__DOT__mif_access__9__address;
    __Vtask_tb_memory_smoke__DOT__mif_access__9__address = 0;
    QData/*63:0*/ __Vtask_tb_memory_smoke__DOT__mif_access__9__data;
    __Vtask_tb_memory_smoke__DOT__mif_access__9__data = 0;
    CData/*0:0*/ __Vtask_tb_memory_smoke__DOT__mif_access__10__write_access;
    __Vtask_tb_memory_smoke__DOT__mif_access__10__write_access = 0;
    QData/*47:0*/ __Vtask_tb_memory_smoke__DOT__mif_access__10__address;
    __Vtask_tb_memory_smoke__DOT__mif_access__10__address = 0;
    QData/*63:0*/ __Vtask_tb_memory_smoke__DOT__mif_access__10__data;
    __Vtask_tb_memory_smoke__DOT__mif_access__10__data = 0;
    // Body
    vlSelfRef.tb_memory_smoke__DOT__clk = 0U;
    vlSelfRef.tb_memory_smoke__DOT__reset_n = 0U;
    vlSelfRef.tb_memory_smoke__DOT__l1_req_valid = 0U;
    vlSelfRef.tb_memory_smoke__DOT__l1_req_write = 0U;
    vlSelfRef.tb_memory_smoke__DOT__l1_req_addr = 0ULL;
    vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[0U] = 0U;
    vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[1U] = 0U;
    vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[2U] = 0U;
    vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[3U] = 0U;
    vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb = 0U;
    vlSelfRef.tb_memory_smoke__DOT__l1_rsp_ready = 3U;
    vlSelfRef.tb_memory_smoke__DOT__tbu_enable = 1U;
    vlSelfRef.tb_memory_smoke__DOT__tbu_allow_read = 1U;
    vlSelfRef.tb_memory_smoke__DOT__tbu_allow_write = 1U;
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_valid = 0U;
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_write = 0U;
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_addr = 0ULL;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_valid = 0U;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_write = 0U;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_addr = 0ULL;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_wdata = 0ULL;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_wstrb = 0U;
    vlSelfRef.tb_memory_smoke__DOT__next_read_response = 0U;
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         386);
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         386);
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         386);
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         386);
    vlSelfRef.tb_memory_smoke__DOT__reset_n = 1U;
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         388);
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         388);
    __Vtask_tb_memory_smoke__DOT__l1_access__0__strobe = 0xffU;
    __Vtask_tb_memory_smoke__DOT__l1_access__0__data = 0x1122334455667788ULL;
    __Vtask_tb_memory_smoke__DOT__l1_access__0__address = 0x10U;
    __Vtask_tb_memory_smoke__DOT__l1_access__0__write_access = 1U;
    vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client = 0U;
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         312);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_write = 
        (((~ ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client))) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_write)) 
         | (3U & ((IData)(__Vtask_tb_memory_smoke__DOT__l1_access__0__write_access) 
                  << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client))));
    tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0 = __Vtask_tb_memory_smoke__DOT__l1_access__0__address;
    if (VL_LIKELY(((0x27U >= (0x3fU & ((IData)(0x14U) 
                                       * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client)))))) {
        vlSelfRef.tb_memory_smoke__DOT__l1_req_addr 
            = (((~ (0xfffffULL << (0x3fU & ((IData)(0x14U) 
                                            * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client)))) 
                & vlSelfRef.tb_memory_smoke__DOT__l1_req_addr) 
               | (0xffffffffffULL & ((QData)((IData)(tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0)) 
                                     << (0x3fU & ((IData)(0x14U) 
                                                  * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client)))));
    }
    VL_ASSIGNSEL_WQ(128, 64, (0x7fU & VL_SHIFTL_III(7,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client, 6U)), vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata, __Vtask_tb_memory_smoke__DOT__l1_access__0__data);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb = 
        (((~ ((IData)(0xffU) << (0xfU & VL_SHIFTL_III(4,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client, 3U)))) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb)) 
         | (0xffffU & ((IData)(__Vtask_tb_memory_smoke__DOT__l1_access__0__strobe) 
                       << (0xfU & VL_SHIFTL_III(4,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client, 3U)))));
    vlSelfRef.tb_memory_smoke__DOT__l1_req_valid = 
        ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid) 
         | (3U & ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client))));
    while ((1U & (~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_ready) 
                     >> (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client))))) {
        co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_memory_smoke.clk)", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             318);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         319);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         320);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_valid = 
        ((~ ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client))) 
         & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid));
    while ((1U & (~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                     >> (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client))))) {
        co_await vlSelfRef.__VtrigSched_he4f62226__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__0__client[0]+:1])", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             322);
    }
    if (VL_UNLIKELY(((0U != vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q
                      [0U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:392: Assertion failed in %Ntb_memory_smoke: L1 full write failed\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 392, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         394);
    __Vtask_tb_memory_smoke__DOT__l1_access__1__strobe = 0U;
    __Vtask_tb_memory_smoke__DOT__l1_access__1__data = 0ULL;
    __Vtask_tb_memory_smoke__DOT__l1_access__1__address = 0x10U;
    __Vtask_tb_memory_smoke__DOT__l1_access__1__write_access = 0U;
    vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client = 1U;
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         312);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_write = 
        (((~ ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client))) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_write)) 
         | (3U & ((IData)(__Vtask_tb_memory_smoke__DOT__l1_access__1__write_access) 
                  << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client))));
    tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0 = __Vtask_tb_memory_smoke__DOT__l1_access__1__address;
    if (VL_LIKELY(((0x27U >= (0x3fU & ((IData)(0x14U) 
                                       * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client)))))) {
        vlSelfRef.tb_memory_smoke__DOT__l1_req_addr 
            = (((~ (0xfffffULL << (0x3fU & ((IData)(0x14U) 
                                            * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client)))) 
                & vlSelfRef.tb_memory_smoke__DOT__l1_req_addr) 
               | (0xffffffffffULL & ((QData)((IData)(tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0)) 
                                     << (0x3fU & ((IData)(0x14U) 
                                                  * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client)))));
    }
    VL_ASSIGNSEL_WQ(128, 64, (0x7fU & VL_SHIFTL_III(7,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client, 6U)), vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata, __Vtask_tb_memory_smoke__DOT__l1_access__1__data);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb = 
        (((~ ((IData)(0xffU) << (0xfU & VL_SHIFTL_III(4,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client, 3U)))) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb)) 
         | (0xffffU & ((IData)(__Vtask_tb_memory_smoke__DOT__l1_access__1__strobe) 
                       << (0xfU & VL_SHIFTL_III(4,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client, 3U)))));
    vlSelfRef.tb_memory_smoke__DOT__l1_req_valid = 
        ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid) 
         | (3U & ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client))));
    while ((1U & (~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_ready) 
                     >> (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client))))) {
        co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_memory_smoke.clk)", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             318);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         319);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         320);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_valid = 
        ((~ ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client))) 
         & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid));
    while ((1U & (~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                     >> (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client))))) {
        co_await vlSelfRef.__VtrigSched_hce1b93bc__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__1__client[0]+:1])", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             322);
    }
    if (VL_UNLIKELY((((0U != vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q
                       [1U]) | (0x1122334455667788ULL 
                                != vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q
                                [1U]))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:398: Assertion failed in %Ntb_memory_smoke: L1 readback mismatch\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 398, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         400);
    __Vtask_tb_memory_smoke__DOT__l1_access__2__strobe = 0xfU;
    __Vtask_tb_memory_smoke__DOT__l1_access__2__data = 0xaaaabbbbccccddddULL;
    __Vtask_tb_memory_smoke__DOT__l1_access__2__address = 0x10U;
    __Vtask_tb_memory_smoke__DOT__l1_access__2__write_access = 1U;
    vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client = 0U;
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         312);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_write = 
        (((~ ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client))) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_write)) 
         | (3U & ((IData)(__Vtask_tb_memory_smoke__DOT__l1_access__2__write_access) 
                  << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client))));
    tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0 = __Vtask_tb_memory_smoke__DOT__l1_access__2__address;
    if (VL_LIKELY(((0x27U >= (0x3fU & ((IData)(0x14U) 
                                       * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client)))))) {
        vlSelfRef.tb_memory_smoke__DOT__l1_req_addr 
            = (((~ (0xfffffULL << (0x3fU & ((IData)(0x14U) 
                                            * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client)))) 
                & vlSelfRef.tb_memory_smoke__DOT__l1_req_addr) 
               | (0xffffffffffULL & ((QData)((IData)(tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0)) 
                                     << (0x3fU & ((IData)(0x14U) 
                                                  * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client)))));
    }
    VL_ASSIGNSEL_WQ(128, 64, (0x7fU & VL_SHIFTL_III(7,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client, 6U)), vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata, __Vtask_tb_memory_smoke__DOT__l1_access__2__data);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb = 
        (((~ ((IData)(0xffU) << (0xfU & VL_SHIFTL_III(4,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client, 3U)))) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb)) 
         | (0xffffU & ((IData)(__Vtask_tb_memory_smoke__DOT__l1_access__2__strobe) 
                       << (0xfU & VL_SHIFTL_III(4,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client, 3U)))));
    vlSelfRef.tb_memory_smoke__DOT__l1_req_valid = 
        ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid) 
         | (3U & ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client))));
    while ((1U & (~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_ready) 
                     >> (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client))))) {
        co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_memory_smoke.clk)", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             318);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         319);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         320);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_valid = 
        ((~ ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client))) 
         & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid));
    while ((1U & (~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                     >> (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client))))) {
        co_await vlSelfRef.__VtrigSched_hfd03ddbb__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__2__client[0]+:1])", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             322);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         402);
    __Vtask_tb_memory_smoke__DOT__l1_access__3__strobe = 0U;
    __Vtask_tb_memory_smoke__DOT__l1_access__3__data = 0ULL;
    __Vtask_tb_memory_smoke__DOT__l1_access__3__address = 0x10U;
    __Vtask_tb_memory_smoke__DOT__l1_access__3__write_access = 0U;
    vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client = 1U;
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         312);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_write = 
        (((~ ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client))) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_write)) 
         | (3U & ((IData)(__Vtask_tb_memory_smoke__DOT__l1_access__3__write_access) 
                  << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client))));
    tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0 = __Vtask_tb_memory_smoke__DOT__l1_access__3__address;
    if (VL_LIKELY(((0x27U >= (0x3fU & ((IData)(0x14U) 
                                       * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client)))))) {
        vlSelfRef.tb_memory_smoke__DOT__l1_req_addr 
            = (((~ (0xfffffULL << (0x3fU & ((IData)(0x14U) 
                                            * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client)))) 
                & vlSelfRef.tb_memory_smoke__DOT__l1_req_addr) 
               | (0xffffffffffULL & ((QData)((IData)(tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0)) 
                                     << (0x3fU & ((IData)(0x14U) 
                                                  * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client)))));
    }
    VL_ASSIGNSEL_WQ(128, 64, (0x7fU & VL_SHIFTL_III(7,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client, 6U)), vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata, __Vtask_tb_memory_smoke__DOT__l1_access__3__data);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb = 
        (((~ ((IData)(0xffU) << (0xfU & VL_SHIFTL_III(4,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client, 3U)))) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb)) 
         | (0xffffU & ((IData)(__Vtask_tb_memory_smoke__DOT__l1_access__3__strobe) 
                       << (0xfU & VL_SHIFTL_III(4,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client, 3U)))));
    vlSelfRef.tb_memory_smoke__DOT__l1_req_valid = 
        ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid) 
         | (3U & ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client))));
    while ((1U & (~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_ready) 
                     >> (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client))))) {
        co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_memory_smoke.clk)", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             318);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         319);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         320);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_valid = 
        ((~ ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client))) 
         & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid));
    while ((1U & (~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                     >> (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client))))) {
        co_await vlSelfRef.__VtrigSched_hd6285ddb__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__3__client[0]+:1])", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             322);
    }
    if (VL_UNLIKELY(((0x11223344ccccddddULL != vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q
                      [1U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:405: Assertion failed in %Ntb_memory_smoke: L1 byte strobes were not applied\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 405, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         407);
    __Vtask_tb_memory_smoke__DOT__l1_access__4__strobe = 0U;
    __Vtask_tb_memory_smoke__DOT__l1_access__4__data = 0ULL;
    __Vtask_tb_memory_smoke__DOT__l1_access__4__address = 0x11U;
    __Vtask_tb_memory_smoke__DOT__l1_access__4__write_access = 0U;
    vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client = 0U;
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         312);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_write = 
        (((~ ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client))) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_write)) 
         | (3U & ((IData)(__Vtask_tb_memory_smoke__DOT__l1_access__4__write_access) 
                  << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client))));
    tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0 = __Vtask_tb_memory_smoke__DOT__l1_access__4__address;
    if (VL_LIKELY(((0x27U >= (0x3fU & ((IData)(0x14U) 
                                       * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client)))))) {
        vlSelfRef.tb_memory_smoke__DOT__l1_req_addr 
            = (((~ (0xfffffULL << (0x3fU & ((IData)(0x14U) 
                                            * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client)))) 
                & vlSelfRef.tb_memory_smoke__DOT__l1_req_addr) 
               | (0xffffffffffULL & ((QData)((IData)(tb_memory_smoke__DOT____Vlvbound_h7f8e1efa__0)) 
                                     << (0x3fU & ((IData)(0x14U) 
                                                  * vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client)))));
    }
    VL_ASSIGNSEL_WQ(128, 64, (0x7fU & VL_SHIFTL_III(7,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client, 6U)), vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata, __Vtask_tb_memory_smoke__DOT__l1_access__4__data);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb = 
        (((~ ((IData)(0xffU) << (0xfU & VL_SHIFTL_III(4,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client, 3U)))) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb)) 
         | (0xffffU & ((IData)(__Vtask_tb_memory_smoke__DOT__l1_access__4__strobe) 
                       << (0xfU & VL_SHIFTL_III(4,32,32, vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client, 3U)))));
    vlSelfRef.tb_memory_smoke__DOT__l1_req_valid = 
        ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid) 
         | (3U & ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client))));
    while ((1U & (~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_ready) 
                     >> (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client))))) {
        co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_memory_smoke.clk)", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             318);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         319);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         320);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_valid = 
        ((~ ((IData)(1U) << (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client))) 
         & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid));
    while ((1U & (~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                     >> (1U & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client))))) {
        co_await vlSelfRef.__VtrigSched_h39a94caa__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__4__client[0]+:1])", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             322);
    }
    if (VL_UNLIKELY(((3U != vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q
                      [0U])))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:410: Assertion failed in %Ntb_memory_smoke: L1 accepted a misaligned request\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 410, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         412);
    __Vtask_tb_memory_smoke__DOT__tbu_access__5__address = 0x1000ULL;
    __Vtask_tb_memory_smoke__DOT__tbu_access__5__write_access = 0U;
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         331);
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_write = __Vtask_tb_memory_smoke__DOT__tbu_access__5__write_access;
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_addr = __Vtask_tb_memory_smoke__DOT__tbu_access__5__address;
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         338);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         339);
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_valid = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h367e0241__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_memory_smoke.u_tbu_direct.rsp_valid_q)", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             341);
    }
    if (VL_UNLIKELY((((0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_status_q)) 
                      | (0x1000ULL != vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_addr_q))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:416: Assertion failed in %Ntb_memory_smoke: TBU identity read failed\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 416, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         418);
    vlSelfRef.tb_memory_smoke__DOT__tbu_allow_write = 0U;
    __Vtask_tb_memory_smoke__DOT__tbu_access__6__address = 0x1008ULL;
    __Vtask_tb_memory_smoke__DOT__tbu_access__6__write_access = 1U;
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         331);
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_write = __Vtask_tb_memory_smoke__DOT__tbu_access__6__write_access;
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_addr = __Vtask_tb_memory_smoke__DOT__tbu_access__6__address;
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         338);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         339);
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_valid = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h367e0241__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_memory_smoke.u_tbu_direct.rsp_valid_q)", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             341);
    }
    if (VL_UNLIKELY(((2U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_status_q))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:422: Assertion failed in %Ntb_memory_smoke: TBU did not reject a denied write\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 422, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         424);
    vlSelfRef.tb_memory_smoke__DOT__tbu_allow_write = 1U;
    __Vtask_tb_memory_smoke__DOT__tbu_access__7__address = 0x2000ULL;
    __Vtask_tb_memory_smoke__DOT__tbu_access__7__write_access = 0U;
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         331);
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_write = __Vtask_tb_memory_smoke__DOT__tbu_access__7__write_access;
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_addr = __Vtask_tb_memory_smoke__DOT__tbu_access__7__address;
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_valid = 1U;
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         338);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         339);
    vlSelfRef.tb_memory_smoke__DOT__tbu_req_valid = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h367e0241__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_memory_smoke.u_tbu_direct.rsp_valid_q)", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             341);
    }
    if (VL_UNLIKELY(((1U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_status_q))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:428: Assertion failed in %Ntb_memory_smoke: TBU did not reject an address outside its range\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 428, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         430);
    __Vtask_tb_memory_smoke__DOT__mif_access__8__data = 0ULL;
    __Vtask_tb_memory_smoke__DOT__mif_access__8__address = 0x1000ULL;
    __Vtask_tb_memory_smoke__DOT__mif_access__8__write_access = 0U;
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         351);
    vlSelfRef.tb_memory_smoke__DOT__mif_req_write = __Vtask_tb_memory_smoke__DOT__mif_access__8__write_access;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_addr = __Vtask_tb_memory_smoke__DOT__mif_access__8__address;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_wdata = __Vtask_tb_memory_smoke__DOT__mif_access__8__data;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_wstrb = 0xffU;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_valid = 1U;
    while ((0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_memory_smoke.clk)", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             357);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         358);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         359);
    vlSelfRef.tb_memory_smoke__DOT__mif_req_valid = 0U;
    while ((7U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_hc47e9d4d__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (3'h7 == tb_memory_smoke.u_mif.state_q))", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             361);
    }
    if (VL_UNLIKELY((((0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q)) 
                      | (0xcafef00d12344678ULL != vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_rdata_q))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:436: Assertion failed in %Ntb_memory_smoke: MIF AXI read failed\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 436, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         438);
    __Vtask_tb_memory_smoke__DOT__mif_access__9__data = 0xdeadbeef01234567ULL;
    __Vtask_tb_memory_smoke__DOT__mif_access__9__address = 0x1008ULL;
    __Vtask_tb_memory_smoke__DOT__mif_access__9__write_access = 1U;
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         351);
    vlSelfRef.tb_memory_smoke__DOT__mif_req_write = __Vtask_tb_memory_smoke__DOT__mif_access__9__write_access;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_addr = __Vtask_tb_memory_smoke__DOT__mif_access__9__address;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_wdata = __Vtask_tb_memory_smoke__DOT__mif_access__9__data;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_wstrb = 0xffU;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_valid = 1U;
    while ((0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_memory_smoke.clk)", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             357);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         358);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         359);
    vlSelfRef.tb_memory_smoke__DOT__mif_req_valid = 0U;
    while ((7U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_hc47e9d4d__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (3'h7 == tb_memory_smoke.u_mif.state_q))", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             361);
    }
    if (VL_UNLIKELY(((((0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q)) 
                       | (0xdeadbeef01234567ULL != vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_wdata_q)) 
                      | (0xffU != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_wstrb_q)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:443: Assertion failed in %Ntb_memory_smoke: MIF AXI write failed\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 443, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         445);
    vlSelfRef.tb_memory_smoke__DOT__next_read_response = 3U;
    __Vtask_tb_memory_smoke__DOT__mif_access__10__data = 0ULL;
    __Vtask_tb_memory_smoke__DOT__mif_access__10__address = 0x1010ULL;
    __Vtask_tb_memory_smoke__DOT__mif_access__10__write_access = 0U;
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         351);
    vlSelfRef.tb_memory_smoke__DOT__mif_req_write = __Vtask_tb_memory_smoke__DOT__mif_access__10__write_access;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_addr = __Vtask_tb_memory_smoke__DOT__mif_access__10__address;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_wdata = __Vtask_tb_memory_smoke__DOT__mif_access__10__data;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_wstrb = 0xffU;
    vlSelfRef.tb_memory_smoke__DOT__mif_req_valid = 1U;
    while ((0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_memory_smoke.clk)", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             357);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         358);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         359);
    vlSelfRef.tb_memory_smoke__DOT__mif_req_valid = 0U;
    while ((7U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
        co_await vlSelfRef.__VtrigSched_hc47e9d4d__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (3'h7 == tb_memory_smoke.u_mif.state_q))", 
                                                             "memory/tb_memory_smoke.sv", 
                                                             361);
    }
    if (VL_UNLIKELY(((4U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:449: Assertion failed in %Ntb_memory_smoke: MIF did not report AXI DECERR\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 449, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hf85b3a82__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         452);
    co_await vlSelfRef.__VtrigSched_hf85b3b43__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_memory_smoke.clk)", 
                                                         "memory/tb_memory_smoke.sv", 
                                                         453);
    if (VL_UNLIKELY((((2U != vlSelfRef.tb_memory_smoke__DOT__read_count) 
                      | (1U != vlSelfRef.tb_memory_smoke__DOT__write_count))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:455: Assertion failed in %Ntb_memory_smoke: AXI target transaction counts do not match\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 455, "", false);
    }
    if (VL_UNLIKELY(((1U & (((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__error_valid_q)) 
                             | (0x1010ULL != vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__error_addr_q)) 
                            | (4U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__error_status_q))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:459: Assertion failed in %Ntb_memory_smoke: MIF sticky error metadata is incorrect\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 459, "", false);
    }
    if (VL_UNLIKELY((((((0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q)) 
                        | (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q)) 
                       | (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q)) 
                      | (0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:462: Assertion failed in %Ntb_memory_smoke: memory modules did not return to idle\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("memory/tb_memory_smoke.sv", 462, "", false);
    }
    VL_WRITEF_NX("PASS: L1BUF, TBU and AXI MIF signature=%0b\n",0,
                 1,(1U & VL_REDXOR_64(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q
                                      [0U])));
    VL_FINISH_MT("memory/tb_memory_smoke.sv", 469, "");
}

VL_INLINE_OPT VlCoroutine Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__1(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x186a0ULL, 
                                         nullptr, "memory/tb_memory_smoke.sv", 
                                         473);
    VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:474: Assertion failed in %Ntb_memory_smoke: memory smoke test timeout\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
    VL_STOP_MT("memory/tb_memory_smoke.sv", 474, "", false);
}

VL_INLINE_OPT VlCoroutine Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__2(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "memory/tb_memory_smoke.sv", 
                                             99);
        vlSelfRef.tb_memory_smoke__DOT__clk = (1U & 
                                               (~ (IData)(vlSelfRef.tb_memory_smoke__DOT__clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_memory_smoke___024root___dump_triggers__act(Vtb_memory_smoke___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_memory_smoke___024root___eval_triggers__act(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_triggers__act\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vtrigprevexpr_h60c90f32__0;
    __Vtrigprevexpr_h60c90f32__0 = 0;
    // Body
    __Vtrigprevexpr_h60c90f32__0 = (7U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q));
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb_memory_smoke__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_memory_smoke__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__reset_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_memory_smoke__DOT__reset_n__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_memory_smoke__DOT__clk__0)));
    vlSelfRef.__VactTriggered.setBit(3U, ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                                                 >> 
                                                 (1U 
                                                  & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client))) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr_h81419cab__0)));
    vlSelfRef.__VactTriggered.setBit(4U, ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                                                 >> 
                                                 (1U 
                                                  & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client))) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr_h5a2c0699__0)));
    vlSelfRef.__VactTriggered.setBit(5U, ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                                                 >> 
                                                 (1U 
                                                  & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client))) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr_ha9345098__0)));
    vlSelfRef.__VactTriggered.setBit(6U, ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                                                 >> 
                                                 (1U 
                                                  & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client))) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr_h521fd0b8__0)));
    vlSelfRef.__VactTriggered.setBit(7U, ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                                                 >> 
                                                 (1U 
                                                  & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client))) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr_had9ebf87__0)));
    vlSelfRef.__VactTriggered.setBit(8U, ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q__0)));
    vlSelfRef.__VactTriggered.setBit(9U, ((IData)(__Vtrigprevexpr_h60c90f32__0) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr_h60c90f32__1)));
    vlSelfRef.__VactTriggered.setBit(0xaU, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb_memory_smoke__DOT__clk__0 
        = vlSelfRef.tb_memory_smoke__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_memory_smoke__DOT__reset_n__0 
        = vlSelfRef.tb_memory_smoke__DOT__reset_n;
    vlSelfRef.__Vtrigprevexpr_h81419cab__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                                               >> (1U 
                                                   & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__0__client)));
    vlSelfRef.__Vtrigprevexpr_h5a2c0699__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                                               >> (1U 
                                                   & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__1__client)));
    vlSelfRef.__Vtrigprevexpr_ha9345098__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                                               >> (1U 
                                                   & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__2__client)));
    vlSelfRef.__Vtrigprevexpr_h521fd0b8__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                                               >> (1U 
                                                   & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__3__client)));
    vlSelfRef.__Vtrigprevexpr_had9ebf87__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                                               >> (1U 
                                                   & vlSelfRef.__Vtask_tb_memory_smoke__DOT__l1_access__4__client)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q__0 
        = vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q;
    vlSelfRef.__Vtrigprevexpr_h60c90f32__1 = __Vtrigprevexpr_h60c90f32__0;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(3U, 1U);
        vlSelfRef.__VactTriggered.setBit(4U, 1U);
        vlSelfRef.__VactTriggered.setBit(5U, 1U);
        vlSelfRef.__VactTriggered.setBit(6U, 1U);
        vlSelfRef.__VactTriggered.setBit(7U, 1U);
        vlSelfRef.__VactTriggered.setBit(8U, 1U);
        vlSelfRef.__VactTriggered.setBit(9U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_memory_smoke___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_memory_smoke___024root___nba_sequent__TOP__0(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___nba_sequent__TOP__0\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__Vfuncout;
    __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response;
    __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response = 0;
    CData/*2:0*/ __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__Vfuncout;
    __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response;
    __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response = 0;
    CData/*0:0*/ __Vdly__tb_memory_smoke__DOT__aw_seen_q;
    __Vdly__tb_memory_smoke__DOT__aw_seen_q = 0;
    CData/*0:0*/ __Vdly__tb_memory_smoke__DOT__w_seen_q;
    __Vdly__tb_memory_smoke__DOT__w_seen_q = 0;
    CData/*0:0*/ __Vdly__tb_memory_smoke__DOT__axi_bvalid;
    __Vdly__tb_memory_smoke__DOT__axi_bvalid = 0;
    CData/*0:0*/ __Vdly__tb_memory_smoke__DOT__axi_rvalid;
    __Vdly__tb_memory_smoke__DOT__axi_rvalid = 0;
    CData/*1:0*/ __Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q;
    __Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q = 0;
    CData/*0:0*/ __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q;
    __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q = 0;
    CData/*2:0*/ __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q;
    __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q = 0;
    CData/*2:0*/ __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q;
    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 0;
    CData/*2:0*/ __Vdly__tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q;
    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q = 0;
    QData/*39:0*/ __Vdly__tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q;
    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q = 0;
    QData/*47:0*/ __Vdly__tb_memory_smoke__DOT__u_mif__DOT__req_addr_q;
    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__req_addr_q = 0;
    CData/*2:0*/ __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0;
    __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0 = 0;
    CData/*0:0*/ __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0;
    __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v1;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0;
    __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0 = 0;
    CData/*2:0*/ __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0;
    __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0 = 0;
    CData/*1:0*/ __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0;
    __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1;
    __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1 = 0;
    CData/*2:0*/ __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1;
    __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1 = 0;
    CData/*1:0*/ __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1;
    __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2;
    __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2 = 0;
    CData/*2:0*/ __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2;
    __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2 = 0;
    CData/*1:0*/ __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2;
    __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3;
    __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3 = 0;
    CData/*2:0*/ __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3;
    __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3 = 0;
    CData/*1:0*/ __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3;
    __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3 = 0;
    CData/*7:0*/ __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4;
    __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4 = 0;
    CData/*2:0*/ __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4;
    __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4 = 0;
    CData/*1:0*/ __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4;
    __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4 = 0;
    CData/*7:0*/ __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5;
    __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5 = 0;
    CData/*2:0*/ __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5;
    __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5 = 0;
    CData/*1:0*/ __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5;
    __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5 = 0;
    CData/*7:0*/ __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6;
    __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6 = 0;
    CData/*2:0*/ __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6;
    __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6 = 0;
    CData/*1:0*/ __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6;
    __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6 = 0;
    CData/*7:0*/ __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7;
    __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7 = 0;
    CData/*2:0*/ __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7;
    __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7 = 0;
    CData/*1:0*/ __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7;
    __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7 = 0;
    CData/*0:0*/ __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v0;
    __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v0;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v0 = 0;
    QData/*63:0*/ __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1;
    __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1 = 0;
    CData/*0:0*/ __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1;
    __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v2;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v2 = 0;
    // Body
    __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q 
        = vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0 = 0U;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v1 = 0U;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v0 = 0U;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1 = 0U;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v2 = 0U;
    __Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q 
        = vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q;
    __Vdly__tb_memory_smoke__DOT__aw_seen_q = vlSelfRef.tb_memory_smoke__DOT__aw_seen_q;
    __Vdly__tb_memory_smoke__DOT__w_seen_q = vlSelfRef.tb_memory_smoke__DOT__w_seen_q;
    __Vdly__tb_memory_smoke__DOT__axi_bvalid = vlSelfRef.tb_memory_smoke__DOT__axi_bvalid;
    __Vdly__tb_memory_smoke__DOT__axi_rvalid = vlSelfRef.tb_memory_smoke__DOT__axi_rvalid;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0 = 0U;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1 = 0U;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2 = 0U;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3 = 0U;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4 = 0U;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5 = 0U;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6 = 0U;
    __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7 = 0U;
    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q 
        = vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q;
    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q 
        = vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q;
    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__req_addr_q 
        = vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_addr_q;
    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q 
        = vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q;
    __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q 
        = vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q;
    if (vlSelfRef.tb_memory_smoke__DOT__reset_n) {
        if (vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q) {
            vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q = 0U;
        }
        if (vlSelfRef.tb_memory_smoke__DOT__tbu_req_valid) {
            vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q = 1U;
        }
        if (((IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q) 
             & (2U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q)))) {
            __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q = 0U;
        }
        if (((1U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_memory_smoke__DOT__mif_tbu_req_ready))) {
            __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q = 1U;
        }
        if (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_handshake) {
            __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0 
                = ((0U != (7U & vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr))
                    ? 3U : ((0xf8U < vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr)
                             ? 4U : 0U));
            __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0 
                = vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client;
            __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0 = 1U;
        }
    } else {
        vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q = 0U;
        __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q = 0U;
        __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v1 = 1U;
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q[__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0] 
            = __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v0;
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q__v1) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q[0U] = 0U;
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q[1U] = 0U;
    }
    if (vlSelfRef.tb_memory_smoke__DOT__reset_n) {
        if (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_handshake) {
            __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v0 
                = vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client;
            __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v0 = 1U;
            if ((0U == (7U & vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr))) {
                if ((0xf8U >= vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr)) {
                    if ((1U & (~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_write) 
                                  >> (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client))))) {
                        __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1 
                            = vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q
                            [(3U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                    >> 3U))][(7U & 
                                              (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                               >> 5U))];
                        __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1 
                            = vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client;
                        __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1 = 1U;
                    }
                }
            }
        }
    } else {
        __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v2 = 1U;
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v0) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q[__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v0] = 0ULL;
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q[__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1] 
            = __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v1;
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q__v2) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q[0U] = 0ULL;
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q[1U] = 0ULL;
    }
    if (vlSelfRef.tb_memory_smoke__DOT__reset_n) {
        if ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                   & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_rsp_ready)))) {
            __Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q 
                = (2U & (IData)(__Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q));
        }
        if ((2U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                   & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_rsp_ready)))) {
            __Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q 
                = (1U & (IData)(__Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q));
        }
        if (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_handshake) {
            __Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q 
                = ((IData)(__Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                   | (3U & ((IData)(1U) << (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client))));
            if ((0U == (7U & vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr))) {
                if ((0xf8U >= vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr)) {
                    if ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_write) 
                               >> (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client)))) {
                        if ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb) 
                                   >> (0xfU & VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 3U))))) {
                            __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0 
                                = (0xffU & (((0U == 
                                              (0x1fU 
                                               & VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))
                                              ? 0U : 
                                             (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                              (((IData)(7U) 
                                                + (0x7fU 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))) 
                                            | (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                               (3U 
                                                & (VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U) 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))));
                            __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0 
                                = (7U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 5U));
                            __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0 
                                = (3U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 3U));
                            __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0 = 1U;
                        }
                        if ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb) 
                                   >> (0xfU & ((IData)(1U) 
                                               + VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 3U)))))) {
                            __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1 
                                = (0xffU & (((0U == 
                                              (0x1fU 
                                               & ((IData)(8U) 
                                                  + 
                                                  VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))
                                              ? 0U : 
                                             (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                              (((IData)(7U) 
                                                + (0x7fU 
                                                   & ((IData)(8U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(8U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                            | (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                               (3U 
                                                & (((IData)(8U) 
                                                    + 
                                                    VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)) 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & ((IData)(8U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))));
                            __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1 
                                = (7U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 5U));
                            __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1 
                                = (3U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 3U));
                            __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1 = 1U;
                        }
                        if ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb) 
                                   >> (0xfU & ((IData)(2U) 
                                               + VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 3U)))))) {
                            __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2 
                                = (0xffU & (((0U == 
                                              (0x1fU 
                                               & ((IData)(0x10U) 
                                                  + 
                                                  VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))
                                              ? 0U : 
                                             (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                              (((IData)(7U) 
                                                + (0x7fU 
                                                   & ((IData)(0x10U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x10U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                            | (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                               (3U 
                                                & (((IData)(0x10U) 
                                                    + 
                                                    VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)) 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & ((IData)(0x10U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))));
                            __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2 
                                = (7U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 5U));
                            __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2 
                                = (3U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 3U));
                            __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2 = 1U;
                        }
                        if ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb) 
                                   >> (0xfU & ((IData)(3U) 
                                               + VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 3U)))))) {
                            __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3 
                                = (0xffU & (((0U == 
                                              (0x1fU 
                                               & ((IData)(0x18U) 
                                                  + 
                                                  VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))
                                              ? 0U : 
                                             (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                              (((IData)(7U) 
                                                + (0x7fU 
                                                   & ((IData)(0x18U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x18U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                            | (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                               (3U 
                                                & (((IData)(0x18U) 
                                                    + 
                                                    VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)) 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & ((IData)(0x18U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))));
                            __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3 
                                = (7U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 5U));
                            __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3 
                                = (3U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 3U));
                            __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3 = 1U;
                        }
                        if ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb) 
                                   >> (0xfU & ((IData)(4U) 
                                               + VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 3U)))))) {
                            __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4 
                                = (0xffU & (((0U == 
                                              (0x1fU 
                                               & ((IData)(0x20U) 
                                                  + 
                                                  VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))
                                              ? 0U : 
                                             (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                              (((IData)(7U) 
                                                + (0x7fU 
                                                   & ((IData)(0x20U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x20U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                            | (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                               (3U 
                                                & (((IData)(0x20U) 
                                                    + 
                                                    VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)) 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & ((IData)(0x20U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))));
                            __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4 
                                = (7U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 5U));
                            __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4 
                                = (3U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 3U));
                            __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4 = 1U;
                        }
                        if ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb) 
                                   >> (0xfU & ((IData)(5U) 
                                               + VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 3U)))))) {
                            __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5 
                                = (0xffU & (((0U == 
                                              (0x1fU 
                                               & ((IData)(0x28U) 
                                                  + 
                                                  VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))
                                              ? 0U : 
                                             (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                              (((IData)(7U) 
                                                + (0x7fU 
                                                   & ((IData)(0x28U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x28U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                            | (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                               (3U 
                                                & (((IData)(0x28U) 
                                                    + 
                                                    VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)) 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & ((IData)(0x28U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))));
                            __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5 
                                = (7U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 5U));
                            __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5 
                                = (3U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 3U));
                            __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5 = 1U;
                        }
                        if ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb) 
                                   >> (0xfU & ((IData)(6U) 
                                               + VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 3U)))))) {
                            __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6 
                                = (0xffU & (((0U == 
                                              (0x1fU 
                                               & ((IData)(0x30U) 
                                                  + 
                                                  VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))
                                              ? 0U : 
                                             (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                              (((IData)(7U) 
                                                + (0x7fU 
                                                   & ((IData)(0x30U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x30U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                            | (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                               (3U 
                                                & (((IData)(0x30U) 
                                                    + 
                                                    VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)) 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & ((IData)(0x30U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))));
                            __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6 
                                = (7U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 5U));
                            __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6 
                                = (3U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 3U));
                            __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6 = 1U;
                        }
                        if ((1U & ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_wstrb) 
                                   >> (0xfU & ((IData)(7U) 
                                               + VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 3U)))))) {
                            __VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7 
                                = (0xffU & (((0U == 
                                              (0x1fU 
                                               & ((IData)(0x38U) 
                                                  + 
                                                  VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))
                                              ? 0U : 
                                             (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                              (((IData)(7U) 
                                                + (0x7fU 
                                                   & ((IData)(0x38U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x38U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                            | (vlSelfRef.tb_memory_smoke__DOT__l1_req_wdata[
                                               (3U 
                                                & (((IData)(0x38U) 
                                                    + 
                                                    VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U)) 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & ((IData)(0x38U) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client), 6U))))));
                            __VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7 
                                = (7U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 5U));
                            __VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7 
                                = (3U & (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
                                         >> 3U));
                            __VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7 = 1U;
                        }
                    }
                }
            }
        }
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q 
            = __Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q;
    } else {
        __Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q = 0U;
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q 
            = __Vdly__tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q;
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q[__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0][__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0] 
            = ((0xffffffffffffff00ULL & vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q
                [__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0]
                [__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0]) 
               | (IData)((IData)(__VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v0)));
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q[__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1][__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1] 
            = ((0xffffffffffff00ffULL & vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q
                [__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1]
                [__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1]) 
               | ((QData)((IData)(__VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v1)) 
                  << 8U));
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q[__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2][__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2] 
            = ((0xffffffffff00ffffULL & vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q
                [__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2]
                [__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2]) 
               | ((QData)((IData)(__VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v2)) 
                  << 0x10U));
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q[__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3][__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3] 
            = ((0xffffffff00ffffffULL & vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q
                [__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3]
                [__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3]) 
               | ((QData)((IData)(__VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v3)) 
                  << 0x18U));
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q[__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4][__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4] 
            = ((0xffffff00ffffffffULL & vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q
                [__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4]
                [__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4]) 
               | ((QData)((IData)(__VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v4)) 
                  << 0x20U));
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q[__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5][__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5] 
            = ((0xffff00ffffffffffULL & vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q
                [__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5]
                [__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5]) 
               | ((QData)((IData)(__VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v5)) 
                  << 0x28U));
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q[__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6][__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6] 
            = ((0xff00ffffffffffffULL & vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q
                [__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6]
                [__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6]) 
               | ((QData)((IData)(__VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v6)) 
                  << 0x30U));
    }
    if (__VdlySet__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7) {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q[__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7][__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7] 
            = ((0xffffffffffffffULL & vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__sram_q
                [__VdlyDim1__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7]
                [__VdlyDim0__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7]) 
               | ((QData)((IData)(__VdlyVal__tb_memory_smoke__DOT__u_l1__DOT__sram_q__v7)) 
                  << 0x38U));
    }
    if (vlSelfRef.tb_memory_smoke__DOT__reset_n) {
        if (((1U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_memory_smoke__DOT__mif_tbu_req_ready))) {
            __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q 
                = (((0U == (7U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_addr_q))) 
                    & (0xfffffff8ULL >= vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_addr_q))
                    ? (((0x33U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__stream_id_q)) 
                        & (0x44U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__substream_id_q)))
                        ? 0U : 2U) : 1U);
        }
        if (vlSelfRef.tb_memory_smoke__DOT__tbu_req_valid) {
            vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_addr_q 
                = vlSelfRef.tb_memory_smoke__DOT__tbu_req_addr;
            vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_status_q 
                = ((1U & ((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__tbu_enable)) 
                          | (~ ((0U == (7U & (IData)(vlSelfRef.tb_memory_smoke__DOT__tbu_req_addr))) 
                                & ((0x1000ULL <= vlSelfRef.tb_memory_smoke__DOT__tbu_req_addr) 
                                   & (0x1ff8ULL >= vlSelfRef.tb_memory_smoke__DOT__tbu_req_addr))))))
                    ? 1U : (((IData)(vlSelfRef.tb_memory_smoke__DOT__tbu_req_write)
                              ? (IData)(vlSelfRef.tb_memory_smoke__DOT__tbu_allow_write)
                              : (IData)(vlSelfRef.tb_memory_smoke__DOT__tbu_allow_read))
                             ? 0U : 2U));
        }
        if (vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_handshake) {
            vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rr_client_q 
                = ((1U & (~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client))) 
                   && (1U & ((IData)(1U) + (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client))));
        }
    } else {
        __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q = 0U;
        vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_addr_q = 0ULL;
        vlSelfRef.tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_status_q = 0U;
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rr_client_q = 0U;
    }
    if (vlSelfRef.tb_memory_smoke__DOT__reset_n) {
        if ((4U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
                    if (vlSelfRef.tb_memory_smoke__DOT__mif_rsp_valid) {
                        __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 0U;
                    }
                } else if (((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_bvalid) 
                            & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_bready))) {
                    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q 
                        = ((0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_bid))
                            ? 5U : ([&]() {
                                __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response 
                                    = vlSelfRef.tb_memory_smoke__DOT__axi_bresp;
                                {
                                    if ((0U == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response))) {
                                        __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__Vfuncout = 0U;
                                        goto __Vlabel0;
                                    } else if ((2U 
                                                == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response))) {
                                        __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__Vfuncout = 3U;
                                        goto __Vlabel0;
                                    } else if ((3U 
                                                == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response))) {
                                        __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__Vfuncout = 4U;
                                        goto __Vlabel0;
                                    } else {
                                        __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__Vfuncout = 5U;
                                        goto __Vlabel0;
                                    }
                                    if (VL_UNLIKELY((
                                                     (1U 
                                                      & (~ 
                                                         VL_ONEHOT_I(
                                                                     (((3U 
                                                                        == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response)) 
                                                                       << 2U) 
                                                                      | (((2U 
                                                                           == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response)) 
                                                                          << 1U) 
                                                                         | (0U 
                                                                            == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response)))))))))) {
                                        if ((0U != 
                                             (((3U 
                                                == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response)) 
                                               << 2U) 
                                              | (((2U 
                                                   == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response)) 
                                                  << 1U) 
                                                 | (0U 
                                                    == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response)))))) {
                                            if (VL_UNLIKELY((
                                                             vlSymsp->_vm_contextp__->assertOn()))) {
                                                VL_WRITEF_NX("[%0t] %%Error: npu_axi_mif_master.sv:116: Assertion failed in %Ntb_memory_smoke.u_mif.axi_resp_status: unique case, but multiple matches found for '2'h%x'\n",0,
                                                             64,
                                                             VL_TIME_UNITED_Q(1),
                                                             -12,
                                                             vlSymsp->name(),
                                                             2,
                                                             (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__response));
                                                VL_STOP_MT("memory/npu_axi_mif_master.sv", 116, "");
                                            }
                                        }
                                    }
                                    __Vlabel0: ;
                                }
                            }(), (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__11__Vfuncout)));
                    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_rdata_q = 0ULL;
                    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
                if (vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__aw_handshake) {
                    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__aw_done_q = 1U;
                }
                if (vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__w_handshake) {
                    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__w_done_q = 1U;
                }
                if (vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__write_channels_done) {
                    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 6U;
                }
            } else if (((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_rvalid) 
                        & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_rready))) {
                vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_rdata_q 
                    = vlSelfRef.tb_memory_smoke__DOT__axi_rdata;
                __Vdly__tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q 
                    = ((1U & ((0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_rid)) 
                              | (~ (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_rlast))))
                        ? 5U : ([&]() {
                            __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response 
                                = vlSelfRef.tb_memory_smoke__DOT__axi_rresp;
                            {
                                if ((0U == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response))) {
                                    __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__Vfuncout = 0U;
                                    goto __Vlabel1;
                                } else if ((2U == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response))) {
                                    __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__Vfuncout = 3U;
                                    goto __Vlabel1;
                                } else if ((3U == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response))) {
                                    __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__Vfuncout = 4U;
                                    goto __Vlabel1;
                                } else {
                                    __Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__Vfuncout = 5U;
                                    goto __Vlabel1;
                                }
                                if (VL_UNLIKELY(((1U 
                                                  & (~ 
                                                     VL_ONEHOT_I(
                                                                 (((3U 
                                                                    == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response)) 
                                                                   << 2U) 
                                                                  | (((2U 
                                                                       == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response)) 
                                                                      << 1U) 
                                                                     | (0U 
                                                                        == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response)))))))))) {
                                    if ((0U != (((3U 
                                                  == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response)) 
                                                 << 2U) 
                                                | (((2U 
                                                     == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response)) 
                                                    << 1U) 
                                                   | (0U 
                                                      == (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response)))))) {
                                        if (VL_UNLIKELY((
                                                         vlSymsp->_vm_contextp__->assertOn()))) {
                                            VL_WRITEF_NX("[%0t] %%Error: npu_axi_mif_master.sv:116: Assertion failed in %Ntb_memory_smoke.u_mif.axi_resp_status: unique case, but multiple matches found for '2'h%x'\n",0,
                                                         64,
                                                         VL_TIME_UNITED_Q(1),
                                                         -12,
                                                         vlSymsp->name(),
                                                         2,
                                                         (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__response));
                                            VL_STOP_MT("memory/npu_axi_mif_master.sv", 116, "");
                                        }
                                    }
                                }
                                __Vlabel1: ;
                            }
                        }(), (IData)(__Vfunc_tb_memory_smoke__DOT__u_mif__DOT__axi_resp_status__12__Vfuncout)));
                __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 7U;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
                if (((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_arvalid) 
                     & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_arready))) {
                    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 4U;
                }
            } else if (((IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q) 
                        & (IData)(vlSelfRef.tb_memory_smoke__DOT__mif_tbu_rsp_ready))) {
                __Vdly__tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q 
                    = (0xffffffffffULL & vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_addr_q);
                if ((0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q))) {
                    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q 
                        = ((4U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q))
                            ? ((2U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q))
                                ? 5U : (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q))
                            : ((2U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q))
                                ? (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q)
                                : ((1U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q))
                                    ? (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q)
                                    : 5U)));
                    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 7U;
                } else if ((0ULL == (0xffffffffffffULL 
                                     & VL_SHIFTR_QQI(48,48,32, vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_addr_q, 0x28U)))) {
                    if (vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_write_q) {
                        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__aw_done_q = 0U;
                        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__w_done_q = 0U;
                        __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 5U;
                    } else {
                        __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 3U;
                    }
                } else {
                    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q = 1U;
                    __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 7U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) {
            if (((IData)(vlSelfRef.tb_memory_smoke__DOT__mif_tbu_req_valid) 
                 & (IData)(vlSelfRef.tb_memory_smoke__DOT__mif_tbu_req_ready))) {
                __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 2U;
            }
        } else if (((IData)(vlSelfRef.tb_memory_smoke__DOT__mif_req_valid) 
                    & (IData)(vlSelfRef.tb_memory_smoke__DOT__mif_req_ready))) {
            vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_write_q 
                = vlSelfRef.tb_memory_smoke__DOT__mif_req_write;
            __Vdly__tb_memory_smoke__DOT__u_mif__DOT__req_addr_q 
                = vlSelfRef.tb_memory_smoke__DOT__mif_req_addr;
            vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_wdata_q 
                = vlSelfRef.tb_memory_smoke__DOT__mif_req_wdata;
            vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_wstrb_q 
                = vlSelfRef.tb_memory_smoke__DOT__mif_req_wstrb;
            vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__stream_id_q = 0x33U;
            vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__substream_id_q = 0x44U;
            vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_rdata_q = 0ULL;
            if ((0U != (7U & (IData)(vlSelfRef.tb_memory_smoke__DOT__mif_req_addr)))) {
                __Vdly__tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q = 1U;
                __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 7U;
            } else {
                __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 1U;
            }
        }
        if ((((7U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q)) 
              & (0U != (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q))) 
             & (~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__error_valid_q)))) {
            vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__error_valid_q = 1U;
            vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__error_addr_q 
                = vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_addr_q;
            vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__error_status_q 
                = vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q;
        }
    } else {
        __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q = 0U;
        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_write_q = 0U;
        __Vdly__tb_memory_smoke__DOT__u_mif__DOT__req_addr_q = 0ULL;
        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_wdata_q = 0ULL;
        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_wstrb_q = 0U;
        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__stream_id_q = 0U;
        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__substream_id_q = 0U;
        __Vdly__tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q = 0ULL;
        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__aw_done_q = 0U;
        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__w_done_q = 0U;
        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_rdata_q = 0ULL;
        __Vdly__tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q = 0U;
        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__error_valid_q = 0U;
        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__error_addr_q = 0ULL;
        vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__error_status_q = 0U;
    }
    vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q 
        = __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q;
    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q 
        = __Vdly__tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q;
    vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q 
        = __Vdly__tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q;
    if (vlSelfRef.tb_memory_smoke__DOT__reset_n) {
        if (((1U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_memory_smoke__DOT__mif_tbu_req_ready))) {
            vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_addr_q 
                = vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_addr_q;
        }
    } else {
        vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_addr_q = 0ULL;
    }
    if (vlSelfRef.tb_memory_smoke__DOT__reset_n) {
        if (((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_awvalid) 
             & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_awready))) {
            if (VL_UNLIKELY(((0x1008ULL != vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q)))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:260: Assertion failed in %Ntb_memory_smoke: MIF AXI write-address fields are incorrect\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("memory/tb_memory_smoke.sv", 260, "", false);
            }
            __Vdly__tb_memory_smoke__DOT__aw_seen_q = 1U;
        }
        if (((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_wvalid) 
             & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_wready))) {
            __Vdly__tb_memory_smoke__DOT__w_seen_q = 1U;
        }
        if ((((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_bvalid)) 
              & ((IData)(vlSelfRef.tb_memory_smoke__DOT__aw_seen_q) 
                 | ((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_awvalid) 
                    & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_awready)))) 
             & ((IData)(vlSelfRef.tb_memory_smoke__DOT__w_seen_q) 
                | ((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_wvalid) 
                   & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_wready))))) {
            __Vdly__tb_memory_smoke__DOT__axi_bvalid = 1U;
            vlSelfRef.tb_memory_smoke__DOT__axi_bid = 0U;
            vlSelfRef.tb_memory_smoke__DOT__axi_bresp = 0U;
        } else if (((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_bvalid) 
                    & (6U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q)))) {
            vlSelfRef.tb_memory_smoke__DOT__write_count 
                = ((IData)(1U) + vlSelfRef.tb_memory_smoke__DOT__write_count);
            __Vdly__tb_memory_smoke__DOT__axi_bvalid = 0U;
            __Vdly__tb_memory_smoke__DOT__aw_seen_q = 0U;
            __Vdly__tb_memory_smoke__DOT__w_seen_q = 0U;
        }
        if ((((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_rvalid)) 
              & (3U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))) 
             & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_arready))) {
            if (VL_UNLIKELY(((1U & (~ ((0x1000ULL == vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q) 
                                       | (0x1010ULL 
                                          == vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q))))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_memory_smoke.sv:290: Assertion failed in %Ntb_memory_smoke: MIF AXI read-address fields are incorrect\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("memory/tb_memory_smoke.sv", 290, "", false);
            }
            __Vdly__tb_memory_smoke__DOT__axi_rvalid = 1U;
            vlSelfRef.tb_memory_smoke__DOT__axi_rid = 0U;
            vlSelfRef.tb_memory_smoke__DOT__axi_rdata 
                = (0xcafef00d12345678ULL ^ vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q);
            vlSelfRef.tb_memory_smoke__DOT__axi_rresp 
                = vlSelfRef.tb_memory_smoke__DOT__next_read_response;
            vlSelfRef.tb_memory_smoke__DOT__axi_rlast = 1U;
        } else if (((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_rvalid) 
                    & (4U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q)))) {
            vlSelfRef.tb_memory_smoke__DOT__read_count 
                = ((IData)(1U) + vlSelfRef.tb_memory_smoke__DOT__read_count);
            __Vdly__tb_memory_smoke__DOT__axi_rvalid = 0U;
        }
    } else {
        __Vdly__tb_memory_smoke__DOT__aw_seen_q = 0U;
        __Vdly__tb_memory_smoke__DOT__w_seen_q = 0U;
        vlSelfRef.tb_memory_smoke__DOT__read_count = 0U;
        vlSelfRef.tb_memory_smoke__DOT__write_count = 0U;
        vlSelfRef.tb_memory_smoke__DOT__axi_awready = 1U;
        vlSelfRef.tb_memory_smoke__DOT__axi_wready = 1U;
        __Vdly__tb_memory_smoke__DOT__axi_bvalid = 0U;
        vlSelfRef.tb_memory_smoke__DOT__axi_bid = 0U;
        vlSelfRef.tb_memory_smoke__DOT__axi_bresp = 0U;
        vlSelfRef.tb_memory_smoke__DOT__axi_arready = 1U;
        __Vdly__tb_memory_smoke__DOT__axi_rvalid = 0U;
        vlSelfRef.tb_memory_smoke__DOT__axi_rid = 0U;
        vlSelfRef.tb_memory_smoke__DOT__axi_rdata = 0xcafef00d12345678ULL;
        vlSelfRef.tb_memory_smoke__DOT__axi_rresp = 0U;
        vlSelfRef.tb_memory_smoke__DOT__axi_rlast = 1U;
    }
    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__req_addr_q 
        = __Vdly__tb_memory_smoke__DOT__u_mif__DOT__req_addr_q;
    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q 
        = __Vdly__tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q;
    vlSelfRef.tb_memory_smoke__DOT__aw_seen_q = __Vdly__tb_memory_smoke__DOT__aw_seen_q;
    vlSelfRef.tb_memory_smoke__DOT__w_seen_q = __Vdly__tb_memory_smoke__DOT__w_seen_q;
    vlSelfRef.tb_memory_smoke__DOT__axi_bvalid = __Vdly__tb_memory_smoke__DOT__axi_bvalid;
    vlSelfRef.tb_memory_smoke__DOT__axi_rvalid = __Vdly__tb_memory_smoke__DOT__axi_rvalid;
    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q 
        = __Vdly__tb_memory_smoke__DOT__u_mif__DOT__state_q;
    vlSelfRef.tb_memory_smoke__DOT__mif_tbu_rsp_ready 
        = (2U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q));
    vlSelfRef.tb_memory_smoke__DOT__mif_req_ready = 
        (0U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q));
    vlSelfRef.tb_memory_smoke__DOT__mif_rsp_valid = 
        (7U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q));
    vlSelfRef.tb_memory_smoke__DOT__mif_tbu_req_valid 
        = (1U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q));
    vlSelfRef.tb_memory_smoke__DOT__axi_bready = (6U 
                                                  == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q));
    vlSelfRef.tb_memory_smoke__DOT__axi_arvalid = (3U 
                                                   == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q));
    vlSelfRef.tb_memory_smoke__DOT__axi_rready = (4U 
                                                  == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q));
    vlSelfRef.tb_memory_smoke__DOT__mif_tbu_req_ready 
        = (1U & ((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q)) 
                 | (2U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q))));
    vlSelfRef.tb_memory_smoke__DOT__axi_awvalid = (
                                                   (~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__aw_done_q)) 
                                                   & (5U 
                                                      == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q)));
    vlSelfRef.tb_memory_smoke__DOT__axi_wvalid = ((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__w_done_q)) 
                                                  & (5U 
                                                     == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q)));
    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__aw_handshake 
        = ((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_awvalid) 
           & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_awready));
    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__w_handshake 
        = ((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_wvalid) 
           & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_wready));
    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__write_channels_done 
        = (((IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__aw_done_q) 
            | (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__aw_handshake)) 
           & ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__w_done_q) 
              | (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__w_handshake)));
}
