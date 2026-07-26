// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_cmd_dfu_smoke.h for the primary calling header

#ifndef VERILATED_VTB_CMD_DFU_SMOKE___024ROOT_H_
#define VERILATED_VTB_CMD_DFU_SMOKE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_cmd_dfu_smoke__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_cmd_dfu_smoke___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__clk;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__reset_n;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__cmd_valid;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__cmd_first;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__cmd_last;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__cmd_rsp_valid;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__ts_cmd_ready;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__lookup_valid;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__lookup_ready;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__lookup_rsp_valid;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__lookup_busy;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__lookup_pending_q;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__cfe_error;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__cmd_accepted;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__fetch_valid;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__fetch_ready;
        CData/*3:0*/ tb_cmd_dfu_smoke__DOT__fetch_engine;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__fetch_crc;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__fetch_rsp_valid;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__mem_req_ready;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__mem_rsp_valid;
        CData/*2:0*/ tb_cmd_dfu_smoke__DOT__mem_rsp_status;
        CData/*2:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q;
        CData/*7:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q;
        CData/*4:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__wait_high_count_q;
        CData/*7:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q;
        CData/*2:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q;
        CData/*2:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q;
        CData/*3:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__header_format_valid;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__opcode_format_valid;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__input_handshake;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now;
        CData/*2:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q;
        CData/*3:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__engine_q;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__crc_enable_q;
        CData/*5:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q;
        CData/*5:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q;
        CData/*7:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__abort_pending_q;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__prefix_valid;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__mem_request_handshake;
        CData/*0:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__mem_response_handshake;
        CData/*0:0*/ __Vfunc_npu_event_ref_valid__25__Vfuncout;
        CData/*0:0*/ __Vfunc_npu_event_ref_valid__26__Vfuncout;
        CData/*0:0*/ __Vfunc_npu_event_ref_valid__27__Vfuncout;
        CData/*0:0*/ __Vfunc_npu_opcode_engine_valid__28__Vfuncout;
        CData/*3:0*/ __Vfunc_npu_opcode_engine_valid__28__engine;
        CData/*7:0*/ __Vfunc_npu_opcode_engine_valid__28__opcode;
        CData/*0:0*/ __Vfunc_npu_numeric_cfg_valid__35__Vfuncout;
        CData/*0:0*/ __Vfunc_npu_numeric_cfg_valid__35__dtype_fields_valid;
        CData/*0:0*/ __Vfunc_npu_dtype_valid__36__Vfuncout;
        CData/*1:0*/ __Vfunc_npu_dtype_valid__36__dtype;
        CData/*0:0*/ __Vfunc_npu_dtype_valid__37__Vfuncout;
        CData/*1:0*/ __Vfunc_npu_dtype_valid__37__dtype;
        CData/*0:0*/ __Vfunc_npu_dtype_valid__38__Vfuncout;
        CData/*1:0*/ __Vfunc_npu_dtype_valid__38__dtype;
        CData/*0:0*/ __Vfunc_npu_dtype_valid__39__Vfuncout;
        CData/*1:0*/ __Vfunc_npu_dtype_valid__39__dtype;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_cmd_dfu_smoke__DOT__clk__0;
    };
    struct {
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_cmd_dfu_smoke__DOT__reset_n__0;
        CData/*0:0*/ __Vtrigprevexpr_h9262126c__1;
        CData/*0:0*/ __Vtrigprevexpr_h68bfd761__1;
        CData/*0:0*/ __Vtrigprevexpr_h6b2234f7__1;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ tb_cmd_dfu_smoke__DOT__expected_lookup_id;
        SData/*11:0*/ tb_cmd_dfu_smoke__DOT__fetch_id;
        SData/*11:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id;
        SData/*11:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__command_id_q;
        SData/*15:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__expected_desc_bytes;
        SData/*11:0*/ __Vfunc_npu_cmd_command_id__24__Vfuncout;
        SData/*11:0*/ __Vfunc_npu_event_ref_valid__25__event_ref;
        SData/*11:0*/ __Vfunc_npu_event_ref_valid__26__event_ref;
        SData/*11:0*/ __Vfunc_npu_event_ref_valid__27__event_ref;
        IData/*31:0*/ tb_cmd_dfu_smoke__DOT__cfe_error_count;
        IData/*31:0*/ tb_cmd_dfu_smoke__DOT__cmd_accepted_count;
        IData/*31:0*/ tb_cmd_dfu_smoke__DOT__mem_request_count;
        VlWide<64>/*2047:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q;
        VlWide<4>/*127:0*/ __Vfunc_npu_cmd_command_id__24__command;
        IData/*31:0*/ __Vfunc_npu_numeric_cfg_valid__35__cfg;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ tb_cmd_dfu_smoke__DOT__cmd_data;
        QData/*47:0*/ tb_cmd_dfu_smoke__DOT__fetch_addr;
        QData/*47:0*/ tb_cmd_dfu_smoke__DOT__mem_req_addr;
        QData/*63:0*/ tb_cmd_dfu_smoke__DOT__mem_rsp_data;
        QData/*63:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q;
        QData/*63:0*/ tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q;
        QData/*47:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_addr_q;
        QData/*47:0*/ tb_cmd_dfu_smoke__DOT__u_dfu__DOT__fault_addr_q;
        VlUnpacked<QData/*63:0*/, 32> tb_cmd_dfu_smoke__DOT__descriptor_words;
        VlUnpacked<VlWide<4>/*127:0*/, 8> tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hefdb7d35__0;
    VlTriggerScheduler __VtrigSched_hefdb7bf8__0;
    VlTriggerScheduler __VtrigSched_h165597e7__0;
    VlTriggerScheduler __VtrigSched_hbc886484__0;
    VlTriggerScheduler __VtrigSched_hfb15c31a__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<7> __VactTriggered;
    VlTriggerVec<7> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_cmd_dfu_smoke__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_cmd_dfu_smoke___024root(Vtb_cmd_dfu_smoke__Syms* symsp, const char* v__name);
    ~Vtb_cmd_dfu_smoke___024root();
    VL_UNCOPYABLE(Vtb_cmd_dfu_smoke___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
