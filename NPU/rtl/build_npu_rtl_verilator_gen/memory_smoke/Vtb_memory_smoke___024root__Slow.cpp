// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_memory_smoke.h for the primary calling header

#include "Vtb_memory_smoke__pch.h"
#include "Vtb_memory_smoke__Syms.h"
#include "Vtb_memory_smoke___024root.h"

void Vtb_memory_smoke___024root___ctor_var_reset(Vtb_memory_smoke___024root* vlSelf);

Vtb_memory_smoke___024root::Vtb_memory_smoke___024root(Vtb_memory_smoke__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_memory_smoke___024root___ctor_var_reset(this);
}

void Vtb_memory_smoke___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_memory_smoke___024root::~Vtb_memory_smoke___024root() {
}
