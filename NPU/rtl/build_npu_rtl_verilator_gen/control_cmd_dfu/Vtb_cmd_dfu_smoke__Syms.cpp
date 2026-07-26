// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_cmd_dfu_smoke__pch.h"
#include "Vtb_cmd_dfu_smoke.h"
#include "Vtb_cmd_dfu_smoke___024root.h"

// FUNCTIONS
Vtb_cmd_dfu_smoke__Syms::~Vtb_cmd_dfu_smoke__Syms()
{
}

Vtb_cmd_dfu_smoke__Syms::Vtb_cmd_dfu_smoke__Syms(VerilatedContext* contextp, const char* namep, Vtb_cmd_dfu_smoke* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(564);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
