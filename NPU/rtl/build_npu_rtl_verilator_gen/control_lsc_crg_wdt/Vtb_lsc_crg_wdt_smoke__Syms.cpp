// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_lsc_crg_wdt_smoke__pch.h"
#include "Vtb_lsc_crg_wdt_smoke.h"
#include "Vtb_lsc_crg_wdt_smoke___024root.h"

// FUNCTIONS
Vtb_lsc_crg_wdt_smoke__Syms::~Vtb_lsc_crg_wdt_smoke__Syms()
{
}

Vtb_lsc_crg_wdt_smoke__Syms::Vtb_lsc_crg_wdt_smoke__Syms(VerilatedContext* contextp, const char* namep, Vtb_lsc_crg_wdt_smoke* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(746);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
