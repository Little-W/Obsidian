// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_inline_scheduler_smoke__pch.h"
#include "Vtb_inline_scheduler_smoke.h"
#include "Vtb_inline_scheduler_smoke___024root.h"
#include "Vtb_inline_scheduler_smoke_npu_inline_desc_decode.h"

// FUNCTIONS
Vtb_inline_scheduler_smoke__Syms::~Vtb_inline_scheduler_smoke__Syms()
{
}

Vtb_inline_scheduler_smoke__Syms::Vtb_inline_scheduler_smoke__Syms(VerilatedContext* contextp, const char* namep, Vtb_inline_scheduler_smoke* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode{this, Verilated::catName(namep, "tb_inline_scheduler_smoke.dut.u_inline_desc_decode")}
    , TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke{this, Verilated::catName(namep, "tb_inline_scheduler_smoke.u_decode_smoke")}
{
        // Check resources
        Verilated::stackCheck(3568);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode = &TOP__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode;
    TOP.__PVT__tb_inline_scheduler_smoke__DOT__u_decode_smoke = &TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode.__Vconfigure(true);
    TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke.__Vconfigure(false);
}
