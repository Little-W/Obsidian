// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_axi_slave_frontend.h for the primary calling header

#include "Vtb_npu_axi_slave_frontend__pch.h"
#include "Vtb_npu_axi_slave_frontend__Syms.h"
#include "Vtb_npu_axi_slave_frontend___024root.h"

void Vtb_npu_axi_slave_frontend___024root___ctor_var_reset(Vtb_npu_axi_slave_frontend___024root* vlSelf);

Vtb_npu_axi_slave_frontend___024root::Vtb_npu_axi_slave_frontend___024root(Vtb_npu_axi_slave_frontend__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_npu_axi_slave_frontend___024root___ctor_var_reset(this);
}

void Vtb_npu_axi_slave_frontend___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_npu_axi_slave_frontend___024root::~Vtb_npu_axi_slave_frontend___024root() {
}
