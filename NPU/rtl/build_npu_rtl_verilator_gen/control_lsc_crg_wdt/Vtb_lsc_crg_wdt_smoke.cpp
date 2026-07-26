// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_lsc_crg_wdt_smoke__pch.h"

//============================================================
// Constructors

Vtb_lsc_crg_wdt_smoke::Vtb_lsc_crg_wdt_smoke(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_lsc_crg_wdt_smoke__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_lsc_crg_wdt_smoke::Vtb_lsc_crg_wdt_smoke(const char* _vcname__)
    : Vtb_lsc_crg_wdt_smoke(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_lsc_crg_wdt_smoke::~Vtb_lsc_crg_wdt_smoke() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_lsc_crg_wdt_smoke___024root___eval_debug_assertions(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_lsc_crg_wdt_smoke___024root___eval_static(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___eval_initial(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___eval_settle(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___eval(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);

void Vtb_lsc_crg_wdt_smoke::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_lsc_crg_wdt_smoke::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_lsc_crg_wdt_smoke___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_lsc_crg_wdt_smoke___024root___eval_static(&(vlSymsp->TOP));
        Vtb_lsc_crg_wdt_smoke___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_lsc_crg_wdt_smoke___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_lsc_crg_wdt_smoke___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_lsc_crg_wdt_smoke::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_lsc_crg_wdt_smoke::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_lsc_crg_wdt_smoke::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_lsc_crg_wdt_smoke___024root___eval_final(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);

VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke::final() {
    Vtb_lsc_crg_wdt_smoke___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_lsc_crg_wdt_smoke::hierName() const { return vlSymsp->name(); }
const char* Vtb_lsc_crg_wdt_smoke::modelName() const { return "Vtb_lsc_crg_wdt_smoke"; }
unsigned Vtb_lsc_crg_wdt_smoke::threads() const { return 1; }
void Vtb_lsc_crg_wdt_smoke::prepareClone() const { contextp()->prepareClone(); }
void Vtb_lsc_crg_wdt_smoke::atClone() const {
    contextp()->threadPoolpOnClone();
}
