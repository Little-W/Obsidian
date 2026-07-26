// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_memory_smoke.h for the primary calling header

#include "Vtb_memory_smoke__pch.h"
#include "Vtb_memory_smoke___024root.h"

VL_ATTR_COLD void Vtb_memory_smoke___024root___eval_static(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_static\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__Vtrigprevexpr_h60c90f32__1 = (7U == (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__state_q));
}

VL_ATTR_COLD void Vtb_memory_smoke___024root___eval_final(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_final\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_memory_smoke___024root___dump_triggers__stl(Vtb_memory_smoke___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_memory_smoke___024root___eval_phase__stl(Vtb_memory_smoke___024root* vlSelf);

VL_ATTR_COLD void Vtb_memory_smoke___024root___eval_settle(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_settle\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_memory_smoke___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("memory/tb_memory_smoke.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_memory_smoke___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_memory_smoke___024root___dump_triggers__stl(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___dump_triggers__stl\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vtb_memory_smoke___024root___stl_sequent__TOP__0(Vtb_memory_smoke___024root* vlSelf);

VL_ATTR_COLD void Vtb_memory_smoke___024root___eval_stl(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_stl\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_memory_smoke___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_memory_smoke___024root___stl_sequent__TOP__0(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___stl_sequent__TOP__0\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_memory_smoke__DOT__u_l1__DOT__grant_found;
    tb_memory_smoke__DOT__u_l1__DOT__grant_found = 0;
    // Body
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
    tb_memory_smoke__DOT__u_l1__DOT__grant_found = 0U;
    vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client 
        = vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rr_client_q;
    if ((((0U >= (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rr_client_q)) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid)) 
         & ((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q)) 
            | (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_rsp_ready)))) {
        tb_memory_smoke__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client = 0U;
    }
    if ((((~ (IData)(tb_memory_smoke__DOT__u_l1__DOT__grant_found)) 
          & ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid) 
             >> 1U)) & ((~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 1U)) | ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_rsp_ready) 
                                       >> 1U)))) {
        tb_memory_smoke__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client = 1U;
    }
    if (((((~ (IData)(tb_memory_smoke__DOT__u_l1__DOT__grant_found)) 
           & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rr_client_q)) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid)) 
         & ((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q)) 
            | (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_rsp_ready)))) {
        tb_memory_smoke__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client = 0U;
    }
    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__aw_handshake 
        = ((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_awvalid) 
           & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_awready));
    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__w_handshake 
        = ((IData)(vlSelfRef.tb_memory_smoke__DOT__axi_wvalid) 
           & (IData)(vlSelfRef.tb_memory_smoke__DOT__axi_wready));
    vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
        = ((0x27U >= (0x3fU & ((IData)(0x14U) * (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client))))
            ? (0xfffffU & (IData)((vlSelfRef.tb_memory_smoke__DOT__l1_req_addr 
                                   >> (0x3fU & ((IData)(0x14U) 
                                                * (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client))))))
            : 0U);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_ready = 0U;
    if (tb_memory_smoke__DOT__u_l1__DOT__grant_found) {
        vlSelfRef.tb_memory_smoke__DOT__l1_req_ready 
            = ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_ready) 
               | (3U & ((IData)(1U) << (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client))));
    }
    vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__write_channels_done 
        = (((IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__aw_done_q) 
            | (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__aw_handshake)) 
           & ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__w_done_q) 
              | (IData)(vlSelfRef.tb_memory_smoke__DOT__u_mif__DOT__w_handshake)));
    vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_handshake 
        = ((IData)(tb_memory_smoke__DOT__u_l1__DOT__grant_found) 
           & (((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid) 
               & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_ready)) 
              >> (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client)));
}

VL_ATTR_COLD void Vtb_memory_smoke___024root___eval_triggers__stl(Vtb_memory_smoke___024root* vlSelf);

