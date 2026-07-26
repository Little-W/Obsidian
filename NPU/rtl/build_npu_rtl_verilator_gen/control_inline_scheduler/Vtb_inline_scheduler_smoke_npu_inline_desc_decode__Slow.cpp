// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_inline_scheduler_smoke.h for the primary calling header

#include "Vtb_inline_scheduler_smoke__pch.h"
#include "Vtb_inline_scheduler_smoke__Syms.h"
#include "Vtb_inline_scheduler_smoke_npu_inline_desc_decode.h"

void Vtb_inline_scheduler_smoke_npu_inline_desc_decode___ctor_var_reset(Vtb_inline_scheduler_smoke_npu_inline_desc_decode* vlSelf);

Vtb_inline_scheduler_smoke_npu_inline_desc_decode::Vtb_inline_scheduler_smoke_npu_inline_desc_decode(Vtb_inline_scheduler_smoke__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_inline_scheduler_smoke_npu_inline_desc_decode___ctor_var_reset(this);
}

void Vtb_inline_scheduler_smoke_npu_inline_desc_decode::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_inline_scheduler_smoke_npu_inline_desc_decode::~Vtb_inline_scheduler_smoke_npu_inline_desc_decode() {
}
