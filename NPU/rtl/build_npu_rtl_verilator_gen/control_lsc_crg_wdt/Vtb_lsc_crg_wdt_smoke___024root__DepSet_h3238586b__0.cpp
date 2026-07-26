// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_lsc_crg_wdt_smoke.h for the primary calling header

#include "Vtb_lsc_crg_wdt_smoke__pch.h"
#include "Vtb_lsc_crg_wdt_smoke__Syms.h"
#include "Vtb_lsc_crg_wdt_smoke___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__0(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__dvfs_req;
    tb_lsc_crg_wdt_smoke__DOT__dvfs_req = 0;
    QData/*63:0*/ tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data;
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data = 0;
    CData/*1:0*/ tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status;
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status = 0;
    CData/*0:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__write_access;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__write_access = 0;
    SData/*15:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__address;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__address = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__write_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__write_data = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__read_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__read_data = 0;
    CData/*1:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__response_status;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__response_status = 0;
    CData/*0:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__write_access;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__write_access = 0;
    SData/*15:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__address;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__address = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__write_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__write_data = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__read_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__read_data = 0;
    CData/*1:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__response_status;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__response_status = 0;
    CData/*0:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__write_access;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__write_access = 0;
    SData/*15:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__address;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__address = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__write_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__write_data = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__read_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__read_data = 0;
    CData/*1:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__response_status;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__response_status = 0;
    CData/*0:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__write_access;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__write_access = 0;
    SData/*15:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__address;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__address = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__write_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__write_data = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__read_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__read_data = 0;
    CData/*1:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__response_status;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__response_status = 0;
    CData/*0:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__write_access;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__write_access = 0;
    SData/*15:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__address;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__address = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__write_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__write_data = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__read_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__read_data = 0;
    CData/*1:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__response_status;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__response_status = 0;
    CData/*0:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__write_access;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__write_access = 0;
    SData/*15:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__address;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__address = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__write_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__write_data = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__read_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__read_data = 0;
    CData/*1:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__response_status;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__response_status = 0;
    CData/*0:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__write_access;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__write_access = 0;
    SData/*15:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__address;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__address = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__write_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__write_data = 0;
    QData/*63:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__read_data;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__read_data = 0;
    CData/*1:0*/ __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__response_status;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__response_status = 0;
    // Body
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__clk = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reset_n = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__sync_reset_n = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata = 0ULL;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__soft_reset_req = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_done = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_terminal_valid = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_command_id = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_engine = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_opcode = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_status = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_fault_addr = 0ULL;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_enable = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_timeout_cycles = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_kick = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_progress = 0U;
    tb_lsc_crg_wdt_smoke__DOT__dvfs_req = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__module_clk_en = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__module_idle = 0xffU;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         240);
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         240);
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         240);
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         240);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reset_n = 1U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__sync_reset_n = 1U;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         243);
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         243);
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         243);
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         243);
    if (VL_UNLIKELY(((1U & (((~ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q) 
                                 >> 1U)) | (~ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q) 
                                               >> 1U))) 
                            | (0U != (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__module_clk_active))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:247: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: CRG reset release or idle clock selection failed\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 247, "", false);
    }
    tb_lsc_crg_wdt_smoke__DOT__dvfs_req = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                         250);
    if (VL_UNLIKELY(((1U & (~ (IData)(tb_lsc_crg_wdt_smoke__DOT__dvfs_req)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:252: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: CRG did not acknowledge an idle DVFS request\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 252, "", false);
    }
    tb_lsc_crg_wdt_smoke__DOT__dvfs_req = 0U;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__write_data = 0x1000ULL;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__address = 0x58U;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__write_access = 1U;
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         190);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__write_access;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__address;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__write_data;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb = 0xffU;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 1U;
    while (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q) {
        co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             196);
    }
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         197);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         198);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata = 0ULL;
    while ((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h77370d68__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_lsc_crg_wdt_smoke.u_lsc.rsp_valid_q)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             203);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__read_data 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_data_q;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__response_status 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         206);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         207);
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__read_data;
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__0__response_status;
    if (VL_UNLIKELY((((0U != (IData)(tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status)) 
                      | (0x1000ULL != vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__input_base_q))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:259: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: LSC input base write failed\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 259, "", false);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__write_data = 0ULL;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__address = 0x58U;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__write_access = 0U;
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         190);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__write_access;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__address;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__write_data;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb = 0xffU;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 1U;
    while (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q) {
        co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             196);
    }
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         197);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         198);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata = 0ULL;
    while ((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h77370d68__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_lsc_crg_wdt_smoke.u_lsc.rsp_valid_q)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             203);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__read_data 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_data_q;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__response_status 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         206);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         207);
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__read_data;
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__1__response_status;
    if (VL_UNLIKELY((((0U != (IData)(tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status)) 
                      | (0x1000ULL != tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:264: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: LSC input base readback failed\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 264, "", false);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__write_data = 1ULL;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__address = 0x40U;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__write_access = 1U;
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         190);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__write_access;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__address;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__write_data;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb = 0xffU;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 1U;
    while (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q) {
        co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             196);
    }
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         197);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         198);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata = 0ULL;
    while ((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h77370d68__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_lsc_crg_wdt_smoke.u_lsc.rsp_valid_q)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             203);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__read_data 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_data_q;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__response_status 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         206);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         207);
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__read_data;
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__2__response_status;
    if (VL_UNLIKELY(((1U & ((0U != (IData)(tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status)) 
                            | (~ ((~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q)) 
                                  & ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__start_q) 
                                     & (0U == (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q)))))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:269: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: LSC start control failed\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 269, "", false);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__write_data = 0ULL;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__address = 0xa8U;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__write_access = 1U;
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         190);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__write_access;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__address;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__write_data;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb = 0xffU;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 1U;
    while (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q) {
        co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             196);
    }
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         197);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         198);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata = 0ULL;
    while ((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h77370d68__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_lsc_crg_wdt_smoke.u_lsc.rsp_valid_q)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             203);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__read_data 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_data_q;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__response_status 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         206);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         207);
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__read_data;
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__3__response_status;
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         273);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_command_id = 0x33U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_engine = 2U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_opcode = 0x40U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_status = 2U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_fault_addr = 0x4440ULL;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_terminal_valid = 1U;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         280);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         281);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_terminal_valid = 0U;
    if (VL_UNLIKELY(((1U & (~ ((~ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_mask_q) 
                                   >> 2U)) & ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q) 
                                              >> 2U))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:284: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: LSC did not raise an unmasked task-error interrupt\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 284, "", false);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__write_data = 0ULL;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__address = 0xb0U;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__write_access = 0U;
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         190);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__write_access;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__address;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__write_data;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb = 0xffU;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 1U;
    while (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q) {
        co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             196);
    }
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         197);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         198);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata = 0ULL;
    while ((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h77370d68__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_lsc_crg_wdt_smoke.u_lsc.rsp_valid_q)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             203);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__read_data 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_data_q;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__response_status 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         206);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         207);
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__read_data;
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__4__response_status;
    if (VL_UNLIKELY(((0x33U != (0xfffU & (IData)(tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:289: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: LSC first-fault command ID mismatch\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 289, "", false);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__write_data = 0ULL;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__address = 0xb8U;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__write_access = 0U;
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         190);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__write_access;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__address;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__write_data;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb = 0xffU;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 1U;
    while (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q) {
        co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             196);
    }
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         197);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         198);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata = 0ULL;
    while ((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h77370d68__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_lsc_crg_wdt_smoke.u_lsc.rsp_valid_q)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             203);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__read_data 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_data_q;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__response_status 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         206);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         207);
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__read_data;
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__5__response_status;
    if (VL_UNLIKELY(((0x4440ULL != (0xffffffffffffULL 
                                    & tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:293: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: LSC first-fault address mismatch\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 293, "", false);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__write_data = 0ULL;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__address = 0xc0U;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__write_access = 0U;
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         190);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__write_access;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__address;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__write_data;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb = 0xffU;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 1U;
    while (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q) {
        co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             196);
    }
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         197);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         198);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr = 0U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata = 0ULL;
    while ((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q)))) {
        co_await vlSelfRef.__VtrigSched_h77370d68__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_lsc_crg_wdt_smoke.u_lsc.rsp_valid_q)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             203);
    }
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__read_data 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_data_q;
    __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__response_status 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         206);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         207);
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__read_data;
    tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__response_status 
        = __Vtask_tb_lsc_crg_wdt_smoke__DOT__csr_access__6__response_status;
    if (VL_UNLIKELY(((IData)((0x40202ULL != (0xfffffULL 
                                             & tb_lsc_crg_wdt_smoke__DOT__unnamedblk1__DOT__read_data)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:299: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: LSC first-fault metadata mismatch\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 299, "", false);
    }
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_timeout_cycles = 3U;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_enable = 1U;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         304);
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         304);
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         304);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                         305);
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:307: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: WDT did not assert after three idle cycles\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 307, "", false);
    }
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         309);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_progress = 1U;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         311);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         312);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_progress = 0U;
    if (VL_UNLIKELY((vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:315: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: WDT progress did not clear the timeout\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 315, "", false);
    }
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__soft_reset_req = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse)))) {
        co_await vlSelfRef.__VtrigSched_h4baaed7e__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_lsc_crg_wdt_smoke.internal_soft_reset_pulse)", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             319);
    }
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         320);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_done = 1U;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         322);
    co_await vlSelfRef.__VtrigSched_hf08046bd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         323);
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_done = 0U;
    while ((3U != (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q))) {
        co_await vlSelfRef.__VtrigSched_h701bf8e5__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (2'h3 == tb_lsc_crg_wdt_smoke.u_lsc.reset_state_q))", 
                                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                                             325);
    }
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__soft_reset_req = 0U;
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         327);
    co_await vlSelfRef.__VtrigSched_hf0804800__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lsc_crg_wdt_smoke.clk)", 
                                                         "control/tb_lsc_crg_wdt_smoke.sv", 
                                                         327);
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q)) 
                      & ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__start_q) 
                         & (0U == (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q))))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:329: Assertion failed in %Ntb_lsc_crg_wdt_smoke.unnamedblk1: controlled reset did not return LSC to stopped state\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 329, "", false);
    }
    VL_WRITEF_NX("PASS: LSC registers/fault/reset, CRG and WDT signature=%0b\n",0,
                 1,(1U & ((VL_REDXOR_32((0xfU & (- (IData)(
                                                           (1U 
                                                            == (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q)))))) 
                           ^ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__single_step_pulse) 
                              ^ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__interface_error_clear) 
                                 ^ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_enable_q) 
                                    ^ (VL_REDXOR_32(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_timeout_cycles_q) 
                                       ^ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__lsc_wdt_kick) 
                                          ^ (((~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_mask_q)) 
                                              & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q)) 
                                             ^ (((~ 
                                                  ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_mask_q) 
                                                   >> 1U)) 
                                                 & ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q) 
                                                    >> 1U)) 
                                                ^ (
                                                   ((((VL_REDXOR_64(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__weight_base_q) 
                                                       ^ 
                                                       VL_REDXOR_64(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__work_base_q)) 
                                                      ^ 
                                                      (VL_REDXOR_64(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__output_base_q) 
                                                       ^ 
                                                       VL_REDXOR_64(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__kv_base_q))) 
                                                     ^ 
                                                     (VL_REDXOR_64(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_base_q) 
                                                      ^ 
                                                      VL_REDXOR_64(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q))) 
                                                    ^ 
                                                    (VL_REDXOR_16(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_stream_id_q) 
                                                     ^ 
                                                     VL_REDXOR_16(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_substream_id_q))) 
                                                   ^ 
                                                   (VL_REDXOR_32(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_base_q) 
                                                    ^ 
                                                    (VL_REDXOR_32(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q) 
                                                     ^ 
                                                     ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_lock_q) 
                                                      ^ 
                                                      ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__l1_host_access_enable_q) 
                                                       ^ 
                                                       VL_REDXOR_8(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__module_clk_enable_q)))))))))))))) 
                          ^ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q) 
                             ^ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__core_clk_gated) 
                                ^ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk_gated))))));
    VL_FINISH_MT("control/tb_lsc_crg_wdt_smoke.sv", 348, "");
}