VL_ATTR_COLD bool Vtb_memory_smoke___024root___eval_phase__stl(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_phase__stl\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_memory_smoke___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_memory_smoke___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_memory_smoke___024root___dump_triggers__act(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___dump_triggers__act\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_memory_smoke.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_memory_smoke.reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge tb_memory_smoke.clk)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__0__client[0]+:1])\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__1__client[0]+:1])\n");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__2__client[0]+:1])\n");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__3__client[0]+:1])\n");
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__4__client[0]+:1])\n");
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @( tb_memory_smoke.u_tbu_direct.rsp_valid_q)\n");
    }
    if ((0x200ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @( (3'h7 == tb_memory_smoke.u_mif.state_q))\n");
    }
    if ((0x400ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 10 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_memory_smoke___024root___dump_triggers__nba(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___dump_triggers__nba\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_memory_smoke.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_memory_smoke.reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge tb_memory_smoke.clk)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__0__client[0]+:1])\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__1__client[0]+:1])\n");
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__2__client[0]+:1])\n");
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__3__client[0]+:1])\n");
    }
    if ((0x80ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__4__client[0]+:1])\n");
    }
    if ((0x100ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @( tb_memory_smoke.u_tbu_direct.rsp_valid_q)\n");
    }
    if ((0x200ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @( (3'h7 == tb_memory_smoke.u_mif.state_q))\n");
    }
    if ((0x400ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 10 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_memory_smoke___024root___ctor_var_reset(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___ctor_var_reset\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb_memory_smoke__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18326061241914626409ull);
    vlSelf->tb_memory_smoke__DOT__reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10805688062063490101ull);
    vlSelf->tb_memory_smoke__DOT__l1_req_valid = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10335311254436124045ull);
    vlSelf->tb_memory_smoke__DOT__l1_req_ready = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12010897574132659766ull);
    vlSelf->tb_memory_smoke__DOT__l1_req_write = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 624111642890862904ull);
    vlSelf->tb_memory_smoke__DOT__l1_req_addr = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 11711825979361598329ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_memory_smoke__DOT__l1_req_wdata, __VscopeHash, 5340087266562909307ull);
    vlSelf->tb_memory_smoke__DOT__l1_req_wstrb = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14563673116877532244ull);
    vlSelf->tb_memory_smoke__DOT__l1_rsp_ready = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15161337858084153361ull);
    vlSelf->tb_memory_smoke__DOT__tbu_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10505492334750736765ull);
    vlSelf->tb_memory_smoke__DOT__tbu_allow_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14510916249552710227ull);
    vlSelf->tb_memory_smoke__DOT__tbu_allow_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17166044532352669046ull);
    vlSelf->tb_memory_smoke__DOT__tbu_req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16024739574058752036ull);
    vlSelf->tb_memory_smoke__DOT__tbu_req_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7693116120357720214ull);
    vlSelf->tb_memory_smoke__DOT__tbu_req_addr = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 16509489216981792796ull);
    vlSelf->tb_memory_smoke__DOT__mif_req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6683438372496812022ull);
    vlSelf->tb_memory_smoke__DOT__mif_req_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2045069332279409422ull);
    vlSelf->tb_memory_smoke__DOT__mif_req_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3613288207679388132ull);
    vlSelf->tb_memory_smoke__DOT__mif_req_addr = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 10135000776836328667ull);
    vlSelf->tb_memory_smoke__DOT__mif_req_wdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7631405916384728073ull);
    vlSelf->tb_memory_smoke__DOT__mif_req_wstrb = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6302594109573908689ull);
    vlSelf->tb_memory_smoke__DOT__mif_rsp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2337957322855969750ull);
    vlSelf->tb_memory_smoke__DOT__mif_tbu_req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4780891259672920831ull);
    vlSelf->tb_memory_smoke__DOT__mif_tbu_req_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9471839930506470258ull);
    vlSelf->tb_memory_smoke__DOT__mif_tbu_rsp_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3678486468142817796ull);
    vlSelf->tb_memory_smoke__DOT__axi_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15238196756982608199ull);
    vlSelf->tb_memory_smoke__DOT__axi_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15086900287175538052ull);
    vlSelf->tb_memory_smoke__DOT__axi_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5271711260291113339ull);
    vlSelf->tb_memory_smoke__DOT__axi_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6479727355599017890ull);
    vlSelf->tb_memory_smoke__DOT__axi_bid = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1534415429825763442ull);
    vlSelf->tb_memory_smoke__DOT__axi_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18307226049627403001ull);
    vlSelf->tb_memory_smoke__DOT__axi_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9833626710000241104ull);
    vlSelf->tb_memory_smoke__DOT__axi_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 418882345221766520ull);
    vlSelf->tb_memory_smoke__DOT__axi_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6841026872832968761ull);
    vlSelf->tb_memory_smoke__DOT__axi_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15799122943544218248ull);
    vlSelf->tb_memory_smoke__DOT__axi_rid = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9394510624512284451ull);
    vlSelf->tb_memory_smoke__DOT__axi_rdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8876559583592436980ull);
    vlSelf->tb_memory_smoke__DOT__axi_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11821645345196900800ull);
    vlSelf->tb_memory_smoke__DOT__axi_rlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7338799364522179644ull);
    vlSelf->tb_memory_smoke__DOT__axi_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6937820998838499101ull);
    vlSelf->tb_memory_smoke__DOT__axi_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8045657285111085154ull);
    vlSelf->tb_memory_smoke__DOT__aw_seen_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4090039964870284032ull);
    vlSelf->tb_memory_smoke__DOT__w_seen_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10365492423126352781ull);
    vlSelf->tb_memory_smoke__DOT__next_read_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11900000672784688525ull);
    vlSelf->tb_memory_smoke__DOT__read_count = 0;
    vlSelf->tb_memory_smoke__DOT__write_count = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->tb_memory_smoke__DOT__u_l1__DOT__sram_q[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16942858302240094138ull);
        }
    }
    vlSelf->tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16835076581636999808ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_memory_smoke__DOT__u_l1__DOT__rsp_data_q[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3232155511890576624ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_memory_smoke__DOT__u_l1__DOT__rsp_status_q[__Vi0] = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9610555670777242141ull);
    }
    vlSelf->tb_memory_smoke__DOT__u_l1__DOT__rr_client_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1679332462657452994ull);
    vlSelf->tb_memory_smoke__DOT__u_l1__DOT__grant_client = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11155186830346278000ull);
    vlSelf->tb_memory_smoke__DOT__u_l1__DOT__grant_addr = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 500748061273186499ull);
    vlSelf->tb_memory_smoke__DOT__u_l1__DOT__grant_handshake = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12503024539515822479ull);
    vlSelf->tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11924630659310175949ull);
    vlSelf->tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_addr_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3219495748504150737ull);
    vlSelf->tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_status_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15219031249430154596ull);
    vlSelf->tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13601576931212781859ull);
    vlSelf->tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_addr_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13857890263459728757ull);
    vlSelf->tb_memory_smoke__DOT__u_tbu_mif__DOT__rsp_status_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6650598386872922804ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__state_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 767128091382434731ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__req_write_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9180135993295766765ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__req_addr_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 6449406855582291299ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__req_wdata_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5434490957908738147ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__req_wstrb_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12642355385564247430ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__stream_id_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1424644803236129481ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__substream_id_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12198290749286441884ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__translated_addr_q = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 9005392343537729408ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__aw_done_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17311467253466781032ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__w_done_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14418279421827236835ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__rsp_rdata_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5169092115765826596ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__rsp_status_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13810989656892612121ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__error_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6143509944212445791ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__error_addr_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 14585436036211976132ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__error_status_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8549159339079018117ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__aw_handshake = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10251880820654117139ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__w_handshake = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14536516946161229865ull);
    vlSelf->tb_memory_smoke__DOT__u_mif__DOT__write_channels_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 931122633849547877ull);
    vlSelf->__Vtask_tb_memory_smoke__DOT__l1_access__0__client = 0;
    vlSelf->__Vtask_tb_memory_smoke__DOT__l1_access__1__client = 0;
    vlSelf->__Vtask_tb_memory_smoke__DOT__l1_access__2__client = 0;
    vlSelf->__Vtask_tb_memory_smoke__DOT__l1_access__3__client = 0;
    vlSelf->__Vtask_tb_memory_smoke__DOT__l1_access__4__client = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_memory_smoke__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16180831596510772176ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_memory_smoke__DOT__reset_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4388159311875308257ull);
    vlSelf->__Vtrigprevexpr_h81419cab__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15785554809362612220ull);
    vlSelf->__Vtrigprevexpr_h5a2c0699__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14359184343673898326ull);
    vlSelf->__Vtrigprevexpr_ha9345098__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17810311446027826413ull);
    vlSelf->__Vtrigprevexpr_h521fd0b8__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3216570273356306400ull);
    vlSelf->__Vtrigprevexpr_had9ebf87__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13272752580154911046ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_memory_smoke__DOT__u_tbu_direct__DOT__rsp_valid_q__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12233925467103365298ull);
    vlSelf->__Vtrigprevexpr_h60c90f32__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9482509075307539076ull);
    vlSelf->__VactDidInit = 0;
}
