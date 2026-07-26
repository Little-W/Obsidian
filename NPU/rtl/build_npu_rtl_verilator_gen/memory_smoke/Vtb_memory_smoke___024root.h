// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_memory_smoke.h for the primary calling header

#ifndef VERILATED_VTB_MEMORY_SMOKE___024ROOT_H_
#define VERILATED_VTB_MEMORY_SMOKE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_memory_smoke__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_memory_smoke___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_memory_smoke__DOT__clk;
        CData/*0:0*/ tb_memory_smoke__DOT__reset_n;
        CData/*1:0*/ tb_memory_smoke__DOT__l1_req_valid;
        CData/*1:0*/ tb_memory_smoke__DOT__l1_req_ready;
        CData/*1:0*/ tb_memory_smoke__DOT__l1_req_write;
        CData/*1:0*/ tb_memory_smoke__DOT__l1_rsp_ready;
        CData/*0:0*/ tb_memory_smoke__DOT__tbu_enable;
        CData/*0:0*/ tb_memory_smoke__DOT__tbu_allow_read;
        CData/*0:0*/ tb_memory_smoke__DOT__tbu_allow_write;
        CData/*0:0*/ tb_memory_smoke__DOT__tbu_req_valid;
        CData/*0:0*/ tb_memory_smoke__DOT__tbu_req_write;
        CData/*0:0*/ tb_memory_smoke__DOT__mif_req_valid;
        CData/*0:0*/ tb_memory_smoke__DOT__mif_req_ready;
        CData/*0:0*/ tb_memory_smoke__DOT__mif_req_write;
        CData/*7:0*/ tb_memory_smoke__DOT__mif_req_wstrb;
        CData/*0:0*/ tb_memory_smoke__DOT__mif_rsp_valid;
        CData/*0:0*/ tb_memory_smoke__DOT__mif_tbu_req_valid;
        CData/*0:0*/ tb_memory_smoke__DOT__mif_tbu_req_ready;
        CData/*0:0*/ tb_memory_smoke__DOT__mif_tbu_rsp_ready;
        CData/*0:0*/ tb_memory_smoke__DOT__axi_awvalid;
        CData/*0:0*/ tb_memory_smoke__DOT__axi_awready;
        CData/*0:0*/ tb_memory_smoke__DOT__axi_wvalid;
        CData/*0:0*/ tb_memory_smoke__DOT__axi_wready;
        CData/*7:0*/ tb_memory_smoke__DOT__axi_bid;
        CData/*1:0*/ tb_memory_smoke__DOT__axi_bresp;
        CData/*0:0*/ tb_memory_smoke__DOT__axi_bvalid;
        CData/*0:0*/ tb_memory_smoke__DOT__axi_bready;
        CData/*0:0*/ tb_memory_smoke__DOT__axi_arvalid;
        CData/*0:0*/ tb_memory_smoke__DOT__axi_arready;
        CData/*7:0*/ tb_memory_smoke__DOT__axi_rid;
        CData/*1:0*/ tb_memory_smoke__DOT__axi_rresp;
        CData/*0:0*/ tb_memory_smoke__DOT__axi_rlast;
        CData/*0:0*/ tb_memory_smoke__DOT__axi_rvalid;
        CData/*0:0*/ tb_memory_smoke__DOT__axi_rready;
        CData/*0:0*/ tb_memory_smoke__DOT__aw_seen_q;
        CData/*0:0*/ tb_memory_smoke__DOT__w_seen_q;
        CData/*1:0*/ tb_memory_smoke__DOT__next_read_response;
        CData/*1:0*/ tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q;
        CData/*0:0*/ tb_memory_smoke__DOT__u_l1__DOT__rr_client_q;
        CData/*0:0*/ tb_memory_smoke__DOT__u_l1__DOT__grant_client;
        CData/*0:0*/ tb_memory_smoke__DOT__u_l1__DOT__grant_handshake;
        CData/*0:0*/ tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q;
        CData/*2:0*/ tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_status_q;
        CData/*0:0*/ tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q;
        CData/*2:0*/ tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q;
        CData/*2:0*/ tb_memory_smoke__DOT__u_mif__DOT__state_q;
        CData/*0:0*/ tb_memory_smoke__DOT__u_mif__DOT__req_write_q;
        CData/*7:0*/ tb_memory_smoke__DOT__u_mif__DOT__req_wstrb_q;
        CData/*0:0*/ tb_memory_smoke__DOT__u_mif__DOT__aw_done_q;
        CData/*0:0*/ tb_memory_smoke__DOT__u_mif__DOT__w_done_q;
        CData/*2:0*/ tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q;
        CData/*0:0*/ tb_memory_smoke__DOT__u_mif__DOT__error_valid_q;
        CData/*2:0*/ tb_memory_smoke__DOT__u_mif__DOT__error_status_q;
        CData/*0:0*/ tb_memory_smoke__DOT__u_mif__DOT__aw_handshake;
        CData/*0:0*/ tb_memory_smoke__DOT__u_mif__DOT__w_handshake;
        CData/*0:0*/ tb_memory_smoke__DOT__u_mif__DOT__write_channels_done;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_memory_smoke__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_memory_smoke__DOT__reset_n__0;
        CData/*0:0*/ __Vtrigprevexpr_h81419cab__0;
        CData/*0:0*/ __Vtrigprevexpr_h5a2c0699__0;
        CData/*0:0*/ __Vtrigprevexpr_ha9345098__0;
        CData/*0:0*/ __Vtrigprevexpr_h521fd0b8__0;
        CData/*0:0*/ __Vtrigprevexpr_had9ebf87__0;
    };
    struct {
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q__0;
        CData/*0:0*/ __Vtrigprevexpr_h60c90f32__1;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ tb_memory_smoke__DOT__l1_req_wstrb;
        SData/*15:0*/ tb_memory_smoke__DOT__u_mif__DOT__stream_id_q;
        SData/*15:0*/ tb_memory_smoke__DOT__u_mif__DOT__substream_id_q;
        VlWide<4>/*127:0*/ tb_memory_smoke__DOT__l1_req_wdata;
        IData/*31:0*/ tb_memory_smoke__DOT__read_count;
        IData/*31:0*/ tb_memory_smoke__DOT__write_count;
        IData/*19:0*/ tb_memory_smoke__DOT__u_l1__DOT__grant_addr;
        IData/*31:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__0__client;
        IData/*31:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__1__client;
        IData/*31:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__2__client;
        IData/*31:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__3__client;
        IData/*31:0*/ __Vtask_tb_memory_smoke__DOT__l1_access__4__client;
        IData/*31:0*/ __VactIterCount;
        QData/*39:0*/ tb_memory_smoke__DOT__l1_req_addr;
        QData/*47:0*/ tb_memory_smoke__DOT__tbu_req_addr;
        QData/*47:0*/ tb_memory_smoke__DOT__mif_req_addr;
        QData/*63:0*/ tb_memory_smoke__DOT__mif_req_wdata;
        QData/*63:0*/ tb_memory_smoke__DOT__axi_rdata;
        QData/*47:0*/ tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_addr_q;
        QData/*47:0*/ tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_addr_q;
        QData/*47:0*/ tb_memory_smoke__DOT__u_mif__DOT__req_addr_q;
        QData/*63:0*/ tb_memory_smoke__DOT__u_mif__DOT__req_wdata_q;
        QData/*39:0*/ tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q;
        QData/*63:0*/ tb_memory_smoke__DOT__u_mif__DOT__rsp_rdata_q;
        QData/*47:0*/ tb_memory_smoke__DOT__u_mif__DOT__error_addr_q;
        VlUnpacked<VlUnpacked<QData/*63:0*/, 8>, 4> tb_memory_smoke__DOT__u_l1__DOT__sram_q;
        VlUnpacked<QData/*63:0*/, 2> tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q;
        VlUnpacked<CData/*2:0*/, 2> tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hf85b3a82__0;
    VlTriggerScheduler __VtrigSched_hf85b3b43__0;
    VlTriggerScheduler __VtrigSched_he4f62226__0;
    VlTriggerScheduler __VtrigSched_hce1b93bc__0;
    VlTriggerScheduler __VtrigSched_hfd03ddbb__0;
    VlTriggerScheduler __VtrigSched_hd6285ddb__0;
    VlTriggerScheduler __VtrigSched_h39a94caa__0;
    VlTriggerScheduler __VtrigSched_h367e0241__0;
    VlTriggerScheduler __VtrigSched_hc47e9d4d__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<11> __VactTriggered;
    VlTriggerVec<11> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_memory_smoke__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_memory_smoke___024root(Vtb_memory_smoke__Syms* symsp, const char* v__name);
    ~Vtb_memory_smoke___024root();
    VL_UNCOPYABLE(Vtb_memory_smoke___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
