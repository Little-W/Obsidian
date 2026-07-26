// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_npu_axi_slave_frontend__pch.h"
#include "Vtb_npu_axi_slave_frontend.h"
#include "Vtb_npu_axi_slave_frontend___024root.h"

// FUNCTIONS
Vtb_npu_axi_slave_frontend__Syms::~Vtb_npu_axi_slave_frontend__Syms()
{
}

Vtb_npu_axi_slave_frontend__Syms::Vtb_npu_axi_slave_frontend__Syms(VerilatedContext* contextp, const char* namep, Vtb_npu_axi_slave_frontend* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(1461);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
