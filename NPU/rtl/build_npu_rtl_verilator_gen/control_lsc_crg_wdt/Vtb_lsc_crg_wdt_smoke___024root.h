// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_lsc_crg_wdt_smoke.h for the primary calling header

#ifndef VERILATED_VTB_LSC_CRG_WDT_SMOKE___024ROOT_H_
#define VERILATED_VTB_LSC_CRG_WDT_SMOKE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_lsc_crg_wdt_smoke__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_lsc_crg_wdt_smoke___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__clk;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__noc_clk;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__reset_n;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__sync_reset_n;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__reg_req_valid;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__reg_req_ready;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__reg_req_write;
        CData/*7:0*/ tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__single_step_pulse;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__soft_reset_req;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_done;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__task_terminal_valid;
        CData/*3:0*/ tb_lsc_crg_wdt_smoke__DOT__task_engine;
        CData/*7:0*/ tb_lsc_crg_wdt_smoke__DOT__task_opcode;
        CData/*7:0*/ tb_lsc_crg_wdt_smoke__DOT__task_status;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__interface_error_clear;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__lsc_wdt_kick;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__wdt_enable;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__wdt_kick;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__wdt_progress;
        CData/*7:0*/ tb_lsc_crg_wdt_smoke__DOT__module_clk_en;
        CData/*7:0*/ tb_lsc_crg_wdt_smoke__DOT__module_idle;
        CData/*7:0*/ tb_lsc_crg_wdt_smoke__DOT__module_clk_active;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__core_clk_gated;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__noc_clk_gated;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q;
        CData/*1:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__start_q;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q;
        CData/*2:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q;
        CData/*2:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_mask_q;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q;
        CData/*3:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_engine_q;
        CData/*7:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_opcode_q;
        CData/*7:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_status_q;
        CData/*2:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_reason_q;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_lock_q;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__l1_host_access_enable_q;
        CData/*7:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__module_clk_enable_q;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_enable_q;
        CData/*1:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_requested;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q;
        CData/*1:0*/ tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q;
        CData/*1:0*/ tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_gate_enable_q;
        CData/*0:0*/ tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_gate_enable_q;
        CData/*1:0*/ __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q;
        CData/*1:0*/ __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__reset_n__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__noc_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse__0;
        CData/*0:0*/ __Vtrigprevexpr_hf82c736a__1;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ tb_lsc_crg_wdt_smoke__DOT__reg_req_addr;
        SData/*11:0*/ tb_lsc_crg_wdt_smoke__DOT__task_command_id;
        SData/*11:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_command_id_q;
        SData/*15:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_stream_id_q;
    };
    struct {
        SData/*15:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_substream_id_q;
        IData/*31:0*/ tb_lsc_crg_wdt_smoke__DOT__wdt_timeout_cycles;
        IData/*19:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_base_q;
        IData/*19:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q;
        IData/*31:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_timeout_cycles_q;
        IData/*31:0*/ tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata;
        QData/*47:0*/ tb_lsc_crg_wdt_smoke__DOT__task_fault_addr;
        QData/*63:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_data_q;
        QData/*47:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_addr_q;
        QData/*47:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__input_base_q;
        QData/*47:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__weight_base_q;
        QData/*47:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__work_base_q;
        QData/*47:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__output_base_q;
        QData/*47:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__kv_base_q;
        QData/*47:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_base_q;
        QData/*47:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q;
        QData/*63:0*/ tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_read_data;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hf0804800__0;
    VlTriggerScheduler __VtrigSched_hf08046bd__0;
    VlTriggerScheduler __VtrigSched_h77370d68__0;
    VlTriggerScheduler __VtrigSched_h4baaed7e__0;
    VlTriggerScheduler __VtrigSched_h701bf8e5__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<9> __VactTriggered;
    VlTriggerVec<9> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_lsc_crg_wdt_smoke__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_lsc_crg_wdt_smoke___024root(Vtb_lsc_crg_wdt_smoke__Syms* symsp, const char* v__name);
    ~Vtb_lsc_crg_wdt_smoke___024root();
    VL_UNCOPYABLE(Vtb_lsc_crg_wdt_smoke___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
