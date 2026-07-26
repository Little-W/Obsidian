// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_inline_scheduler_smoke.h for the primary calling header

#include "Vtb_inline_scheduler_smoke__pch.h"
#include "Vtb_inline_scheduler_smoke__Syms.h"
#include "Vtb_inline_scheduler_smoke___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___dump_triggers__stl(Vtb_inline_scheduler_smoke___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___eval_triggers__stl(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_triggers__stl\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_inline_scheduler_smoke___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__0(Vtb_inline_scheduler_smoke___024root* vlSelf);
VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__1(Vtb_inline_scheduler_smoke___024root* vlSelf);
VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__2(Vtb_inline_scheduler_smoke___024root* vlSelf);
VL_ATTR_COLD void Vtb_inline_scheduler_smoke_npu_inline_desc_decode___stl_sequent__TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke__0(Vtb_inline_scheduler_smoke_npu_inline_desc_decode* vlSelf);
VL_ATTR_COLD void Vtb_inline_scheduler_smoke_npu_inline_desc_decode___stl_sequent__TOP__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode__0(Vtb_inline_scheduler_smoke_npu_inline_desc_decode* vlSelf);
void Vtb_inline_scheduler_smoke___024root___act_comb__TOP__1(Vtb_inline_scheduler_smoke___024root* vlSelf);

VL_ATTR_COLD void Vtb_inline_scheduler_smoke___024root___eval_stl(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___eval_stl\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__1(vlSelf);
        Vtb_inline_scheduler_smoke___024root___stl_sequent__TOP__2(vlSelf);
        Vtb_inline_scheduler_smoke_npu_inline_desc_decode___stl_sequent__TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke__0((&vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke));
        Vtb_inline_scheduler_smoke_npu_inline_desc_decode___stl_sequent__TOP__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode__0((&vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode));
        Vtb_inline_scheduler_smoke___024root___act_comb__TOP__1(vlSelf);
    }
}
