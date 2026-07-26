// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_inline_scheduler_smoke.h for the primary calling header

#include "Vtb_inline_scheduler_smoke__pch.h"
#include "Vtb_inline_scheduler_smoke___024root.h"

VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___eval_static(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_static\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_inline_scheduler_smoke__DOT__clk__0 
        = vlSelfRef.tb_inline_scheduler_smoke__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_inline_scheduler_smoke__DOT__reset_n__0 
        = vlSelfRef.tb_inline_scheduler_smoke__DOT__reset_n;
    vlSelfRef.__Vtrigprevexpr_ha64895be__1 = (2U == 
                                              vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                              [7U]);
    vlSelfRef.__Vtrigprevexpr_h5500e8de__1 = ((0U == 
                                               vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                               [7U]) 
                                              & (1U 
                                                 == 
                                                 vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                                                 [7U]));
    vlSelfRef.__Vtrigprevexpr_h0d5889ad__1 = (((((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_active_q)) 
                                                 & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dma_select_found)) 
                                                & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_active_q)) 
                                                   & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__matrix_select_found))) 
                                               & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_active_q)) 
                                                  & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__vector_select_found))) 
                                              & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_active_q)) 
                                                 & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found)));
}

VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___eval_final(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_final\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___dump_triggers__stl(Vtb_inline_scheduler_smoke___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_inline_scheduler_smoke___024root___eval_phase__stl(Vtb_inline_scheduler_smoke___024root* vlSelf);

VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___eval_settle(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_settle\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_inline_scheduler_smoke___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("control/tb_inline_scheduler_smoke.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_inline_scheduler_smoke___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___dump_triggers__stl(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___dump_triggers__stl\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__0(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__0\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*11:0*/ __Vfunc_npu_cmd_command_id__29__Vfuncout;
    __Vfunc_npu_cmd_command_id__29__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_command_id__29__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_command_id__29__command);
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_header_flags__30__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_header_flags__30__command);
    // Body
    vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy = 0U;
    if ((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
         [0U])) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
         [1U])) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
         [2U])) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
         [3U])) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
         [4U])) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
         [5U])) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
         [6U])) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
         [7U])) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__task_occupancy)));
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_slot = 0U;
    if ((0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
         [0U])) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_slot = 0U;
    }
    if (((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)) 
         & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [1U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_slot = 1U;
    }
    if (((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)) 
         & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [2U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_slot = 2U;
    }
    if (((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)) 
         & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [3U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_slot = 3U;
    }
    if (((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)) 
         & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [4U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_slot = 4U;
    }
    if (((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)) 
         & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [5U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_slot = 5U;
    }
    if (((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)) 
         & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [6U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_slot = 6U;
    }
    if (((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found)) 
         & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [7U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__free_slot = 7U;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_found = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_terminal = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_state = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_producer = 0U;
    if (((((0xfffU != (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q)) 
           & (0xffU > (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q)))) 
          & (((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q)))
               ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
              [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q))]
               : 0U) == (0xfU & ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q) 
                                 >> 8U)))) & (0U != 
                                              ((0xfeU 
                                                >= 
                                                (0xffU 
                                                 & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q)))
                                                ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                               [(0xffU 
                                                 & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q))]
                                                : 0U)))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_terminal 
            = ((2U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q)))
                        ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                       [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q))]
                        : 0U)) | (3U == ((0xfeU >= 
                                          (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q)))
                                          ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                         [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q))]
                                          : 0U)));
        if ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q)))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_state 
                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q))];
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_producer 
                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_producer_q
                [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_arg0_q))];
        } else {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_state = 0U;
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_wait_event_producer = 0U;
        }
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select = 0U;
    if (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
        [0U]) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select = 0U;
    }
    if ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
         [1U] & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found)) 
                 | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select = 1U;
    }
    if ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
         [2U] & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found)) 
                 | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select = 2U;
    }
    if ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
         [3U] & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found)) 
                 | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select = 3U;
    }
    if ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
         [4U] & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found)) 
                 | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select = 4U;
    }
    if ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
         [5U] & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found)) 
                 | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select = 5U;
    }
    if ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
         [6U] & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found)) 
                 | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select = 6U;
    }
    if ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
         [7U] & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found)) 
                 | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__completion_select = 7U;
    }
    __Vfunc_npu_cmd_command_id__29__command[0U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_command_id__29__command[1U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_command_id__29__command[2U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_command_id__29__command[3U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U];
    __Vfunc_npu_cmd_command_id__29__Vfuncout = (0xfffU 
                                                & ((__Vfunc_npu_cmd_command_id__29__command[3U] 
                                                    >> 0x1fU)
                                                    ? 
                                                   (0x3ffU 
                                                    & (__Vfunc_npu_cmd_command_id__29__command[3U] 
                                                       >> 0x10U))
                                                    : 
                                                   ((__Vfunc_npu_cmd_command_id__29__command[1U] 
                                                     << 0x10U) 
                                                    | (__Vfunc_npu_cmd_command_id__29__command[1U] 
                                                       >> 0x10U))));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_command_id 
        = __Vfunc_npu_cmd_command_id__29__Vfuncout;
    __Vfunc_npu_cmd_header_flags__30__command[0U] = 
        vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_header_flags__30__command[1U] = 
        vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_header_flags__30__command[2U] = 
        vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_header_flags__30__command[3U] = 
        vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U];
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_npu_cmd_header_flags__30__flags = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17311288755175545044ull);
    {
        if ((1U & (~ (__Vfunc_npu_cmd_header_flags__30__command[3U] 
                      >> 0x1fU)))) {
            vlSelfRef.__Vfunc_npu_cmd_header_flags__30__Vfuncout 
                = (0xfffU & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                             >> 8U));
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags = 0U;
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags 
            = ((0xff8U & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags)) 
               | ((4U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                         >> 0x13U)) | ((2U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                                              >> 0x15U)) 
                                       | (1U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                                                >> 0x17U)))));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags 
            = ((0xfefU & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags)) 
               | (0x10U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                           >> 0x10U)));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags 
            = ((0xf3fU & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags)) 
               | (0xc0U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                           >> 0xcU)));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__Vfuncout 
            = vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags;
        __Vlabel0: ;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_header_flags 
        = vlSelfRef.__Vfunc_npu_cmd_header_flags__30__Vfuncout;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select = 0U;
    if ((1U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
         [0U])) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select = 0U;
    }
    if (((1U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [1U]) & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found)) 
                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select = 1U;
    }
    if (((1U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [2U]) & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found)) 
                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select = 2U;
    }
    if (((1U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [3U]) & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found)) 
                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select = 3U;
    }
    if (((1U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [4U]) & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found)) 
                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select = 4U;
    }
    if (((1U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [5U]) & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found)) 
                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select = 5U;
    }
    if (((1U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [6U]) & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found)) 
                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select = 6U;
    }
    if (((1U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [7U]) & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found)) 
                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select])))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found = 1U;
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_select = 7U;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_pending = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_status 
        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_status_q;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq 
        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_failure_seq_q;
    if ((((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_q) 
          & (0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
             [0U])) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                       [0U] == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_seq_q
                       [0U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                  [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                           [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                    [0U];
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [0U];
            }
        } else {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_q) 
           >> 1U) & (0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                     [1U])) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                               [1U] == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_seq_q
                               [1U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                  [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                           [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                    [1U];
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [1U];
            }
        } else {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_q) 
           >> 2U) & (0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                     [2U])) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                               [2U] == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_seq_q
                               [2U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                  [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                           [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                    [2U];
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [2U];
            }
        } else {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_q) 
           >> 3U) & (0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                     [3U])) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                               [3U] == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_seq_q
                               [3U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                  [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                           [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                    [3U];
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [3U];
            }
        } else {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_q) 
           >> 4U) & (0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                     [4U])) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                               [4U] == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_seq_q
                               [4U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                        [4U];
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                  [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                           [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                    [4U];
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [4U];
            }
        } else {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_q) 
           >> 5U) & (0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                     [5U])) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                               [5U] == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_seq_q
                               [5U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                        [5U];
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                  [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                           [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                    [5U];
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [5U];
            }
        } else {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_q) 
           >> 6U) & (0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                     [6U])) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                               [6U] == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_seq_q
                               [6U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                        [6U];
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                  [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                           [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                    [6U];
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [6U];
            }
        } else {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_q) 
           >> 7U) & (0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                     [7U])) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                               [7U] == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_target_seq_q
                               [7U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                        [7U];
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                  [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                           [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_status_q
                    [7U];
                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                    [7U];
            }
        } else {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ctl_fence_pending = 1U;
        }
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found = 0U;
    if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [0U]) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                   [0U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select = 0U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
             [0U])) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                       [0U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found = 1U;
    }
    if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [1U]) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                   [1U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select = 1U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
             [1U])) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                       [1U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found = 1U;
    }
    if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [2U]) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                   [2U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select = 2U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
             [2U])) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                       [2U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found = 1U;
    }
    if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [3U]) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                   [3U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select = 3U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
             [3U])) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                       [3U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found = 1U;
    }
    if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [4U]) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                   [4U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select = 4U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
             [4U])) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                       [4U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found = 1U;
    }
    if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [5U]) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                   [5U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select = 5U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
             [5U])) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                       [5U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found = 1U;
    }
    if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [6U]) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                   [6U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select = 6U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
             [6U])) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                       [6U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found = 1U;
    }
    if (((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [7U]) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                   [7U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select = 7U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_notify_q
             [7U])) & (0U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_command_id_q
                       [7U]))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__ack_found = 1U;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_success[0U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel1;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel1: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel2;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel2;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel2: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_failed[0U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel3;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel3: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel4;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel4;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel4: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 0U;
    if ((1U & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                [0U] >> 4U) | (4U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                               [0U])))) {
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[0U] = 1U;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_success[1U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel5;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel5;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel5: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel6;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel6;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel6: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_failed[1U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel7;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel7;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel7: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel8;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel8;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel8: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 0U;
    if ((1U & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                [1U] >> 4U) | (4U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                               [1U])))) {
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[1U] = 1U;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_success[2U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel9;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel9;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel9: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel10;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel10;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel10: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_failed[2U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel11;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel11;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel11: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel12;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel12;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel12: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 0U;
    if ((1U & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                [2U] >> 4U) | (4U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                               [2U])))) {
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[2U] = 1U;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_success[3U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel13;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel13;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel13: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel14;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel14;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel14: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_failed[3U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel15;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel15;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel15: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel16;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel16;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel16: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 0U;
    if ((1U & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                [3U] >> 4U) | (4U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                               [3U])))) {
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
        }
    }
}

VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__1(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__1\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*11:0*/ __Vfunc_npu_cmd_wait0__31__Vfuncout;
    __Vfunc_npu_cmd_wait0__31__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_wait0__31__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_wait0__31__command);
    SData/*11:0*/ __Vfunc_npu_cmd_wait1__33__Vfuncout;
    __Vfunc_npu_cmd_wait1__33__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_wait1__33__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_wait1__33__command);
    SData/*11:0*/ __Vfunc_npu_cmd_signal__35__Vfuncout;
    __Vfunc_npu_cmd_signal__35__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_signal__35__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_signal__35__command);
    CData/*3:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__state;
    __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__state = 0;
    // Body
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[3U] = 1U;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_success[4U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel0;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel0;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel0: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel1;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel1: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_failed[4U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel2;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel2;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel2: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel3;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel3: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 0U;
    if ((1U & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                [4U] >> 4U) | (4U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                               [4U])))) {
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[4U] = 1U;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_success[5U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [5U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel4;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel4;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel4: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [5U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel5;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel5;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel5: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_failed[5U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [5U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel6;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel6;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel6: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [5U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel7;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel7;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel7: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 0U;
    if ((1U & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                [5U] >> 4U) | (4U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                               [5U])))) {
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[5U] = 1U;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_success[6U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [6U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel8;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel8;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel8: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [6U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel9;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel9;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel9: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_failed[6U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [6U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel10;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel10;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel10: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [6U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel11;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel11;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel11: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 0U;
    if ((1U & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                [6U] >> 4U) | (4U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                               [6U])))) {
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[6U] = 1U;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_success[7U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [7U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel12;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel12;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel12: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [7U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel13;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel13;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel13: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__dependency_failed[7U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                    [7U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel14;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel14;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel14: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                    [7U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel15;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel15;
                    }
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel15: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 0U;
    if ((1U & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                [7U] >> 4U) | (4U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_opcode_q
                               [7U])))) {
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked[7U] = 1U;
    }
    __Vfunc_npu_cmd_wait0__31__command[0U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_wait0__31__command[1U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_wait0__31__command[2U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_wait0__31__command[3U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U];
    __Vfunc_npu_cmd_wait0__31__Vfuncout = (0xfffU & 
                                           ((__Vfunc_npu_cmd_wait0__31__command[3U] 
                                             >> 0x1fU)
                                             ? ([&]() {
                    vlSelfRef.__Vfunc_npu_v2_event_ref__32__event_id 
                        = (0xffU & (__Vfunc_npu_cmd_wait0__31__command[3U] 
                                    >> 8U));
                    vlSelfRef.__Vfunc_npu_v2_event_ref__32__Vfuncout 
                        = ((0xffU == (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__32__event_id))
                            ? 0xfffU : (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__32__event_id));
                }(), (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__32__Vfuncout))
                                             : ((__Vfunc_npu_cmd_wait0__31__command[2U] 
                                                 << 0xcU) 
                                                | (__Vfunc_npu_cmd_wait0__31__command[2U] 
                                                   >> 0x14U))));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0 
        = __Vfunc_npu_cmd_wait0__31__Vfuncout;
    __Vfunc_npu_cmd_wait1__33__command[0U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_wait1__33__command[1U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_wait1__33__command[2U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_wait1__33__command[3U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U];
    __Vfunc_npu_cmd_wait1__33__Vfuncout = (0xfffU & 
                                           ((__Vfunc_npu_cmd_wait1__33__command[3U] 
                                             >> 0x1fU)
                                             ? ([&]() {
                    vlSelfRef.__Vfunc_npu_v2_event_ref__34__event_id 
                        = (0xffU & __Vfunc_npu_cmd_wait1__33__command[3U]);
                    vlSelfRef.__Vfunc_npu_v2_event_ref__34__Vfuncout 
                        = ((0xffU == (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__34__event_id))
                            ? 0xfffU : (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__34__event_id));
                }(), (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__34__Vfuncout))
                                             : __Vfunc_npu_cmd_wait1__33__command[3U]));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1 
        = __Vfunc_npu_cmd_wait1__33__Vfuncout;
    __Vfunc_npu_cmd_signal__35__command[0U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_signal__35__command[1U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_signal__35__command[2U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_signal__35__command[3U] = vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U];
    __Vfunc_npu_cmd_signal__35__Vfuncout = (0xfffU 
                                            & ((__Vfunc_npu_cmd_signal__35__command[3U] 
                                                >> 0x1fU)
                                                ? ([&]() {
                    vlSelfRef.__Vfunc_npu_v2_event_ref__36__event_id 
                        = (__Vfunc_npu_cmd_signal__35__command[2U] 
                           >> 0x18U);
                    vlSelfRef.__Vfunc_npu_v2_event_ref__36__Vfuncout 
                        = ((0xffU == (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__36__event_id))
                            ? 0xfffU : (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__36__event_id));
                }(), (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__36__Vfuncout))
                                                : (
                                                   (__Vfunc_npu_cmd_signal__35__command[3U] 
                                                    << 0x14U) 
                                                   | (__Vfunc_npu_cmd_signal__35__command[3U] 
                                                      >> 0xcU))));
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal 
        = __Vfunc_npu_cmd_signal__35__Vfuncout;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__df_fetch_valid 
        = ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_active_q)) 
           & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__fetch_found));
    __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__state 
        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
        [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__query_select];
    {
        if ((0U == (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__state))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__Vfuncout = 0U;
            goto __Vlabel16;
        }
        if ((4U == (IData)(__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__state))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__Vfuncout = 2U;
            goto __Vlabel16;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__56__state 
                        = __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__state;
                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__56__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__56__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__56__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__56__Vfuncout))) {
            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__Vfuncout = 3U;
            goto __Vlabel16;
        }
        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__Vfuncout = 1U;
        __Vlabel16: ;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__task_query_state 
        = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__software_task_state__55__Vfuncout;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select = 0U;
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [0U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [0U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [0U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [1U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [1U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [2U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [2U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [2U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [3U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [3U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [3U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select = 3U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [4U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [4U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [4U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [4U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [4U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [4U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select = 4U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [5U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [5U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [5U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [5U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [5U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [5U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select = 5U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [6U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [6U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [6U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [6U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [6U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [6U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select = 6U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [7U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [7U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [7U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                          [7U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [7U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [7U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [7U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__control_select = 7U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found = 0U;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select = 0U;
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                 [0U])) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [0U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [0U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                 [1U])) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [1U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [1U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                 [2U])) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [2U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [2U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                 [3U])) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [3U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [3U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select = 3U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [4U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [4U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [4U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                 [4U])) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [4U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [4U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [4U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select = 4U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [5U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [5U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [5U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                 [5U])) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [5U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [5U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [5U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select = 5U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
          [6U]) & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__order_blocked
                   [6U]))) {
        if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                      [6U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                 [6U])) {
                if ((1U & (~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                              [6U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_engine_q
                               [6U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [6U] < vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select])))) {
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__complex_select = 6U;
                        }
                    }
                }
            }
        }
    }
}
