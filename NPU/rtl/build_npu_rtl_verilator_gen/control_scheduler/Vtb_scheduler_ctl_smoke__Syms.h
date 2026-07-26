// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_SCHEDULER_CTL_SMOKE__SYMS_H_
#define VERILATED_VTB_SCHEDULER_CTL_SMOKE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_scheduler_ctl_smoke.h"

// INCLUDE MODULE CLASSES
#include "Vtb_scheduler_ctl_smoke___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_scheduler_ctl_smoke__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_scheduler_ctl_smoke* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_scheduler_ctl_smoke___024root TOP;

    // CONSTRUCTORS
    Vtb_scheduler_ctl_smoke__Syms(VerilatedContext* contextp, const char* namep, Vtb_scheduler_ctl_smoke* modelp);
    ~Vtb_scheduler_ctl_smoke__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
