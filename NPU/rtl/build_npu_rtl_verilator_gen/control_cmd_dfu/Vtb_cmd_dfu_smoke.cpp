// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_cmd_dfu_smoke__pch.h"

//============================================================
// Constructors

Vtb_cmd_dfu_smoke::Vtb_cmd_dfu_smoke(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_cmd_dfu_smoke__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_cmd_dfu_smoke::Vtb_cmd_dfu_smoke(const char* _vcname__)
    : Vtb_cmd_dfu_smoke(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_cmd_dfu_smoke::~Vtb_cmd_dfu_smoke() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_cmd_dfu_smoke___024root___eval_debug_assertions(Vtb_cmd_dfu_smoke___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_cmd_dfu_smoke___024root___eval_static(Vtb_cmd_dfu_smoke___024root* vlSelf);
void Vtb_cmd_dfu_smoke___024root___eval_initial(Vtb_cmd_dfu_smoke___024root* vlSelf);
void Vtb_cmd_dfu_smoke___024root___eval_settle(Vtb_cmd_dfu_smoke___024root* vlSelf);
void Vtb_cmd_dfu_smoke___024root___eval(Vtb_cmd_dfu_smoke___024root* vlSelf);

void Vtb_cmd_dfu_smoke::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_cmd_dfu_smoke::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_cmd_dfu_smoke___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_cmd_dfu_smoke___024root___eval_static(&(vlSymsp->TOP));
        Vtb_cmd_dfu_smoke___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_cmd_dfu_smoke___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_cmd_dfu_smoke___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_cmd_dfu_smoke::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_cmd_dfu_smoke::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_cmd_dfu_smoke::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_cmd_dfu_smoke___024root___eval_final(Vtb_cmd_dfu_smoke___024root* vlSelf);

VL_ATTR_COLD void Vtb_cmd_dfu_smoke::final() {
    Vtb_cmd_dfu_smoke___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_cmd_dfu_smoke::hierName() const { return vlSymsp->name(); }
const char* Vtb_cmd_dfu_smoke::modelName() const { return "Vtb_cmd_dfu_smoke"; }
unsigned Vtb_cmd_dfu_smoke::threads() const { return 1; }
void Vtb_cmd_dfu_smoke::prepareClone() const { contextp()->prepareClone(); }
void Vtb_cmd_dfu_smoke::atClone() const {
    contextp()->threadPoolpOnClone();
}
