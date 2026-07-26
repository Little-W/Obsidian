// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_npu_engines__pch.h"

//============================================================
// Constructors

Vtb_npu_engines::Vtb_npu_engines(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_npu_engines__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_npu_engines::Vtb_npu_engines(const char* _vcname__)
    : Vtb_npu_engines(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_npu_engines::~Vtb_npu_engines() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_npu_engines___024root___eval_debug_assertions(Vtb_npu_engines___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_npu_engines___024root___eval_static(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___eval_initial(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___eval_settle(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___eval(Vtb_npu_engines___024root* vlSelf);

void Vtb_npu_engines::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_npu_engines::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_npu_engines___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_npu_engines___024root___eval_static(&(vlSymsp->TOP));
        Vtb_npu_engines___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_npu_engines___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_npu_engines___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_npu_engines::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_npu_engines::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_npu_engines::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_npu_engines___024root___eval_final(Vtb_npu_engines___024root* vlSelf);

VL_ATTR_COLD void Vtb_npu_engines::final() {
    Vtb_npu_engines___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_npu_engines::hierName() const { return vlSymsp->name(); }
const char* Vtb_npu_engines::modelName() const { return "Vtb_npu_engines"; }
unsigned Vtb_npu_engines::threads() const { return 1; }
void Vtb_npu_engines::prepareClone() const { contextp()->prepareClone(); }
void Vtb_npu_engines::atClone() const {
    contextp()->threadPoolpOnClone();
}
