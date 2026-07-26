// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_engines.h for the primary calling header

#include "Vtb_npu_engines__pch.h"
#include "Vtb_npu_engines___024root.h"

VL_ATTR_COLD void Vtb_npu_engines___024root___ctor_var_reset_0(Vtb_npu_engines___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_engines___024root___ctor_var_reset_1(Vtb_npu_engines___024root* vlSelf);

VL_ATTR_COLD void Vtb_npu_engines___024root___ctor_var_reset(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___ctor_var_reset\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_npu_engines___024root___ctor_var_reset_0(vlSelf);
    Vtb_npu_engines___024root___ctor_var_reset_1(vlSelf);
}