VL_INLINE_OPT VlCoroutine Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__1(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x186a0ULL, 
                                         nullptr, "control/tb_lsc_crg_wdt_smoke.sv", 
                                         352);
    VL_WRITEF_NX("[%0t] %%Fatal: tb_lsc_crg_wdt_smoke.sv:353: Assertion failed in %Ntb_lsc_crg_wdt_smoke: LSC/CRG/WDT smoke test timeout\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
    VL_STOP_MT("control/tb_lsc_crg_wdt_smoke.sv", 353, "", false);
}

VL_INLINE_OPT VlCoroutine Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__2(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(7ULL, 
                                             nullptr, 
                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                             79);
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk 
            = (1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__3(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__3\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "control/tb_lsc_crg_wdt_smoke.sv", 
                                             78);
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__clk = 
            (1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__act(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_lsc_crg_wdt_smoke___024root___eval_triggers__act(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_triggers__act\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vtrigprevexpr_hf82c736a__0;
    __Vtrigprevexpr_hf82c736a__0 = 0;
    // Body
    __Vtrigprevexpr_hf82c736a__0 = (3U == (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q));
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reset_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__reset_n__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__noc_clk__0))));
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__clk__0)));
    vlSelfRef.__VactTriggered.setBit(4U, ((~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__noc_clk__0)));
    vlSelfRef.__VactTriggered.setBit(5U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(6U, ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q__0)));
    vlSelfRef.__VactTriggered.setBit(7U, ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse__0)));
    vlSelfRef.__VactTriggered.setBit(8U, ((IData)(__Vtrigprevexpr_hf82c736a__0) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr_hf82c736a__1)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__clk__0 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__reset_n__0 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reset_n;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__noc_clk__0 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q__0 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse__0 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse;
    vlSelfRef.__Vtrigprevexpr_hf82c736a__1 = __Vtrigprevexpr_hf82c736a__0;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(6U, 1U);
        vlSelfRef.__VactTriggered.setBit(7U, 1U);
        vlSelfRef.__VactTriggered.setBit(8U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__act(vlSelf);
    }
#endif
}
