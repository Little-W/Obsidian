// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_INLINE_SCHEDULER_SMOKE__SYMS_H_
#define VERILATED_VTB_INLINE_SCHEDULER_SMOKE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_inline_scheduler_smoke.h"

// INCLUDE MODULE CLASSES
#include "Vtb_inline_scheduler_smoke___024root.h"
#include "Vtb_inline_scheduler_smoke_npu_inline_desc_decode.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_inline_scheduler_smoke__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_inline_scheduler_smoke* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_inline_scheduler_smoke___024root TOP;
    Vtb_inline_scheduler_smoke_npu_inline_desc_decode TOP__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode;
    Vtb_inline_scheduler_smoke_npu_inline_desc_decode TOP__tb_inline_scheduler_smoke__DOT__u_decode_smoke;

    // CONSTRUCTORS
    Vtb_inline_scheduler_smoke__Syms(VerilatedContext* contextp, const char* namep, Vtb_inline_scheduler_smoke* modelp);
    ~Vtb_inline_scheduler_smoke__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
