// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_inline_scheduler_smoke.h for the primary calling header

#include "Vtb_inline_scheduler_smoke__pch.h"
#include "Vtb_inline_scheduler_smoke__Syms.h"
#include "Vtb_inline_scheduler_smoke___024root.h"

void Vtb_inline_scheduler_smoke___024root___ctor_var_reset(Vtb_inline_scheduler_smoke___024root* vlSelf);

Vtb_inline_scheduler_smoke___024root::Vtb_inline_scheduler_smoke___024root(Vtb_inline_scheduler_smoke__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_inline_scheduler_smoke___024root___ctor_var_reset(this);
}

void Vtb_inline_scheduler_smoke___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_inline_scheduler_smoke___024root::~Vtb_inline_scheduler_smoke___024root() {
}
