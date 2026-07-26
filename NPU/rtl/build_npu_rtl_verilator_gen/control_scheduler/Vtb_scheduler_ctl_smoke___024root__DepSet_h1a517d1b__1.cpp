// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_scheduler_ctl_smoke.h for the primary calling header

#include "Vtb_scheduler_ctl_smoke__pch.h"
#include "Vtb_scheduler_ctl_smoke__Syms.h"
#include "Vtb_scheduler_ctl_smoke___024root.h"

extern const VlWide<15>/*479:0*/ Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0;
extern const VlWide<48>/*1535:0*/ Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0;
extern const VlWide<64>/*2047:0*/ Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0;

VL_INLINE_OPT void Vtb_scheduler_ctl_smoke___024root___nba_sequent__TOP__0(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___nba_sequent__TOP__0\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__57__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__57__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__57__state;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__57__state = 0;
    CData/*3:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__state;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__state = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__59__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__59__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__59__state;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__59__state = 0;
    CData/*0:0*/ __Vfunc_npu_event_ref_valid__60__Vfuncout;
    __Vfunc_npu_event_ref_valid__60__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_npu_event_ref_valid__60__event_ref;
    __Vfunc_npu_event_ref_valid__60__event_ref = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__62__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__62__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__62__opcode;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__62__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__63__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__63__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__63__state;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__63__state = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__64__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__64__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__64__opcode;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__64__opcode = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__status;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__status = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__opcode;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__opcode = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__opcode;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__unnamedblk1__DOT__slot;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__unnamedblk1__DOT__slot = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__found;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__found = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__69__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__69__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__69__opcode;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__69__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__70__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__70__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__70__state;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__70__state = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__71__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__71__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__71__status;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__71__status = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__72__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__72__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__72__status;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__72__status = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__status;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__status = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__opcode;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__74__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__74__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__74__status;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__74__status = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__75__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__75__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__75__status;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__75__status = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__76__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__76__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__76__state;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__76__state = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__77__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__77__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__77__status;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__77__status = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__78__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__78__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__78__status;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__78__status = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__status;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__status = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__opcode;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__80__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__80__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__80__status;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__80__status = 0;
    CData/*0:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__81__Vfuncout;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__81__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__81__status;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__81__status = 0;
    CData/*1:0*/ __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_op_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_op_q = 0;
    IData/*31:0*/ __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg1_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg1_q = 0;
    IData/*31:0*/ __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q = 0;
    CData/*3:0*/ __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q = 0;
    CData/*0:0*/ __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q = 0;
    CData/*1:0*/ __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q = 0;
    CData/*0:0*/ __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q = 0;
    CData/*1:0*/ __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q = 0;
    CData/*0:0*/ __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q = 0;
    CData/*1:0*/ __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v0;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v0 = 0;
    QData/*63:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v0;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v0 = 0;
    QData/*63:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v1;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v1 = 0;
    QData/*63:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v2;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v2 = 0;
    QData/*63:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v3;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v3 = 0;
    CData/*3:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1 = 0;
    SData/*11:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q__v0 = 0;
    CData/*3:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q__v0 = 0;
    SData/*11:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q__v0 = 0;
    SData/*11:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q__v0 = 0;
    SData/*11:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q__v0 = 0;
    QData/*63:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q__v0 = 0;
    VlWide<64>/*2047:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1;
    VL_ZERO_W(2048, __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1);
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v1;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v1 = 0;
    IData/*31:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v1;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v1 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v1;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v1 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v1;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v1 = 0;
    CData/*0:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v1;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v1 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v1;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v1 = 0;
    CData/*2:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v0 = 0;
    SData/*11:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v2;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v2;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v2 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v1;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v1 = 0;
    QData/*47:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v1;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v1 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v1;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v1 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v2;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v2 = 0;
    IData/*31:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v2;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v2 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v2;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v2 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v3;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v3;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v3 = 0;
    CData/*7:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v2;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v2 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v2;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v2 = 0;
    QData/*47:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v2;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v2 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v2;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v2 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v3;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v3 = 0;
    IData/*31:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v3;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v3 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v3;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v3 = 0;
    VlWide<64>/*2047:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2;
    VL_ZERO_W(2048, __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2);
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v4;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v5;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v5 = 0;
    IData/*31:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v4;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v4;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v6;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v7;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v7 = 0;
    IData/*31:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v5;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v5 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v5;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v5 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v8;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v8 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v9;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v9 = 0;
    IData/*31:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v6;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v6;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v10;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v10 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v11;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v11 = 0;
    IData/*31:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v7;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v7;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v12;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v12 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v7;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v7;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v7 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v8;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v8 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v8;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v8 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v8;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v8 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v7;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v7;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v7 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v8;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v8 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v13;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v13 = 0;
    CData/*2:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v1;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v1;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v1 = 0;
    CData/*3:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v0;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v0;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v0 = 0;
    SData/*11:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v1;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v1;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v1 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v8;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v8 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v8;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v8 = 0;
    IData/*31:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v14;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v14 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v9;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v9 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v9;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v9 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v10;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v10 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v15;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v15 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v16;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v16 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v16;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v16 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v17;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v17 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v17;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v17 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v18;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v18 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v18;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v18 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v19;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v19 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v19;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v19 = 0;
    CData/*7:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10 = 0;
    QData/*47:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v8;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v8 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v8;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v8 = 0;
    QData/*63:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v9;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v9 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v9;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v9 = 0;
    IData/*31:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v11;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v11 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v11;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v11 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v9;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v9 = 0;
    CData/*3:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v20;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v20 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v20;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v20 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v9;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v9 = 0;
    CData/*7:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11 = 0;
    QData/*47:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v9;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v9 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v9;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v9 = 0;
    QData/*63:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v10;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v10 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v10;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v10 = 0;
    IData/*31:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v12;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v12 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v12;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v12 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v10;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v10 = 0;
    CData/*3:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v21;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v21 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v21;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v21 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v10;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v10 = 0;
    CData/*1:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v11;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v11 = 0;
    CData/*0:0*/ __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v11;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v11 = 0;
    CData/*2:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v2;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v2 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v2;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v2 = 0;
    CData/*2:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v3;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v3 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v3;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v3 = 0;
    CData/*2:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v4;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v4 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v4;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v4 = 0;
    CData/*2:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v5;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v5 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v5;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v5 = 0;
    CData/*2:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v6;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v6 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v6;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v6 = 0;
    CData/*2:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v7;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v7 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v7;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v7 = 0;
    CData/*2:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v8;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v8 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v8;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v8 = 0;
    CData/*2:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v9;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v9 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v9;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v9 = 0;
    CData/*2:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v10;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v10 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v10;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v10 = 0;
    CData/*3:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v1;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v1;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v1 = 0;
    SData/*11:0*/ __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v2;
    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v2 = 0;
    CData/*7:0*/ __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v2;
    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v2 = 0;
    // Body
    vlSelfRef.__Vdly__tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_valid 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_valid;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_op_q 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_op_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg1_q 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg1_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q;
    vlSelfRef.__Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_active_q 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_active_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q;
    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v0 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v8 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v11 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v4 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v5 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v6 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v7 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v7 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v6 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v8 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v10 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v12 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v16 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v17 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v18 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v19 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v7 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v9 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v2 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v3 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v5 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v7 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v9 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v11 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v0 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10 = 0U;
    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11 = 0U;
    vlSelfRef.__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1 = 0U;
    vlSelfRef.__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v22 = 0U;
    if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__reset_n) {
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_found) {
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                              [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select])))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_scheduler_ctl_smoke.sv:305: Assertion failed in %Ntb_scheduler_ctl_smoke: unexpected failed completion\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("control/tb_scheduler_ctl_smoke.sv", 305, "", false);
            }
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_count 
                = ((IData)(1U) + vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_count);
            if (VL_UNLIKELY(((1U & ((((0ULL != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q
                                       [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select]) 
                                      | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                                         [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select] 
                                         & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                                            [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select]))) 
                                     | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                                         [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select] 
                                         >> 1U) & (0U 
                                                   != 
                                                   vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                                                   [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select]))) 
                                    | (~ ((((1U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_command_id)) 
                                            & (1U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_engine))) 
                                           & (0x20U 
                                              == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_opcode))) 
                                          | (((2U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_command_id)) 
                                              & (2U 
                                                 == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_engine))) 
                                             & (0x40U 
                                                == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_opcode)))))))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_scheduler_ctl_smoke.sv:315: Assertion failed in %Ntb_scheduler_ctl_smoke: completion metadata is incorrect\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("control/tb_scheduler_ctl_smoke.sv", 315, "", false);
            }
            if (VL_UNLIKELY((((1U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_command_id)) 
                              & (0x123ULL != vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_progress))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_scheduler_ctl_smoke.sv:319: Assertion failed in %Ntb_scheduler_ctl_smoke: DMA progress was not retained\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("control/tb_scheduler_ctl_smoke.sv", 319, "", false);
            }
            if (VL_UNLIKELY((((2U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_command_id)) 
                              & (0x456ULL != vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_progress))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_scheduler_ctl_smoke.sv:323: Assertion failed in %Ntb_scheduler_ctl_smoke: Matrix progress was not retained\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("control/tb_scheduler_ctl_smoke.sv", 323, "", false);
            }
        }
    } else {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_count = 0U;
    }
    if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__reset_n) {
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_valid) {
            if (VL_UNLIKELY((((0U != ((((((((((((((
                                                   (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0U] 
                                                    ^ 
                                                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0U]) 
                                                   | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[1U] 
                                                      ^ 
                                                      vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[1U])) 
                                                  | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[2U] 
                                                     ^ 
                                                     vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[2U])) 
                                                 | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[3U] 
                                                    ^ 
                                                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[3U])) 
                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[4U] 
                                                   ^ 
                                                   vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[4U])) 
                                               | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[5U] 
                                                  ^ 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[5U])) 
                                              | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[6U] 
                                                 ^ 
                                                 vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[6U])) 
                                             | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[7U] 
                                                ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[7U])) 
                                            | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[8U] 
                                               ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[8U])) 
                                           | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[9U] 
                                              ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[9U])) 
                                          | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0xaU] 
                                             ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xaU])) 
                                         | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0xbU] 
                                            ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xbU])) 
                                        | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0xcU] 
                                           ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xcU])) 
                                       | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0xdU] 
                                          ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xdU])) 
                                      | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0xeU] 
                                         ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xeU]))) 
                              | (0U != ((((((((((((
                                                   ((((((((((((((((((((((((((((((((((((Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x10U]) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[1U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x11U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[2U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x12U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[3U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x13U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[4U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x14U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[5U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x15U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[6U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x16U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[7U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x17U])) 
                                                                               | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[8U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x18U])) 
                                                                              | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[9U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x19U])) 
                                                                             | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xaU] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1aU])) 
                                                                            | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xbU] 
                                                                               ^ 
                                                                               vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1bU])) 
                                                                           | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xcU] 
                                                                              ^ 
                                                                              vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1cU])) 
                                                                          | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xdU] 
                                                                             ^ 
                                                                             vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1dU])) 
                                                                         | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xeU] 
                                                                            ^ 
                                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1eU])) 
                                                                        | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xfU] 
                                                                           ^ 
                                                                           vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1fU])) 
                                                                       | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x10U] 
                                                                          ^ 
                                                                          vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x20U])) 
                                                                      | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x11U] 
                                                                         ^ 
                                                                         vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x21U])) 
                                                                     | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x12U] 
                                                                        ^ 
                                                                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x22U])) 
                                                                    | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x13U] 
                                                                       ^ 
                                                                       vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x23U])) 
                                                                   | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x14U] 
                                                                      ^ 
                                                                      vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x24U])) 
                                                                  | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x15U] 
                                                                     ^ 
                                                                     vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x25U])) 
                                                                 | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x16U] 
                                                                    ^ 
                                                                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x26U])) 
                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x17U] 
                                                                   ^ 
                                                                   vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x27U])) 
                                                               | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x18U] 
                                                                  ^ 
                                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x28U])) 
                                                              | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x19U] 
                                                                 ^ 
                                                                 vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x29U])) 
                                                             | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1aU] 
                                                                ^ 
                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2aU])) 
                                                            | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1bU] 
                                                               ^ 
                                                               vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2bU])) 
                                                           | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1cU] 
                                                              ^ 
                                                              vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2cU])) 
                                                          | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1dU] 
                                                             ^ 
                                                             vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2dU])) 
                                                         | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1eU] 
                                                            ^ 
                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2eU])) 
                                                        | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1fU] 
                                                           ^ 
                                                           vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2fU])) 
                                                       | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x20U] 
                                                          ^ 
                                                          vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x30U])) 
                                                      | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x21U] 
                                                         ^ 
                                                         vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x31U])) 
                                                     | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x22U] 
                                                        ^ 
                                                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x32U])) 
                                                    | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x23U] 
                                                       ^ 
                                                       vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x33U])) 
                                                   | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x24U] 
                                                      ^ 
                                                      vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x34U])) 
                                                  | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x25U] 
                                                     ^ 
                                                     vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x35U])) 
                                                 | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x26U] 
                                                    ^ 
                                                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x36U])) 
                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x27U] 
                                                   ^ 
                                                   vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x37U])) 
                                               | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x28U] 
                                                  ^ 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x38U])) 
                                              | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x29U] 
                                                 ^ 
                                                 vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x39U])) 
                                             | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2aU] 
                                                ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3aU])) 
                                            | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2bU] 
                                               ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3bU])) 
                                           | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2cU] 
                                              ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3cU])) 
                                          | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2dU] 
                                             ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3dU])) 
                                         | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2eU] 
                                            ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3eU])) 
                                        | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2fU] 
                                           ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3fU]))))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_scheduler_ctl_smoke.sv:342: Assertion failed in %Ntb_scheduler_ctl_smoke: DMA dispatch changed descriptor data\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("control/tb_scheduler_ctl_smoke.sv", 342, "", false);
            }
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_seen_q = 1U;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_accepted_opcode_q 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select];
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_accepted_command_id_q 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select];
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_accepted_user_tag_q 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xfU];
        }
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_valid) {
            if (VL_UNLIKELY((((0U != ((((((((((((((
                                                   (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0U] 
                                                    ^ 
                                                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0U]) 
                                                   | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[1U] 
                                                      ^ 
                                                      vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[1U])) 
                                                  | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[2U] 
                                                     ^ 
                                                     vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[2U])) 
                                                 | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[3U] 
                                                    ^ 
                                                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[3U])) 
                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[4U] 
                                                   ^ 
                                                   vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[4U])) 
                                               | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[5U] 
                                                  ^ 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[5U])) 
                                              | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[6U] 
                                                 ^ 
                                                 vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[6U])) 
                                             | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[7U] 
                                                ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[7U])) 
                                            | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[8U] 
                                               ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[8U])) 
                                           | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[9U] 
                                              ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[9U])) 
                                          | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0xaU] 
                                             ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xaU])) 
                                         | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0xbU] 
                                            ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xbU])) 
                                        | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0xcU] 
                                           ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xcU])) 
                                       | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0xdU] 
                                          ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xdU])) 
                                      | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_hbd99daea_0[0xeU] 
                                         ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xeU]))) 
                              | (0U != ((((((((((((
                                                   ((((((((((((((((((((((((((((((((((((Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x10U]) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[1U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x11U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[2U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x12U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[3U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x13U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[4U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x14U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[5U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x15U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[6U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x16U])) 
                                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[7U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x17U])) 
                                                                               | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[8U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x18U])) 
                                                                              | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[9U] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x19U])) 
                                                                             | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xaU] 
                                                                                ^ 
                                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1aU])) 
                                                                            | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xbU] 
                                                                               ^ 
                                                                               vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1bU])) 
                                                                           | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xcU] 
                                                                              ^ 
                                                                              vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1cU])) 
                                                                          | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xdU] 
                                                                             ^ 
                                                                             vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1dU])) 
                                                                         | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xeU] 
                                                                            ^ 
                                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1eU])) 
                                                                        | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0xfU] 
                                                                           ^ 
                                                                           vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1fU])) 
                                                                       | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x10U] 
                                                                          ^ 
                                                                          vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x20U])) 
                                                                      | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x11U] 
                                                                         ^ 
                                                                         vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x21U])) 
                                                                     | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x12U] 
                                                                        ^ 
                                                                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x22U])) 
                                                                    | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x13U] 
                                                                       ^ 
                                                                       vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x23U])) 
                                                                   | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x14U] 
                                                                      ^ 
                                                                      vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x24U])) 
                                                                  | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x15U] 
                                                                     ^ 
                                                                     vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x25U])) 
                                                                 | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x16U] 
                                                                    ^ 
                                                                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x26U])) 
                                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x17U] 
                                                                   ^ 
                                                                   vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x27U])) 
                                                               | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x18U] 
                                                                  ^ 
                                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x28U])) 
                                                              | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x19U] 
                                                                 ^ 
                                                                 vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x29U])) 
                                                             | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1aU] 
                                                                ^ 
                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2aU])) 
                                                            | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1bU] 
                                                               ^ 
                                                               vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2bU])) 
                                                           | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1cU] 
                                                              ^ 
                                                              vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2cU])) 
                                                          | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1dU] 
                                                             ^ 
                                                             vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2dU])) 
                                                         | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1eU] 
                                                            ^ 
                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2eU])) 
                                                        | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x1fU] 
                                                           ^ 
                                                           vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2fU])) 
                                                       | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x20U] 
                                                          ^ 
                                                          vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x30U])) 
                                                      | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x21U] 
                                                         ^ 
                                                         vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x31U])) 
                                                     | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x22U] 
                                                        ^ 
                                                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x32U])) 
                                                    | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x23U] 
                                                       ^ 
                                                       vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x33U])) 
                                                   | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x24U] 
                                                      ^ 
                                                      vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x34U])) 
                                                  | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x25U] 
                                                     ^ 
                                                     vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x35U])) 
                                                 | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x26U] 
                                                    ^ 
                                                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x36U])) 
                                                | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x27U] 
                                                   ^ 
                                                   vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x37U])) 
                                               | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x28U] 
                                                  ^ 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x38U])) 
                                              | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x29U] 
                                                 ^ 
                                                 vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x39U])) 
                                             | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2aU] 
                                                ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3aU])) 
                                            | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2bU] 
                                               ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3bU])) 
                                           | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2cU] 
                                              ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3cU])) 
                                          | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2dU] 
                                             ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3dU])) 
                                         | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2eU] 
                                            ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3eU])) 
                                        | (Vtb_scheduler_ctl_smoke__ConstPool__CONST_h22f5c49d_0[0x2fU] 
                                           ^ vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3fU]))))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_scheduler_ctl_smoke.sv:352: Assertion failed in %Ntb_scheduler_ctl_smoke: Matrix dispatch changed descriptor data\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("control/tb_scheduler_ctl_smoke.sv", 352, "", false);
            }
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_seen_q = 1U;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_accepted_opcode_q 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select];
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_accepted_command_id_q 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select];
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_accepted_user_tag_q 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xfU];
        }
    } else {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_seen_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_accepted_opcode_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_accepted_command_id_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_accepted_user_tag_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_seen_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_accepted_opcode_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_accepted_command_id_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_accepted_user_tag_q = 0U;
    }
    if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__reset_n) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__cmd_id_lookup_rsp_valid = 0U;
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 0U;
            if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_release_q) {
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v0 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_slot_q;
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v0 = 1U;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v0 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_slot_q;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_slot_q;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v0 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_slot_q;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v0 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_slot_q;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v0 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_slot_q;
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_release_q = 0U;
            }
        }
        if (((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_valid) 
             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_ready))) {
            __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_op_q 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_op;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q 
                = (0xfffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0));
            __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg1_q 
                = (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1);
            __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q = 0U;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_release_q = 0U;
            __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q = 0U;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_status_q = 0U;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_failure_seq_q = 0xffffffffffffffffULL;
            if ((2U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_op))) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                if ((((0U != (vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0 
                              >> 0xcU)) | (0U != (vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1 
                                                  >> 3U))) 
                     | (7U == (7U & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1))))) {
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                } else if ((1U & (IData)((vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1 
                                          >> 2U)))) {
                    if ((1U & (IData)((vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1 
                                       >> 1U)))) {
                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q 
                            = ((1U & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1))
                                ? 2ULL : ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found)
                                           ? (QData)((IData)(
                                                             vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q
                                                             [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select]))
                                           : 0ULL));
                    } else if ((1U & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1))) {
                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q 
                            = ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found)
                                ? (QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q
                                                  [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select]))
                                : 0ULL);
                    } else if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found) {
                        if ((1U & ((~ ([&]() {
                                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__57__state 
                                                    = 
                                                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                    [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select];
                                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__57__Vfuncout 
                                                    = 
                                                    ((5U 
                                                      == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__57__state)) 
                                                     | (6U 
                                                        == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__57__state)));
                                            }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__57__Vfuncout))) 
                                   | vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
                                   [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select]))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 1ULL;
                        } else {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_release_q = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 0ULL;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_slot_q 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select;
                        }
                    } else {
                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                    }
                } else {
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q 
                        = ((1U & (IData)((vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1 
                                          >> 1U))) ? 
                           ((1U & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1))
                             ? ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found)
                                 ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q
                                [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select]
                                 : 0ULL) : ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found)
                                             ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q
                                            [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select]
                                             : 0ULL))
                            : ((1U & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1))
                                ? ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found)
                                    ? (((QData)((IData)(
                                                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                                                        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                                                    [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select][0xfU])))
                                    : 0ULL) : ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found)
                                                ? (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                                                                    [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select])) 
                                                    << 0xcU) 
                                                   | (QData)((IData)(
                                                                     ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                                                                       [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select] 
                                                                       << 4U) 
                                                                      | ([&]() {
                                                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__state 
                                                            = 
                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                            [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select];
                                                        {
                                                            if (
                                                                (0U 
                                                                 == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__state))) {
                                                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__Vfuncout = 0U;
                                                                goto __Vlabel0;
                                                            }
                                                            if (
                                                                (4U 
                                                                 == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__state))) {
                                                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__Vfuncout = 2U;
                                                                goto __Vlabel0;
                                                            }
                                                            if (
                                                                ([&]() {
                                                                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__59__state 
                                                                            = __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__state;
                                                                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__59__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__59__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__59__state)));
                                                                    }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__59__Vfuncout))) {
                                                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__Vfuncout = 3U;
                                                                goto __Vlabel0;
                                                            }
                                                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__Vfuncout = 1U;
                                                            __Vlabel0: ;
                                                        }
                                                    }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__58__Vfuncout))))))
                                                : (0x810ULL 
                                                   | ((QData)((IData)(
                                                                      (0xfffU 
                                                                       & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0)))) 
                                                      << 0xcU)))));
                }
            } else if ((1U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_op))) {
                if ((1U & (((((0U != (vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0 
                                      >> 0xcU)) | (0U 
                                                   != (IData)(
                                                              (vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1 
                                                               >> 0x20U)))) 
                             | (~ ([&]() {
                                                __Vfunc_npu_event_ref_valid__60__event_ref 
                                                    = 
                                                    (0xfffU 
                                                     & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0));
                                                __Vfunc_npu_event_ref_valid__60__Vfuncout 
                                                    = 
                                                    ((0xfffU 
                                                      == (IData)(__Vfunc_npu_event_ref_valid__60__event_ref)) 
                                                     | (0xffU 
                                                        != 
                                                        (0xffU 
                                                         & (IData)(__Vfunc_npu_event_ref_valid__60__event_ref))));
                                            }(), (IData)(__Vfunc_npu_event_ref_valid__60__Vfuncout)))) 
                            | (0xfffU == (0xfffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0)))) 
                           | (0xffU <= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0)))))) {
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                } else if (((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0)))
                               ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                              [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0))]
                               : 0U) != (0xfU & (IData)(
                                                        (vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0 
                                                         >> 8U)))) 
                            | (0U == ((0xfeU >= (0xffU 
                                                 & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0)))
                                       ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                      [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0))]
                                       : 0U)))) {
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 0x81ULL;
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                } else if (((2U == ((0xfeU >= (0xffU 
                                               & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0)))
                                     ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                    [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0))]
                                     : 0U)) | (3U == 
                                               ((0xfeU 
                                                 >= 
                                                 (0xffU 
                                                  & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0)))
                                                 ? 
                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                                [(0xffU 
                                                  & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0))]
                                                 : 0U)))) {
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q 
                        = (((QData)((IData)(((0xfeU 
                                              >= (0xffU 
                                                  & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0)))
                                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q
                                             [(0xffU 
                                               & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0))]
                                              : 0U))) 
                            << 8U) | (QData)((IData)(
                                                     ((0xfeU 
                                                       >= 
                                                       (0xffU 
                                                        & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0)))
                                                       ? 
                                                      vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                                      [
                                                      (0xffU 
                                                       & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0))]
                                                       : 0U))));
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                } else if ((0U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1))) {
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 9ULL;
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                } else {
                    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q = 1U;
                }
            } else if ((3U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_op))) {
                if (((0U != (vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0 
                             >> 4U)) | (0U != (IData)(
                                                      (vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg1 
                                                       >> 0x20U))))) {
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                } else {
                    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_target;
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_status_q 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_status;
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_failure_seq_q 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_failure_seq;
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v0 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [0U];
                    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v0 = 1U;
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v1 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [1U];
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [2U];
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v3 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [3U];
                    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q = 1U;
                }
            } else {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
            }
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((3U 
                                                     == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_op)) 
                                                    << 2U) 
                                                   | (((1U 
                                                        == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_op)) 
                                                       << 1U) 
                                                      | (2U 
                                                         == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_op)))))))))) {
                if ((0U != (((3U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_op)) 
                             << 2U) | (((1U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_op)) 
                                        << 1U) | (2U 
                                                  == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_op)))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: npu_task_scheduler.sv:861: Assertion failed in %Ntb_scheduler_ctl_smoke.u_scheduler: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1),
                                     -12,vlSymsp->name(),
                                     2,(IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_op));
                        VL_STOP_MT("control/npu_task_scheduler.sv", 861, "");
                    }
                }
            }
        }
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q) {
            if ((1U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_op_q))) {
                if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_found) {
                    if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_terminal) {
                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q 
                            = (((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_producer)) 
                                << 8U) | (QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_state)));
                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q = 0U;
                    } else if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q 
                                >= vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg1_q)) {
                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 9ULL;
                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q = 0U;
                    } else {
                        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q 
                            = ((IData)(1U) + vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q);
                    }
                } else {
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 0x81ULL;
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q = 0U;
                }
            } else if ((3U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_op_q))) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_status_q 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_status;
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_failure_seq_q 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_seq;
                if (((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q) 
                     & (((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                          [0U]) | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                   [0U] != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q
                                   [0U])) | ([&]() {
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state 
                                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                        [0U];
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state)) 
                                           | (6U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state)));
                                }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__Vfuncout))))) {
                    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q 
                        = (0xeU & (IData)(__Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q));
                }
                if ((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q) 
                      >> 1U) & (((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                  [1U]) | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                           [1U] != 
                                           vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q
                                           [1U])) | 
                                ([&]() {
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state 
                                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                        [1U];
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state)) 
                                           | (6U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state)));
                                }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__Vfuncout))))) {
                    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q 
                        = (0xdU & (IData)(__Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q));
                }
                if ((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q) 
                      >> 2U) & (((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                  [2U]) | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                           [2U] != 
                                           vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q
                                           [2U])) | 
                                ([&]() {
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state 
                                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                        [2U];
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state)) 
                                           | (6U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state)));
                                }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__Vfuncout))))) {
                    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q 
                        = (0xbU & (IData)(__Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q));
                }
                if ((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q) 
                      >> 3U) & (((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                  [3U]) | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                           [3U] != 
                                           vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q
                                           [3U])) | 
                                ([&]() {
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state 
                                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                        [3U];
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__Vfuncout 
                                        = ((5U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state)) 
                                           | (6U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__state)));
                                }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__61__Vfuncout))))) {
                    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q 
                        = (7U & (IData)(__Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q));
                }
                if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_pending) {
                    if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q 
                         >= vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg1_q)) {
                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 9ULL;
                        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q = 0U;
                    } else {
                        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q 
                            = ((IData)(1U) + vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q);
                    }
                } else {
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q 
                        = (QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_status));
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                    __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q = 0U;
                }
            } else {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 2ULL;
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 1U;
                __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q = 0U;
            }
        }
        if (((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd_valid) 
             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_found))) {
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            vlSelfRef.__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1 = 1U;
            if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
                 >> 0x1fU)) {
                vlSelfRef.__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q__v0 = 0ULL;
                IData/*31:0*/ __Vilp1;
                __Vilp1 = 0U;
                while ((__Vilp1 <= 0x3fU)) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[__Vilp1] 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[__Vilp1];
                    __Vilp1 = ((IData)(1U) + __Vilp1);
                }
            } else {
                vlSelfRef.__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q__v0 
                    = (0xffffffffffffULL & (((QData)((IData)(
                                                             vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[0U]))));
                IData/*31:0*/ __Vilp2;
                __Vilp2 = 0U;
                while ((__Vilp2 <= 0x3fU)) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[__Vilp2] 
                        = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[__Vilp2];
                    __Vilp2 = ((IData)(1U) + __Vilp2);
                }
            }
            vlSelfRef.__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_command_id;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_engine;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_opcode;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            vlSelfRef.__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_header_flags;
            vlSelfRef.__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0_resolved;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1_resolved;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__submit_seq_q;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v0 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v1 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_static_valid) {
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1 
                    = ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
                        >> 0x1fU) ? 2U : 1U);
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q__v0 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved;
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v0 = 0U;
            } else {
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1 = 6U;
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q__v0 = 0xfffU;
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v0 = 2U;
            }
            __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v1 
                = ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_static_valid)
                    ? 0U : ([&]() {
                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__62__opcode 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_opcode;
                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__62__Vfuncout 
                            = (0x6002ff00U | (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__62__opcode));
                    }(), __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__62__Vfuncout));
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v1 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v1 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v1 
                = (1U & (~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_static_valid)));
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v1 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__submit_seq_q 
                = (1ULL + vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__submit_seq_q);
            if ((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_static_valid) 
                  & (0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved))) 
                 & (~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_is_inline_rearm)))) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h0a2df4ca__0 = 1U;
                if (VL_LIKELY(((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)))))) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v0 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h0a2df4ca__0;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v0 
                        = (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved));
                    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v0, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v0));
                }
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h496575a3__0 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_command_id;
                if (VL_LIKELY(((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)))))) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v0 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h496575a3__0;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v0 
                        = (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved));
                    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v0, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v0));
                }
            }
        }
        if (((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_valid) 
             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_ready))) {
            vlSelfRef.__Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_active_q = 1U;
            __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select;
        }
        if (((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_valid) 
             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_active_q))) {
            vlSelfRef.__Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_active_q = 0U;
            if ((1U & (~ ([&]() {
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__63__state 
                                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                    [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q];
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__63__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__63__state)) 
                                       | (6U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__63__state)));
                            }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__63__Vfuncout))))) {
                if (((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_command_id) 
                     != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                     [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q])) {
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v2 = 1U;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v1 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v1 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q
                        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q];
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v1 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__64__opcode 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q];
                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__64__Vfuncout 
                        = (0x2002ff00U | (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__64__opcode));
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2 
                        = __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__64__Vfuncout;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2 = 1U;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                } else if ((0U != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_status))) {
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v3 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v3 = 1U;
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_status;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_fault_addr;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v3 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__opcode 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q];
                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__status 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_status;
                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__Vfuncout 
                        = (0x2000ff00U | (((IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__status) 
                                           << 0x10U) 
                                          | (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__opcode)));
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3 
                        = __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__65__Vfuncout;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3 = 1U;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v3 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v3 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                } else {
                    IData/*31:0*/ __Vilp3;
                    __Vilp3 = 0U;
                    while ((__Vilp3 <= 0x3fU)) {
                        __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[__Vilp3] 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_desc_flat[__Vilp3];
                        __Vilp3 = ((IData)(1U) + __Vilp3);
                    }
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2 = 1U;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v4 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
                }
            }
        }
        if ((2U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
             [0U])) {
            if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_failed
                [0U]) {
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v5 = 1U;
                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__opcode 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                    [0U];
                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__opcode));
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v4 
                    = __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__Vfuncout;
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v4 = 1U;
            } else if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_success
                        [0U] & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                                [0U]))) {
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v6 = 1U;
            }
        }
        if ((2U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
             [1U])) {
            if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_failed
                [1U]) {
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v7 = 1U;
                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__opcode 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                    [1U];
                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__opcode));
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v5 
                    = __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__Vfuncout;
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v5 = 1U;
            } else if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_success
                        [1U] & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                                [1U]))) {
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v8 = 1U;
            }
        }
        if ((2U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
             [2U])) {
            if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_failed
                [2U]) {
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v9 = 1U;
                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__opcode 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                    [2U];
                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__opcode));
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v6 
                    = __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__Vfuncout;
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v6 = 1U;
            } else if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_success
                        [2U] & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                                [2U]))) {
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v10 = 1U;
            }
        }
        if ((2U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
             [3U])) {
            if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_failed
                [3U]) {
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v11 = 1U;
                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__opcode 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                    [3U];
                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__Vfuncout 
                    = (0x6008ff00U | (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__opcode));
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v7 
                    = __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__66__Vfuncout;
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v7 = 1U;
            } else if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_success
                        [3U] & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                                [3U]))) {
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v12 = 1U;
            }
        }
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select_found) {
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v7 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
            __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v7 = 1U;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v8 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v8 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v8 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
            if ((2U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                 [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select])) {
                if (((((((0xffU > (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                   [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U])) 
                         & ((2U == ((0xfeU >= (0xffU 
                                               & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                               [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U]))
                                     ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                    [(0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U])]
                                     : 0U)) | (3U == 
                                               ((0xfeU 
                                                 >= 
                                                 (0xffU 
                                                  & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                                  [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U]))
                                                 ? 
                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                                [(0xffU 
                                                  & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                                  [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U])]
                                                 : 0U)))) 
                        & (((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                       [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U]))
                             ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                            [(0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                              [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U])]
                             : 0U) == (0xfU & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                               [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U] 
                                               >> 8U)))) 
                       & (~ ([&]() {
                                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref 
                                                = (0xfffU 
                                                   & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                                   [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U]);
                                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__unnamedblk1__DOT__slot = 0;
                                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__found = 0U;
                                            if ((0xfffU 
                                                 != (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref))) {
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                       [0U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state 
                                                                            = 
                                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                            [0U];
                                                                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state)));
                                                                    }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                         [0U] 
                                                         == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref)) 
                                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                            [0U] 
                                                            == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref)) 
                                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                              [0U] 
                                                              != 
                                                              vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                              [0U]))))) {
                                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__found = 1U;
                                                }
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                       [1U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state 
                                                                            = 
                                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                            [1U];
                                                                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state)));
                                                                    }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                         [1U] 
                                                         == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref)) 
                                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                            [1U] 
                                                            == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref)) 
                                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                              [1U] 
                                                              != 
                                                              vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                              [1U]))))) {
                                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__found = 1U;
                                                }
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                       [2U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state 
                                                                            = 
                                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                            [2U];
                                                                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state)));
                                                                    }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                         [2U] 
                                                         == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref)) 
                                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                            [2U] 
                                                            == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref)) 
                                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                              [2U] 
                                                              != 
                                                              vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                              [2U]))))) {
                                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__found = 1U;
                                                }
                                                if (
                                                    (((0U 
                                                       != 
                                                       vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                       [3U]) 
                                                      & (~ 
                                                         ([&]() {
                                                                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state 
                                                                            = 
                                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                            [3U];
                                                                        __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__Vfuncout 
                                                                            = 
                                                                            ((5U 
                                                                              == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state)) 
                                                                             | (6U 
                                                                                == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__state)));
                                                                    }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__68__Vfuncout)))) 
                                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                         [3U] 
                                                         == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref)) 
                                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                            [3U] 
                                                            == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__event_ref)) 
                                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                              [3U] 
                                                              != 
                                                              vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                              [3U]))))) {
                                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__found = 1U;
                                                }
                                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__unnamedblk1__DOT__slot = 4U;
                                            }
                                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__Vfuncout 
                                                = __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__found;
                                        }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__67__Vfuncout)))) 
                      & ((0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                          [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][8U]) 
                         == (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                             [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U]))) 
                     & ((0xfU & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                 [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][8U] 
                                 >> 8U)) == (0xfU & 
                                             ((IData)(1U) 
                                              + ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                                  [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U] 
                                                  << 0x18U) 
                                                 | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                                    [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U] 
                                                    >> 8U))))))) {
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v7 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
                    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v7 = 1U;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v8 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v13 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h0036ad8d__0 = 0U;
                    if (VL_LIKELY(((0xfeU >= (0xffU 
                                              & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                              [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U]))))) {
                        __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v1 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h0036ad8d__0;
                        __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v1 
                            = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                               [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U]);
                        vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v1, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v1));
                    }
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h95abc389__0 
                        = (0xfU & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                   [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][8U] 
                                   >> 8U));
                    if (VL_LIKELY(((0xfeU >= (0xffU 
                                              & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                              [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U]))))) {
                        __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v0 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h95abc389__0;
                        __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v0 
                            = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                               [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U]);
                        vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v0, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v0));
                    }
                    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h3f69ad0e__0 = 0U;
                    if (VL_LIKELY(((0xfeU >= (0xffU 
                                              & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                                              [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U]))))) {
                        __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v1 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h3f69ad0e__0;
                        __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v1 
                            = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
                               [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select][2U]);
                        vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v1, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v1));
                    }
                } else {
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v8 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
                    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v8 = 1U;
                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__69__opcode 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select];
                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__69__Vfuncout 
                        = (0x4002ff00U | (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__69__opcode));
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9 
                        = __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__69__Vfuncout;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
                    __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9 = 1U;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v14 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
                }
            } else {
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v9 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v9 = 1U;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v10 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v15 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select;
            }
        }
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_valid) {
            __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q = 1U;
            __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v16 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select;
            __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v16 = 1U;
        }
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_valid) {
            __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q = 1U;
            __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v17 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select;
            __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v17 = 1U;
        }
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__vector_task_valid) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_active_q = 1U;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v18 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select;
            __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v18 = 1U;
        }
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__complex_task_valid) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_active_q = 1U;
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v19 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select;
            __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v19 = 1U;
        }
        if (((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_valid) 
             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q))) {
            __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q = 0U;
            if ((1U & (~ ([&]() {
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__70__state 
                                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                    [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q];
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__70__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__70__state)) 
                                       | (6U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__70__state)));
                            }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__70__Vfuncout))))) {
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10 
                    = ((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_command_id) 
                         == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                         [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q]) 
                        & ([&]() {
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__71__status 
                                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_status;
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__71__Vfuncout 
                                    = (0xdU >= (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__71__status));
                            }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__71__Vfuncout)))
                        ? (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_status)
                        : 2U);
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q;
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10 = 1U;
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v8 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_fault_addr;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v8 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q;
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v9 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_progress;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v9 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q;
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v11 
                    = (((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_command_id) 
                          == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__72__status 
                                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_status;
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__72__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__72__status));
                                }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__72__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_status)))
                        ? 0U : ([&]() {
                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__opcode 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                                [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q];
                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__status 
                                = ((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_command_id) 
                                     == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                                     [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q]) 
                                    & ([&]() {
                                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__74__status 
                                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_status;
                                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__74__Vfuncout 
                                                = (0xdU 
                                                   >= (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__74__status));
                                        }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__74__Vfuncout)))
                                    ? (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_status)
                                    : 2U);
                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__Vfuncout 
                                = (0x4000ff00U | (((IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__status) 
                                                   << 0x10U) 
                                                  | (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__opcode)));
                        }(), __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__73__Vfuncout));
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v11 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v9 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q;
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v20 
                    = (((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_command_id) 
                          == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__75__status 
                                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_status;
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__75__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__75__status));
                                }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__75__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_status)))
                        ? 5U : 6U);
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v20 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v9 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q;
            }
        }
        if (((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_valid) 
             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q))) {
            __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q = 0U;
            if ((1U & (~ ([&]() {
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__76__state 
                                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                    [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q];
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__76__Vfuncout 
                                    = ((5U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__76__state)) 
                                       | (6U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__76__state)));
                            }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__76__Vfuncout))))) {
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11 
                    = ((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_command_id) 
                         == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                         [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q]) 
                        & ([&]() {
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__77__status 
                                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_status;
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__77__Vfuncout 
                                    = (0xdU >= (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__77__status));
                            }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__77__Vfuncout)))
                        ? (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_status)
                        : 2U);
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q;
                __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11 = 1U;
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v9 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_fault_addr;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v9 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q;
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v10 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_progress;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v10 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q;
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v12 
                    = (((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_command_id) 
                          == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__78__status 
                                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_status;
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__78__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__78__status));
                                }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__78__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_status)))
                        ? 0U : ([&]() {
                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__opcode 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                                [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q];
                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__status 
                                = ((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_command_id) 
                                     == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                                     [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q]) 
                                    & ([&]() {
                                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__80__status 
                                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_status;
                                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__80__Vfuncout 
                                                = (0xdU 
                                                   >= (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__80__status));
                                        }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__80__Vfuncout)))
                                    ? (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_status)
                                    : 2U);
                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__Vfuncout 
                                = (0x4000ff00U | (((IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__status) 
                                                   << 0x10U) 
                                                  | (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__opcode)));
                        }(), __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__make_error_info__79__Vfuncout));
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v12 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v10 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q;
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v21 
                    = (((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_command_id) 
                          == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                          [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q]) 
                         & ([&]() {
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__81__status 
                                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_status;
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__81__Vfuncout 
                                        = (0xdU >= (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__81__status));
                                }(), (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_valid__81__Vfuncout))) 
                        & (0U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_status)))
                        ? 5U : 6U);
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v21 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v10 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q;
            }
        }
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_found) {
            __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v11 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select;
            __VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v11 = 1U;
        }
        if (((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
              [0U] & (0xfffU != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                      [0U])) & (~ ((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                                    [0U]) & (2U == 
                                             vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                                             [0U]))))) {
            if ((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                 [0U])) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                                          [0U]))))) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v2 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__0;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v2 
                        = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                           [0U]);
                    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v2, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v2));
                }
            } else {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                                          [0U]))))) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v3 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__1;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v3 
                        = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                           [0U]);
                    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v3, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v3));
                }
            }
        }
        if (((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
              [1U] & (0xfffU != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                      [1U])) & (~ ((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                                    [1U]) & (2U == 
                                             vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                                             [1U]))))) {
            if ((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                 [1U])) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                                          [1U]))))) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v4 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__0;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v4 
                        = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                           [1U]);
                    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v4, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v4));
                }
            } else {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                                          [1U]))))) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v5 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__1;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v5 
                        = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                           [1U]);
                    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v5, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v5));
                }
            }
        }
        if (((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
              [2U] & (0xfffU != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                      [2U])) & (~ ((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                                    [2U]) & (2U == 
                                             vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                                             [2U]))))) {
            if ((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                 [2U])) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                                          [2U]))))) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v6 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__0;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v6 
                        = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                           [2U]);
                    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v6, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v6));
                }
            } else {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                                          [2U]))))) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v7 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__1;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v7 
                        = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                           [2U]);
                    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v7, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v7));
                }
            }
        }
        if (((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
              [3U] & (0xfffU != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                      [3U])) & (~ ((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                                    [3U]) & (2U == 
                                             vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                                             [3U]))))) {
            if ((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                 [3U])) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__0 = 2U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                                          [3U]))))) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v8 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__0;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v8 
                        = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                           [3U]);
                    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v8, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v8));
                }
            } else {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__1 = 3U;
                if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                                          [3U]))))) {
                    __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v9 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h965a31be__1;
                    __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v9 
                        = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q
                           [3U]);
                    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v9, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v9));
                }
            }
        }
    } else {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__submit_seq_q = 0ULL;
        vlSelfRef.__Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_active_q = 0U;
        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q = 0U;
        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q = 0U;
        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_active_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_active_q = 0U;
        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q = 0U;
        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__cmd_id_lookup_rsp_valid = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__lookup_busy_q = 0U;
        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q = 0U;
        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_op_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q = 0U;
        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg1_q = 0U;
        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_data_q = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_release_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_ack_slot_q = 0U;
        __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_status_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_failure_seq_q = 0xffffffffffffffffULL;
        vlSelfRef.__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v22 = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__unnamedblk13__DOT__event_idx = 0U;
        while ((0xffU > vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__unnamedblk13__DOT__event_idx)) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_ha0a524a9__0 = 0U;
            if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__unnamedblk13__DOT__event_idx))))) {
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v10 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_ha0a524a9__0;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v10 
                    = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__unnamedblk13__DOT__event_idx);
                vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v10, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q__v10));
            }
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_haf1f49ed__0 = 0U;
            if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__unnamedblk13__DOT__event_idx))))) {
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v1 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_haf1f49ed__0;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v1 
                    = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__unnamedblk13__DOT__event_idx);
                vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v1, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q__v1));
            }
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h1fd80602__0 = 0U;
            if (VL_LIKELY(((0xfeU >= (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__unnamedblk13__DOT__event_idx))))) {
                __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v2 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____Vlvbound_h1fd80602__0;
                __VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v2 
                    = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__unnamedblk13__DOT__event_idx);
                vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q.enqueue(__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v2, (IData)(__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q__v2));
            }
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__unnamedblk13__DOT__event_idx 
                = ((IData)(1U) + vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__unnamedblk13__DOT__event_idx);
        }
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_op_q 
        = __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_op_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg1_q 
        = __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg1_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q 
        = __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_count_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q 
        = __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_slot_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q 
        = __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_slot_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q 
        = __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_slot_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q 
        = __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q 
        = __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q 
        = __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q;
    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q.commit(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q);
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q 
        = __Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q;
    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q.commit(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q);
    vlSelfRef.__VdlyCommitQueuetb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q.commit(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q);
    if (vlSelfRef.__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q__v0] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q__v0;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v0) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][1U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][2U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][3U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][4U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][5U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][6U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][7U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][8U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][9U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0xaU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0xbU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0xcU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0xdU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0xeU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0xfU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x10U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x11U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x12U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x13U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x14U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x15U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x16U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x17U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x18U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x19U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x1aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x1bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x1cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x1dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x1eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x1fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x20U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x21U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x22U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x23U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x24U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x25U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x26U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x27U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x28U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x29U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x2aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x2bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x2cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x2dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x2eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x2fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x30U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x31U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x32U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x33U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x34U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x35U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x36U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x37U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x38U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x39U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x3aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x3bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x3cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x3dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x3eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v0][0x3fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v0] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v0] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v0] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v0] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v0] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][1U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[1U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][2U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[2U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][3U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[3U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][4U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[4U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][5U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[5U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][6U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[6U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][7U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[7U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][8U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[8U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][9U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[9U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0xaU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0xaU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0xbU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0xbU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0xcU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0xcU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0xdU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0xdU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0xeU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0xeU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0xfU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0xfU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x10U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x10U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x11U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x11U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x12U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x12U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x13U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x13U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x14U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x14U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x15U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x15U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x16U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x16U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x17U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x17U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x18U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x18U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x19U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x19U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x1aU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x1aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x1bU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x1bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x1cU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x1cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x1dU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x1dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x1eU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x1eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x1fU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x1fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x20U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x20U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x21U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x21U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x22U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x22U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x23U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x23U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x24U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x24U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x25U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x25U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x26U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x26U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x27U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x27U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x28U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x28U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x29U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x29U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x2aU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x2aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x2bU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x2bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x2cU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x2cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x2dU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x2dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x2eU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x2eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x2fU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x2fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x30U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x30U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x31U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x31U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x32U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x32U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x33U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x33U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x34U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x34U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x35U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x35U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x36U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x36U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x37U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x37U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x38U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x38U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x39U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x39U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x3aU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x3aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x3bU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x3bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x3cU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x3cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x3dU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x3dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x3eU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x3eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1][0x3fU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v1[0x3fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v1] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v0] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v1] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v1] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v1;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q__v0] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q__v0;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v0] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v0;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v1] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v1;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q__v0] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q__v0;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q__v0] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q__v0;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q__v0] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q__v0;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q__v0] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q__v0;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q__v0] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q__v0;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v2] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v2;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v2] = 1U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v3] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v3;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v3] = 1U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v4) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[0U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[0U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v4;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[0U] = 1U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v5) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[1U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[1U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v5;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[1U] = 1U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v6) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[2U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[2U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v6;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[2U] = 1U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v7) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[3U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[3U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v7;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[3U] = 1U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v7) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v8] = 0U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v2) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v1] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v1;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v2] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v1] = 2U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v2] = 6U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v3) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v2] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v2;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v3] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v2] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v2;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v3] = 6U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][1U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[1U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][2U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[2U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][3U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[3U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][4U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[4U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][5U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[5U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][6U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[6U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][7U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[7U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][8U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[8U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][9U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[9U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0xaU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0xaU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0xbU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0xbU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0xcU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0xcU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0xdU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0xdU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0xeU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0xeU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0xfU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0xfU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x10U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x10U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x11U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x11U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x12U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x12U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x13U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x13U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x14U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x14U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x15U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x15U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x16U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x16U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x17U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x17U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x18U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x18U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x19U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x19U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x1aU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x1aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x1bU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x1bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x1cU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x1cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x1dU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x1dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x1eU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x1eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x1fU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x1fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x20U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x20U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x21U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x21U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x22U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x22U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x23U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x23U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x24U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x24U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x25U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x25U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x26U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x26U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x27U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x27U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x28U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x28U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x29U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x29U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x2aU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x2aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x2bU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x2bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x2cU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x2cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x2dU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x2dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x2eU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x2eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x2fU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x2fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x30U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x30U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x31U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x31U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x32U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x32U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x33U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x33U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x34U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x34U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x35U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x35U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x36U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x36U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x37U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x37U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x38U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x38U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x39U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x39U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x3aU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x3aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x3bU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x3bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x3cU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x3cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x3dU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x3dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x3eU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x3eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2][0x3fU] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q__v2[0x3fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v4] = 2U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v5) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[0U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[0U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[0U] = 8U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[0U] = 6U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v7) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[1U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[1U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[1U] = 8U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v9) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[2U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[2U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[2U] = 8U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v11) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[3U] = 0ULL;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v7) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v7] = 0ULL;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v11) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[3U] = 0ULL;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v7) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v8] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v8] = 1U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v0) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q[0U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v0;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q[1U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v1;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q[2U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v2;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q[3U] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q__v3;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v11) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[3U] = 8U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v7) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v8] = 0U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v9) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v10] = 0U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v9] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v8] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v8;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v9] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v9;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v11] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v11;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v7) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v7] = 0U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v8) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v8] = 2U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v9) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v9] = 0U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v9] = 1U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q__v10] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v9] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q__v9;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v10] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q__v10;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v12] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v12;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v10] = 1U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v11) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q__v11] = 0U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v6) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[0U] = 3U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v7) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[1U] = 6U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v8) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[1U] = 3U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v9) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[2U] = 6U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v10) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[2U] = 3U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v11) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[3U] = 6U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v12) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[3U] = 3U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v7) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v13] = 5U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q__v9) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v14] = 6U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v9) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v15] = 5U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v16) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v16] = 4U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v17) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v17] = 4U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v18) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v18] = 4U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v19) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v19] = 4U;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v10) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v20] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v20;
    }
    if (__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q__v11) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v21] 
            = __VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v21;
    }
    if (vlSelfRef.__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v22) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q[0U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q[1U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q[2U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_signal_q[3U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][1U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][2U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][3U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][4U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][5U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][6U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][7U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][8U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][9U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0xaU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0xbU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0xcU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0xdU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0xeU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0xfU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x10U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x11U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x12U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x13U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x14U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x15U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x16U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x17U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x18U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x19U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x1aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x1bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x1cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x1dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x1eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x1fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x20U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x21U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x22U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x23U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x24U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x25U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x26U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x27U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x28U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x29U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x2aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x2bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x2cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x2dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x2eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x2fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x30U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x31U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x32U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x33U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x34U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x35U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x36U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x37U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x38U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x39U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x3aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x3bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x3cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x3dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x3eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[0U][0x3fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][1U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][2U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][3U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][4U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][5U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][6U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][7U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][8U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][9U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0xaU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0xbU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0xcU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0xdU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0xeU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0xfU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x10U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x11U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x12U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x13U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x14U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x15U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x16U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x17U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x18U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x19U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x1aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x1bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x1cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x1dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x1eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x1fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x20U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x21U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x22U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x23U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x24U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x25U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x26U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x27U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x28U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x29U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x2aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x2bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x2cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x2dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x2eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x2fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x30U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x31U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x32U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x33U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x34U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x35U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x36U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x37U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x38U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x39U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x3aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x3bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x3cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x3dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x3eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[1U][0x3fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][1U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][2U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][3U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][4U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][5U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][6U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][7U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][8U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][9U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0xaU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0xbU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0xcU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0xdU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0xeU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0xfU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x10U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x11U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x12U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x13U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x14U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x15U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x16U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x17U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x18U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x19U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x1aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x1bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x1cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x1dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x1eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x1fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x20U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x21U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x22U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x23U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x24U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x25U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x26U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x27U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x28U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x29U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x2aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x2bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x2cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x2dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x2eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x2fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x30U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x31U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x32U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x33U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x34U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x35U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x36U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x37U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x38U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x39U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x3aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x3bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x3cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x3dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x3eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[2U][0x3fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][1U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[1U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][2U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[2U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][3U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[3U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][4U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[4U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][5U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[5U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][6U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[6U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][7U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[7U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][8U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[8U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][9U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[9U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0xaU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xaU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0xbU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xbU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0xcU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xcU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0xdU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xdU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0xeU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xeU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0xfU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0xfU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x10U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x10U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x11U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x11U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x12U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x12U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x13U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x13U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x14U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x14U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x15U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x15U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x16U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x16U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x17U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x17U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x18U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x18U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x19U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x19U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x1aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x1bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x1cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x1dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x1eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x1fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x1fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x20U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x20U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x21U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x21U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x22U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x22U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x23U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x23U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x24U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x24U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x25U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x25U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x26U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x26U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x27U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x27U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x28U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x28U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x29U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x29U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x2aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x2bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x2cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x2dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x2eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x2fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x2fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x30U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x30U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x31U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x31U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x32U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x32U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x33U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x33U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x34U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x34U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x35U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x35U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x36U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x36U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x37U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x37U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x38U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x38U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x39U] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x39U];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x3aU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3aU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x3bU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3bU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x3cU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3cU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x3dU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3dU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x3eU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3eU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q[3U][0x3fU] 
            = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[0x3fU];
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[0U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[1U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[2U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_done_flags_q[3U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[0U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[1U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[2U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_fault_addr_q[3U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q[0U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q[1U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q[2U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q[3U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[0U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[1U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[2U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q[3U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[0U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[1U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[2U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_error_info_q[3U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q[0U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q[1U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q[2U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q[3U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[0U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[1U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[2U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q[3U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[0U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[1U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[2U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q[3U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q[0U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q[1U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q[2U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q[3U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q[0U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q[1U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q[2U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q[3U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q[0U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q[1U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q[2U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q[3U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q[0U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q[1U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q[2U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q[3U] = 0xfffU;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q[0U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q[1U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q[2U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q[3U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[0U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[1U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[2U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q[3U] = 0U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_ready 
        = (1U & (~ ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_active_q) 
                    | (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_rsp_valid_q))));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_found = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_terminal = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_state = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_producer = 0U;
    if (((((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q)) 
           & (0xffU > (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q)))) 
          & (((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q)))
               ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
              [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q))]
               : 0U) == (0xfU & ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q) 
                                 >> 8U)))) & (0U != 
                                              ((0xfeU 
                                                >= 
                                                (0xffU 
                                                 & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q)))
                                                ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                               [(0xffU 
                                                 & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q))]
                                                : 0U)))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_terminal 
            = ((2U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q)))
                        ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                       [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q))]
                        : 0U)) | (3U == ((0xfeU >= 
                                          (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q)))
                                          ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                         [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q))]
                                          : 0U)));
        if ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q)))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_state 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q))];
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_producer 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_producer_q
                [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_arg0_q))];
        } else {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_state = 0U;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_wait_event_producer = 0U;
        }
    }
    if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__reset_n) {
        if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_pending_q) {
            vlSelfRef.__Vdly__tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_valid = 1U;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_command_id 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_pending_command_id_q;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_status = 0U;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_fault_addr = 0ULL;
            IData/*31:0*/ __Vilp4;
            __Vilp4 = 0U;
            while ((__Vilp4 <= 0x3fU)) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_desc_flat[__Vilp4] 
                    = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[__Vilp4];
                __Vilp4 = ((IData)(1U) + __Vilp4);
            }
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_desc_flat[0xfU] 
                = (0xabcde000U | (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_pending_command_id_q));
        } else {
            vlSelfRef.__Vdly__tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_valid = 0U;
        }
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_pending_q = 0U;
        if (((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_valid) 
             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_ready))) {
            if (VL_UNLIKELY(((1U & (((0ULL != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select]) 
                                     | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                                        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select] 
                                        >> 5U)) | (~ 
                                                   (((1U 
                                                      == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_command_id)) 
                                                     & (1U 
                                                        == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_engine))) 
                                                    | ((2U 
                                                        == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_command_id)) 
                                                       & (2U 
                                                          == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_engine)))))))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_scheduler_ctl_smoke.sv:288: Assertion failed in %Ntb_scheduler_ctl_smoke: descriptor-fetch request fields are incorrect\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("control/tb_scheduler_ctl_smoke.sv", 288, "", false);
            }
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_pending_q = 1U;
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_pending_command_id_q 
                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_command_id;
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_valid) 
                          & (~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_active_q)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: tb_scheduler_ctl_smoke.sv:294: Assertion failed in %Ntb_scheduler_ctl_smoke: scheduler did not accept a descriptor response\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name());
            VL_STOP_MT("control/tb_scheduler_ctl_smoke.sv", 294, "", false);
        }
    } else {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_pending_q = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_pending_command_id_q = 0U;
        vlSelfRef.__Vdly__tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_valid = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_command_id = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_status = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_fault_addr = 0ULL;
        IData/*31:0*/ __Vilp5;
        __Vilp5 = 0U;
        while ((__Vilp5 <= 0x3fU)) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_desc_flat[__Vilp5] 
                = Vtb_scheduler_ctl_smoke__ConstPool__CONST_h6be9aa18_0[__Vilp5];
            __Vilp5 = ((IData)(1U) + __Vilp5);
        }
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_found = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select = 0U;
    if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
        [0U]) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select = 0U;
    }
    if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
         [1U] & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select = 1U;
    }
    if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
         [2U] & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select = 2U;
    }
    if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
         [3U] & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select = 3U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__task_occupancy = 0U;
    if ((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
         [0U])) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
         [1U])) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
         [2U])) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
         [3U])) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__task_occupancy)));
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_found = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot = 0U;
    if ((0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
         [0U])) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot = 0U;
    }
    if (((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_found)) 
         & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [1U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot = 1U;
    }
    if (((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_found)) 
         & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [2U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot = 2U;
    }
    if (((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_found)) 
         & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [3U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__free_slot = 3U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_pending = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_status 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_status_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_seq 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_failure_seq_q;
    if ((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q) 
          & (0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
             [0U])) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                       [0U] == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q
                       [0U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                  [0U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                           [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                    [0U];
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [0U];
            }
        } else {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q) 
           >> 1U) & (0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                     [1U])) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                               [1U] == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q
                               [1U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                  [1U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                           [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                    [1U];
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [1U];
            }
        } else {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
}
