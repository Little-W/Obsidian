// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cmd_dfu_smoke.h for the primary calling header

#include "Vtb_cmd_dfu_smoke__pch.h"
#include "Vtb_cmd_dfu_smoke___024root.h"

VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___eval_static(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_static\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_cmd_dfu_smoke__DOT__clk__0 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_cmd_dfu_smoke__DOT__reset_n__0 
        = vlSelfRef.tb_cmd_dfu_smoke__DOT__reset_n;
    vlSelfRef.__Vtrigprevexpr_h9262126c__1 = (5U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q));
    vlSelfRef.__Vtrigprevexpr_h68bfd761__1 = (0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q));
    vlSelfRef.__Vtrigprevexpr_h6b2234f7__1 = (4U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q));
}

VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___eval_final(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_final\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___dump_triggers__stl(Vtb_cmd_dfu_smoke___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_cmd_dfu_smoke___024root___eval_phase__stl(Vtb_cmd_dfu_smoke___024root* vlSelf);

VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___eval_settle(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_settle\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_cmd_dfu_smoke___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("control/tb_cmd_dfu_smoke.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_cmd_dfu_smoke___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___dump_triggers__stl(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___dump_triggers__stl\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___stl_sequent__TOP__0(Vtb_cmd_dfu_smoke___024root* vlSelf);

VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___eval_stl(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_stl\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_cmd_dfu_smoke___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___eval_triggers__stl(Vtb_cmd_dfu_smoke___024root* vlSelf);

VL_ATTR_COLD bool Vtb_cmd_dfu_smoke___024root___eval_phase__stl(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_phase__stl\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_cmd_dfu_smoke___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_cmd_dfu_smoke___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___dump_triggers__act(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___dump_triggers__act\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_cmd_dfu_smoke.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_cmd_dfu_smoke.reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge tb_cmd_dfu_smoke.clk)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @( (3'h5 == tb_cmd_dfu_smoke.u_cfe.state_q))\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @( (4'h0 != tb_cmd_dfu_smoke.u_cfe.fifo_count_q))\n");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @( (3'h4 == tb_cmd_dfu_smoke.u_dfu.state_q))\n");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___dump_triggers__nba(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___dump_triggers__nba\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_cmd_dfu_smoke.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_cmd_dfu_smoke.reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge tb_cmd_dfu_smoke.clk)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @( (3'h5 == tb_cmd_dfu_smoke.u_cfe.state_q))\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @( (4'h0 != tb_cmd_dfu_smoke.u_cfe.fifo_count_q))\n");
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @( (3'h4 == tb_cmd_dfu_smoke.u_dfu.state_q))\n");
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___ctor_var_reset(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___ctor_var_reset\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb_cmd_dfu_smoke__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16252886987315409236ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5991474682464562905ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__cmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10864093833708373549ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__cmd_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15430526702770940563ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__cmd_first = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11888046832947137507ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__cmd_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11949729892575007283ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__cmd_rsp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11785362618342639743ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__ts_cmd_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6528190687017730393ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__lookup_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9313621423076365207ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__lookup_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15011249899118870364ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__lookup_rsp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5704211714270452137ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__lookup_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10937441410766897236ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__lookup_pending_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10690527568820061421ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__expected_lookup_id = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 2451285242467349643ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__cfe_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4434011635472143842ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__cmd_accepted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13208768725985516657ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__cfe_error_count = 0;
    vlSelf->tb_cmd_dfu_smoke__DOT__cmd_accepted_count = 0;
    vlSelf->tb_cmd_dfu_smoke__DOT__fetch_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4948929454497679794ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__fetch_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11096168077066139176ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__fetch_addr = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 17279016768248642340ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__fetch_id = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 14312004621655907662ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__fetch_engine = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13756081896270367725ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__fetch_crc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10068620302862786530ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__fetch_rsp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15418808879686684182ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__mem_req_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 794138853832777833ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__mem_req_addr = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 5358877213647497916ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__mem_rsp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6855218111699511223ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__mem_rsp_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15844775674486987769ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__mem_rsp_status = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3380862544006102797ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_cmd_dfu_smoke__DOT__descriptor_words[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4996785730974614083ull);
    }
    vlSelf->tb_cmd_dfu_smoke__DOT__mem_request_count = 0;
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2648339127085831455ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__low_word_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13431759551505034735ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__high_word_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 208203440258778381ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__response_status_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15031863544627999894ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__lookup_sent_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8619324435031123227ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__wait_high_count_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1211238814190020561ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_q[__Vi0], __VscopeHash, 8723983965595577813ull);
    }
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_valid_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1562262300535484900ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_wr_ptr_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14968754169023766958ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_rd_ptr_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8144082659529944260ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17172434330165774768ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__local_duplicate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14324349142649574119ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__header_format_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14748104636714387591ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__opcode_format_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 631142619574102695ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__input_handshake = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5164691124512288613ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4167518188202176608ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__enqueue_now = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6228079667940937698ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_cfe__DOT__candidate_command_id = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 9616777094258098280ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1244044114351293258ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_addr_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 2405053940853140165ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__command_id_q = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 3229577853357511098ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__engine_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16017887678410678286ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__crc_enable_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1879790546369678215ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__beat_index_q = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 11663544824485988898ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__total_beats_q = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 6933253028355350596ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__rsp_status_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11878913812212462797ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__fault_addr_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 17352047615839695848ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__desc_flat_q, __VscopeHash, 16807417276890451298ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__abort_pending_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15069293185750187629ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__expected_desc_bytes = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7476297513288292318ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__prefix_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11628953218093130369ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__mem_request_handshake = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13280905591159523735ull);
    vlSelf->tb_cmd_dfu_smoke__DOT__u_dfu__DOT__mem_response_handshake = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16413974330731347480ull);
    vlSelf->__Vfunc_npu_cmd_command_id__24__Vfuncout = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 98398424690795199ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__Vfunc_npu_cmd_command_id__24__command, __VscopeHash, 10144081561103733320ull);
    vlSelf->__Vfunc_npu_event_ref_valid__25__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10518827394403574886ull);
    vlSelf->__Vfunc_npu_event_ref_valid__25__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 1771035234759884756ull);
    vlSelf->__Vfunc_npu_event_ref_valid__26__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5432428254507677525ull);
    vlSelf->__Vfunc_npu_event_ref_valid__26__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4051359759823170551ull);
    vlSelf->__Vfunc_npu_event_ref_valid__27__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7321566189457090880ull);
    vlSelf->__Vfunc_npu_event_ref_valid__27__event_ref = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17703332214262350808ull);
    vlSelf->__Vfunc_npu_opcode_engine_valid__28__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 646029864682528779ull);
    vlSelf->__Vfunc_npu_opcode_engine_valid__28__engine = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4649973405178921501ull);
    vlSelf->__Vfunc_npu_opcode_engine_valid__28__opcode = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7649069602940896972ull);
    vlSelf->__Vfunc_npu_numeric_cfg_valid__35__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7469920593653348503ull);
    vlSelf->__Vfunc_npu_numeric_cfg_valid__35__cfg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 924157669528064198ull);
    vlSelf->__Vfunc_npu_numeric_cfg_valid__35__dtype_fields_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 997662774071596720ull);
    vlSelf->__Vfunc_npu_dtype_valid__36__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11282427578824801199ull);
    vlSelf->__Vfunc_npu_dtype_valid__36__dtype = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2348453980295890982ull);
    vlSelf->__Vfunc_npu_dtype_valid__37__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3997234950148887480ull);
    vlSelf->__Vfunc_npu_dtype_valid__37__dtype = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7443822348702859582ull);
    vlSelf->__Vfunc_npu_dtype_valid__38__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14515176525929243761ull);
    vlSelf->__Vfunc_npu_dtype_valid__38__dtype = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7442351705208895105ull);
    vlSelf->__Vfunc_npu_dtype_valid__39__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5128519829270757227ull);
    vlSelf->__Vfunc_npu_dtype_valid__39__dtype = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9879251098265809805ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_cmd_dfu_smoke__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6010626560764481782ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_cmd_dfu_smoke__DOT__reset_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11501596712831548805ull);
    vlSelf->__Vtrigprevexpr_h9262126c__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16378616844239261533ull);
    vlSelf->__Vtrigprevexpr_h68bfd761__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16295160026496765195ull);
    vlSelf->__Vtrigprevexpr_h6b2234f7__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 632453924128453437ull);
    vlSelf->__VactDidInit = 0;
}
