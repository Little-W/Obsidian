// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_inline_scheduler_smoke.h for the primary calling header

#ifndef VERILATED_VTB_INLINE_SCHEDULER_SMOKE___024ROOT_H_
#define VERILATED_VTB_INLINE_SCHEDULER_SMOKE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtb_inline_scheduler_smoke_npu_inline_desc_decode;


class Vtb_inline_scheduler_smoke__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_inline_scheduler_smoke___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtb_inline_scheduler_smoke_npu_inline_desc_decode* __PVT__tb_inline_scheduler_smoke__DOT__u_decode_smoke;
    Vtb_inline_scheduler_smoke_npu_inline_desc_decode* __PVT__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__clk;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__reset_n;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__cfe_cmd_valid;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__df_fetch_valid;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__lookup_rsp_valid;
        CData/*3:0*/ tb_inline_scheduler_smoke__DOT__task_query_state;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_active_q;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__dma_active_q;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_active_q;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__vector_active_q;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__complex_active_q;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_active_q;
        CData/*1:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_op_q;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_rsp_valid_q;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_ack_release_q;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_ack_slot_q;
        CData/*7:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_q;
        CData/*7:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_status_q;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__free_found;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__free_slot;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__lookup_busy_q;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__query_select;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__control_select;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_static_valid;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_found;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_terminal;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_state;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_pending;
        CData/*7:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_status;
        CData/*3:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_engine;
        CData/*7:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_opcode;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_is_inline_rearm;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h0a2df4ca__0;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h2233453d__0;
        CData/*3:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h2fa16ab9__0;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h046bb140__0;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h046bb140__1;
        CData/*2:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_ha0a524a9__0;
        CData/*3:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_haf1f49ed__0;
        CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT____VdfgExtracted_hf6182e41__0;
        CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__compact_opcode;
        CData/*1:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__dtype;
        CData/*4:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__compact_opcode;
        CData/*3:0*/ __Vfunc_npu_v2_engine__2__Vfuncout;
        CData/*4:0*/ __Vfunc_npu_v2_engine__2__compact_opcode;
        CData/*7:0*/ __Vfunc_npu_v2_opcode__3__Vfuncout;
        CData/*4:0*/ __Vfunc_npu_v2_opcode__3__compact_opcode;
        CData/*3:0*/ __Vfunc_npu_v2_engine__4__Vfuncout;
        CData/*4:0*/ __Vfunc_npu_v2_engine__4__compact_opcode;
        CData/*3:0*/ __Vfunc_npu_desc_bytes_for_engine__5__engine;
    };
    struct {
        CData/*3:0*/ __Vfunc_npu_v2_engine__6__Vfuncout;
        CData/*4:0*/ __Vfunc_npu_v2_engine__6__compact_opcode;
        CData/*7:0*/ __Vfunc_npu_v2_event_ref__32__event_id;
        CData/*7:0*/ __Vfunc_npu_v2_event_ref__34__event_id;
        CData/*7:0*/ __Vfunc_npu_v2_event_ref__36__event_id;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout;
        CData/*3:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state;
        CData/*0:0*/ __Vfunc_npu_opcode_engine_valid__40__Vfuncout;
        CData/*3:0*/ __Vfunc_npu_opcode_engine_valid__40__engine;
        CData/*7:0*/ __Vfunc_npu_opcode_engine_valid__40__opcode;
        CData/*0:0*/ __Vfunc_npu_event_ref_valid__41__Vfuncout;
        CData/*0:0*/ __Vfunc_npu_event_ref_valid__42__Vfuncout;
        CData/*0:0*/ __Vfunc_npu_event_ref_valid__43__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout;
        CData/*3:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout;
        CData/*3:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout;
        CData/*3:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout;
        CData/*3:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout;
        CData/*3:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state;
        CData/*3:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__56__Vfuncout;
        CData/*3:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__56__state;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_inline_scheduler_smoke__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_inline_scheduler_smoke__DOT__reset_n__0;
        CData/*0:0*/ __Vtrigprevexpr_ha64895be__1;
        CData/*0:0*/ __Vtrigprevexpr_h5500e8de__1;
        CData/*0:0*/ __Vtrigprevexpr_h0d5889ad__1;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ tb_inline_scheduler_smoke__DOT__task_occupancy;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_producer;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_command_id;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_header_flags;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0_resolved;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1_resolved;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h496575a3__0;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_ha16e251e__0;
        SData/*11:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT____Vlvbound_h1fd80602__0;
        SData/*9:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command_id;
        SData/*15:0*/ __Vfunc_npu_desc_bytes_for_engine__5__Vfuncout;
        SData/*11:0*/ __Vfunc_npu_cmd_header_flags__30__Vfuncout;
        SData/*11:0*/ __Vfunc_npu_cmd_header_flags__30__flags;
        SData/*11:0*/ __Vfunc_npu_v2_event_ref__32__Vfuncout;
        SData/*11:0*/ __Vfunc_npu_v2_event_ref__34__Vfuncout;
        SData/*11:0*/ __Vfunc_npu_v2_event_ref__36__Vfuncout;
        SData/*11:0*/ __Vfunc_npu_event_ref_valid__41__event_ref;
    };
    struct {
        SData/*11:0*/ __Vfunc_npu_event_ref_valid__42__event_ref;
        SData/*11:0*/ __Vfunc_npu_event_ref_valid__43__event_ref;
        SData/*11:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref;
        SData/*11:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref;
        SData/*11:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref;
        SData/*11:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref;
        SData/*11:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref;
        SData/*11:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref;
        VlWide<4>/*127:0*/ tb_inline_scheduler_smoke__DOT__cfe_cmd;
        VlWide<4>/*127:0*/ tb_inline_scheduler_smoke__DOT__decode_cmd;
        IData/*31:0*/ tb_inline_scheduler_smoke__DOT__dfu_request_count;
        IData/*31:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg1_q;
        IData/*31:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_count_q;
        VlWide<64>/*2047:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved;
        IData/*31:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__unnamedblk13__DOT__event_idx;
        VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__Vfuncout;
        VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__payload;
        VlWide<4>/*127:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__make_v2_command__0__command;
        VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__Vfuncout;
        VlWide<3>/*79:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__payload_for_opcode__1__result;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__submit_seq_q;
        QData/*63:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_rsp_data_q;
        QData/*63:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_failure_seq_q;
        QData/*63:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq;
        VlUnpacked<CData/*3:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q;
        VlUnpacked<QData/*47:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_addr_q;
        VlUnpacked<SData/*11:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q;
        VlUnpacked<CData/*3:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q;
        VlUnpacked<CData/*7:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q;
        VlUnpacked<SData/*11:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q;
        VlUnpacked<SData/*11:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q;
        VlUnpacked<SData/*11:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q;
        VlUnpacked<SData/*11:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_signal_q;
        VlUnpacked<QData/*63:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q;
        VlUnpacked<VlWide<64>/*2047:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_desc_flat_q;
        VlUnpacked<CData/*7:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q;
        VlUnpacked<QData/*47:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_fault_addr_q;
        VlUnpacked<QData/*63:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_progress_q;
        VlUnpacked<IData/*31:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_error_info_q;
        VlUnpacked<SData/*15:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_done_flags_q;
        VlUnpacked<CData/*0:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q;
        VlUnpacked<CData/*2:0*/, 255> tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q;
        VlUnpacked<CData/*3:0*/, 255> tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q;
        VlUnpacked<SData/*11:0*/, 255> tb_inline_scheduler_smoke__DOT__dut__DOT__event_producer_q;
        VlUnpacked<QData/*63:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_seq_q;
        VlUnpacked<CData/*0:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_success;
        VlUnpacked<CData/*0:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_failed;
        VlUnpacked<CData/*0:0*/, 8> tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked;
    };
    VlNBACommitQueue<VlUnpacked<CData/*2:0*/, 255>, false, CData/*2:0*/, 1> __VdlyCommitQueuetb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q;
    VlNBACommitQueue<VlUnpacked<SData/*11:0*/, 255>, false, SData/*11:0*/, 1> __VdlyCommitQueuetb_inline_scheduler_smoke__DOT__dut__DOT__event_producer_q;
    VlNBACommitQueue<VlUnpacked<CData/*3:0*/, 255>, false, CData/*3:0*/, 1> __VdlyCommitQueuetb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hb281dba9__0;
    VlTriggerScheduler __VtrigSched_hb281dc6c__0;
    VlTriggerScheduler __VtrigSched_h01ef22e1__0;
    VlTriggerScheduler __VtrigSched_hd0c76f01__0;
    VlTriggerScheduler __VtrigSched_h995f0f28__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<7> __VactTriggered;
    VlTriggerVec<7> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_inline_scheduler_smoke__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_inline_scheduler_smoke___024root(Vtb_inline_scheduler_smoke__Syms* symsp, const char* v__name);
    ~Vtb_inline_scheduler_smoke___024root();
    VL_UNCOPYABLE(Vtb_inline_scheduler_smoke___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
