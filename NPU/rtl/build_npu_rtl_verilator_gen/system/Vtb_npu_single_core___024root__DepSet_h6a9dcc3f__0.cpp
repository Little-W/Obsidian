// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core___024root.h"

void Vtb_npu_single_core___024root::__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP(Vtb_npu_single_core__Syms* __restrict vlSymsp, VlWide<64>/*2047:0*/ &desc, SData/*15:0*/ offset, CData/*7:0*/ value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root::__VnoInFunc_tb_npu_single_core__DOT__put_u8_TOP\n"); );
    // Body
    VL_ASSIGNSEL_WI(2048, 8, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(offset), 3U)), desc, value);
}

void Vtb_npu_single_core___024root::__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP(Vtb_npu_single_core__Syms* __restrict vlSymsp, VlWide<64>/*2047:0*/ &desc, SData/*15:0*/ offset, QData/*63:0*/ value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root::__VnoInFunc_tb_npu_single_core__DOT__put_u64_TOP\n"); );
    // Body
    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU & VL_SHIFTL_III(11,32,32, (IData)(offset), 3U)), desc, value);
}

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__1(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__2(Vtb_npu_single_core___024root* vlSelf);

void Vtb_npu_single_core___024root___eval_initial(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__0(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__1(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__2(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__3(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__4(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__5(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__6(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__7(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__8(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__9(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__10(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__11(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__12(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__13(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__14(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__15(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__16(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__17(Vtb_npu_single_core___024root* vlSelf);
VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__18(Vtb_npu_single_core___024root* vlSelf);

VL_INLINE_OPT VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__0(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__1(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__2(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__3(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__4(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__5(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__6(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__7(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__8(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__9(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__10(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__11(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__12(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__13(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__14(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__15(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__16(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__17(vlSelf);
    co_await Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__18(vlSelf);
}

void Vtb_npu_single_core___024root___act_comb__TOP__0(Vtb_npu_single_core___024root* vlSelf);

void Vtb_npu_single_core___024root___eval_act(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_act\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((9ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb_npu_single_core___024root___act_comb__TOP__0(vlSelf);
    }
}

void Vtb_npu_single_core___024root___nba_sequent__TOP__0(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__1(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__2(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__3(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__4(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__5(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__6(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__7(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__8(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_comb__TOP__0(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__9(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_comb__TOP__1(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__10(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__11(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__12(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__13(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__14(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__15(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__16(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__17(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_sequent__TOP__18(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_comb__TOP__2(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_comb__TOP__3(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_comb__TOP__4(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_comb__TOP__5(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_comb__TOP__6(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_comb__TOP__7(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___nba_comb__TOP__8(Vtb_npu_single_core___024root* vlSelf);

void Vtb_npu_single_core___024root___eval_nba(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_nba\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_sequent__TOP__2(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__3(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__4(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__5(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__6(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__7(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((9ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0xdULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_sequent__TOP__10(vlSelf);
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_sequent__TOP__11(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__12(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__13(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__14(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__15(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__16(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__17(vlSelf);
        Vtb_npu_single_core___024root___nba_sequent__TOP__18(vlSelf);
    }
    if ((9ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_comb__TOP__3(vlSelf);
        Vtb_npu_single_core___024root___nba_comb__TOP__4(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_comb__TOP__5(vlSelf);
    }
    if ((0xbULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_comb__TOP__6(vlSelf);
    }
    if ((0xdULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_comb__TOP__7(vlSelf);
    }
    if ((0xfULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_single_core___024root___nba_comb__TOP__8(vlSelf);
    }
}

extern const VlWide<64>/*2047:0*/ Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0;

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__3(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__3\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*11:0*/ __Vfunc_npu_cmd_command_id__1667__Vfuncout;
    __Vfunc_npu_cmd_command_id__1667__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_command_id__1667__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_command_id__1667__command);
    CData/*0:0*/ __Vfunc_npu_v2_compact_opcode_valid__1677__Vfuncout;
    __Vfunc_npu_v2_compact_opcode_valid__1677__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_npu_v2_compact_opcode_valid__1677__compact_opcode;
    __Vfunc_npu_v2_compact_opcode_valid__1677__compact_opcode = 0;
    SData/*11:0*/ __Vfunc_npu_cmd_command_id__1678__Vfuncout;
    __Vfunc_npu_cmd_command_id__1678__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_command_id__1678__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_command_id__1678__command);
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_header_flags__1679__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_header_flags__1679__command);
    SData/*11:0*/ __Vfunc_npu_cmd_wait0__1680__Vfuncout;
    __Vfunc_npu_cmd_wait0__1680__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_wait0__1680__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_wait0__1680__command);
    SData/*11:0*/ __Vfunc_npu_cmd_wait1__1682__Vfuncout;
    __Vfunc_npu_cmd_wait1__1682__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_wait1__1682__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_wait1__1682__command);
    SData/*11:0*/ __Vfunc_npu_cmd_signal__1684__Vfuncout;
    __Vfunc_npu_cmd_signal__1684__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_signal__1684__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_signal__1684__command);
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2275__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2275__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2275__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2275__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2276__Vfuncout;
    __Vfunc_memory_status_to_task__2276__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2276__status;
    __Vfunc_memory_status_to_task__2276__status = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2277__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2277__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2277__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2277__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2278__Vfuncout;
    __Vfunc_memory_status_to_task__2278__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2278__status;
    __Vfunc_memory_status_to_task__2278__status = 0;
    QData/*63:0*/ __Vfunc_dtype_min__2279__Vfuncout;
    __Vfunc_dtype_min__2279__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__2279__dtype;
    __Vfunc_dtype_min__2279__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__2280__Vfuncout;
    __Vfunc_dtype_max__2280__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__2280__dtype;
    __Vfunc_dtype_max__2280__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2281__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2281__fail_addr = 0;
    QData/*63:0*/ __Vfunc_wrap_to_dtype__2282__Vfuncout;
    __Vfunc_wrap_to_dtype__2282__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_wrap_to_dtype__2282__value;
    __Vfunc_wrap_to_dtype__2282__value = 0;
    CData/*1:0*/ __Vfunc_wrap_to_dtype__2282__dtype;
    __Vfunc_wrap_to_dtype__2282__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2283__Vfuncout;
    __Vfunc_clip_to_dtype__2283__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2283__value;
    __Vfunc_clip_to_dtype__2283__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__2283__dtype;
    __Vfunc_clip_to_dtype__2283__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2283__minimum;
    __Vfunc_clip_to_dtype__2283__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2283__maximum;
    __Vfunc_clip_to_dtype__2283__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__2284__Vfuncout;
    __Vfunc_dtype_min__2284__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__2284__dtype;
    __Vfunc_dtype_min__2284__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__2285__Vfuncout;
    __Vfunc_dtype_max__2285__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__2285__dtype;
    __Vfunc_dtype_max__2285__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2287__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2287__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2288__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2288__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2288__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2288__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2289__Vfuncout;
    __Vfunc_memory_status_to_task__2289__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2289__status;
    __Vfunc_memory_status_to_task__2289__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2290__Vfuncout;
    __Vfunc_load_element__2290__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2290__beat;
    __Vfunc_load_element__2290__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2290__byte_lane;
    __Vfunc_load_element__2290__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__2290__high_nibble;
    __Vfunc_load_element__2290__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__2290__dtype;
    __Vfunc_load_element__2290__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__2290__byte_value;
    __Vfunc_load_element__2290__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__2290__nibble_value;
    __Vfunc_load_element__2290__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__2290__half_value;
    __Vfunc_load_element__2290__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__2290__word_value;
    __Vfunc_load_element__2290__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2292__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2292__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2293__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2293__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2293__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2293__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2294__Vfuncout;
    __Vfunc_memory_status_to_task__2294__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2294__status;
    __Vfunc_memory_status_to_task__2294__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2295__Vfuncout;
    __Vfunc_load_element__2295__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2295__beat;
    __Vfunc_load_element__2295__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2295__byte_lane;
    __Vfunc_load_element__2295__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__2295__high_nibble;
    __Vfunc_load_element__2295__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__2295__dtype;
    __Vfunc_load_element__2295__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__2295__byte_value;
    __Vfunc_load_element__2295__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__2295__nibble_value;
    __Vfunc_load_element__2295__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__2295__half_value;
    __Vfunc_load_element__2295__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__2295__word_value;
    __Vfunc_load_element__2295__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2297__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2297__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2298__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2298__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2298__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2298__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2299__Vfuncout;
    __Vfunc_memory_status_to_task__2299__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2299__status;
    __Vfunc_memory_status_to_task__2299__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2300__Vfuncout;
    __Vfunc_load_element__2300__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2300__beat;
    __Vfunc_load_element__2300__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2300__byte_lane;
    __Vfunc_load_element__2300__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__2300__high_nibble;
    __Vfunc_load_element__2300__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__2300__dtype;
    __Vfunc_load_element__2300__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__2300__byte_value;
    __Vfunc_load_element__2300__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__2300__nibble_value;
    __Vfunc_load_element__2300__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__2300__half_value;
    __Vfunc_load_element__2300__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__2300__word_value;
    __Vfunc_load_element__2300__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2301__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2301__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2301__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2301__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2303__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2303__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2304__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2304__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2304__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2304__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2305__Vfuncout;
    __Vfunc_memory_status_to_task__2305__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2305__status;
    __Vfunc_memory_status_to_task__2305__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2306__Vfuncout;
    __Vfunc_load_element__2306__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2306__beat;
    __Vfunc_load_element__2306__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2306__byte_lane;
    __Vfunc_load_element__2306__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__2306__high_nibble;
    __Vfunc_load_element__2306__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__2306__dtype;
    __Vfunc_load_element__2306__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__2306__byte_value;
    __Vfunc_load_element__2306__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__2306__nibble_value;
    __Vfunc_load_element__2306__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__2306__half_value;
    __Vfunc_load_element__2306__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__2306__word_value;
    __Vfunc_load_element__2306__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2308__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2308__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2308__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2308__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2310__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2310__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2311__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2311__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2311__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2311__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2312__Vfuncout;
    __Vfunc_memory_status_to_task__2312__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2312__status;
    __Vfunc_memory_status_to_task__2312__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_known__2313__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_known__2313__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_known__2313__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_known__2313__opcode = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2323__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2323__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2325__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2325__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2325__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2325__opcode = 0;
    // Body
    __Vfunc_npu_cmd_command_id__1667__command[0U] = 
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[0U];
    __Vfunc_npu_cmd_command_id__1667__command[1U] = 
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[1U];
    __Vfunc_npu_cmd_command_id__1667__command[2U] = 
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[2U];
    __Vfunc_npu_cmd_command_id__1667__command[3U] = 
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[3U];
    __Vfunc_npu_cmd_command_id__1667__Vfuncout = (0xfffU 
                                                  & ((__Vfunc_npu_cmd_command_id__1667__command[3U] 
                                                      >> 0x1fU)
                                                      ? 
                                                     (0x3ffU 
                                                      & (__Vfunc_npu_cmd_command_id__1667__command[3U] 
                                                         >> 0x10U))
                                                      : 
                                                     ((__Vfunc_npu_cmd_command_id__1667__command[1U] 
                                                       << 0x10U) 
                                                      | (__Vfunc_npu_cmd_command_id__1667__command[1U] 
                                                         >> 0x10U))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id 
        = __Vfunc_npu_cmd_command_id__1667__Vfuncout;
    __Vfunc_npu_v2_compact_opcode_valid__1677__compact_opcode 
        = (0x1fU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[3U] 
                    >> 0x1aU));
    __Vfunc_npu_v2_compact_opcode_valid__1677__Vfuncout 
        = ((0x1cU != (IData)(__Vfunc_npu_v2_compact_opcode_valid__1677__compact_opcode)) 
           & (0x1eU != (IData)(__Vfunc_npu_v2_compact_opcode_valid__1677__compact_opcode)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT____VdfgExtracted_h654434c1__0 
        = __Vfunc_npu_v2_compact_opcode_valid__1677__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_cancel_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_cancel_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_inflight_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_inflight_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_pending_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_pending_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_op_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_op_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_op_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg1_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg1_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg1_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_count_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_slot_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_slot_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_slot_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_slot_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_slot_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__lookup_valid 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q)) 
           & (3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q;
    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q.commit(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q;
    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q.commit(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q);
    vlSelfRef.__VdlyCommitQueuetb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q.commit(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q);
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[0U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v0;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[1U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v1;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[2U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v2;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[3U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v3;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[4U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v4;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[5U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v5;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[6U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v6;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[7U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q__v7;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v1) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q__v0;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q__v0;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v0] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v0] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v0] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v0] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v0] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v1) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v1] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v1] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v1] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v1;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v1] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v1;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q__v0;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q__v0;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q__v0;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v1] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v1;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v2) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v2] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v2] = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v2] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v2;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v3) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v3] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v3] = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v3] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v3;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v4) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[0U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[0U] = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[0U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v4;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v5) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[1U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[1U] = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[1U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v5;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v6) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[2U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[2U] = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[2U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v6;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v7) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[3U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[3U] = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[3U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v7;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v8) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[4U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[4U] = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[4U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v8;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v9) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[5U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[5U] = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[5U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v9;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v10) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[6U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[6U] = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[6U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v10;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v11) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[7U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[7U] = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[7U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v11;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v11) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v12] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v13] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v14] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v15] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q__v16] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v19) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[0U] = 4U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v20) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[1U] = 4U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v21) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[2U] = 4U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v22) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[3U] = 4U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v23) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[4U] = 4U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v24) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[5U] = 4U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v2) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v2] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v2] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v3) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v3] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v3] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v5) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[0U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v7) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[1U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v9) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[2U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v11) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[3U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v13) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[4U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v15) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[5U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v17) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[6U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v19) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[7U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v11) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v12] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v12] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v13] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v13;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v13] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v14] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v14;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v14] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v15] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v15;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v16] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q__v16;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v32) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[0U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v33) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[1U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v34) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[2U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v35) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[3U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v36) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[4U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v37) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[5U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v38) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[6U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v25) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[6U] = 4U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v15] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v16] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v17) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q__v17] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v19) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v20) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v21) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v22) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[3U] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v23) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[4U] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v24) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[5U] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v25) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[6U] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v26) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[7U] = 4U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[7U] = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v11) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v12] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v13) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v13] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v13;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v13) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v14] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v15] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v15;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v16] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v16;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v17] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v17;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v18] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v18;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v19) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[0U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v19;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v20) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[1U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v20;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v21) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[2U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v21;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v22) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[3U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v22;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v23) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[4U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v23;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v24) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[5U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v24;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v25) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[6U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v25;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v26) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[7U] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v26;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v39) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[7U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q__v2) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v4] = 2U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v5) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[0U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v6) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[0U] = 3U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v7) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[1U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v8) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[1U] = 3U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v9) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[2U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v10) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[2U] = 3U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v11) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[3U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v12) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[3U] = 3U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v13) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[4U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v14) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[4U] = 3U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v15) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[5U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v16) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[5U] = 3U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v17) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[6U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v18) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[6U] = 3U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v19) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[7U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v20) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[7U] = 3U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v11) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v21] = 5U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q__v13) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v22] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v13) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v23] = 5U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v24) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v24] = 4U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v25) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v25] = 4U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v26) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v26] = 4U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v27) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v27] = 4U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v28] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v28;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v29] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v29;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v30] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v30;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v31] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v31;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v32) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[0U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v33) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[1U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v34) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[2U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v35) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[3U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v36) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[4U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v37) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[5U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v38) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[6U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v39) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[7U] = 6U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v40) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q[0U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q[1U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q[2U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q[3U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q[4U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q[5U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q[6U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_signal_q[7U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q[0U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q[1U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q[2U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q[3U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q[4U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q[5U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q[6U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_addr_q[7U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[0U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[1U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[2U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[3U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[4U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[5U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[6U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q[7U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[0U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[1U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[2U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[3U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[4U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[5U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[6U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_done_flags_q[7U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[0U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[1U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[2U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[3U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[4U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[5U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[6U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_progress_q[7U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[0U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[1U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[2U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[3U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[4U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[5U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[6U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q[7U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[0U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[1U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[2U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[3U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[4U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[5U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[6U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_error_info_q[7U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q[0U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q[1U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q[2U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q[3U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q[4U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q[5U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q[6U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q[7U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q[0U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q[1U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q[2U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q[3U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q[4U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q[5U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q[6U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q[7U] = 0xfffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q[0U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q[1U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q[2U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q[3U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q[4U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q[5U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q[6U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q[7U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[0U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[1U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[2U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[3U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[4U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[5U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[6U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q[7U] = 0U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[0U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
        [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q][0U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
        [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q][1U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
        [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q][2U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
        [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_rd_ptr_q][3U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 0U;
    if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
         & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [0U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [0U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [0U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [0U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
            == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 1U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [1U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [1U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [1U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [1U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 2U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [2U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [2U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [2U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [2U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 3U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [3U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [3U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [3U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [3U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 4U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [4U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [4U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [4U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [4U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 5U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [5U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [5U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [5U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [5U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 6U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [6U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [6U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [6U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [6U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 7U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [7U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [7U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [7U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [7U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                       >> 0x3fU)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__header_format_valid = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__opcode_format_valid 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT____VdfgExtracted_h654434c1__0;
    } else {
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode 
            = (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__header_format_valid 
            = ((((IData)(((0ULL == (0x3fULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q)) 
                          & (0x100000000000000ULL == 
                             (0xff000000000c0000ULL 
                              & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q)))) 
                 & ([&]() {
                            vlSelfRef.__Vfunc_npu_event_ref_valid__1669__event_ref 
                                = (0xfffU & (IData)(
                                                    (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                                                     >> 0x14U)));
                            vlSelfRef.__Vfunc_npu_event_ref_valid__1669__Vfuncout 
                                = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1669__event_ref)) 
                                   | (0xffU != (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1669__event_ref))));
                        }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1669__Vfuncout))) 
                & ([&]() {
                        vlSelfRef.__Vfunc_npu_event_ref_valid__1670__event_ref 
                            = (0xfffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                                                 >> 0x20U)));
                        vlSelfRef.__Vfunc_npu_event_ref_valid__1670__Vfuncout 
                            = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1670__event_ref)) 
                               | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1670__event_ref))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1670__Vfuncout))) 
               & ([&]() {
                    vlSelfRef.__Vfunc_npu_event_ref_valid__1671__event_ref 
                        = (0xfffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                                             >> 0x2cU)));
                    vlSelfRef.__Vfunc_npu_event_ref_valid__1671__Vfuncout 
                        = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1671__event_ref)) 
                           | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1671__event_ref))));
                }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1671__Vfuncout)));
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine 
            = (0xfU & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q 
                               >> 0x3cU)));
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__Vfuncout 
            = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine) 
                         >> 3U))) && ((4U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine))
                                       ? ((1U & (~ 
                                                 ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine) 
                                                  >> 1U))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine))) 
                                              && (((((0x80U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)) 
                                                     | (0x81U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                    | (0x82U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                   | (0x84U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                  | (0x86U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)))))
                                       : ((2U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine))
                                           ? ((1U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine))
                                               ? ((
                                                   ((((((((0x60U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)) 
                                                          | (0x61U 
                                                             == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                         | (0x62U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                        | (0x63U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                       | (0x64U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                      | (0x65U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                     | (0x66U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                    | (0x67U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                   | (0x68U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                  | (0x69U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)))
                                               : ((
                                                   ((0x40U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)) 
                                                    | (0x41U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                   | (0x42U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                  | (0x43U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))))
                                           : ((1U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine))
                                               ? ((
                                                   ((((0x20U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)) 
                                                      | (0x21U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                     | (0x22U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                    | (0x23U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                   | (0x24U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                  | (0x25U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)))
                                               : ((
                                                   (((0U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)) 
                                                     | (1U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                    | (2U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                   | (3U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                  | (4U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)))))));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__opcode_format_valid 
            = vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__Vfuncout;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__ctl_req_ready 
        = (1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q) 
                    | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_idle 
        = ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)) 
           & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_terminal = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_state = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_producer = 0U;
    if (((((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q)) 
           & (0xffU > (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q)))) 
          & (((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q)))
               ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
              [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q))]
               : 0U) == (0xfU & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q) 
                                 >> 8U)))) & (0U != 
                                              ((0xfeU 
                                                >= 
                                                (0xffU 
                                                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q)))
                                                ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                               [(0xffU 
                                                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q))]
                                                : 0U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_terminal 
            = ((2U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q)))
                        ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                       [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q))]
                        : 0U)) | (3U == ((0xfeU >= 
                                          (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q)))
                                          ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                         [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q))]
                                          : 0U)));
        if ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_state 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q))];
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_producer 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_producer_q
                [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_arg0_q))];
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_state = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_producer = 0U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot = 0U;
    if ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
         [0U])) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot = 0U;
    }
    if (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found)) 
         & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot = 1U;
    }
    if (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found)) 
         & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot = 2U;
    }
    if (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found)) 
         & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot = 3U;
    }
    if (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found)) 
         & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot = 4U;
    }
    if (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found)) 
         & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot = 5U;
    }
    if (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found)) 
         & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot = 6U;
    }
    if (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found)) 
         & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_slot = 7U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy = 0U;
    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
         [0U])) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
         [1U])) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
         [2U])) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
         [3U])) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
         [4U])) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
         [5U])) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
         [6U])) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy)));
    }
    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
         [7U])) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy 
            = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__task_occupancy)));
    }
    __Vfunc_npu_cmd_command_id__1678__command[0U] = 
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[0U];
    __Vfunc_npu_cmd_command_id__1678__command[1U] = 
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U];
    __Vfunc_npu_cmd_command_id__1678__command[2U] = 
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U];
    __Vfunc_npu_cmd_command_id__1678__command[3U] = 
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U];
    __Vfunc_npu_cmd_command_id__1678__Vfuncout = (0xfffU 
                                                  & ((__Vfunc_npu_cmd_command_id__1678__command[3U] 
                                                      >> 0x1fU)
                                                      ? 
                                                     (0x3ffU 
                                                      & (__Vfunc_npu_cmd_command_id__1678__command[3U] 
                                                         >> 0x10U))
                                                      : 
                                                     ((__Vfunc_npu_cmd_command_id__1678__command[1U] 
                                                       << 0x10U) 
                                                      | (__Vfunc_npu_cmd_command_id__1678__command[1U] 
                                                         >> 0x10U))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_command_id 
        = __Vfunc_npu_cmd_command_id__1678__Vfuncout;
    __Vfunc_npu_cmd_header_flags__1679__command[0U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[0U];
    __Vfunc_npu_cmd_header_flags__1679__command[1U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U];
    __Vfunc_npu_cmd_header_flags__1679__command[2U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U];
    __Vfunc_npu_cmd_header_flags__1679__command[3U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U];
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_npu_cmd_header_flags__1679__flags = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 16503384002410822002ull);
    {
        if ((1U & (~ (__Vfunc_npu_cmd_header_flags__1679__command[3U] 
                      >> 0x1fU)))) {
            vlSelfRef.__Vfunc_npu_cmd_header_flags__1679__Vfuncout 
                = (0xfffU & (__Vfunc_npu_cmd_header_flags__1679__command[2U] 
                             >> 8U));
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_npu_cmd_header_flags__1679__flags = 0U;
        vlSelfRef.__Vfunc_npu_cmd_header_flags__1679__flags 
            = ((0xff8U & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__1679__flags)) 
               | ((4U & (__Vfunc_npu_cmd_header_flags__1679__command[2U] 
                         >> 0x13U)) | ((2U & (__Vfunc_npu_cmd_header_flags__1679__command[2U] 
                                              >> 0x15U)) 
                                       | (1U & (__Vfunc_npu_cmd_header_flags__1679__command[2U] 
                                                >> 0x17U)))));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__1679__flags 
            = ((0xfefU & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__1679__flags)) 
               | (0x10U & (__Vfunc_npu_cmd_header_flags__1679__command[2U] 
                           >> 0x10U)));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__1679__flags 
            = ((0xf3fU & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__1679__flags)) 
               | (0xc0U & (__Vfunc_npu_cmd_header_flags__1679__command[2U] 
                           >> 0xcU)));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__1679__Vfuncout 
            = vlSelfRef.__Vfunc_npu_cmd_header_flags__1679__flags;
        __Vlabel0: ;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_header_flags 
        = vlSelfRef.__Vfunc_npu_cmd_header_flags__1679__Vfuncout;
    __Vfunc_npu_cmd_wait0__1680__command[0U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[0U];
    __Vfunc_npu_cmd_wait0__1680__command[1U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U];
    __Vfunc_npu_cmd_wait0__1680__command[2U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U];
    __Vfunc_npu_cmd_wait0__1680__command[3U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U];
    __Vfunc_npu_cmd_wait0__1680__Vfuncout = (0xfffU 
                                             & ((__Vfunc_npu_cmd_wait0__1680__command[3U] 
                                                 >> 0x1fU)
                                                 ? 
                                                ([&]() {
                    vlSelfRef.__Vfunc_npu_v2_event_ref__1681__event_id 
                        = (0xffU & (__Vfunc_npu_cmd_wait0__1680__command[3U] 
                                    >> 8U));
                    vlSelfRef.__Vfunc_npu_v2_event_ref__1681__Vfuncout 
                        = ((0xffU == (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__1681__event_id))
                            ? 0xfffU : (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__1681__event_id));
                }(), (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__1681__Vfuncout))
                                                 : 
                                                ((__Vfunc_npu_cmd_wait0__1680__command[2U] 
                                                  << 0xcU) 
                                                 | (__Vfunc_npu_cmd_wait0__1680__command[2U] 
                                                    >> 0x14U))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0 
        = __Vfunc_npu_cmd_wait0__1680__Vfuncout;
    __Vfunc_npu_cmd_wait1__1682__command[0U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[0U];
    __Vfunc_npu_cmd_wait1__1682__command[1U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U];
    __Vfunc_npu_cmd_wait1__1682__command[2U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U];
    __Vfunc_npu_cmd_wait1__1682__command[3U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U];
    __Vfunc_npu_cmd_wait1__1682__Vfuncout = (0xfffU 
                                             & ((__Vfunc_npu_cmd_wait1__1682__command[3U] 
                                                 >> 0x1fU)
                                                 ? 
                                                ([&]() {
                    vlSelfRef.__Vfunc_npu_v2_event_ref__1683__event_id 
                        = (0xffU & __Vfunc_npu_cmd_wait1__1682__command[3U]);
                    vlSelfRef.__Vfunc_npu_v2_event_ref__1683__Vfuncout 
                        = ((0xffU == (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__1683__event_id))
                            ? 0xfffU : (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__1683__event_id));
                }(), (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__1683__Vfuncout))
                                                 : 
                                                __Vfunc_npu_cmd_wait1__1682__command[3U]));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1 
        = __Vfunc_npu_cmd_wait1__1682__Vfuncout;
    __Vfunc_npu_cmd_signal__1684__command[0U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[0U];
    __Vfunc_npu_cmd_signal__1684__command[1U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U];
    __Vfunc_npu_cmd_signal__1684__command[2U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U];
    __Vfunc_npu_cmd_signal__1684__command[3U] = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U];
    __Vfunc_npu_cmd_signal__1684__Vfuncout = (0xfffU 
                                              & ((__Vfunc_npu_cmd_signal__1684__command[3U] 
                                                  >> 0x1fU)
                                                  ? 
                                                 ([&]() {
                    vlSelfRef.__Vfunc_npu_v2_event_ref__1685__event_id 
                        = (__Vfunc_npu_cmd_signal__1684__command[2U] 
                           >> 0x18U);
                    vlSelfRef.__Vfunc_npu_v2_event_ref__1685__Vfuncout 
                        = ((0xffU == (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__1685__event_id))
                            ? 0xfffU : (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__1685__event_id));
                }(), (IData)(vlSelfRef.__Vfunc_npu_v2_event_ref__1685__Vfuncout))
                                                  : 
                                                 ((__Vfunc_npu_cmd_signal__1684__command[3U] 
                                                   << 0x14U) 
                                                  | (__Vfunc_npu_cmd_signal__1684__command[3U] 
                                                     >> 0xcU))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal 
        = __Vfunc_npu_cmd_signal__1684__Vfuncout;
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) {
        if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0U;
            } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0U;
            } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0U;
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_q) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0U;
                }
            } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                     [3U])) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2275__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr);
                    __Vfunc_memory_status_to_task__2276__status 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                        [3U];
                    __Vfunc_memory_status_to_task__2276__Vfuncout 
                        = ((0U == (IData)(__Vfunc_memory_status_to_task__2276__status))
                            ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2276__status))
                                     ? 6U : ((2U == (IData)(__Vfunc_memory_status_to_task__2276__status))
                                              ? 5U : 4U)));
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2275__fail_status 
                        = __Vfunc_memory_status_to_task__2276__Vfuncout;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2275__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2275__fail_status;
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__progress_q 
                        = (1ULL + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__progress_q);
                    if ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q) 
                         < ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__row_q) 
                             == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rows)
                             ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__valid_length
                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__length))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q 
                            = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q);
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_value_q = 1U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q 
                            = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_enable)
                                ? 2U : 4U);
                    } else if ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__row_q) 
                                < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rows)) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__row_q 
                            = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__row_q);
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q = 0U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_value_q = 1U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q 
                            = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_enable)
                                ? 2U : 4U);
                    } else {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 0U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                    }
                }
            }
        } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                        if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x10U;
                        }
                    } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                             [3U])) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2277__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr);
                            __Vfunc_memory_status_to_task__2278__status 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                                [3U];
                            __Vfunc_memory_status_to_task__2278__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__2278__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2278__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__2278__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2277__fail_status 
                                = __Vfunc_memory_status_to_task__2278__Vfuncout;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2277__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2277__fail_status;
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rmw_beat_q 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                [3U];
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0xfU;
                        }
                    }
                } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                    if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0xeU;
                    }
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result = 0ULL;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__compare_result = 0U;
                    if (((((((((0x60U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q)) 
                               | (0x61U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                              | (0x62U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                             | (0x63U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                            | (0x64U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                           | (0x65U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                          | (0x66U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                         | (0x67U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q)))) {
                        if ((0x60U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result 
                                = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q 
                                   + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q);
                        } else if ((0x61U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result 
                                = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q 
                                   - vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q);
                        } else if ((0x62U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result 
                                = VL_MULS_QQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q);
                        } else if ((0x63U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result 
                                = (VL_MULS_QQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q) 
                                   + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_value_q);
                        } else if ((0x64U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result 
                                = (VL_GTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q)
                                    ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q);
                        } else if ((0x65U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result 
                                = (VL_LTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q)
                                    ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q);
                        } else if ((0x66U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__compare_result 
                                = ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__compare_mode))
                                    ? (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q 
                                       == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q)
                                    : ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__compare_mode))
                                        ? (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q 
                                           != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q)
                                        : ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__compare_mode))
                                            ? VL_LTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q)
                                            : ((3U 
                                                == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__compare_mode))
                                                ? VL_LTES_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q)
                                                : (
                                                   (4U 
                                                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__compare_mode))
                                                    ? 
                                                   VL_GTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q)
                                                    : 
                                                   VL_GTES_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q))))));
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result 
                                = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__compare_result)
                                    ? 1ULL : 0ULL);
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result 
                                = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_value_q)
                                    ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q);
                        }
                    } else {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result 
                            = ((0x68U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))
                                ? (VL_LTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q, 
                                              (((QData)((IData)(
                                                                (- (IData)(
                                                                           (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar0 
                                                                            >> 0x1fU))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar0))))
                                    ? (((QData)((IData)(
                                                        (- (IData)(
                                                                   (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar0 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar0)))
                                    : (VL_GTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q, 
                                                  (((QData)((IData)(
                                                                    (- (IData)(
                                                                               (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar1 
                                                                                >> 0x1fU))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar1))))
                                        ? (((QData)((IData)(
                                                            (- (IData)(
                                                                       (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar1 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar1)))
                                        : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q))
                                : (VL_GTS_IQQ(64, 0ULL, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q)
                                    ? 0ULL : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q));
                    }
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__overflow 
                        = (VL_LTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result, 
                                      ([&]() {
                                    __Vfunc_dtype_min__2279__dtype 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype;
                                    __Vfunc_dtype_min__2279__Vfuncout 
                                        = ((2U & (IData)(__Vfunc_dtype_min__2279__dtype))
                                            ? ((1U 
                                                & (IData)(__Vfunc_dtype_min__2279__dtype))
                                                ? 0xffffffffffff8000ULL
                                                : 0xffffffff80000000ULL)
                                            : ((1U 
                                                & (IData)(__Vfunc_dtype_min__2279__dtype))
                                                ? 0xffffffffffffff80ULL
                                                : 0xfffffffffffffff8ULL));
                                }(), __Vfunc_dtype_min__2279__Vfuncout)) 
                           | VL_GTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result, 
                                        ([&]() {
                                    __Vfunc_dtype_max__2280__dtype 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype;
                                    __Vfunc_dtype_max__2280__Vfuncout 
                                        = ((2U & (IData)(__Vfunc_dtype_max__2280__dtype))
                                            ? ((1U 
                                                & (IData)(__Vfunc_dtype_max__2280__dtype))
                                                ? 0x7fffULL
                                                : 0x7fffffffULL)
                                            : ((1U 
                                                & (IData)(__Vfunc_dtype_max__2280__dtype))
                                                ? 0x7fULL
                                                : 7ULL));
                                }(), __Vfunc_dtype_max__2280__Vfuncout)));
                    if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__overflow) 
                         & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__overflow_mode)))) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2281__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr);
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 0xcU;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2281__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                    } else {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__result_q 
                            = ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__overflow_mode))
                                ? ([&]() {
                                    __Vfunc_wrap_to_dtype__2282__dtype 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype;
                                    __Vfunc_wrap_to_dtype__2282__value 
                                        = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result);
                                    __Vfunc_wrap_to_dtype__2282__Vfuncout 
                                        = ((2U & (IData)(__Vfunc_wrap_to_dtype__2282__dtype))
                                            ? ((1U 
                                                & (IData)(__Vfunc_wrap_to_dtype__2282__dtype))
                                                ? (
                                                   ((- (QData)((IData)(
                                                                       (1U 
                                                                        & (__Vfunc_wrap_to_dtype__2282__value 
                                                                           >> 0xfU))))) 
                                                    << 0x10U) 
                                                   | (QData)((IData)(
                                                                     (0xffffU 
                                                                      & __Vfunc_wrap_to_dtype__2282__value))))
                                                : (
                                                   ((QData)((IData)(
                                                                    (- (IData)(
                                                                               (__Vfunc_wrap_to_dtype__2282__value 
                                                                                >> 0x1fU))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(__Vfunc_wrap_to_dtype__2282__value))))
                                            : ((1U 
                                                & (IData)(__Vfunc_wrap_to_dtype__2282__dtype))
                                                ? (
                                                   ((- (QData)((IData)(
                                                                       (1U 
                                                                        & (__Vfunc_wrap_to_dtype__2282__value 
                                                                           >> 7U))))) 
                                                    << 8U) 
                                                   | (QData)((IData)(
                                                                     (0xffU 
                                                                      & __Vfunc_wrap_to_dtype__2282__value))))
                                                : (
                                                   ((- (QData)((IData)(
                                                                       (1U 
                                                                        & (__Vfunc_wrap_to_dtype__2282__value 
                                                                           >> 3U))))) 
                                                    << 4U) 
                                                   | (QData)((IData)(
                                                                     (0xfU 
                                                                      & __Vfunc_wrap_to_dtype__2282__value))))));
                                }(), __Vfunc_wrap_to_dtype__2282__Vfuncout)
                                : ([&]() {
                                    __Vfunc_clip_to_dtype__2283__dtype 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype;
                                    __Vfunc_clip_to_dtype__2283__value 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__unnamedblk1__DOT__arithmetic_result;
                                    __Vfunc_clip_to_dtype__2283__minimum = 0;
                                    __Vfunc_clip_to_dtype__2283__maximum = 0;
                                    {
                                        __Vfunc_dtype_min__2284__dtype 
                                            = __Vfunc_clip_to_dtype__2283__dtype;
                                        __Vfunc_dtype_min__2284__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_min__2284__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__2284__dtype))
                                                    ? 0xffffffffffff8000ULL
                                                    : 0xffffffff80000000ULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__2284__dtype))
                                                    ? 0xffffffffffffff80ULL
                                                    : 0xfffffffffffffff8ULL));
                                        __Vfunc_clip_to_dtype__2283__minimum 
                                            = __Vfunc_dtype_min__2284__Vfuncout;
                                        __Vfunc_dtype_max__2285__dtype 
                                            = __Vfunc_clip_to_dtype__2283__dtype;
                                        __Vfunc_dtype_max__2285__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_max__2285__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__2285__dtype))
                                                    ? 0x7fffULL
                                                    : 0x7fffffffULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__2285__dtype))
                                                    ? 0x7fULL
                                                    : 7ULL));
                                        __Vfunc_clip_to_dtype__2283__maximum 
                                            = __Vfunc_dtype_max__2285__Vfuncout;
                                        if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__2283__value, __Vfunc_clip_to_dtype__2283__minimum)) {
                                            __Vfunc_clip_to_dtype__2283__Vfuncout 
                                                = __Vfunc_clip_to_dtype__2283__minimum;
                                            goto __Vlabel1;
                                        }
                                        if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__2283__value, __Vfunc_clip_to_dtype__2283__maximum)) {
                                            __Vfunc_clip_to_dtype__2283__Vfuncout 
                                                = __Vfunc_clip_to_dtype__2283__maximum;
                                            goto __Vlabel1;
                                        }
                                        __Vfunc_clip_to_dtype__2283__Vfuncout 
                                            = __Vfunc_clip_to_dtype__2283__value;
                                        __Vlabel1: ;
                                    }
                                }(), __Vfunc_clip_to_dtype__2283__Vfuncout));
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rmw_beat_q = 0ULL;
                        if (([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__dtype 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__byte_lane 
                                        = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr));
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__Vfuncout 
                                        = (((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__dtype)) 
                                            & (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__byte_lane))) 
                                           | ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__dtype)) 
                                              & (6U 
                                                 < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__byte_lane))));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2286__Vfuncout))) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2287__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr);
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 4U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2287__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q 
                                = (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype)) 
                                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_high_nibble))
                                    ? 0xdU : 0xfU);
                        }
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                    if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                             [3U])) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2288__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr);
                            __Vfunc_memory_status_to_task__2289__status 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                                [3U];
                            __Vfunc_memory_status_to_task__2289__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__2289__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2289__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__2289__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2288__fail_status 
                                = __Vfunc_memory_status_to_task__2289__Vfuncout;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2288__fail_status;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2288__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                        } else {
                            __Vfunc_load_element__2290__dtype 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype;
                            __Vfunc_load_element__2290__high_nibble 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_high_nibble;
                            __Vfunc_load_element__2290__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr));
                            __Vfunc_load_element__2290__beat 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                [3U];
                            __Vfunc_load_element__2290__byte_value 
                                = (0xffU & (IData)(
                                                   (__Vfunc_load_element__2290__beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2290__byte_lane), 3U)))));
                            __Vfunc_load_element__2290__nibble_value 
                                = (0xfU & ((IData)(__Vfunc_load_element__2290__high_nibble)
                                            ? ((IData)(__Vfunc_load_element__2290__byte_value) 
                                               >> 4U)
                                            : (IData)(__Vfunc_load_element__2290__byte_value)));
                            __Vfunc_load_element__2290__half_value 
                                = (0xffffU & (IData)(
                                                     (__Vfunc_load_element__2290__beat 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2290__byte_lane), 3U)))));
                            __Vfunc_load_element__2290__word_value 
                                = (IData)((__Vfunc_load_element__2290__beat 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2290__byte_lane), 3U))));
                            __Vfunc_load_element__2290__Vfuncout 
                                = ((2U & (IData)(__Vfunc_load_element__2290__dtype))
                                    ? ((1U & (IData)(__Vfunc_load_element__2290__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2290__half_value) 
                                                                   >> 0xfU))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(__Vfunc_load_element__2290__half_value)))
                                        : (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_load_element__2290__word_value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_load_element__2290__word_value))))
                                    : ((1U & (IData)(__Vfunc_load_element__2290__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2290__byte_value) 
                                                                   >> 7U))))) 
                                            << 8U) 
                                           | (QData)((IData)(__Vfunc_load_element__2290__byte_value)))
                                        : (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2290__nibble_value) 
                                                                   >> 3U))))) 
                                            << 4U) 
                                           | (QData)((IData)(__Vfunc_load_element__2290__nibble_value)))));
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__result_q 
                                = __Vfunc_load_element__2290__Vfuncout;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rmw_beat_q 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                [3U];
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0xfU;
                        }
                    }
                } else if (([&]() {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__dtype 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__Vfuncout 
                                = (((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__dtype)) 
                                    & (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__byte_lane))) 
                                   | ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__dtype)) 
                                      & (6U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__byte_lane))));
                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2291__Vfuncout))) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2292__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr);
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2292__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0xbU;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                         [3U])) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2293__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_addr);
                        __Vfunc_memory_status_to_task__2294__status 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                            [3U];
                        __Vfunc_memory_status_to_task__2294__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__2294__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2294__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__2294__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2293__fail_status 
                            = __Vfunc_memory_status_to_task__2294__Vfuncout;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2293__fail_status;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2293__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                    } else {
                        __Vfunc_load_element__2295__dtype 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_dtype;
                        __Vfunc_load_element__2295__high_nibble 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_high_nibble;
                        __Vfunc_load_element__2295__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_addr));
                        __Vfunc_load_element__2295__beat 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                            [3U];
                        __Vfunc_load_element__2295__byte_value 
                            = (0xffU & (IData)((__Vfunc_load_element__2295__beat 
                                                >> 
                                                (0x3fU 
                                                 & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2295__byte_lane), 3U)))));
                        __Vfunc_load_element__2295__nibble_value 
                            = (0xfU & ((IData)(__Vfunc_load_element__2295__high_nibble)
                                        ? ((IData)(__Vfunc_load_element__2295__byte_value) 
                                           >> 4U) : (IData)(__Vfunc_load_element__2295__byte_value)));
                        __Vfunc_load_element__2295__half_value 
                            = (0xffffU & (IData)((__Vfunc_load_element__2295__beat 
                                                  >> 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2295__byte_lane), 3U)))));
                        __Vfunc_load_element__2295__word_value 
                            = (IData)((__Vfunc_load_element__2295__beat 
                                       >> (0x3fU & 
                                           VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2295__byte_lane), 3U))));
                        __Vfunc_load_element__2295__Vfuncout 
                            = ((2U & (IData)(__Vfunc_load_element__2295__dtype))
                                ? ((1U & (IData)(__Vfunc_load_element__2295__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2295__half_value) 
                                                               >> 0xfU))))) 
                                        << 0x10U) | (QData)((IData)(__Vfunc_load_element__2295__half_value)))
                                    : (((QData)((IData)(
                                                        (- (IData)(
                                                                   (__Vfunc_load_element__2295__word_value 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(__Vfunc_load_element__2295__word_value))))
                                : ((1U & (IData)(__Vfunc_load_element__2295__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2295__byte_value) 
                                                               >> 7U))))) 
                                        << 8U) | (QData)((IData)(__Vfunc_load_element__2295__byte_value)))
                                    : (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2295__nibble_value) 
                                                               >> 3U))))) 
                                        << 4U) | (QData)((IData)(__Vfunc_load_element__2295__nibble_value)))));
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_value_q 
                            = __Vfunc_load_element__2295__Vfuncout;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0xcU;
                    }
                }
            } else if (([&]() {
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__dtype 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_dtype;
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_addr));
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__Vfuncout 
                            = (((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__dtype)) 
                                & (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__byte_lane))) 
                               | ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__dtype)) 
                                  & (6U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__byte_lane))));
                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2296__Vfuncout))) {
                __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2297__fail_addr 
                    = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_addr);
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 4U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                    = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2297__fail_addr;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
            } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 9U;
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                    if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                             [3U])) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2298__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_addr);
                            __Vfunc_memory_status_to_task__2299__status 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                                [3U];
                            __Vfunc_memory_status_to_task__2299__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__2299__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2299__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__2299__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2298__fail_status 
                                = __Vfunc_memory_status_to_task__2299__Vfuncout;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2298__fail_status;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2298__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                        } else {
                            __Vfunc_load_element__2300__dtype 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_dtype;
                            __Vfunc_load_element__2300__high_nibble 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_high_nibble;
                            __Vfunc_load_element__2300__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_addr));
                            __Vfunc_load_element__2300__beat 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                [3U];
                            __Vfunc_load_element__2300__byte_value 
                                = (0xffU & (IData)(
                                                   (__Vfunc_load_element__2300__beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2300__byte_lane), 3U)))));
                            __Vfunc_load_element__2300__nibble_value 
                                = (0xfU & ((IData)(__Vfunc_load_element__2300__high_nibble)
                                            ? ((IData)(__Vfunc_load_element__2300__byte_value) 
                                               >> 4U)
                                            : (IData)(__Vfunc_load_element__2300__byte_value)));
                            __Vfunc_load_element__2300__half_value 
                                = (0xffffU & (IData)(
                                                     (__Vfunc_load_element__2300__beat 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2300__byte_lane), 3U)))));
                            __Vfunc_load_element__2300__word_value 
                                = (IData)((__Vfunc_load_element__2300__beat 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2300__byte_lane), 3U))));
                            __Vfunc_load_element__2300__Vfuncout 
                                = ((2U & (IData)(__Vfunc_load_element__2300__dtype))
                                    ? ((1U & (IData)(__Vfunc_load_element__2300__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2300__half_value) 
                                                                   >> 0xfU))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(__Vfunc_load_element__2300__half_value)))
                                        : (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_load_element__2300__word_value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_load_element__2300__word_value))))
                                    : ((1U & (IData)(__Vfunc_load_element__2300__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2300__byte_value) 
                                                                   >> 7U))))) 
                                            << 8U) 
                                           | (QData)((IData)(__Vfunc_load_element__2300__byte_value)))
                                        : (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2300__nibble_value) 
                                                                   >> 3U))))) 
                                            << 4U) 
                                           | (QData)((IData)(__Vfunc_load_element__2300__nibble_value)))));
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q 
                                = __Vfunc_load_element__2300__Vfuncout;
                            if (([&]() {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2301__opcode 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q;
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2301__Vfuncout 
                                            = (0x63U 
                                               == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2301__opcode));
                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2301__Vfuncout))) {
                                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_from_scalar1) {
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_value_q 
                                        = (((QData)((IData)(
                                                            (- (IData)(
                                                                       (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar1 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar1)));
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0xcU;
                                } else {
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 8U;
                                }
                            } else {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0xcU;
                            }
                        }
                    }
                } else if (([&]() {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__dtype 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_dtype;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_addr));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__Vfuncout 
                                = (((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__dtype)) 
                                    & (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__byte_lane))) 
                                   | ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__dtype)) 
                                      & (6U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__byte_lane))));
                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2302__Vfuncout))) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2303__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_addr);
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2303__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                         [3U])) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2304__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_addr);
                        __Vfunc_memory_status_to_task__2305__status 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                            [3U];
                        __Vfunc_memory_status_to_task__2305__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__2305__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2305__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__2305__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2304__fail_status 
                            = __Vfunc_memory_status_to_task__2305__Vfuncout;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2304__fail_status;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2304__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                    } else {
                        __Vfunc_load_element__2306__dtype 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_dtype;
                        __Vfunc_load_element__2306__high_nibble 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_high_nibble;
                        __Vfunc_load_element__2306__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_addr));
                        __Vfunc_load_element__2306__beat 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                            [3U];
                        __Vfunc_load_element__2306__byte_value 
                            = (0xffU & (IData)((__Vfunc_load_element__2306__beat 
                                                >> 
                                                (0x3fU 
                                                 & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2306__byte_lane), 3U)))));
                        __Vfunc_load_element__2306__nibble_value 
                            = (0xfU & ((IData)(__Vfunc_load_element__2306__high_nibble)
                                        ? ((IData)(__Vfunc_load_element__2306__byte_value) 
                                           >> 4U) : (IData)(__Vfunc_load_element__2306__byte_value)));
                        __Vfunc_load_element__2306__half_value 
                            = (0xffffU & (IData)((__Vfunc_load_element__2306__beat 
                                                  >> 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2306__byte_lane), 3U)))));
                        __Vfunc_load_element__2306__word_value 
                            = (IData)((__Vfunc_load_element__2306__beat 
                                       >> (0x3fU & 
                                           VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2306__byte_lane), 3U))));
                        __Vfunc_load_element__2306__Vfuncout 
                            = ((2U & (IData)(__Vfunc_load_element__2306__dtype))
                                ? ((1U & (IData)(__Vfunc_load_element__2306__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2306__half_value) 
                                                               >> 0xfU))))) 
                                        << 0x10U) | (QData)((IData)(__Vfunc_load_element__2306__half_value)))
                                    : (((QData)((IData)(
                                                        (- (IData)(
                                                                   (__Vfunc_load_element__2306__word_value 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(__Vfunc_load_element__2306__word_value))))
                                : ((1U & (IData)(__Vfunc_load_element__2306__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2306__byte_value) 
                                                               >> 7U))))) 
                                        << 8U) | (QData)((IData)(__Vfunc_load_element__2306__byte_value)))
                                    : (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2306__nibble_value) 
                                                               >> 3U))))) 
                                        << 4U) | (QData)((IData)(__Vfunc_load_element__2306__nibble_value)))));
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q 
                            = __Vfunc_load_element__2306__Vfuncout;
                        if (([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__opcode 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__Vfuncout 
                                        = ((((((((0x60U 
                                                  == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__opcode)) 
                                                 || (0x61U 
                                                     == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__opcode))) 
                                                || (0x62U 
                                                    == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__opcode))) 
                                               || (0x64U 
                                                   == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__opcode))) 
                                              || (0x65U 
                                                  == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__opcode))) 
                                             || (0x66U 
                                                 == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__opcode))) 
                                            || (0x67U 
                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__opcode))) 
                                           || (0x63U 
                                               == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__opcode)));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2307__Vfuncout))) {
                            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_from_scalar0) {
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q 
                                    = (((QData)((IData)(
                                                        (- (IData)(
                                                                   (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar0 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar0)));
                                if (([&]() {
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2308__opcode 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q;
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2308__Vfuncout 
                                                = (0x63U 
                                                   == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2308__opcode));
                                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2308__Vfuncout))) {
                                    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_from_scalar1) {
                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_value_q 
                                            = (((QData)((IData)(
                                                                (- (IData)(
                                                                           (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar1 
                                                                            >> 0x1fU))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar1)));
                                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0xcU;
                                    } else {
                                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 8U;
                                    }
                                } else {
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0xcU;
                                }
                            } else {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 6U;
                            }
                        } else {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0xcU;
                        }
                    }
                }
            } else if (([&]() {
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__dtype 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_dtype;
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_addr));
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__Vfuncout 
                            = (((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__dtype)) 
                                & (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__byte_lane))) 
                               | ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__dtype)) 
                                  & (6U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__byte_lane))));
                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__element_crosses_beat__2309__Vfuncout))) {
                __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2310__fail_addr 
                    = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_addr);
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 4U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                    = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2310__fail_addr;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
            } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                         [3U])) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2311__fail_addr 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_addr;
                        __Vfunc_memory_status_to_task__2312__status 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                            [3U];
                        __Vfunc_memory_status_to_task__2312__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__2312__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2312__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__2312__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2311__fail_status 
                            = __Vfunc_memory_status_to_task__2312__Vfuncout;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2311__fail_status;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2311__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_value_q 
                            = (0U != (0xffU & (IData)(
                                                      (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                                       [3U] 
                                                       >> 
                                                       (0x3fU 
                                                        & VL_SHIFTL_III(6,32,32, 
                                                                        (7U 
                                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_addr)), 3U))))));
                        if ((0x67U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 4U;
                        } else if ((0U == (0xffU & (IData)(
                                                           (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                                            [3U] 
                                                            >> 
                                                            (0x3fU 
                                                             & VL_SHIFTL_III(6,32,32, 
                                                                             (7U 
                                                                              & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_addr)), 3U))))))) {
                            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_false_keep_dst) {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0xaU;
                            } else {
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__result_q = 0ULL;
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rmw_beat_q = 0ULL;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q 
                                    = (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype)) 
                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_high_nibble))
                                        ? 0xdU : 0xfU);
                            }
                        } else {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 4U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if (([&]() {
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_known__2313__opcode 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q;
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_known__2313__Vfuncout 
                            = ((0x60U <= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_known__2313__opcode)) 
                               & (0x69U >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_known__2313__opcode)));
                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_known__2313__Vfuncout))) {
                if ((((1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_version)) 
                      | (3U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_type))) 
                     | (0xc0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_bytes)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if ((IData)((0U != (0xfffe0300U 
                                           & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__numeric_cfg)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if ((IData)(((((0U != (0xfffffff0U 
                                              & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__vector_flags)) 
                                      | (0U != (0xc0U 
                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__broadcast_mode)))) 
                                     | (0U != (0xfefefefeU 
                                               & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU]))) 
                                    | (((5U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__compare_mode)) 
                                        | (2U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__overflow_mode))) 
                                       | (1U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_mode)))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if ((((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rows) 
                             | (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__length)) 
                            & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__valid_length))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rows) 
                             & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__length)) 
                            & ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__valid_length) 
                               | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__valid_length 
                                  > vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__length)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_nibble) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2323__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_base);
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fail_task__2323__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if ((((((0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_base 
                                         >> 0x14U)) 
                               | (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_base 
                                           >> 0x14U))) 
                              | ((([&]() {
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__opcode 
                                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q;
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__Vfuncout 
                                                    = 
                                                    ((((((((0x60U 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__opcode)) 
                                                           || (0x61U 
                                                               == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__opcode))) 
                                                          || (0x62U 
                                                              == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__opcode))) 
                                                         || (0x64U 
                                                             == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__opcode))) 
                                                        || (0x65U 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__opcode))) 
                                                       || (0x66U 
                                                           == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__opcode))) 
                                                      || (0x67U 
                                                          == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__opcode))) 
                                                     || (0x63U 
                                                         == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__opcode)));
                                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src1__2324__Vfuncout)) 
                                  & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_from_scalar0))) 
                                 & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_base 
                                             >> 0x14U)))) 
                             | ((([&]() {
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2325__opcode 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q;
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2325__Vfuncout 
                                                = (0x63U 
                                                   == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2325__opcode));
                                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_uses_src2__2325__Vfuncout)) 
                                 & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_from_scalar1))) 
                                & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_base 
                                            >> 0x14U)))) 
                            | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_enable) 
                               & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_base 
                                           >> 0x14U))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_enable) 
                              & (1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_mode))) 
                             | ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_enable)) 
                                & (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_mode)))) 
                            | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_enable) 
                               & ((1U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_elem_stride) 
                                  | ((1U < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rows) 
                                     & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_row_stride)))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if (((((((0x60U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q)) 
                                | (0x61U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                               | (0x64U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                              | (0x65U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                             | (0x67U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                            & (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_dtype) 
                                != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_dtype)) 
                               | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype) 
                                  != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_dtype))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if (((0x66U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q)) 
                            & (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_dtype) 
                                != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_dtype)) 
                               | (1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if ((((0x62U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q)) 
                             | (0x63U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                            & ((((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_dtype)) 
                                 | (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_dtype))) 
                                | (2U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype))) 
                               | ((0x63U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q)) 
                                  & (2U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_dtype)))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if ((((0x68U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q)) 
                             | (0x69U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q))) 
                            & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype) 
                               != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_dtype)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if (((0x68U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q)) 
                            & VL_GTS_III(32, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar0, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar1))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else if (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rows) 
                            | (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__length))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__row_q = 0U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_value_q = 1U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q 
                        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_enable)
                            ? 2U : 4U);
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0x11U;
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__progress_q = 0ULL;
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_task_valid) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[1U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][1U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[2U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][2U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[3U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][3U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[4U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][4U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[5U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][5U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[6U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][6U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[7U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][7U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[8U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][8U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[9U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][9U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xaU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0xaU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xbU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0xbU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xcU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0xcU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xdU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0xdU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0xeU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xfU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0xfU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x10U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x10U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x11U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x11U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x12U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x12U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x13U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x13U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x14U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x14U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x15U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x15U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x16U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x16U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x17U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x17U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x18U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x18U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x19U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x19U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x1aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x1bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x1cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x1dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x1eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x1fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x20U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x20U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x21U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x21U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x22U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x22U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x23U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x23U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x24U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x24U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x25U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x25U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x26U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x26U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x27U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x27U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x28U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x28U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x29U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x29U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x2aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x2aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x2bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x2bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x2cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x2cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x2dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x2dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x2eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x2eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x2fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x2fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x30U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x30U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x31U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x31U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x32U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x32U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x33U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x33U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x34U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x34U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x35U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x35U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x36U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x36U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x37U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x37U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x38U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x38U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x39U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x39U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x3aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x3aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x3bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x3bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x3cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x3cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x3dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x3dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x3eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x3eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x3fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select][0x3fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select];
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 1U;
            }
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q = 0U;
        IData/*31:0*/ __Vilp1;
        __Vilp1 = 0U;
        while ((__Vilp1 <= 0x3fU)) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[__Vilp1] 
                = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp1];
            __Vilp1 = ((IData)(1U) + __Vilp1);
        }
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__opcode_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__row_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_value_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_value_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_value_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__result_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rmw_beat_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_value_q = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__status_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__fault_addr_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__progress_q = 0ULL;
    }
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__4(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__4\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vfunc_npu_mem_to_task_status__2114__Vfuncout;
    __Vfunc_npu_mem_to_task_status__2114__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_npu_mem_to_task_status__2114__status;
    __Vfunc_npu_mem_to_task_status__2114__status = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2142__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2142__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2142__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2142__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2143__Vfuncout;
    __Vfunc_memory_status_to_task__2143__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2143__status;
    __Vfunc_memory_status_to_task__2143__status = 0;
    CData/*2:0*/ __Vfunc_dtype_bytes__2144__Vfuncout;
    __Vfunc_dtype_bytes__2144__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_bytes__2144__dtype;
    __Vfunc_dtype_bytes__2144__dtype = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2145__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2145__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2145__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2145__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2146__Vfuncout;
    __Vfunc_memory_status_to_task__2146__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2146__status;
    __Vfunc_memory_status_to_task__2146__status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2147__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2147__fail_addr = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2148__Vfuncout;
    __Vfunc_clip_to_dtype__2148__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2148__value;
    __Vfunc_clip_to_dtype__2148__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__2148__dtype;
    __Vfunc_clip_to_dtype__2148__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2148__minimum;
    __Vfunc_clip_to_dtype__2148__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2148__maximum;
    __Vfunc_clip_to_dtype__2148__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__2149__Vfuncout;
    __Vfunc_dtype_min__2149__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__2149__dtype;
    __Vfunc_dtype_min__2149__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__2150__Vfuncout;
    __Vfunc_dtype_max__2150__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__2150__dtype;
    __Vfunc_dtype_max__2150__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2151__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2151__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2152__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2152__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2152__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2152__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2153__Vfuncout;
    __Vfunc_memory_status_to_task__2153__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2153__status;
    __Vfunc_memory_status_to_task__2153__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2154__Vfuncout;
    __Vfunc_load_element__2154__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2154__beat;
    __Vfunc_load_element__2154__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2154__byte_lane;
    __Vfunc_load_element__2154__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__2154__high_nibble;
    __Vfunc_load_element__2154__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__2154__dtype;
    __Vfunc_load_element__2154__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__2154__byte_value;
    __Vfunc_load_element__2154__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__2154__nibble_value;
    __Vfunc_load_element__2154__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__2154__half_value;
    __Vfunc_load_element__2154__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__2154__word_value;
    __Vfunc_load_element__2154__word_value = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__value = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2156__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2156__fail_addr = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2157__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2157__fail_addr = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2158__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2158__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2159__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2159__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2159__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2159__opcode = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__rank_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__rank_value = 0;
    VlWide<5>/*159:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes;
    VL_ZERO_W(160, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes);
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product);
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__dimension;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__dimension = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__opcode = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2169__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2169__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2173__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2173__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2173__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2173__opcode = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2179__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2179__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2199__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2199__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2199__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2199__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2200__Vfuncout;
    __Vfunc_memory_status_to_task__2200__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2200__status;
    __Vfunc_memory_status_to_task__2200__status = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2201__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2201__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2201__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2201__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2202__Vfuncout;
    __Vfunc_memory_status_to_task__2202__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2202__status;
    __Vfunc_memory_status_to_task__2202__status = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__value = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__multiplier;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__multiplier = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_value = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product);
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted);
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product);
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding_bias;
    VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding_bias);
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount = 0;
    QData/*63:0*/ __Vfunc_dtype_min__2204__Vfuncout;
    __Vfunc_dtype_min__2204__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__2204__dtype;
    __Vfunc_dtype_min__2204__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__2205__Vfuncout;
    __Vfunc_dtype_max__2205__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__2205__dtype;
    __Vfunc_dtype_max__2205__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2206__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2206__fail_addr = 0;
    QData/*63:0*/ __Vfunc_wrap_to_dtype__2207__Vfuncout;
    __Vfunc_wrap_to_dtype__2207__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_wrap_to_dtype__2207__value;
    __Vfunc_wrap_to_dtype__2207__value = 0;
    CData/*1:0*/ __Vfunc_wrap_to_dtype__2207__dtype;
    __Vfunc_wrap_to_dtype__2207__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2208__Vfuncout;
    __Vfunc_clip_to_dtype__2208__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2208__value;
    __Vfunc_clip_to_dtype__2208__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__2208__dtype;
    __Vfunc_clip_to_dtype__2208__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2208__minimum;
    __Vfunc_clip_to_dtype__2208__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2208__maximum;
    __Vfunc_clip_to_dtype__2208__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__2209__Vfuncout;
    __Vfunc_dtype_min__2209__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__2209__dtype;
    __Vfunc_dtype_min__2209__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__2210__Vfuncout;
    __Vfunc_dtype_max__2210__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__2210__dtype;
    __Vfunc_dtype_max__2210__dtype = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2211__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2211__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2211__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2211__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2212__Vfuncout;
    __Vfunc_memory_status_to_task__2212__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2212__status;
    __Vfunc_memory_status_to_task__2212__status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2213__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2213__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2214__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2214__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2214__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2214__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2215__Vfuncout;
    __Vfunc_memory_status_to_task__2215__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2215__status;
    __Vfunc_memory_status_to_task__2215__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2216__Vfuncout;
    __Vfunc_load_element__2216__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2216__beat;
    __Vfunc_load_element__2216__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2216__byte_lane;
    __Vfunc_load_element__2216__byte_lane = 0;
    IData/*31:0*/ __Vfunc_load_element__2216__word_value;
    __Vfunc_load_element__2216__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2217__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2217__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2217__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2217__byte_lane = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2218__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2218__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2219__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2219__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2219__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2219__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2220__Vfuncout;
    __Vfunc_memory_status_to_task__2220__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2220__status;
    __Vfunc_memory_status_to_task__2220__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2221__Vfuncout;
    __Vfunc_load_element__2221__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2221__beat;
    __Vfunc_load_element__2221__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2221__byte_lane;
    __Vfunc_load_element__2221__byte_lane = 0;
    IData/*31:0*/ __Vfunc_load_element__2221__word_value;
    __Vfunc_load_element__2221__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2222__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2222__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2222__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2222__byte_lane = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2223__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2223__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2224__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2224__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2224__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2224__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2225__Vfuncout;
    __Vfunc_memory_status_to_task__2225__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2225__status;
    __Vfunc_memory_status_to_task__2225__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2226__Vfuncout;
    __Vfunc_load_element__2226__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2226__beat;
    __Vfunc_load_element__2226__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2226__byte_lane;
    __Vfunc_load_element__2226__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__2226__high_nibble;
    __Vfunc_load_element__2226__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__2226__dtype;
    __Vfunc_load_element__2226__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__2226__byte_value;
    __Vfunc_load_element__2226__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__2226__nibble_value;
    __Vfunc_load_element__2226__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__2226__half_value;
    __Vfunc_load_element__2226__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__2226__word_value;
    __Vfunc_load_element__2226__word_value = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2227__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2227__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2227__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2227__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2228__Vfuncout;
    __Vfunc_memory_status_to_task__2228__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2228__status;
    __Vfunc_memory_status_to_task__2228__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2229__Vfuncout;
    __Vfunc_load_element__2229__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2229__beat;
    __Vfunc_load_element__2229__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2229__byte_lane;
    __Vfunc_load_element__2229__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__2229__high_nibble;
    __Vfunc_load_element__2229__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__2229__dtype;
    __Vfunc_load_element__2229__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__2229__byte_value;
    __Vfunc_load_element__2229__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__2229__nibble_value;
    __Vfunc_load_element__2229__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__2229__half_value;
    __Vfunc_load_element__2229__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__2229__word_value;
    __Vfunc_load_element__2229__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2231__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2231__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2233__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2233__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2235__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2235__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_known__2236__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_known__2236__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_known__2236__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_known__2236__opcode = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__size;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__size = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__tile;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__tile = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__size;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__size = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__tile;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__tile = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__size;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__size = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__tile;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__tile = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2535__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2535__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2535__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2535__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2536__Vfuncout;
    __Vfunc_memory_status_to_task__2536__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2536__status;
    __Vfunc_memory_status_to_task__2536__status = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2537__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2537__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2537__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2537__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2538__Vfuncout;
    __Vfunc_memory_status_to_task__2538__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2538__status;
    __Vfunc_memory_status_to_task__2538__status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2539__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2539__fail_addr = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2542__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2542__fail_addr = 0;
    QData/*63:0*/ __Vfunc_wrap_to_dtype__2543__Vfuncout;
    __Vfunc_wrap_to_dtype__2543__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_wrap_to_dtype__2543__value;
    __Vfunc_wrap_to_dtype__2543__value = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2544__Vfuncout;
    __Vfunc_clip_to_dtype__2544__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2544__value;
    __Vfunc_clip_to_dtype__2544__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__2544__dtype;
    __Vfunc_clip_to_dtype__2544__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2544__minimum;
    __Vfunc_clip_to_dtype__2544__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2544__maximum;
    __Vfunc_clip_to_dtype__2544__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__2545__Vfuncout;
    __Vfunc_dtype_min__2545__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__2545__dtype;
    __Vfunc_dtype_min__2545__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__2546__Vfuncout;
    __Vfunc_dtype_max__2546__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__2546__dtype;
    __Vfunc_dtype_max__2546__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2547__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2547__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2547__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2547__byte_lane = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2548__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2548__fail_addr = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2551__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2551__fail_addr = 0;
    QData/*63:0*/ __Vfunc_wrap_to_dtype__2552__Vfuncout;
    __Vfunc_wrap_to_dtype__2552__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_wrap_to_dtype__2552__value;
    __Vfunc_wrap_to_dtype__2552__value = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2553__Vfuncout;
    __Vfunc_clip_to_dtype__2553__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2553__value;
    __Vfunc_clip_to_dtype__2553__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__2553__dtype;
    __Vfunc_clip_to_dtype__2553__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2553__minimum;
    __Vfunc_clip_to_dtype__2553__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2553__maximum;
    __Vfunc_clip_to_dtype__2553__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__2554__Vfuncout;
    __Vfunc_dtype_min__2554__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__2554__dtype;
    __Vfunc_dtype_min__2554__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__2555__Vfuncout;
    __Vfunc_dtype_max__2555__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__2555__dtype;
    __Vfunc_dtype_max__2555__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2556__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2556__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2556__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2556__byte_lane = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2557__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2557__fail_addr = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2558__Vfuncout;
    __Vfunc_clip_to_dtype__2558__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2558__value;
    __Vfunc_clip_to_dtype__2558__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__2558__dtype;
    __Vfunc_clip_to_dtype__2558__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2558__minimum;
    __Vfunc_clip_to_dtype__2558__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2558__maximum;
    __Vfunc_clip_to_dtype__2558__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__2559__Vfuncout;
    __Vfunc_dtype_min__2559__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__2559__dtype;
    __Vfunc_dtype_min__2559__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__2560__Vfuncout;
    __Vfunc_dtype_max__2560__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__2560__dtype;
    __Vfunc_dtype_max__2560__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2562__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2562__fail_addr = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2563__Vfuncout;
    __Vfunc_clip_to_dtype__2563__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2563__value;
    __Vfunc_clip_to_dtype__2563__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__2563__dtype;
    __Vfunc_clip_to_dtype__2563__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2563__minimum;
    __Vfunc_clip_to_dtype__2563__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2563__maximum;
    __Vfunc_clip_to_dtype__2563__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__2564__Vfuncout;
    __Vfunc_dtype_min__2564__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__2564__dtype;
    __Vfunc_dtype_min__2564__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__2565__Vfuncout;
    __Vfunc_dtype_max__2565__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__2565__dtype;
    __Vfunc_dtype_max__2565__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2567__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2567__fail_addr = 0;
    CData/*0:0*/ __Vfunc_fp32_less_than__2568__Vfuncout;
    __Vfunc_fp32_less_than__2568__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_less_than__2568__lhs;
    __Vfunc_fp32_less_than__2568__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_less_than__2568__rhs;
    __Vfunc_fp32_less_than__2568__rhs = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2569__Vfuncout;
    __Vfunc_fp32_is_nan__2569__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__2569__bits;
    __Vfunc_fp32_is_nan__2569__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2569__unused_sign;
    __Vfunc_fp32_is_nan__2569__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2570__Vfuncout;
    __Vfunc_fp32_is_nan__2570__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__2570__bits;
    __Vfunc_fp32_is_nan__2570__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2570__unused_sign;
    __Vfunc_fp32_is_nan__2570__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_equal__2571__Vfuncout;
    __Vfunc_fp32_equal__2571__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_equal__2571__lhs;
    __Vfunc_fp32_equal__2571__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_equal__2571__rhs;
    __Vfunc_fp32_equal__2571__rhs = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2572__Vfuncout;
    __Vfunc_fp32_is_nan__2572__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__2572__bits;
    __Vfunc_fp32_is_nan__2572__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2572__unused_sign;
    __Vfunc_fp32_is_nan__2572__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2573__Vfuncout;
    __Vfunc_fp32_is_nan__2573__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__2573__bits;
    __Vfunc_fp32_is_nan__2573__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2573__unused_sign;
    __Vfunc_fp32_is_nan__2573__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2574__Vfuncout;
    __Vfunc_fp32_is_zero__2574__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_zero__2574__bits;
    __Vfunc_fp32_is_zero__2574__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2574__unused_sign;
    __Vfunc_fp32_is_zero__2574__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2575__Vfuncout;
    __Vfunc_fp32_is_zero__2575__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_zero__2575__bits;
    __Vfunc_fp32_is_zero__2575__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2575__unused_sign;
    __Vfunc_fp32_is_zero__2575__unused_sign = 0;
    QData/*63:0*/ __Vfunc_dtype_min__2576__Vfuncout;
    __Vfunc_dtype_min__2576__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__2576__dtype;
    __Vfunc_dtype_min__2576__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__2577__Vfuncout;
    __Vfunc_dtype_max__2577__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__2577__dtype;
    __Vfunc_dtype_max__2577__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2578__Vfuncout;
    __Vfunc_clip_to_dtype__2578__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2578__value;
    __Vfunc_clip_to_dtype__2578__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__2578__dtype;
    __Vfunc_clip_to_dtype__2578__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2578__minimum;
    __Vfunc_clip_to_dtype__2578__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__2578__maximum;
    __Vfunc_clip_to_dtype__2578__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__2579__Vfuncout;
    __Vfunc_dtype_min__2579__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__2579__dtype;
    __Vfunc_dtype_min__2579__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__2580__Vfuncout;
    __Vfunc_dtype_max__2580__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__2580__dtype;
    __Vfunc_dtype_max__2580__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2581__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2581__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2583__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2583__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2584__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2584__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2584__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2584__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2585__Vfuncout;
    __Vfunc_memory_status_to_task__2585__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2585__status;
    __Vfunc_memory_status_to_task__2585__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2586__Vfuncout;
    __Vfunc_load_element__2586__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2586__beat;
    __Vfunc_load_element__2586__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2586__byte_lane;
    __Vfunc_load_element__2586__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__2586__high_nibble;
    __Vfunc_load_element__2586__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__2586__dtype;
    __Vfunc_load_element__2586__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__2586__byte_value;
    __Vfunc_load_element__2586__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__2586__nibble_value;
    __Vfunc_load_element__2586__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__2586__half_value;
    __Vfunc_load_element__2586__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__2586__word_value;
    __Vfunc_load_element__2586__word_value = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2587__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2587__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2587__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2587__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2588__Vfuncout;
    __Vfunc_memory_status_to_task__2588__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2588__status;
    __Vfunc_memory_status_to_task__2588__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2589__Vfuncout;
    __Vfunc_load_element__2589__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2589__beat;
    __Vfunc_load_element__2589__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2589__byte_lane;
    __Vfunc_load_element__2589__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__2589__high_nibble;
    __Vfunc_load_element__2589__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__2589__dtype;
    __Vfunc_load_element__2589__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__2589__byte_value;
    __Vfunc_load_element__2589__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__2589__nibble_value;
    __Vfunc_load_element__2589__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__2589__half_value;
    __Vfunc_load_element__2589__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__2589__word_value;
    __Vfunc_load_element__2589__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2591__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2591__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2592__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2592__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2592__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2592__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2593__Vfuncout;
    __Vfunc_memory_status_to_task__2593__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2593__status;
    __Vfunc_memory_status_to_task__2593__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2594__Vfuncout;
    __Vfunc_load_element__2594__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2594__beat;
    __Vfunc_load_element__2594__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2594__byte_lane;
    __Vfunc_load_element__2594__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__2594__high_nibble;
    __Vfunc_load_element__2594__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__2594__dtype;
    __Vfunc_load_element__2594__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__2594__byte_value;
    __Vfunc_load_element__2594__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__2594__nibble_value;
    __Vfunc_load_element__2594__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__2594__half_value;
    __Vfunc_load_element__2594__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__2594__word_value;
    __Vfunc_load_element__2594__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2596__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2596__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2597__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2597__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2597__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2597__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2598__Vfuncout;
    __Vfunc_memory_status_to_task__2598__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2598__status;
    __Vfunc_memory_status_to_task__2598__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2600__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2600__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2602__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2602__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2603__fail_status;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2603__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2603__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2603__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__2604__Vfuncout;
    __Vfunc_memory_status_to_task__2604__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__2604__status;
    __Vfunc_memory_status_to_task__2604__status = 0;
    QData/*63:0*/ __Vfunc_load_element__2605__Vfuncout;
    __Vfunc_load_element__2605__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__2605__beat;
    __Vfunc_load_element__2605__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__2605__byte_lane;
    __Vfunc_load_element__2605__byte_lane = 0;
    IData/*31:0*/ __Vfunc_load_element__2605__word_value;
    __Vfunc_load_element__2605__word_value = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2606__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2606__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2607__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2607__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2607__byte_lane;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2607__byte_lane = 0;
    QData/*47:0*/ __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2608__fail_addr;
    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2608__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__opcode;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__opcode = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__function_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__function_value = 0;
    CData/*0:0*/ __Vfunc_fp32_finite_positive__2625__Vfuncout;
    __Vfunc_fp32_finite_positive__2625__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_finite_positive__2625__bits;
    __Vfunc_fp32_finite_positive__2625__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_finite_positive__2626__Vfuncout;
    __Vfunc_fp32_finite_positive__2626__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_finite_positive__2626__bits;
    __Vfunc_fp32_finite_positive__2626__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_finite_positive__2627__Vfuncout;
    __Vfunc_fp32_finite_positive__2627__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_finite_positive__2627__bits;
    __Vfunc_fp32_finite_positive__2627__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_finite_positive__2628__Vfuncout;
    __Vfunc_fp32_finite_positive__2628__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_finite_positive__2628__bits;
    __Vfunc_fp32_finite_positive__2628__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_finite_positive__2630__Vfuncout;
    __Vfunc_fp32_finite_positive__2630__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_finite_positive__2630__bits;
    __Vfunc_fp32_finite_positive__2630__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_less_than__2633__Vfuncout;
    __Vfunc_fp32_less_than__2633__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_less_than__2633__lhs;
    __Vfunc_fp32_less_than__2633__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_less_than__2633__rhs;
    __Vfunc_fp32_less_than__2633__rhs = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2634__Vfuncout;
    __Vfunc_fp32_is_nan__2634__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__2634__bits;
    __Vfunc_fp32_is_nan__2634__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2634__unused_sign;
    __Vfunc_fp32_is_nan__2634__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2635__Vfuncout;
    __Vfunc_fp32_is_nan__2635__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__2635__bits;
    __Vfunc_fp32_is_nan__2635__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2635__unused_sign;
    __Vfunc_fp32_is_nan__2635__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_equal__2636__Vfuncout;
    __Vfunc_fp32_equal__2636__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_equal__2636__lhs;
    __Vfunc_fp32_equal__2636__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_equal__2636__rhs;
    __Vfunc_fp32_equal__2636__rhs = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2637__Vfuncout;
    __Vfunc_fp32_is_nan__2637__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__2637__bits;
    __Vfunc_fp32_is_nan__2637__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2637__unused_sign;
    __Vfunc_fp32_is_nan__2637__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2638__Vfuncout;
    __Vfunc_fp32_is_nan__2638__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__2638__bits;
    __Vfunc_fp32_is_nan__2638__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2638__unused_sign;
    __Vfunc_fp32_is_nan__2638__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2639__Vfuncout;
    __Vfunc_fp32_is_zero__2639__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_zero__2639__bits;
    __Vfunc_fp32_is_zero__2639__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2639__unused_sign;
    __Vfunc_fp32_is_zero__2639__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2640__Vfuncout;
    __Vfunc_fp32_is_zero__2640__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_zero__2640__bits;
    __Vfunc_fp32_is_zero__2640__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2640__unused_sign;
    __Vfunc_fp32_is_zero__2640__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2641__Vfuncout;
    __Vfunc_fp32_is_nan__2641__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__2641__bits;
    __Vfunc_fp32_is_nan__2641__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2642__Vfuncout;
    __Vfunc_fp32_is_nan__2642__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__2642__bits;
    __Vfunc_fp32_is_nan__2642__bits = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<4>/*127:0*/ __Vtemp_6;
    VlWide<4>/*127:0*/ __Vtemp_7;
    VlWide<4>/*127:0*/ __Vtemp_8;
    VlWide<4>/*127:0*/ __Vtemp_9;
    VlWide<4>/*127:0*/ __Vtemp_10;
    VlWide<4>/*127:0*/ __Vtemp_11;
    VlWide<4>/*127:0*/ __Vtemp_13;
    VlWide<4>/*127:0*/ __Vtemp_14;
    VlWide<4>/*127:0*/ __Vtemp_15;
    VlWide<4>/*127:0*/ __Vtemp_16;
    VlWide<4>/*127:0*/ __Vtemp_17;
    VlWide<4>/*127:0*/ __Vtemp_18;
    VlWide<4>/*127:0*/ __Vtemp_19;
    VlWide<4>/*127:0*/ __Vtemp_20;
    VlWide<4>/*127:0*/ __Vtemp_21;
    VlWide<4>/*127:0*/ __Vtemp_22;
    VlWide<4>/*127:0*/ __Vtemp_23;
    VlWide<4>/*127:0*/ __Vtemp_24;
    VlWide<4>/*127:0*/ __Vtemp_25;
    VlWide<4>/*127:0*/ __Vtemp_26;
    VlWide<4>/*127:0*/ __Vtemp_27;
    VlWide<4>/*127:0*/ __Vtemp_28;
    VlWide<4>/*127:0*/ __Vtemp_29;
    VlWide<4>/*127:0*/ __Vtemp_33;
    VlWide<4>/*127:0*/ __Vtemp_34;
    VlWide<4>/*127:0*/ __Vtemp_35;
    VlWide<4>/*127:0*/ __Vtemp_36;
    VlWide<4>/*127:0*/ __Vtemp_37;
    VlWide<4>/*127:0*/ __Vtemp_38;
    VlWide<4>/*127:0*/ __Vtemp_39;
    VlWide<4>/*127:0*/ __Vtemp_40;
    VlWide<4>/*127:0*/ __Vtemp_41;
    VlWide<4>/*127:0*/ __Vtemp_42;
    // Body
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) {
        if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0U;
            } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0U;
            } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q) {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0U;
                    }
                } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                         [2U])) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2199__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr);
                        __Vfunc_memory_status_to_task__2200__status 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                            [2U];
                        __Vfunc_memory_status_to_task__2200__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__2200__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2200__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__2200__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2199__fail_status 
                            = __Vfunc_memory_status_to_task__2200__Vfuncout;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2199__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2199__fail_status;
                    } else {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__progress_q 
                            = (1ULL + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__progress_q);
                        if ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q) 
                             < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_n)) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q 
                                = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q);
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 2U;
                        } else if ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q) 
                                    < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_m)) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q 
                                = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q);
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q = 0U;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 2U;
                        } else if ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_q) 
                                    < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_count)) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_q 
                                = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_q);
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q = 0U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q = 0U;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 2U;
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 0U;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                        }
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x12U;
                }
            } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                     [2U])) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2201__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr);
                    __Vfunc_memory_status_to_task__2202__status 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                        [2U];
                    __Vfunc_memory_status_to_task__2202__Vfuncout 
                        = ((0U == (IData)(__Vfunc_memory_status_to_task__2202__status))
                            ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2202__status))
                                     ? 6U : ((2U == (IData)(__Vfunc_memory_status_to_task__2202__status))
                                              ? 5U : 4U)));
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2201__fail_status 
                        = __Vfunc_memory_status_to_task__2202__Vfuncout;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2201__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2201__fail_status;
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__rmw_beat_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                        [2U];
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x11U;
                }
            }
        } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                        if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x10U;
                        }
                    } else {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__epilogue_value 
                            = ((0x43U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q))
                                ? 0ULL : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q);
                        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__relu_enable) 
                             & VL_GTS_IQQ(64, 0ULL, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__epilogue_value))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__epilogue_value = 0ULL;
                        }
                        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__requant_value 
                                = (([&]() {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__round_mode;
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_value 
                                            = (0xffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_entry_q 
                                                          >> 0x20U)));
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__multiplier 
                                            = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_entry_q);
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__value 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__epilogue_value;
                                        VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product);
                                        VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted);
                                        VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product);
                                        VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding_bias);
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount = 0;
                                        {
                                            VL_EXTENDS_WQ(128,64, __Vtemp_1, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__value);
                                            VL_EXTENDS_WQ(128,33, __Vtemp_2, (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__multiplier)));
                                            VL_MULS_WWW(128, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product, __Vtemp_1, __Vtemp_2);
                                            if (VL_GTS_III(32, 0U, 
                                                           VL_EXTENDS_II(32,8, (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_value)))) {
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount 
                                                    = 
                                                    (- 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_value) 
                                                                      >> 7U)))) 
                                                       << 8U) 
                                                      | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_value)));
                                                VL_SHIFTL_WWI(128,128,32, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount);
                                            } else if (
                                                       (0U 
                                                        == 
                                                        VL_EXTENDS_II(32,8, (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_value)))) {
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[0U] 
                                                    = 
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product[0U];
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[1U] 
                                                    = 
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product[1U];
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[2U] 
                                                    = 
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product[2U];
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[3U] 
                                                    = 
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product[3U];
                                            } else {
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount 
                                                    = 
                                                    (((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_value) 
                                                                     >> 7U)))) 
                                                      << 8U) 
                                                     | (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_value));
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding_bias[0U] = 0U;
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding_bias[1U] = 0U;
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding_bias[2U] = 0U;
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding_bias[3U] = 0U;
                                                if (
                                                    ((0U 
                                                      == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding)) 
                                                     & VL_LTS_III(32, 0U, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount))) {
                                                    __Vtemp_3[0U] = 0U;
                                                    __Vtemp_3[1U] = 0U;
                                                    __Vtemp_3[2U] = 0U;
                                                    __Vtemp_3[3U] = 0U;
                                                    VL_NEGATE_W(4, __Vtemp_4, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product);
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product[0U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_3, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product)
                                                          ? 
                                                         __Vtemp_4[0U]
                                                          : 
                                                         __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product[0U]);
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product[1U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_3, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product)
                                                          ? 
                                                         __Vtemp_4[1U]
                                                          : 
                                                         __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product[1U]);
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product[2U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_3, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product)
                                                          ? 
                                                         __Vtemp_4[2U]
                                                          : 
                                                         __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product[2U]);
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product[3U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_3, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product)
                                                          ? 
                                                         __Vtemp_4[3U]
                                                          : 
                                                         __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product[3U]);
                                                    __Vtemp_6[0U] = 1U;
                                                    __Vtemp_6[1U] = 0U;
                                                    __Vtemp_6[2U] = 0U;
                                                    __Vtemp_6[3U] = 0U;
                                                    VL_SHIFTL_WWI(128,128,32, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding_bias, __Vtemp_6, 
                                                                  (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount 
                                                                   - (IData)(1U)));
                                                    VL_ADD_W(4, __Vtemp_7, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding_bias);
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product[0U] 
                                                        = 
                                                        __Vtemp_7[0U];
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product[1U] 
                                                        = 
                                                        __Vtemp_7[1U];
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product[2U] 
                                                        = 
                                                        __Vtemp_7[2U];
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product[3U] 
                                                        = 
                                                        __Vtemp_7[3U];
                                                    __Vtemp_8[0U] = 0U;
                                                    __Vtemp_8[1U] = 0U;
                                                    __Vtemp_8[2U] = 0U;
                                                    __Vtemp_8[3U] = 0U;
                                                    VL_SHIFTRS_WWI(128,128,32, __Vtemp_9, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount);
                                                    VL_NEGATE_W(4, __Vtemp_10, __Vtemp_9);
                                                    VL_SHIFTRS_WWI(128,128,32, __Vtemp_11, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__absolute_product, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount);
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[0U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_8, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product)
                                                          ? 
                                                         __Vtemp_10[0U]
                                                          : 
                                                         __Vtemp_11[0U]);
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[1U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_8, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product)
                                                          ? 
                                                         __Vtemp_10[1U]
                                                          : 
                                                         __Vtemp_11[1U]);
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[2U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_8, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product)
                                                          ? 
                                                         __Vtemp_10[2U]
                                                          : 
                                                         __Vtemp_11[2U]);
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[3U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_8, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product)
                                                          ? 
                                                         __Vtemp_10[3U]
                                                          : 
                                                         __Vtemp_11[3U]);
                                                } else {
                                                    __Vtemp_13[0U] = 0U;
                                                    __Vtemp_13[1U] = 0U;
                                                    __Vtemp_13[2U] = 0U;
                                                    __Vtemp_13[3U] = 0U;
                                                    __Vtemp_14[0U] = 1U;
                                                    __Vtemp_14[1U] = 0U;
                                                    __Vtemp_14[2U] = 0U;
                                                    __Vtemp_14[3U] = 0U;
                                                    VL_SHIFTL_WWI(128,128,32, __Vtemp_15, __Vtemp_14, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount);
                                                    __Vtemp_16[0U] = 1U;
                                                    __Vtemp_16[1U] = 0U;
                                                    __Vtemp_16[2U] = 0U;
                                                    __Vtemp_16[3U] = 0U;
                                                    VL_SUB_W(4, __Vtemp_17, __Vtemp_15, __Vtemp_16);
                                                    VL_ADD_W(4, __Vtemp_18, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product, __Vtemp_17);
                                                    VL_SHIFTRS_WWI(128,128,32, __Vtemp_19, __Vtemp_18, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount);
                                                    __Vtemp_20[0U] = 0U;
                                                    __Vtemp_20[1U] = 0U;
                                                    __Vtemp_20[2U] = 0U;
                                                    __Vtemp_20[3U] = 0U;
                                                    VL_NEGATE_W(4, __Vtemp_21, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product);
                                                    __Vtemp_22[0U] = 1U;
                                                    __Vtemp_22[1U] = 0U;
                                                    __Vtemp_22[2U] = 0U;
                                                    __Vtemp_22[3U] = 0U;
                                                    VL_SHIFTL_WWI(128,128,32, __Vtemp_23, __Vtemp_22, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount);
                                                    __Vtemp_24[0U] = 1U;
                                                    __Vtemp_24[1U] = 0U;
                                                    __Vtemp_24[2U] = 0U;
                                                    __Vtemp_24[3U] = 0U;
                                                    VL_SUB_W(4, __Vtemp_25, __Vtemp_23, __Vtemp_24);
                                                    VL_ADD_W(4, __Vtemp_26, __Vtemp_21, __Vtemp_25);
                                                    VL_SHIFTRS_WWI(128,128,32, __Vtemp_27, __Vtemp_26, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount);
                                                    VL_NEGATE_W(4, __Vtemp_28, __Vtemp_27);
                                                    VL_SHIFTRS_WWI(128,128,32, __Vtemp_29, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shift_amount);
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[0U] 
                                                        = 
                                                        (((2U 
                                                           == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding)) 
                                                          & VL_LTS_IWW(128, __Vtemp_13, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product))
                                                          ? 
                                                         __Vtemp_19[0U]
                                                          : 
                                                         (((3U 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding)) 
                                                           & VL_GTS_IWW(128, __Vtemp_20, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product))
                                                           ? 
                                                          __Vtemp_28[0U]
                                                           : 
                                                          __Vtemp_29[0U]));
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[1U] 
                                                        = 
                                                        (((2U 
                                                           == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding)) 
                                                          & VL_LTS_IWW(128, __Vtemp_13, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product))
                                                          ? 
                                                         __Vtemp_19[1U]
                                                          : 
                                                         (((3U 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding)) 
                                                           & VL_GTS_IWW(128, __Vtemp_20, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product))
                                                           ? 
                                                          __Vtemp_28[1U]
                                                           : 
                                                          __Vtemp_29[1U]));
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[2U] 
                                                        = 
                                                        (((2U 
                                                           == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding)) 
                                                          & VL_LTS_IWW(128, __Vtemp_13, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product))
                                                          ? 
                                                         __Vtemp_19[2U]
                                                          : 
                                                         (((3U 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding)) 
                                                           & VL_GTS_IWW(128, __Vtemp_20, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product))
                                                           ? 
                                                          __Vtemp_28[2U]
                                                           : 
                                                          __Vtemp_29[2U]));
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[3U] 
                                                        = 
                                                        (((2U 
                                                           == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding)) 
                                                          & VL_LTS_IWW(128, __Vtemp_13, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product))
                                                          ? 
                                                         __Vtemp_19[3U]
                                                          : 
                                                         (((3U 
                                                            == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__rounding)) 
                                                           & VL_GTS_IWW(128, __Vtemp_20, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__product))
                                                           ? 
                                                          __Vtemp_28[3U]
                                                           : 
                                                          __Vtemp_29[3U]));
                                                }
                                            }
                                            if (((((QData)((IData)(
                                                                   __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[3U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[2U]))) 
                                                 != 
                                                 (- (QData)((IData)(
                                                                    (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[1U] 
                                                                     >> 0x1fU)))))) {
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__Vfuncout 
                                                    = 
                                                    ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[3U] 
                                                      >> 0x1fU)
                                                      ? 0x8000000000000000ULL
                                                      : 0x7fffffffffffffffULL);
                                                goto __Vlabel0;
                                            }
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__Vfuncout 
                                                = (
                                                   ((QData)((IData)(
                                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__shifted[0U])));
                                            __Vlabel0: ;
                                        }
                                    }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requantize__2203__Vfuncout) 
                                   + (((QData)((IData)(
                                                       (- (IData)(
                                                                  (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__output_zero_point 
                                                                   >> 0x1fU))))) 
                                       << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__output_zero_point))));
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__epilogue_value 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__requant_value;
                        }
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__overflow 
                            = (VL_LTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__epilogue_value, 
                                          ([&]() {
                                        __Vfunc_dtype_min__2204__dtype 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype;
                                        __Vfunc_dtype_min__2204__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_min__2204__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__2204__dtype))
                                                    ? 0xffffffffffff8000ULL
                                                    : 0xffffffff80000000ULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__2204__dtype))
                                                    ? 0xffffffffffffff80ULL
                                                    : 0xfffffffffffffff8ULL));
                                    }(), __Vfunc_dtype_min__2204__Vfuncout)) 
                               | VL_GTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__epilogue_value, 
                                            ([&]() {
                                        __Vfunc_dtype_max__2205__dtype 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype;
                                        __Vfunc_dtype_max__2205__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_max__2205__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__2205__dtype))
                                                    ? 0x7fffULL
                                                    : 0x7fffffffULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__2205__dtype))
                                                    ? 0x7fULL
                                                    : 7ULL));
                                    }(), __Vfunc_dtype_max__2205__Vfuncout)));
                        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__overflow) 
                             & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__overflow_mode)))) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2206__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr);
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 0xcU;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2206__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__result_q 
                                = ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__overflow_mode))
                                    ? ([&]() {
                                        __Vfunc_wrap_to_dtype__2207__dtype 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype;
                                        __Vfunc_wrap_to_dtype__2207__value 
                                            = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__epilogue_value);
                                        __Vfunc_wrap_to_dtype__2207__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_wrap_to_dtype__2207__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_wrap_to_dtype__2207__dtype))
                                                    ? 
                                                   (((- (QData)((IData)(
                                                                        (1U 
                                                                         & (__Vfunc_wrap_to_dtype__2207__value 
                                                                            >> 0xfU))))) 
                                                     << 0x10U) 
                                                    | (QData)((IData)(
                                                                      (0xffffU 
                                                                       & __Vfunc_wrap_to_dtype__2207__value))))
                                                    : 
                                                   (((QData)((IData)(
                                                                     (- (IData)(
                                                                                (__Vfunc_wrap_to_dtype__2207__value 
                                                                                >> 0x1fU))))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(__Vfunc_wrap_to_dtype__2207__value))))
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_wrap_to_dtype__2207__dtype))
                                                    ? 
                                                   (((- (QData)((IData)(
                                                                        (1U 
                                                                         & (__Vfunc_wrap_to_dtype__2207__value 
                                                                            >> 7U))))) 
                                                     << 8U) 
                                                    | (QData)((IData)(
                                                                      (0xffU 
                                                                       & __Vfunc_wrap_to_dtype__2207__value))))
                                                    : 
                                                   (((- (QData)((IData)(
                                                                        (1U 
                                                                         & (__Vfunc_wrap_to_dtype__2207__value 
                                                                            >> 3U))))) 
                                                     << 4U) 
                                                    | (QData)((IData)(
                                                                      (0xfU 
                                                                       & __Vfunc_wrap_to_dtype__2207__value))))));
                                    }(), __Vfunc_wrap_to_dtype__2207__Vfuncout)
                                    : ([&]() {
                                        __Vfunc_clip_to_dtype__2208__dtype 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype;
                                        __Vfunc_clip_to_dtype__2208__value 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__unnamedblk1__DOT__epilogue_value;
                                        __Vfunc_clip_to_dtype__2208__minimum = 0;
                                        __Vfunc_clip_to_dtype__2208__maximum = 0;
                                        {
                                            __Vfunc_dtype_min__2209__dtype 
                                                = __Vfunc_clip_to_dtype__2208__dtype;
                                            __Vfunc_dtype_min__2209__Vfuncout 
                                                = (
                                                   (2U 
                                                    & (IData)(__Vfunc_dtype_min__2209__dtype))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_dtype_min__2209__dtype))
                                                     ? 0xffffffffffff8000ULL
                                                     : 0xffffffff80000000ULL)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_dtype_min__2209__dtype))
                                                     ? 0xffffffffffffff80ULL
                                                     : 0xfffffffffffffff8ULL));
                                            __Vfunc_clip_to_dtype__2208__minimum 
                                                = __Vfunc_dtype_min__2209__Vfuncout;
                                            __Vfunc_dtype_max__2210__dtype 
                                                = __Vfunc_clip_to_dtype__2208__dtype;
                                            __Vfunc_dtype_max__2210__Vfuncout 
                                                = (
                                                   (2U 
                                                    & (IData)(__Vfunc_dtype_max__2210__dtype))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_dtype_max__2210__dtype))
                                                     ? 0x7fffULL
                                                     : 0x7fffffffULL)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_dtype_max__2210__dtype))
                                                     ? 0x7fULL
                                                     : 7ULL));
                                            __Vfunc_clip_to_dtype__2208__maximum 
                                                = __Vfunc_dtype_max__2210__Vfuncout;
                                            if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__2208__value, __Vfunc_clip_to_dtype__2208__minimum)) {
                                                __Vfunc_clip_to_dtype__2208__Vfuncout 
                                                    = __Vfunc_clip_to_dtype__2208__minimum;
                                                goto __Vlabel1;
                                            }
                                            if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__2208__value, __Vfunc_clip_to_dtype__2208__maximum)) {
                                                __Vfunc_clip_to_dtype__2208__Vfuncout 
                                                    = __Vfunc_clip_to_dtype__2208__maximum;
                                                goto __Vlabel1;
                                            }
                                            __Vfunc_clip_to_dtype__2208__Vfuncout 
                                                = __Vfunc_clip_to_dtype__2208__value;
                                            __Vlabel1: ;
                                        }
                                    }(), __Vfunc_clip_to_dtype__2208__Vfuncout));
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__rmw_beat_q = 0ULL;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q 
                                = (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype)) 
                                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_high_nibble))
                                    ? 0xfU : 0x11U);
                        }
                    }
                } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                             [2U])) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2211__fail_addr 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_addr;
                            __Vfunc_memory_status_to_task__2212__status 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                                [2U];
                            __Vfunc_memory_status_to_task__2212__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__2212__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2212__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__2212__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2211__fail_status 
                                = __Vfunc_memory_status_to_task__2212__Vfuncout;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2211__fail_status;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2211__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                        } else if ((0U != (0xffffffU 
                                           & (IData)(
                                                     (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                                      [2U] 
                                                      >> 0x28U))))) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2213__fail_addr 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_addr;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2213__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_entry_q 
                                = (0xffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                   [2U]);
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0xeU;
                        }
                    }
                } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__inline_requant) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_entry_q 
                        = (1ULL | ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__inline_requant_shift)) 
                                   << 0x20U));
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0xeU;
                } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0xdU;
                }
            } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                             [2U])) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2214__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_addr);
                            __Vfunc_memory_status_to_task__2215__status 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                                [2U];
                            __Vfunc_memory_status_to_task__2215__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__2215__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2215__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__2215__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2214__fail_status 
                                = __Vfunc_memory_status_to_task__2215__Vfuncout;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2214__fail_status;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2214__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q 
                                = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q 
                                   + ([&]() {
                                        __Vfunc_load_element__2216__byte_lane 
                                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_addr));
                                        __Vfunc_load_element__2216__beat 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                            [2U];
                                        __Vfunc_load_element__2216__word_value 
                                            = (IData)(
                                                      (__Vfunc_load_element__2216__beat 
                                                       >> 
                                                       (0x3fU 
                                                        & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2216__byte_lane), 3U))));
                                        __Vfunc_load_element__2216__Vfuncout 
                                            = (((QData)((IData)(
                                                                (- (IData)(
                                                                           (__Vfunc_load_element__2216__word_value 
                                                                            >> 0x1fU))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(__Vfunc_load_element__2216__word_value)));
                                    }(), __Vfunc_load_element__2216__Vfuncout));
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q 
                                = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable)
                                    ? 0xcU : 0xeU);
                        }
                    }
                } else if (([&]() {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2217__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_addr));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2217__Vfuncout 
                                = (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2217__byte_lane));
                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2217__Vfuncout))) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2218__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_addr);
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2218__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0xbU;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                         [2U])) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2219__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__src2_addr);
                        __Vfunc_memory_status_to_task__2220__status 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                            [2U];
                        __Vfunc_memory_status_to_task__2220__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__2220__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2220__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__2220__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2219__fail_status 
                            = __Vfunc_memory_status_to_task__2220__Vfuncout;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2219__fail_status;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2219__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q 
                            = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q 
                               + ([&]() {
                                    __Vfunc_load_element__2221__byte_lane 
                                        = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__src2_addr));
                                    __Vfunc_load_element__2221__beat 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                        [2U];
                                    __Vfunc_load_element__2221__word_value 
                                        = (IData)((__Vfunc_load_element__2221__beat 
                                                   >> 
                                                   (0x3fU 
                                                    & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2221__byte_lane), 3U))));
                                    __Vfunc_load_element__2221__Vfuncout 
                                        = (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_load_element__2221__word_value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_load_element__2221__word_value)));
                                }(), __Vfunc_load_element__2221__Vfuncout));
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q 
                            = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_enable)
                                ? 0xaU : ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable)
                                           ? 0xcU : 0xeU));
                    }
                }
            } else if (([&]() {
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2222__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__src2_addr));
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2222__Vfuncout 
                            = (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2222__byte_lane));
                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2222__Vfuncout))) {
                __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2223__fail_addr 
                    = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__src2_addr);
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 4U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                    = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2223__fail_addr;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
            } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 9U;
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q 
                        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q 
                           + VL_MULS_QQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_value_q));
                    if ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q) 
                         < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_k)) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q 
                            = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q);
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 3U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q 
                            = (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_from_src2) 
                                | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__residual_enable))
                                ? 8U : ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_enable)
                                         ? 0xaU : ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable)
                                                    ? 0xcU
                                                    : 0xeU)));
                    }
                } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                         [2U])) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2224__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_addr);
                        __Vfunc_memory_status_to_task__2225__status 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                            [2U];
                        __Vfunc_memory_status_to_task__2225__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__2225__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2225__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__2225__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2224__fail_status 
                            = __Vfunc_memory_status_to_task__2225__Vfuncout;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2224__fail_status;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2224__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else {
                        __Vfunc_load_element__2226__dtype 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_dtype;
                        __Vfunc_load_element__2226__high_nibble 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_high_nibble;
                        __Vfunc_load_element__2226__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_addr));
                        __Vfunc_load_element__2226__beat 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                            [2U];
                        __Vfunc_load_element__2226__byte_value 
                            = (0xffU & (IData)((__Vfunc_load_element__2226__beat 
                                                >> 
                                                (0x3fU 
                                                 & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2226__byte_lane), 3U)))));
                        __Vfunc_load_element__2226__nibble_value 
                            = (0xfU & ((IData)(__Vfunc_load_element__2226__high_nibble)
                                        ? ((IData)(__Vfunc_load_element__2226__byte_value) 
                                           >> 4U) : (IData)(__Vfunc_load_element__2226__byte_value)));
                        __Vfunc_load_element__2226__half_value 
                            = (0xffffU & (IData)((__Vfunc_load_element__2226__beat 
                                                  >> 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2226__byte_lane), 3U)))));
                        __Vfunc_load_element__2226__word_value 
                            = (IData)((__Vfunc_load_element__2226__beat 
                                       >> (0x3fU & 
                                           VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2226__byte_lane), 3U))));
                        __Vfunc_load_element__2226__Vfuncout 
                            = ((2U & (IData)(__Vfunc_load_element__2226__dtype))
                                ? ((1U & (IData)(__Vfunc_load_element__2226__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2226__half_value) 
                                                               >> 0xfU))))) 
                                        << 0x10U) | (QData)((IData)(__Vfunc_load_element__2226__half_value)))
                                    : (((QData)((IData)(
                                                        (- (IData)(
                                                                   (__Vfunc_load_element__2226__word_value 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(__Vfunc_load_element__2226__word_value))))
                                : ((1U & (IData)(__Vfunc_load_element__2226__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2226__byte_value) 
                                                               >> 7U))))) 
                                        << 8U) | (QData)((IData)(__Vfunc_load_element__2226__byte_value)))
                                    : (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2226__nibble_value) 
                                                               >> 3U))))) 
                                        << 4U) | (QData)((IData)(__Vfunc_load_element__2226__nibble_value)))));
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_value_q 
                            = __Vfunc_load_element__2226__Vfuncout;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 7U;
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 6U;
                }
            } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                     [2U])) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2227__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_addr);
                    __Vfunc_memory_status_to_task__2228__status 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                        [2U];
                    __Vfunc_memory_status_to_task__2228__Vfuncout 
                        = ((0U == (IData)(__Vfunc_memory_status_to_task__2228__status))
                            ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2228__status))
                                     ? 6U : ((2U == (IData)(__Vfunc_memory_status_to_task__2228__status))
                                              ? 5U : 4U)));
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2227__fail_status 
                        = __Vfunc_memory_status_to_task__2228__Vfuncout;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2227__fail_status;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2227__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else {
                    __Vfunc_load_element__2229__dtype 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_dtype;
                    __Vfunc_load_element__2229__high_nibble 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_high_nibble;
                    __Vfunc_load_element__2229__byte_lane 
                        = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_addr));
                    __Vfunc_load_element__2229__beat 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                        [2U];
                    __Vfunc_load_element__2229__byte_value 
                        = (0xffU & (IData)((__Vfunc_load_element__2229__beat 
                                            >> (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2229__byte_lane), 3U)))));
                    __Vfunc_load_element__2229__nibble_value 
                        = (0xfU & ((IData)(__Vfunc_load_element__2229__high_nibble)
                                    ? ((IData)(__Vfunc_load_element__2229__byte_value) 
                                       >> 4U) : (IData)(__Vfunc_load_element__2229__byte_value)));
                    __Vfunc_load_element__2229__half_value 
                        = (0xffffU & (IData)((__Vfunc_load_element__2229__beat 
                                              >> (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2229__byte_lane), 3U)))));
                    __Vfunc_load_element__2229__word_value 
                        = (IData)((__Vfunc_load_element__2229__beat 
                                   >> (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2229__byte_lane), 3U))));
                    __Vfunc_load_element__2229__Vfuncout 
                        = ((2U & (IData)(__Vfunc_load_element__2229__dtype))
                            ? ((1U & (IData)(__Vfunc_load_element__2229__dtype))
                                ? (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__2229__half_value) 
                                                           >> 0xfU))))) 
                                    << 0x10U) | (QData)((IData)(__Vfunc_load_element__2229__half_value)))
                                : (((QData)((IData)(
                                                    (- (IData)(
                                                               (__Vfunc_load_element__2229__word_value 
                                                                >> 0x1fU))))) 
                                    << 0x20U) | (QData)((IData)(__Vfunc_load_element__2229__word_value))))
                            : ((1U & (IData)(__Vfunc_load_element__2229__dtype))
                                ? (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__2229__byte_value) 
                                                           >> 7U))))) 
                                    << 8U) | (QData)((IData)(__Vfunc_load_element__2229__byte_value)))
                                : (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__2229__nibble_value) 
                                                           >> 3U))))) 
                                    << 4U) | (QData)((IData)(__Vfunc_load_element__2229__nibble_value)))));
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_value_q 
                        = __Vfunc_load_element__2229__Vfuncout;
                    if (([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__dtype 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_dtype;
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__byte_lane 
                                    = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_addr));
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__Vfuncout 
                                    = (((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__dtype)) 
                                        & (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__byte_lane))) 
                                       | ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__dtype)) 
                                          & (6U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__byte_lane))));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2230__Vfuncout))) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2231__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_addr);
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 4U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2231__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 5U;
                    }
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 4U;
                }
            } else {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q = 0ULL;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q = 0U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__rmw_beat_q = 0ULL;
                if (([&]() {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__dtype 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__Vfuncout 
                                = (((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__dtype)) 
                                    & (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__byte_lane))) 
                                   | ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__dtype)) 
                                      & (6U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__byte_lane))));
                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2232__Vfuncout))) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2233__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr);
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2233__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if (((0x43U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q)) 
                            | (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_k))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q 
                        = ((0x43U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q))
                            ? 0xeU : (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_from_src2) 
                                       | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__residual_enable))
                                       ? 8U : ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_enable)
                                                ? 0xaU
                                                : ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable)
                                                    ? 0xcU
                                                    : 0xeU))));
                } else if (([&]() {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__dtype 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_dtype;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_addr));
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__Vfuncout 
                                = (((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__dtype)) 
                                    & (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__byte_lane))) 
                                   | ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__dtype)) 
                                      & (6U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__byte_lane))));
                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__crosses_beat__2234__Vfuncout))) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2235__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_addr);
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fail_task__2235__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 3U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if (([&]() {
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_known__2236__opcode 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q;
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_known__2236__Vfuncout 
                            = ((0x40U <= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_known__2236__opcode)) 
                               & (0x43U >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_known__2236__opcode)));
                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_known__2236__Vfuncout))) {
                if ((((1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_version)) 
                      | (2U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_type))) 
                     | (0x100U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_bytes)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if ((IData)((0U != (0xfffe0300U 
                                           & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__numeric_cfg)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if (((((((((((6U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_pack_format)) 
                                    | (6U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_pack_format))) 
                                   | (6U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_pack_format))) 
                                  | (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__pack_version))) 
                                 | (2U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__overflow_mode))) 
                                | (1U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__activation_mode))) 
                               | (0U != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_flags 
                                         >> 8U))) | 
                              (1U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__residual_mode))) 
                             | (0U != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x29U] 
                                       >> 0x18U))) 
                            | (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2bU]))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if (((((((0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_base 
                                          >> 0x14U)) 
                                | (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_base 
                                            >> 0x14U))) 
                               | (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_base 
                                           >> 0x14U))) 
                              | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_from_src2) 
                                  | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__residual_enable)) 
                                 & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__src2_base 
                                             >> 0x14U)))) 
                             | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_enable) 
                                & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_base 
                                            >> 0x14U)))) 
                            | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable) 
                                & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__inline_requant))) 
                               & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_base 
                                           >> 0x14U))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if (((0U != (0x7fU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2cU] 
                                             >> 1U))) 
                            | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__inline_requant) 
                               & (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable)) 
                                   | (1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_mode))) 
                                  | (1U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_count))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if ((((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_count) 
                             | ((0x40U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q)) 
                                & (1U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_count))) 
                            | ((0x41U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q)) 
                               & (1U > vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_count)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if ((((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__last_valid_m 
                              != ([&]() {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__tile = 8U;
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__size 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_m;
                                        {
                                            if ((0U 
                                                 == __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__size)) {
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__Vfuncout = 0U;
                                                goto __Vlabel2;
                                            }
                                            if ((0U 
                                                 == 
                                                 VL_MODDIV_III(32, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__size, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__tile))) {
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__Vfuncout 
                                                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__tile;
                                                goto __Vlabel2;
                                            }
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__Vfuncout 
                                                = VL_MODDIV_III(32, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__size, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__tile);
                                            __Vlabel2: ;
                                        }
                                    }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2247__Vfuncout)) 
                             | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__last_valid_n 
                                != ([&]() {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__tile = 8U;
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__size 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_n;
                                        {
                                            if ((0U 
                                                 == __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__size)) {
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__Vfuncout = 0U;
                                                goto __Vlabel3;
                                            }
                                            if ((0U 
                                                 == 
                                                 VL_MODDIV_III(32, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__size, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__tile))) {
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__Vfuncout 
                                                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__tile;
                                                goto __Vlabel3;
                                            }
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__Vfuncout 
                                                = VL_MODDIV_III(32, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__size, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__tile);
                                            __Vlabel3: ;
                                        }
                                    }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2248__Vfuncout))) 
                            | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__last_valid_k 
                               != ([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__tile = 0x10U;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__size 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_k;
                                    {
                                        if ((0U == __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__size)) {
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__Vfuncout = 0U;
                                            goto __Vlabel4;
                                        }
                                        if ((0U == 
                                             VL_MODDIV_III(32, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__size, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__tile))) {
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__Vfuncout 
                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__tile;
                                            goto __Vlabel4;
                                        }
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__Vfuncout 
                                            = VL_MODDIV_III(32, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__size, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__tile);
                                        __Vlabel4: ;
                                    }
                                }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__expected_tail__2249__Vfuncout)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if (((0x43U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q)) 
                            & (~ ((((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_dtype)) 
                                    & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_dtype))) 
                                   | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_dtype)) 
                                      & ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_dtype)) 
                                         | (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_dtype))))) 
                                  | ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_dtype)) 
                                     & (3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_dtype))))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if (((0x43U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q)) 
                            & (~ ((((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_dtype)) 
                                    & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_pack_format))) 
                                   | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_dtype)) 
                                      & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_pack_format)))) 
                                  | ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_dtype)) 
                                     & (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_pack_format))))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if (((0x43U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q)) 
                            & (~ ((((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_dtype)) 
                                    & ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_pack_format)) 
                                       | (3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_pack_format)))) 
                                   | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_dtype)) 
                                      & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_pack_format)) 
                                         | (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_pack_format))))) 
                                  | ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_dtype)) 
                                     & ((5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_pack_format)) 
                                        | (6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_pack_format)))))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                } else if ((((((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype)) 
                               & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_pack_format))) 
                              | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype)) 
                                 & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_pack_format)))) 
                             | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype)) 
                                & (4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_pack_format)))) 
                            | ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype)) 
                               & (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_pack_format))))) {
                    if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_is_tiled) 
                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__transpose_b))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__output_zero_point)) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__residual_enable) 
                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_from_src2))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else if (((0x42U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q)) 
                                & (((((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_from_src2)) 
                                        | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__final_output)) 
                                       | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_enable)) 
                                      | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__residual_enable)) 
                                     | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__relu_enable)) 
                                    | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable)) 
                                   | (2U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype))))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else if (((0x43U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q)) 
                                & ((((((2U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype)) 
                                       | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_enable)) 
                                      | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__residual_enable)) 
                                     | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_from_src2)) 
                                    | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable)) 
                                   | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__relu_enable)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else if ((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__final_output)) 
                                 & (0x43U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q))) 
                                & (((((2U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype)) 
                                      | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_enable)) 
                                     | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__residual_enable)) 
                                    | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__relu_enable)) 
                                   | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__final_output) 
                                 & (2U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype))) 
                                & (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable)) 
                                      | (~ ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_mode)) 
                                            | (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_mode))))) 
                                     | (8U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_entry_bytes))) 
                                    | (~ (((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_mode)) 
                                           & (1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_count)) 
                                          | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_mode)) 
                                             & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_count 
                                                == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_n))))) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_region_bytes 
                                      < VL_SHIFTL_III(32,32,32, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_count, 3U))))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else if (((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype)) 
                                & (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable) 
                                    | (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_count)) 
                                   | (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_mode))))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_enable) 
                                 & (((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_count 
                                      != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_n) 
                                     | (4U > vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_stride_bytes)) 
                                    | (0U != (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_stride_bytes)))) 
                                | ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_enable)) 
                                   & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_count)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else if (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_m) 
                                | (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_n))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 0U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                    } else {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_q = 0U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q = 0U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q = 0U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q = 0U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 2U;
                    }
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0x13U;
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__progress_q = 0ULL;
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_task_valid) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[1U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][1U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[2U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][2U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[3U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][3U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[4U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][4U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[5U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][5U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[6U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][6U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[7U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][7U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[8U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][8U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[9U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][9U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xaU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0xaU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xbU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0xbU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xcU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0xcU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xdU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0xdU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0xeU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xfU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0xfU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x10U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x10U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x11U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x11U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x12U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x12U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x13U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x13U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x14U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x14U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x15U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x15U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x16U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x16U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x17U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x18U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x18U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x19U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x19U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x1aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x1bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x1cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x1dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x1eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x1fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x20U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x20U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x21U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x21U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x22U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x22U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x23U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x23U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x24U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x24U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x25U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x25U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x26U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x26U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x27U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x27U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x28U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x28U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x29U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x29U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x2aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x2bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x2cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x2dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x2eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x2fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x30U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x30U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x31U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x31U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x32U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x32U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x33U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x33U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x34U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x34U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x35U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x35U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x36U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x36U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x37U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x37U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x38U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x38U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x39U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x39U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x3aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x3aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x3bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x3bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x3cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x3cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x3dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x3dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x3eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x3eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x3fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select][0x3fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select];
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 1U;
            }
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q = 0U;
        IData/*31:0*/ __Vilp1;
        __Vilp1 = 0U;
        while ((__Vilp1 <= 0x3fU)) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[__Vilp1] 
                = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp1];
            __Vilp1 = ((IData)(1U) + __Vilp1);
        }
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__opcode_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_value_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_value_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__result_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_entry_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__rmw_beat_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__status_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__fault_addr_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__progress_q = 0ULL;
    }
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) {
        if ((((0U != (0xfU & (- (IData)((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)))))) 
              & (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q))) 
             & (4U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q)))) {
            if ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q))) {
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__mem_response_handshake) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q = 0xaU;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__fault_addr_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_mem_req_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 4U;
                } else {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q = 1U;
                }
            } else if (((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q)) 
                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__mem_request_handshake))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q = 1U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 2U;
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q = 0xaU;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__fault_addr_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_mem_req_addr;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q = 0U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 4U;
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 0U;
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 0U;
            } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_rsp_valid) 
                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_active_q))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 0U;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q))) {
                if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__prefix_valid)) 
                           | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__crc_enable_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__fault_addr_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_addr_q;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 4U;
                } else if ((0x40U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__expected_desc_bytes))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 4U;
                } else {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__total_beats_q 
                        = (0x3fU & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__expected_desc_bytes) 
                                    >> 3U));
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q = 8U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 1U;
                }
            } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__mem_response_handshake) {
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q = 0xaU;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__fault_addr_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_mem_req_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 4U;
                } else if ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q))) {
                    __Vfunc_npu_mem_to_task_status__2114__status 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q;
                    __Vfunc_npu_mem_to_task_status__2114__Vfuncout 
                        = ((4U & (IData)(__Vfunc_npu_mem_to_task_status__2114__status))
                            ? ((2U & (IData)(__Vfunc_npu_mem_to_task_status__2114__status))
                                ? 2U : ((1U & (IData)(__Vfunc_npu_mem_to_task_status__2114__status))
                                         ? 2U : 5U))
                            : ((2U & (IData)(__Vfunc_npu_mem_to_task_status__2114__status))
                                ? ((1U & (IData)(__Vfunc_npu_mem_to_task_status__2114__status))
                                    ? 6U : 4U) : ((1U 
                                                   & (IData)(__Vfunc_npu_mem_to_task_status__2114__status))
                                                   ? 4U
                                                   : 0U)));
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q 
                        = __Vfunc_npu_mem_to_task_status__2114__Vfuncout;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__fault_addr_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_mem_req_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 4U;
                } else {
                    VL_ASSIGNSEL_WQ(2048, 64, (0x7ffU 
                                               & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q), 6U)), vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_flat_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_rdata_q);
                    if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q) 
                         == (0x3fU & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__total_beats_q) 
                                      - (IData)(1U))))) {
                        if ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__total_beats_q))) {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 3U;
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q = 0U;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 4U;
                        }
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q 
                            = (0x3fU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q)));
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 1U;
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q))) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__mem_request_handshake) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 2U;
            }
        } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_valid) 
                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_ready))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_addr_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_desc_addr;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__command_id_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select];
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__engine_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select];
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__crc_enable_q 
                = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                         [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select] 
                         >> 5U));
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q = 0U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__total_beats_q = 8U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q = 0U;
            IData/*31:0*/ __Vilp2;
            __Vilp2 = 0U;
            while ((__Vilp2 <= 0x3fU)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_flat_q[__Vilp2] 
                    = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp2];
                __Vilp2 = ((IData)(1U) + __Vilp2);
            }
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__fault_addr_q = 0ULL;
            if ((0U != (0x3fU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_desc_addr)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q = 2U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__fault_addr_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_desc_addr;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 4U;
            } else {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 1U;
            }
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_addr_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__command_id_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__engine_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__crc_enable_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__total_beats_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__rsp_status_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__fault_addr_q = 0ULL;
        IData/*31:0*/ __Vilp3;
        __Vilp3 = 0U;
        while ((__Vilp3 <= 0x3fU)) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_flat_q[__Vilp3] 
                = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp3];
            __Vilp3 = ((IData)(1U) + __Vilp3);
        }
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__abort_pending_q = 0U;
    }
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__read_ready 
            = (1U & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_space))
                      ? ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready) 
                         >> 1U) : (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_ready)));
        if ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_space))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__rmw_ready 
                = (1U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready) 
                         >> 1U));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__write_ready 
                = (1U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready) 
                         >> 1U));
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__rmw_ready 
                = (1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_ready));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__write_ready 
                = (1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_ready));
        }
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__source_in_range 
            = ((((0ULL != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_region_bytes) 
                 & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr 
                    >= vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_base)) 
                & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_end_addr 
                   <= (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_base 
                       + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_region_bytes))) 
               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_end_addr 
                  >= vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__destination_in_range 
            = ((((0ULL != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_region_bytes) 
                 & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr 
                    >= vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_base)) 
                & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_end_addr 
                   <= (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_base 
                       + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_region_bytes))) 
               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_end_addr 
                  >= vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr));
        if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0U;
        } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0U;
            } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0U;
                } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_q) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__write_rsp_valid) {
                    if ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__write_rsp_status))) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2142__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr);
                        __Vfunc_memory_status_to_task__2143__status 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__write_rsp_status;
                        __Vfunc_memory_status_to_task__2143__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__2143__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2143__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__2143__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2142__fail_status 
                            = __Vfunc_memory_status_to_task__2143__Vfuncout;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2142__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2142__fail_status;
                    } else {
                        if ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype))) {
                            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_high_nibble)))) {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__progress_q 
                                    = (1ULL + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__progress_q);
                            }
                        } else {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__progress_q 
                                = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__progress_q 
                                   + VL_EXTEND_QI(64,3, 
                                                  ([&]() {
                                            __Vfunc_dtype_bytes__2144__dtype 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype;
                                            __Vfunc_dtype_bytes__2144__Vfuncout 
                                                = (
                                                   (1U 
                                                    == (IData)(__Vfunc_dtype_bytes__2144__dtype))
                                                    ? 1U
                                                    : 
                                                   ((2U 
                                                     == (IData)(__Vfunc_dtype_bytes__2144__dtype))
                                                     ? 4U
                                                     : 
                                                    ((3U 
                                                      == (IData)(__Vfunc_dtype_bytes__2144__dtype))
                                                      ? 2U
                                                      : 0U)));
                                        }(), (IData)(__Vfunc_dtype_bytes__2144__Vfuncout))));
                        }
                        if (((1ULL + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q) 
                             < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__total_units_q)) {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q 
                                = (1ULL + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q);
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 2U;
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 0U;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                        }
                    }
                }
            } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__write_ready) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 9U;
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
                    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__write_rsp_valid) {
                        if ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__write_rsp_status))) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2145__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr);
                            __Vfunc_memory_status_to_task__2146__status 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__write_rsp_status;
                            __Vfunc_memory_status_to_task__2146__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__2146__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2146__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__2146__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2145__fail_status 
                                = __Vfunc_memory_status_to_task__2146__Vfuncout;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2145__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2145__fail_status;
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rmw_beat_q 
                                = ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_space))
                                    ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                   [1U] : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_rdata_q);
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 8U;
                        }
                    }
                } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__rmw_ready) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__converted_value 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_value_q;
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__verify_pass_q) {
                    if ((VL_GTS_IQQ(64, 0xfffffffffffffff8ULL, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_value_q) 
                         | VL_LTS_IQQ(64, 7ULL, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_value_q))) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2147__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr);
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 0xcU;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2147__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                    } else if (((1ULL + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q) 
                                < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__total_units_q)) {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q 
                            = (1ULL + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q);
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 2U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q = 0ULL;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__verify_pass_q = 0U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 2U;
                    }
                } else {
                    if ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__convert_mode))) {
                        __Vfunc_clip_to_dtype__2148__dtype 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype;
                        __Vfunc_clip_to_dtype__2148__value 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_value_q;
                        __Vfunc_clip_to_dtype__2148__minimum = 0;
                        __Vfunc_clip_to_dtype__2148__maximum = 0;
                        {
                            __Vfunc_dtype_min__2149__dtype 
                                = __Vfunc_clip_to_dtype__2148__dtype;
                            __Vfunc_dtype_min__2149__Vfuncout 
                                = ((2U & (IData)(__Vfunc_dtype_min__2149__dtype))
                                    ? ((1U & (IData)(__Vfunc_dtype_min__2149__dtype))
                                        ? 0xffffffffffff8000ULL
                                        : 0xffffffff80000000ULL)
                                    : ((1U & (IData)(__Vfunc_dtype_min__2149__dtype))
                                        ? 0xffffffffffffff80ULL
                                        : 0xfffffffffffffff8ULL));
                            __Vfunc_clip_to_dtype__2148__minimum 
                                = __Vfunc_dtype_min__2149__Vfuncout;
                            __Vfunc_dtype_max__2150__dtype 
                                = __Vfunc_clip_to_dtype__2148__dtype;
                            __Vfunc_dtype_max__2150__Vfuncout 
                                = ((2U & (IData)(__Vfunc_dtype_max__2150__dtype))
                                    ? ((1U & (IData)(__Vfunc_dtype_max__2150__dtype))
                                        ? 0x7fffULL
                                        : 0x7fffffffULL)
                                    : ((1U & (IData)(__Vfunc_dtype_max__2150__dtype))
                                        ? 0x7fULL : 7ULL));
                            __Vfunc_clip_to_dtype__2148__maximum 
                                = __Vfunc_dtype_max__2150__Vfuncout;
                            if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__2148__value, __Vfunc_clip_to_dtype__2148__minimum)) {
                                __Vfunc_clip_to_dtype__2148__Vfuncout 
                                    = __Vfunc_clip_to_dtype__2148__minimum;
                                goto __Vlabel5;
                            }
                            if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__2148__value, __Vfunc_clip_to_dtype__2148__maximum)) {
                                __Vfunc_clip_to_dtype__2148__Vfuncout 
                                    = __Vfunc_clip_to_dtype__2148__maximum;
                                goto __Vlabel5;
                            }
                            __Vfunc_clip_to_dtype__2148__Vfuncout 
                                = __Vfunc_clip_to_dtype__2148__value;
                            __Vlabel5: ;
                        }
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__converted_value 
                            = __Vfunc_clip_to_dtype__2148__Vfuncout;
                    }
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__result_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__converted_value;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rmw_beat_q = 0ULL;
                    if ((((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype)) 
                          & (4U < (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr)))) 
                         | ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype)) 
                            & (6U < (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr)))))) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2151__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr);
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 4U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2151__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q 
                            = (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype)) 
                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_high_nibble))
                                ? 6U : 8U);
                    }
                }
            } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_valid) {
                if ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_status))) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2152__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr);
                    __Vfunc_memory_status_to_task__2153__status 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_status;
                    __Vfunc_memory_status_to_task__2153__Vfuncout 
                        = ((0U == (IData)(__Vfunc_memory_status_to_task__2153__status))
                            ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2153__status))
                                     ? 6U : ((2U == (IData)(__Vfunc_memory_status_to_task__2153__status))
                                              ? 5U : 4U)));
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2152__fail_status 
                        = __Vfunc_memory_status_to_task__2153__Vfuncout;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2152__fail_status;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2152__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else {
                    __Vfunc_load_element__2154__dtype 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_src_dtype;
                    __Vfunc_load_element__2154__high_nibble 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_high_nibble;
                    __Vfunc_load_element__2154__byte_lane 
                        = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr));
                    __Vfunc_load_element__2154__beat 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_data;
                    __Vfunc_load_element__2154__byte_value 
                        = (0xffU & (IData)((__Vfunc_load_element__2154__beat 
                                            >> (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2154__byte_lane), 3U)))));
                    __Vfunc_load_element__2154__nibble_value 
                        = (0xfU & ((IData)(__Vfunc_load_element__2154__high_nibble)
                                    ? ((IData)(__Vfunc_load_element__2154__byte_value) 
                                       >> 4U) : (IData)(__Vfunc_load_element__2154__byte_value)));
                    __Vfunc_load_element__2154__half_value 
                        = (0xffffU & (IData)((__Vfunc_load_element__2154__beat 
                                              >> (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2154__byte_lane), 3U)))));
                    __Vfunc_load_element__2154__word_value 
                        = (IData)((__Vfunc_load_element__2154__beat 
                                   >> (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2154__byte_lane), 3U))));
                    __Vfunc_load_element__2154__Vfuncout 
                        = ((2U & (IData)(__Vfunc_load_element__2154__dtype))
                            ? ((1U & (IData)(__Vfunc_load_element__2154__dtype))
                                ? (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__2154__half_value) 
                                                           >> 0xfU))))) 
                                    << 0x10U) | (QData)((IData)(__Vfunc_load_element__2154__half_value)))
                                : (((QData)((IData)(
                                                    (- (IData)(
                                                               (__Vfunc_load_element__2154__word_value 
                                                                >> 0x1fU))))) 
                                    << 0x20U) | (QData)((IData)(__Vfunc_load_element__2154__word_value))))
                            : ((1U & (IData)(__Vfunc_load_element__2154__dtype))
                                ? (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__2154__byte_value) 
                                                           >> 7U))))) 
                                    << 8U) | (QData)((IData)(__Vfunc_load_element__2154__byte_value)))
                                : (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__2154__nibble_value) 
                                                           >> 3U))))) 
                                    << 4U) | (QData)((IData)(__Vfunc_load_element__2154__nibble_value)))));
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_value_q 
                        = __Vfunc_load_element__2154__Vfuncout;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 5U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__read_ready) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 4U;
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rmw_beat_q = 0ULL;
                if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__destination_in_range) {
                    if ((0x22U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q))) {
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__dtype 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype;
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__value 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_value;
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__Vfuncout 
                            = ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__dtype))
                                ? (((- (QData)((IData)(
                                                       (1U 
                                                        & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__value 
                                                           >> 3U))))) 
                                    << 4U) | (QData)((IData)(
                                                             (0xfU 
                                                              & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__value))))
                                : ((1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__value 
                                                               >> 7U))))) 
                                        << 8U) | (QData)((IData)(
                                                                 (0xffU 
                                                                  & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__value))))
                                    : ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__value 
                                                                   >> 0xfU))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(
                                                             (0xffffU 
                                                              & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__value))))
                                        : (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__value))))));
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__result_q 
                            = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_as_integer__2155__Vfuncout;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q 
                            = (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype)) 
                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_high_nibble))
                                ? 6U : 8U);
                    } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__source_in_range) {
                        if ((((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_src_dtype)) 
                              & (4U < (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr)))) 
                             | ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_src_dtype)) 
                                & (6U < (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr)))))) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2156__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr);
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 4U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2156__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 3U;
                        }
                    } else {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2157__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr);
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 4U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2157__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                    }
                } else {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2158__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr);
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2158__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__computed_total 
                = (([&]() {
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2159__opcode 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q;
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2159__Vfuncout 
                            = ((0x24U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2159__opcode)) 
                               | (0x25U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2159__opcode)));
                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2159__Vfuncout))
                    ? ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__segment_count)) 
                       * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__segment_bytes)))
                    : ([&]() {
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_packed[0U];
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_packed[1U];
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_packed[2U];
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_packed[3U];
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes[4U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_packed[4U];
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__rank_value 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rank;
                        VL_ZERO_W(128, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product);
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__dimension = 0;
                        {
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[0U] = 1U;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[1U] = 0U;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[2U] = 0U;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[3U] = 0U;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__dimension = 0U;
                            if ((0U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__rank_value))) {
                                __Vtemp_34[0U] = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes[0U];
                                __Vtemp_34[1U] = 0U;
                                __Vtemp_34[2U] = 0U;
                                __Vtemp_34[3U] = 0U;
                                VL_MUL_W(4, __Vtemp_33, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product, __Vtemp_34);
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[0U] 
                                    = __Vtemp_33[0U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[1U] 
                                    = __Vtemp_33[1U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[2U] 
                                    = __Vtemp_33[2U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[3U] 
                                    = __Vtemp_33[3U];
                            }
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__dimension = 1U;
                            if ((1U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__rank_value))) {
                                __Vtemp_36[0U] = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes[1U];
                                __Vtemp_36[1U] = 0U;
                                __Vtemp_36[2U] = 0U;
                                __Vtemp_36[3U] = 0U;
                                VL_MUL_W(4, __Vtemp_35, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product, __Vtemp_36);
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[0U] 
                                    = __Vtemp_35[0U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[1U] 
                                    = __Vtemp_35[1U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[2U] 
                                    = __Vtemp_35[2U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[3U] 
                                    = __Vtemp_35[3U];
                            }
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__dimension = 2U;
                            if ((2U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__rank_value))) {
                                __Vtemp_38[0U] = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes[2U];
                                __Vtemp_38[1U] = 0U;
                                __Vtemp_38[2U] = 0U;
                                __Vtemp_38[3U] = 0U;
                                VL_MUL_W(4, __Vtemp_37, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product, __Vtemp_38);
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[0U] 
                                    = __Vtemp_37[0U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[1U] 
                                    = __Vtemp_37[1U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[2U] 
                                    = __Vtemp_37[2U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[3U] 
                                    = __Vtemp_37[3U];
                            }
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__dimension = 3U;
                            if ((3U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__rank_value))) {
                                __Vtemp_40[0U] = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes[3U];
                                __Vtemp_40[1U] = 0U;
                                __Vtemp_40[2U] = 0U;
                                __Vtemp_40[3U] = 0U;
                                VL_MUL_W(4, __Vtemp_39, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product, __Vtemp_40);
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[0U] 
                                    = __Vtemp_39[0U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[1U] 
                                    = __Vtemp_39[1U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[2U] 
                                    = __Vtemp_39[2U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[3U] 
                                    = __Vtemp_39[3U];
                            }
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__dimension = 4U;
                            if ((4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__rank_value))) {
                                __Vtemp_42[0U] = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__shapes[4U];
                                __Vtemp_42[1U] = 0U;
                                __Vtemp_42[2U] = 0U;
                                __Vtemp_42[3U] = 0U;
                                VL_MUL_W(4, __Vtemp_41, __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product, __Vtemp_42);
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[0U] 
                                    = __Vtemp_41[0U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[1U] 
                                    = __Vtemp_41[1U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[2U] 
                                    = __Vtemp_41[2U];
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[3U] 
                                    = __Vtemp_41[3U];
                            }
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__dimension = 5U;
                            if ((0ULL != (((QData)((IData)(
                                                           __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[3U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[2U]))))) {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__Vfuncout = 0xffffffffffffffffULL;
                                goto __Vlabel6;
                            }
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__Vfuncout 
                                = (((QData)((IData)(
                                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__product[0U])));
                            __Vlabel6: ;
                        }
                    }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_product__2160__Vfuncout));
            if (([&]() {
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__opcode 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q;
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__Vfuncout 
                            = ((((((0x20U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__opcode)) 
                                   || (0x21U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__opcode))) 
                                  || (0x22U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__opcode))) 
                                 || (0x23U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__opcode))) 
                                || (0x24U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__opcode))) 
                               || (0x25U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__opcode)));
                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_known__2161__Vfuncout))) {
                if ((((1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_version)) 
                      | (1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_type))) 
                     | (0x100U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_bytes)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if ((IData)((0U != (0xfffe0300U 
                                           & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__numeric_cfg)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if ((IData)(((0U != (0xfefe0000U 
                                            & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U])) 
                                    | ((((((((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rank)) 
                                             | (5U 
                                                < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rank))) 
                                            | (1U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_space))) 
                                           | (1U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_space))) 
                                          | (3U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__convert_mode))) 
                                         | (0xfU < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__burst_beats_minus1))) 
                                        | (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__max_outstanding))) 
                                       | (0x10U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__max_outstanding)))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_nibble) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2169__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_base);
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2169__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if (((((((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_space)) 
                                & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_base 
                                            >> 0x14U))) 
                               & (0x22U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q))) 
                              | (((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_space)) 
                                  & (0U != (0xffffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_base 
                                                       >> 0x30U))))) 
                                 & (0x22U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q)))) 
                             | ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_space)) 
                                & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_base 
                                            >> 0x14U)))) 
                            | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_space)) 
                               & (0U != (0xffffU & (IData)(
                                                           (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_base 
                                                            >> 0x30U))))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if (((0x20U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q)) 
                            & (1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rank)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if (((0x23U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q)) 
                            & (((2U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rank)) 
                                | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype) 
                                   != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype))) 
                               | (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__convert_mode))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if ((([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2173__opcode 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q;
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2173__Vfuncout 
                                    = ((0x24U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2173__opcode)) 
                                       | (0x25U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2173__opcode)));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2173__Vfuncout)) 
                            & (((((((1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rank)) 
                                    | (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__convert_mode))) 
                                   | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype) 
                                      != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype))) 
                                  | (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__segment_count))) 
                                 | (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__segment_bytes))) 
                                | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__segment_stride 
                                   < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__segment_bytes))) 
                               | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_packed[0U] 
                                  != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__segment_count))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if (((0x22U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q)) 
                            & (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__convert_mode)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if (((0x22U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q)) 
                            & (((((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__convert_mode)) 
                                  & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype) 
                                     != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype))) 
                                 | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__convert_mode)) 
                                    & (~ ((((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype)) 
                                            & (((1U 
                                                 == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype)) 
                                                | (3U 
                                                   == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype))) 
                                               | (2U 
                                                  == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype)))) 
                                           | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype)) 
                                              & ((3U 
                                                  == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype)) 
                                                 | (2U 
                                                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype))))) 
                                          | ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype)) 
                                             & (2U 
                                                == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype))))))) 
                                | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__convert_mode)) 
                                   & (~ ((((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype)) 
                                           & (((3U 
                                                == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype)) 
                                               | (1U 
                                                  == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype))) 
                                              | (0U 
                                                 == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype)))) 
                                          | ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype)) 
                                             & ((1U 
                                                 == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype)) 
                                                | (0U 
                                                   == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype))))) 
                                         | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype)) 
                                            & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype))))))) 
                               | ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__convert_mode)) 
                                  & (~ ((((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype)) 
                                          | (3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype))) 
                                         | (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype))) 
                                        & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype)))))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if ((0xffffffffffffffffULL == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__computed_total)) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if ((0ULL == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__computed_total)) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if (((0ULL == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_region_bytes) 
                            | ((0x22U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q)) 
                               & (0ULL == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_region_bytes)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else if (((((0x22U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q)) 
                              & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_space) 
                                 == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_space))) 
                             & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_base 
                                < (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_base 
                                   + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_region_bytes))) 
                            & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_base 
                               < (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_base 
                                  + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_region_bytes)))) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2179__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_base);
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 0xdU;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fail_task__2179__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__total_units_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__unnamedblk1__DOT__computed_total;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q = 0ULL;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__verify_pass_q 
                        = ((0x22U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q)) 
                           & (3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__convert_mode)));
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 2U;
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0xaU;
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__progress_q = 0ULL;
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_task_valid) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[1U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][1U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[2U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][2U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[3U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][3U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[4U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][4U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[5U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][5U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[6U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][6U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[7U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][7U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[8U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][8U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[9U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][9U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xaU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0xaU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xbU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0xbU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xcU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0xcU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xdU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0xdU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0xeU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xfU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0xfU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x10U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x11U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x12U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x12U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x13U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x13U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x14U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x14U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x15U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x15U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x16U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x16U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x17U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x17U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x18U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x18U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x19U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x19U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x1aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x1bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x1cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x1dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x1eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x1fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x20U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x20U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x21U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x21U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x22U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x22U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x23U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x23U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x24U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x24U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x25U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x25U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x26U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x26U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x27U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x27U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x28U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x28U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x29U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x29U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x2aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x2bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x2cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x2dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x2eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x2fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x30U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x30U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x31U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x31U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x32U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x32U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x33U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x33U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x34U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x34U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x35U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x35U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x36U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x36U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x37U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x37U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x38U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x38U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x39U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x39U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x3aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x3aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x3bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x3bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x3cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x3cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x3dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x3dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x3eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x3eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x3fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select][0x3fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select];
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 1U;
            }
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q = 0U;
        IData/*31:0*/ __Vilp4;
        __Vilp4 = 0U;
        while ((__Vilp4 <= 0x3fU)) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[__Vilp4] 
                = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp4];
            __Vilp4 = ((IData)(1U) + __Vilp4);
        }
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__total_units_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__verify_pass_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_value_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__result_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rmw_beat_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__status_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fault_addr_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__progress_q = 0ULL;
    }
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) {
        if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0U;
            } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0U;
                } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0U;
                } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_q) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0U;
                }
            } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                             [4U])) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2535__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr);
                            __Vfunc_memory_status_to_task__2536__status 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                                [4U];
                            __Vfunc_memory_status_to_task__2536__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__2536__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2536__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__2536__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2535__fail_status 
                                = __Vfunc_memory_status_to_task__2536__Vfuncout;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2535__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2535__fail_status;
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__progress_q 
                                = (1ULL + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__progress_q);
                            if ((7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                                if ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q) 
                                     < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__rows)) {
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q 
                                        = ((IData)(1U) 
                                           + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q);
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 2U;
                                } else {
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 0U;
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                                }
                            } else if ((((IData)(1U) 
                                         + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q) 
                                        < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns)) {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q 
                                    = ((IData)(1U) 
                                       + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q);
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 5U;
                            } else if ((((IData)(1U) 
                                         + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q) 
                                        < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__rows)) {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q 
                                    = ((IData)(1U) 
                                       + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q);
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 2U;
                            } else {
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 0U;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x13U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                         [4U])) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2537__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr);
                        __Vfunc_memory_status_to_task__2538__status 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                            [4U];
                        __Vfunc_memory_status_to_task__2538__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__2538__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2538__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__2538__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2537__fail_status 
                            = __Vfunc_memory_status_to_task__2538__Vfuncout;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2537__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2537__fail_status;
                    } else {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__rmw_beat_q 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                            [4U];
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x12U;
                    }
                }
            } else if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x11U;
            }
        } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                        if ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q) 
                             < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns)) {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q 
                                = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q);
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 5U;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q = 0U;
                            if ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                                if (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_seen_q)) 
                                     & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__all_mask_mode)))) {
                                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2539__fail_addr 
                                        = (0xffffffffffffULL 
                                           & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_base);
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 0xcU;
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2539__fail_addr;
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                                } else {
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_q = 0U;
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q 
                                        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_seen_q)
                                            ? 2U : 3U);
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 5U;
                                }
                            } else if ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q = 3U;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 5U;
                            } else if ((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_mean_q 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean;
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_invstd_q 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_result;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q = 5U;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 5U;
                            } else {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 5U;
                            }
                        }
                    } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                        if ((7U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_mode)) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat 
                                = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sum_q 
                                   + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q);
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sum_q 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat;
                        } else if ((8U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_mode)) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat 
                                = (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q) 
                                    | VL_GTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q))
                                    ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q);
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat;
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat 
                                = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sumsq_q 
                                   + VL_MULS_QQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q));
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sumsq_q 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat;
                        }
                        if ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q) 
                             == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns)) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_overflow 
                                = (VL_GTS_IQQ(64, 0xffffffff80000000ULL, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat) 
                                   | VL_LTS_IQQ(64, 0x7fffffffULL, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat));
                            if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_overflow) 
                                 & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__overflow_mode)))) {
                                __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2542__fail_addr 
                                    = (0xffffffffffffULL 
                                       & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_dst_addr);
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 0xcU;
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                    = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2542__fail_addr;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                            } else {
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__result_q 
                                    = ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__overflow_mode))
                                        ? ([&]() {
                                            __Vfunc_wrap_to_dtype__2543__value 
                                                = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat);
                                            __Vfunc_wrap_to_dtype__2543__Vfuncout 
                                                = (
                                                   ((QData)((IData)(
                                                                    (- (IData)(
                                                                               (__Vfunc_wrap_to_dtype__2543__value 
                                                                                >> 0x1fU))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(__Vfunc_wrap_to_dtype__2543__value)));
                                        }(), __Vfunc_wrap_to_dtype__2543__Vfuncout)
                                        : ([&]() {
                                            __Vfunc_clip_to_dtype__2544__dtype = 2U;
                                            __Vfunc_clip_to_dtype__2544__value 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat;
                                            __Vfunc_clip_to_dtype__2544__minimum = 0;
                                            __Vfunc_clip_to_dtype__2544__maximum = 0;
                                            {
                                                __Vfunc_dtype_min__2545__dtype 
                                                    = __Vfunc_clip_to_dtype__2544__dtype;
                                                __Vfunc_dtype_min__2545__Vfuncout 
                                                    = 
                                                    ((2U 
                                                      & (IData)(__Vfunc_dtype_min__2545__dtype))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(__Vfunc_dtype_min__2545__dtype))
                                                       ? 0xffffffffffff8000ULL
                                                       : 0xffffffff80000000ULL)
                                                      : 
                                                     ((1U 
                                                       & (IData)(__Vfunc_dtype_min__2545__dtype))
                                                       ? 0xffffffffffffff80ULL
                                                       : 0xfffffffffffffff8ULL));
                                                __Vfunc_clip_to_dtype__2544__minimum 
                                                    = __Vfunc_dtype_min__2545__Vfuncout;
                                                __Vfunc_dtype_max__2546__dtype 
                                                    = __Vfunc_clip_to_dtype__2544__dtype;
                                                __Vfunc_dtype_max__2546__Vfuncout 
                                                    = 
                                                    ((2U 
                                                      & (IData)(__Vfunc_dtype_max__2546__dtype))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(__Vfunc_dtype_max__2546__dtype))
                                                       ? 0x7fffULL
                                                       : 0x7fffffffULL)
                                                      : 
                                                     ((1U 
                                                       & (IData)(__Vfunc_dtype_max__2546__dtype))
                                                       ? 0x7fULL
                                                       : 7ULL));
                                                __Vfunc_clip_to_dtype__2544__maximum 
                                                    = __Vfunc_dtype_max__2546__Vfuncout;
                                                if (
                                                    VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__2544__value, __Vfunc_clip_to_dtype__2544__minimum)) {
                                                    __Vfunc_clip_to_dtype__2544__Vfuncout 
                                                        = __Vfunc_clip_to_dtype__2544__minimum;
                                                    goto __Vlabel7;
                                                }
                                                if (
                                                    VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__2544__value, __Vfunc_clip_to_dtype__2544__maximum)) {
                                                    __Vfunc_clip_to_dtype__2544__Vfuncout 
                                                        = __Vfunc_clip_to_dtype__2544__maximum;
                                                    goto __Vlabel7;
                                                }
                                                __Vfunc_clip_to_dtype__2544__Vfuncout 
                                                    = __Vfunc_clip_to_dtype__2544__value;
                                                __Vlabel7: ;
                                            }
                                        }(), __Vfunc_clip_to_dtype__2544__Vfuncout));
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q = 7U;
                                if (([&]() {
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2547__byte_lane 
                                                = (7U 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_dst_addr));
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2547__Vfuncout 
                                                = (4U 
                                                   < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2547__byte_lane));
                                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2547__Vfuncout))) {
                                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2548__fail_addr 
                                        = (0xffffffffffffULL 
                                           & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_dst_addr);
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 4U;
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2548__fail_addr;
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                                } else {
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x12U;
                                }
                            }
                        } else {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xfU;
                        }
                    } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                        if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                            if ((7U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_mode)) {
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat 
                                    = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sum_q 
                                       + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q);
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sum_q 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat;
                            } else if ((8U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_mode)) {
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat 
                                    = (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q) 
                                        | VL_GTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q))
                                        ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q
                                        : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q);
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat;
                            } else {
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat 
                                    = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sumsq_q 
                                       + VL_MULS_QQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q));
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sumsq_q 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat;
                            }
                            if ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q) 
                                 == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns)) {
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_overflow 
                                    = (VL_GTS_IQQ(64, 0xffffffff80000000ULL, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat) 
                                       | VL_LTS_IQQ(64, 0x7fffffffULL, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat));
                                if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_overflow) 
                                     & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__overflow_mode)))) {
                                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2551__fail_addr 
                                        = (0xffffffffffffULL 
                                           & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_dst_addr);
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 0xcU;
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2551__fail_addr;
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                                } else {
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__result_q 
                                        = ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__overflow_mode))
                                            ? ([&]() {
                                                __Vfunc_wrap_to_dtype__2552__value 
                                                    = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat);
                                                __Vfunc_wrap_to_dtype__2552__Vfuncout 
                                                    = 
                                                    (((QData)((IData)(
                                                                      (- (IData)(
                                                                                (__Vfunc_wrap_to_dtype__2552__value 
                                                                                >> 0x1fU))))) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(__Vfunc_wrap_to_dtype__2552__value)));
                                            }(), __Vfunc_wrap_to_dtype__2552__Vfuncout)
                                            : ([&]() {
                                                __Vfunc_clip_to_dtype__2553__dtype = 2U;
                                                __Vfunc_clip_to_dtype__2553__value 
                                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__next_stat;
                                                __Vfunc_clip_to_dtype__2553__minimum = 0;
                                                __Vfunc_clip_to_dtype__2553__maximum = 0;
                                                {
                                                    __Vfunc_dtype_min__2554__dtype 
                                                        = __Vfunc_clip_to_dtype__2553__dtype;
                                                    __Vfunc_dtype_min__2554__Vfuncout 
                                                        = 
                                                        ((2U 
                                                          & (IData)(__Vfunc_dtype_min__2554__dtype))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(__Vfunc_dtype_min__2554__dtype))
                                                           ? 0xffffffffffff8000ULL
                                                           : 0xffffffff80000000ULL)
                                                          : 
                                                         ((1U 
                                                           & (IData)(__Vfunc_dtype_min__2554__dtype))
                                                           ? 0xffffffffffffff80ULL
                                                           : 0xfffffffffffffff8ULL));
                                                    __Vfunc_clip_to_dtype__2553__minimum 
                                                        = __Vfunc_dtype_min__2554__Vfuncout;
                                                    __Vfunc_dtype_max__2555__dtype 
                                                        = __Vfunc_clip_to_dtype__2553__dtype;
                                                    __Vfunc_dtype_max__2555__Vfuncout 
                                                        = 
                                                        ((2U 
                                                          & (IData)(__Vfunc_dtype_max__2555__dtype))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(__Vfunc_dtype_max__2555__dtype))
                                                           ? 0x7fffULL
                                                           : 0x7fffffffULL)
                                                          : 
                                                         ((1U 
                                                           & (IData)(__Vfunc_dtype_max__2555__dtype))
                                                           ? 0x7fULL
                                                           : 7ULL));
                                                    __Vfunc_clip_to_dtype__2553__maximum 
                                                        = __Vfunc_dtype_max__2555__Vfuncout;
                                                    if (
                                                        VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__2553__value, __Vfunc_clip_to_dtype__2553__minimum)) {
                                                        __Vfunc_clip_to_dtype__2553__Vfuncout 
                                                            = __Vfunc_clip_to_dtype__2553__minimum;
                                                        goto __Vlabel8;
                                                    }
                                                    if (
                                                        VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__2553__value, __Vfunc_clip_to_dtype__2553__maximum)) {
                                                        __Vfunc_clip_to_dtype__2553__Vfuncout 
                                                            = __Vfunc_clip_to_dtype__2553__maximum;
                                                        goto __Vlabel8;
                                                    }
                                                    __Vfunc_clip_to_dtype__2553__Vfuncout 
                                                        = __Vfunc_clip_to_dtype__2553__value;
                                                    __Vlabel8: ;
                                                }
                                            }(), __Vfunc_clip_to_dtype__2553__Vfuncout));
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q = 7U;
                                    if (([&]() {
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2556__byte_lane 
                                                    = 
                                                    (7U 
                                                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_dst_addr));
                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2556__Vfuncout 
                                                    = 
                                                    (4U 
                                                     < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2556__byte_lane));
                                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2556__Vfuncout))) {
                                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2557__fail_addr 
                                            = (0xffffffffffffULL 
                                               & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_dst_addr);
                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 4U;
                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2557__fail_addr;
                                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                                    } else {
                                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x12U;
                                    }
                                }
                            } else {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xfU;
                            }
                        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_integer 
                                = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__f2i_result 
                                   + (((QData)((IData)(
                                                       (- (IData)(
                                                                  (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_zero_point 
                                                                   >> 0x1fU))))) 
                                       << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_zero_point))));
                            __Vfunc_clip_to_dtype__2558__dtype 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype;
                            __Vfunc_clip_to_dtype__2558__value 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_integer;
                            __Vfunc_clip_to_dtype__2558__minimum = 0;
                            __Vfunc_clip_to_dtype__2558__maximum = 0;
                            {
                                __Vfunc_dtype_min__2559__dtype 
                                    = __Vfunc_clip_to_dtype__2558__dtype;
                                __Vfunc_dtype_min__2559__Vfuncout 
                                    = ((2U & (IData)(__Vfunc_dtype_min__2559__dtype))
                                        ? ((1U & (IData)(__Vfunc_dtype_min__2559__dtype))
                                            ? 0xffffffffffff8000ULL
                                            : 0xffffffff80000000ULL)
                                        : ((1U & (IData)(__Vfunc_dtype_min__2559__dtype))
                                            ? 0xffffffffffffff80ULL
                                            : 0xfffffffffffffff8ULL));
                                __Vfunc_clip_to_dtype__2558__minimum 
                                    = __Vfunc_dtype_min__2559__Vfuncout;
                                __Vfunc_dtype_max__2560__dtype 
                                    = __Vfunc_clip_to_dtype__2558__dtype;
                                __Vfunc_dtype_max__2560__Vfuncout 
                                    = ((2U & (IData)(__Vfunc_dtype_max__2560__dtype))
                                        ? ((1U & (IData)(__Vfunc_dtype_max__2560__dtype))
                                            ? 0x7fffULL
                                            : 0x7fffffffULL)
                                        : ((1U & (IData)(__Vfunc_dtype_max__2560__dtype))
                                            ? 0x7fULL
                                            : 7ULL));
                                __Vfunc_clip_to_dtype__2558__maximum 
                                    = __Vfunc_dtype_max__2560__Vfuncout;
                                if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__2558__value, __Vfunc_clip_to_dtype__2558__minimum)) {
                                    __Vfunc_clip_to_dtype__2558__Vfuncout 
                                        = __Vfunc_clip_to_dtype__2558__minimum;
                                    goto __Vlabel9;
                                }
                                if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__2558__value, __Vfunc_clip_to_dtype__2558__maximum)) {
                                    __Vfunc_clip_to_dtype__2558__Vfuncout 
                                        = __Vfunc_clip_to_dtype__2558__maximum;
                                    goto __Vlabel9;
                                }
                                __Vfunc_clip_to_dtype__2558__Vfuncout 
                                    = __Vfunc_clip_to_dtype__2558__value;
                                __Vlabel9: ;
                            }
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__result_q 
                                = __Vfunc_clip_to_dtype__2558__Vfuncout;
                            if (([&]() {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__dtype 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype;
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__byte_lane 
                                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr));
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__Vfuncout 
                                            = (((2U 
                                                 == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__dtype)) 
                                                & (4U 
                                                   < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__byte_lane))) 
                                               | ((3U 
                                                   == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__dtype)) 
                                                  & (6U 
                                                     < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__byte_lane))));
                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2561__Vfuncout))) {
                                __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2562__fail_addr 
                                    = (0xffffffffffffULL 
                                       & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr);
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 4U;
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                    = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2562__fail_addr;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                            } else {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q 
                                    = (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype)) 
                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_high_nibble))
                                        ? 0x10U : 0x12U);
                            }
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_q 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_plus_x;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sumsq_q 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sumsq_plus_x_squared;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xfU;
                        }
                    } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                        if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_integer 
                                = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__f2i_result 
                                   + (((QData)((IData)(
                                                       (- (IData)(
                                                                  (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_zero_point 
                                                                   >> 0x1fU))))) 
                                       << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_zero_point))));
                            __Vfunc_clip_to_dtype__2563__dtype 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype;
                            __Vfunc_clip_to_dtype__2563__value 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_integer;
                            __Vfunc_clip_to_dtype__2563__minimum = 0;
                            __Vfunc_clip_to_dtype__2563__maximum = 0;
                            {
                                __Vfunc_dtype_min__2564__dtype 
                                    = __Vfunc_clip_to_dtype__2563__dtype;
                                __Vfunc_dtype_min__2564__Vfuncout 
                                    = ((2U & (IData)(__Vfunc_dtype_min__2564__dtype))
                                        ? ((1U & (IData)(__Vfunc_dtype_min__2564__dtype))
                                            ? 0xffffffffffff8000ULL
                                            : 0xffffffff80000000ULL)
                                        : ((1U & (IData)(__Vfunc_dtype_min__2564__dtype))
                                            ? 0xffffffffffffff80ULL
                                            : 0xfffffffffffffff8ULL));
                                __Vfunc_clip_to_dtype__2563__minimum 
                                    = __Vfunc_dtype_min__2564__Vfuncout;
                                __Vfunc_dtype_max__2565__dtype 
                                    = __Vfunc_clip_to_dtype__2563__dtype;
                                __Vfunc_dtype_max__2565__Vfuncout 
                                    = ((2U & (IData)(__Vfunc_dtype_max__2565__dtype))
                                        ? ((1U & (IData)(__Vfunc_dtype_max__2565__dtype))
                                            ? 0x7fffULL
                                            : 0x7fffffffULL)
                                        : ((1U & (IData)(__Vfunc_dtype_max__2565__dtype))
                                            ? 0x7fULL
                                            : 7ULL));
                                __Vfunc_clip_to_dtype__2563__maximum 
                                    = __Vfunc_dtype_max__2565__Vfuncout;
                                if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__2563__value, __Vfunc_clip_to_dtype__2563__minimum)) {
                                    __Vfunc_clip_to_dtype__2563__Vfuncout 
                                        = __Vfunc_clip_to_dtype__2563__minimum;
                                    goto __Vlabel10;
                                }
                                if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__2563__value, __Vfunc_clip_to_dtype__2563__maximum)) {
                                    __Vfunc_clip_to_dtype__2563__Vfuncout 
                                        = __Vfunc_clip_to_dtype__2563__maximum;
                                    goto __Vlabel10;
                                }
                                __Vfunc_clip_to_dtype__2563__Vfuncout 
                                    = __Vfunc_clip_to_dtype__2563__value;
                                __Vlabel10: ;
                            }
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__result_q 
                                = __Vfunc_clip_to_dtype__2563__Vfuncout;
                            if (([&]() {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__dtype 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype;
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__byte_lane 
                                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr));
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__Vfuncout 
                                            = (((2U 
                                                 == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__dtype)) 
                                                & (4U 
                                                   < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__byte_lane))) 
                                               | ((3U 
                                                   == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__dtype)) 
                                                  & (6U 
                                                     < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__byte_lane))));
                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2566__Vfuncout))) {
                                __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2567__fail_addr 
                                    = (0xffffffffffffULL 
                                       & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr);
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 4U;
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                    = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2567__fail_addr;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                            } else {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q 
                                    = (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype)) 
                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_high_nibble))
                                        ? 0x10U : 0x12U);
                            }
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_q 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_soft_sum_plus_exp;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xfU;
                        }
                    } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_seen_q)) 
                                   | ([&]() {
                                            __Vfunc_fp32_less_than__2568__rhs 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
                                            __Vfunc_fp32_less_than__2568__lhs 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_max_q;
                                            {
                                                if (
                                                    ((([&]() {
                                                                    __Vfunc_fp32_is_nan__2569__bits 
                                                                        = __Vfunc_fp32_less_than__2568__lhs;
                                                                    __Vfunc_fp32_is_nan__2569__unused_sign = 0;
                                                                    __Vfunc_fp32_is_nan__2569__unused_sign 
                                                                        = 
                                                                        (__Vfunc_fp32_is_nan__2569__bits 
                                                                         >> 0x1fU);
                                                                    __Vfunc_fp32_is_nan__2569__Vfuncout 
                                                                        = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__2569__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__2569__bits))));
                                                                }(), (IData)(__Vfunc_fp32_is_nan__2569__Vfuncout)) 
                                                      | ([&]() {
                                                                    __Vfunc_fp32_is_nan__2570__bits 
                                                                        = __Vfunc_fp32_less_than__2568__rhs;
                                                                    __Vfunc_fp32_is_nan__2570__unused_sign = 0;
                                                                    __Vfunc_fp32_is_nan__2570__unused_sign 
                                                                        = 
                                                                        (__Vfunc_fp32_is_nan__2570__bits 
                                                                         >> 0x1fU);
                                                                    __Vfunc_fp32_is_nan__2570__Vfuncout 
                                                                        = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__2570__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__2570__bits))));
                                                                }(), (IData)(__Vfunc_fp32_is_nan__2570__Vfuncout))) 
                                                     | ([&]() {
                                                                __Vfunc_fp32_equal__2571__rhs 
                                                                    = __Vfunc_fp32_less_than__2568__rhs;
                                                                __Vfunc_fp32_equal__2571__lhs 
                                                                    = __Vfunc_fp32_less_than__2568__lhs;
                                                                {
                                                                    if (
                                                                        (([&]() {
                                                                                __Vfunc_fp32_is_nan__2572__bits 
                                                                                = __Vfunc_fp32_equal__2571__lhs;
                                                                                __Vfunc_fp32_is_nan__2572__unused_sign = 0;
                                                                                __Vfunc_fp32_is_nan__2572__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_nan__2572__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_nan__2572__Vfuncout 
                                                                                = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__2572__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__2572__bits))));
                                                                                }(), (IData)(__Vfunc_fp32_is_nan__2572__Vfuncout)) 
                                                                         | ([&]() {
                                                                                __Vfunc_fp32_is_nan__2573__bits 
                                                                                = __Vfunc_fp32_equal__2571__rhs;
                                                                                __Vfunc_fp32_is_nan__2573__unused_sign = 0;
                                                                                __Vfunc_fp32_is_nan__2573__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_nan__2573__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_nan__2573__Vfuncout 
                                                                                = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__2573__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__2573__bits))));
                                                                                }(), (IData)(__Vfunc_fp32_is_nan__2573__Vfuncout)))) {
                                                                        __Vfunc_fp32_equal__2571__Vfuncout = 0U;
                                                                        goto __Vlabel12;
                                                                    }
                                                                    if (
                                                                        (([&]() {
                                                                                __Vfunc_fp32_is_zero__2574__bits 
                                                                                = __Vfunc_fp32_equal__2571__lhs;
                                                                                __Vfunc_fp32_is_zero__2574__unused_sign = 0;
                                                                                __Vfunc_fp32_is_zero__2574__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_zero__2574__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_zero__2574__Vfuncout 
                                                                                = 
                                                                                (0U 
                                                                                == 
                                                                                (0x7fffffffU 
                                                                                & __Vfunc_fp32_is_zero__2574__bits));
                                                                                }(), (IData)(__Vfunc_fp32_is_zero__2574__Vfuncout)) 
                                                                         & ([&]() {
                                                                                __Vfunc_fp32_is_zero__2575__bits 
                                                                                = __Vfunc_fp32_equal__2571__rhs;
                                                                                __Vfunc_fp32_is_zero__2575__unused_sign = 0;
                                                                                __Vfunc_fp32_is_zero__2575__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_zero__2575__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_zero__2575__Vfuncout 
                                                                                = 
                                                                                (0U 
                                                                                == 
                                                                                (0x7fffffffU 
                                                                                & __Vfunc_fp32_is_zero__2575__bits));
                                                                                }(), (IData)(__Vfunc_fp32_is_zero__2575__Vfuncout)))) {
                                                                        __Vfunc_fp32_equal__2571__Vfuncout = 1U;
                                                                        goto __Vlabel12;
                                                                    }
                                                                    __Vfunc_fp32_equal__2571__Vfuncout 
                                                                        = 
                                                                        (__Vfunc_fp32_equal__2571__lhs 
                                                                         == __Vfunc_fp32_equal__2571__rhs);
                                                                    __Vlabel12: ;
                                                                }
                                                            }(), (IData)(__Vfunc_fp32_equal__2571__Vfuncout)))) {
                                                    __Vfunc_fp32_less_than__2568__Vfuncout = 0U;
                                                    goto __Vlabel11;
                                                }
                                                if (
                                                    ((__Vfunc_fp32_less_than__2568__lhs 
                                                      >> 0x1fU) 
                                                     != 
                                                     (__Vfunc_fp32_less_than__2568__rhs 
                                                      >> 0x1fU))) {
                                                    __Vfunc_fp32_less_than__2568__Vfuncout 
                                                        = 
                                                        (__Vfunc_fp32_less_than__2568__lhs 
                                                         >> 0x1fU);
                                                    goto __Vlabel11;
                                                }
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (__Vfunc_fp32_less_than__2568__lhs 
                                                         >> 0x1fU)))) {
                                                    __Vfunc_fp32_less_than__2568__Vfuncout 
                                                        = 
                                                        ((0x7fffffffU 
                                                          & __Vfunc_fp32_less_than__2568__lhs) 
                                                         < 
                                                         (0x7fffffffU 
                                                          & __Vfunc_fp32_less_than__2568__rhs));
                                                    goto __Vlabel11;
                                                }
                                                __Vfunc_fp32_less_than__2568__Vfuncout 
                                                    = 
                                                    ((0x7fffffffU 
                                                      & __Vfunc_fp32_less_than__2568__lhs) 
                                                     > 
                                                     (0x7fffffffU 
                                                      & __Vfunc_fp32_less_than__2568__rhs));
                                                __Vlabel11: ;
                                            }
                                        }(), (IData)(__Vfunc_fp32_less_than__2568__Vfuncout))))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_max_q 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
                        }
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_seen_q = 1U;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xfU;
                    } else {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_integer 
                            = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__f2i_result 
                               + (((QData)((IData)(
                                                   (- (IData)(
                                                              (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_zero_point 
                                                               >> 0x1fU))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_zero_point))));
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_overflow 
                            = (VL_LTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_integer, 
                                          ([&]() {
                                        __Vfunc_dtype_min__2576__dtype 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype;
                                        __Vfunc_dtype_min__2576__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_min__2576__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__2576__dtype))
                                                    ? 0xffffffffffff8000ULL
                                                    : 0xffffffff80000000ULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__2576__dtype))
                                                    ? 0xffffffffffffff80ULL
                                                    : 0xfffffffffffffff8ULL));
                                    }(), __Vfunc_dtype_min__2576__Vfuncout)) 
                               | VL_GTS_IQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_integer, 
                                            ([&]() {
                                        __Vfunc_dtype_max__2577__dtype 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype;
                                        __Vfunc_dtype_max__2577__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_max__2577__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__2577__dtype))
                                                    ? 0x7fffULL
                                                    : 0x7fffffffULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__2577__dtype))
                                                    ? 0x7fULL
                                                    : 7ULL));
                                    }(), __Vfunc_dtype_max__2577__Vfuncout)));
                        __Vfunc_clip_to_dtype__2578__dtype 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype;
                        __Vfunc_clip_to_dtype__2578__value 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_integer;
                        __Vfunc_clip_to_dtype__2578__minimum = 0;
                        __Vfunc_clip_to_dtype__2578__maximum = 0;
                        {
                            __Vfunc_dtype_min__2579__dtype 
                                = __Vfunc_clip_to_dtype__2578__dtype;
                            __Vfunc_dtype_min__2579__Vfuncout 
                                = ((2U & (IData)(__Vfunc_dtype_min__2579__dtype))
                                    ? ((1U & (IData)(__Vfunc_dtype_min__2579__dtype))
                                        ? 0xffffffffffff8000ULL
                                        : 0xffffffff80000000ULL)
                                    : ((1U & (IData)(__Vfunc_dtype_min__2579__dtype))
                                        ? 0xffffffffffffff80ULL
                                        : 0xfffffffffffffff8ULL));
                            __Vfunc_clip_to_dtype__2578__minimum 
                                = __Vfunc_dtype_min__2579__Vfuncout;
                            __Vfunc_dtype_max__2580__dtype 
                                = __Vfunc_clip_to_dtype__2578__dtype;
                            __Vfunc_dtype_max__2580__Vfuncout 
                                = ((2U & (IData)(__Vfunc_dtype_max__2580__dtype))
                                    ? ((1U & (IData)(__Vfunc_dtype_max__2580__dtype))
                                        ? 0x7fffULL
                                        : 0x7fffffffULL)
                                    : ((1U & (IData)(__Vfunc_dtype_max__2580__dtype))
                                        ? 0x7fULL : 7ULL));
                            __Vfunc_clip_to_dtype__2578__maximum 
                                = __Vfunc_dtype_max__2580__Vfuncout;
                            if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__2578__value, __Vfunc_clip_to_dtype__2578__minimum)) {
                                __Vfunc_clip_to_dtype__2578__Vfuncout 
                                    = __Vfunc_clip_to_dtype__2578__minimum;
                                goto __Vlabel13;
                            }
                            if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__2578__value, __Vfunc_clip_to_dtype__2578__maximum)) {
                                __Vfunc_clip_to_dtype__2578__Vfuncout 
                                    = __Vfunc_clip_to_dtype__2578__maximum;
                                goto __Vlabel13;
                            }
                            __Vfunc_clip_to_dtype__2578__Vfuncout 
                                = __Vfunc_clip_to_dtype__2578__value;
                            __Vlabel13: ;
                        }
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__result_q 
                            = __Vfunc_clip_to_dtype__2578__Vfuncout;
                        if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__output_overflow) 
                              | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__f2i_exceptional)) 
                             & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__overflow_mode)))) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2581__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr);
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 0xcU;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2581__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                        } else if (([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__dtype 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__byte_lane 
                                        = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr));
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__Vfuncout 
                                        = (((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__dtype)) 
                                            & (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__byte_lane))) 
                                           | ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__dtype)) 
                                              & (6U 
                                                 < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__byte_lane))));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2582__Vfuncout))) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2583__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr);
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 4U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2583__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q 
                                = (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype)) 
                                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_high_nibble))
                                    ? 0x10U : 0x12U);
                        }
                    }
                } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                             [4U])) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2584__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_addr);
                            __Vfunc_memory_status_to_task__2585__status 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                                [4U];
                            __Vfunc_memory_status_to_task__2585__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__2585__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2585__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__2585__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2584__fail_status 
                                = __Vfunc_memory_status_to_task__2585__Vfuncout;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2584__fail_status;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2584__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                        } else {
                            __Vfunc_load_element__2586__dtype 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_dtype;
                            __Vfunc_load_element__2586__high_nibble 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_high_nibble;
                            __Vfunc_load_element__2586__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_addr));
                            __Vfunc_load_element__2586__beat 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                [4U];
                            __Vfunc_load_element__2586__byte_value 
                                = (0xffU & (IData)(
                                                   (__Vfunc_load_element__2586__beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2586__byte_lane), 3U)))));
                            __Vfunc_load_element__2586__nibble_value 
                                = (0xfU & ((IData)(__Vfunc_load_element__2586__high_nibble)
                                            ? ((IData)(__Vfunc_load_element__2586__byte_value) 
                                               >> 4U)
                                            : (IData)(__Vfunc_load_element__2586__byte_value)));
                            __Vfunc_load_element__2586__half_value 
                                = (0xffffU & (IData)(
                                                     (__Vfunc_load_element__2586__beat 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2586__byte_lane), 3U)))));
                            __Vfunc_load_element__2586__word_value 
                                = (IData)((__Vfunc_load_element__2586__beat 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2586__byte_lane), 3U))));
                            __Vfunc_load_element__2586__Vfuncout 
                                = ((2U & (IData)(__Vfunc_load_element__2586__dtype))
                                    ? ((1U & (IData)(__Vfunc_load_element__2586__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2586__half_value) 
                                                                   >> 0xfU))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(__Vfunc_load_element__2586__half_value)))
                                        : (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_load_element__2586__word_value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_load_element__2586__word_value))))
                                    : ((1U & (IData)(__Vfunc_load_element__2586__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2586__byte_value) 
                                                                   >> 7U))))) 
                                            << 8U) 
                                           | (QData)((IData)(__Vfunc_load_element__2586__byte_value)))
                                        : (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2586__nibble_value) 
                                                                   >> 3U))))) 
                                            << 4U) 
                                           | (QData)((IData)(__Vfunc_load_element__2586__nibble_value)))));
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_value_q 
                                = __Vfunc_load_element__2586__Vfuncout;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xeU;
                        }
                    }
                } else if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xdU;
                }
            } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                             [4U])) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2587__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_addr);
                            __Vfunc_memory_status_to_task__2588__status 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                                [4U];
                            __Vfunc_memory_status_to_task__2588__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__2588__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2588__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__2588__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2587__fail_status 
                                = __Vfunc_memory_status_to_task__2588__Vfuncout;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2587__fail_status;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2587__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                        } else {
                            __Vfunc_load_element__2589__dtype 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_dtype;
                            __Vfunc_load_element__2589__high_nibble 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_high_nibble;
                            __Vfunc_load_element__2589__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_addr));
                            __Vfunc_load_element__2589__beat 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                [4U];
                            __Vfunc_load_element__2589__byte_value 
                                = (0xffU & (IData)(
                                                   (__Vfunc_load_element__2589__beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2589__byte_lane), 3U)))));
                            __Vfunc_load_element__2589__nibble_value 
                                = (0xfU & ((IData)(__Vfunc_load_element__2589__high_nibble)
                                            ? ((IData)(__Vfunc_load_element__2589__byte_value) 
                                               >> 4U)
                                            : (IData)(__Vfunc_load_element__2589__byte_value)));
                            __Vfunc_load_element__2589__half_value 
                                = (0xffffU & (IData)(
                                                     (__Vfunc_load_element__2589__beat 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2589__byte_lane), 3U)))));
                            __Vfunc_load_element__2589__word_value 
                                = (IData)((__Vfunc_load_element__2589__beat 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2589__byte_lane), 3U))));
                            __Vfunc_load_element__2589__Vfuncout 
                                = ((2U & (IData)(__Vfunc_load_element__2589__dtype))
                                    ? ((1U & (IData)(__Vfunc_load_element__2589__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2589__half_value) 
                                                                   >> 0xfU))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(__Vfunc_load_element__2589__half_value)))
                                        : (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_load_element__2589__word_value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_load_element__2589__word_value))))
                                    : ((1U & (IData)(__Vfunc_load_element__2589__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2589__byte_value) 
                                                                   >> 7U))))) 
                                            << 8U) 
                                           | (QData)((IData)(__Vfunc_load_element__2589__byte_value)))
                                        : (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__2589__nibble_value) 
                                                                   >> 3U))))) 
                                            << 4U) 
                                           | (QData)((IData)(__Vfunc_load_element__2589__nibble_value)))));
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_value_q 
                                = __Vfunc_load_element__2589__Vfuncout;
                            if (((5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q)) 
                                 & (5U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_mode))) {
                                if (([&]() {
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__dtype 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_dtype;
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__byte_lane 
                                                = (7U 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_addr));
                                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__Vfuncout 
                                                = (
                                                   ((2U 
                                                     == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__dtype)) 
                                                    & (4U 
                                                       < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__byte_lane))) 
                                                   | ((3U 
                                                       == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__dtype)) 
                                                      & (6U 
                                                         < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__byte_lane))));
                                        }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2590__Vfuncout))) {
                                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2591__fail_addr 
                                        = (0xffffffffffffULL 
                                           & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_addr);
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 4U;
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2591__fail_addr;
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                                } else {
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xcU;
                                }
                            } else {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xeU;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xbU;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                         [4U])) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2592__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_addr);
                        __Vfunc_memory_status_to_task__2593__status 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                            [4U];
                        __Vfunc_memory_status_to_task__2593__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__2593__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2593__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__2593__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2592__fail_status 
                            = __Vfunc_memory_status_to_task__2593__Vfuncout;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2592__fail_status;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2592__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                    } else {
                        __Vfunc_load_element__2594__dtype 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_dtype;
                        __Vfunc_load_element__2594__high_nibble 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_high_nibble;
                        __Vfunc_load_element__2594__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_addr));
                        __Vfunc_load_element__2594__beat 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                            [4U];
                        __Vfunc_load_element__2594__byte_value 
                            = (0xffU & (IData)((__Vfunc_load_element__2594__beat 
                                                >> 
                                                (0x3fU 
                                                 & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2594__byte_lane), 3U)))));
                        __Vfunc_load_element__2594__nibble_value 
                            = (0xfU & ((IData)(__Vfunc_load_element__2594__high_nibble)
                                        ? ((IData)(__Vfunc_load_element__2594__byte_value) 
                                           >> 4U) : (IData)(__Vfunc_load_element__2594__byte_value)));
                        __Vfunc_load_element__2594__half_value 
                            = (0xffffU & (IData)((__Vfunc_load_element__2594__beat 
                                                  >> 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2594__byte_lane), 3U)))));
                        __Vfunc_load_element__2594__word_value 
                            = (IData)((__Vfunc_load_element__2594__beat 
                                       >> (0x3fU & 
                                           VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2594__byte_lane), 3U))));
                        __Vfunc_load_element__2594__Vfuncout 
                            = ((2U & (IData)(__Vfunc_load_element__2594__dtype))
                                ? ((1U & (IData)(__Vfunc_load_element__2594__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2594__half_value) 
                                                               >> 0xfU))))) 
                                        << 0x10U) | (QData)((IData)(__Vfunc_load_element__2594__half_value)))
                                    : (((QData)((IData)(
                                                        (- (IData)(
                                                                   (__Vfunc_load_element__2594__word_value 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(__Vfunc_load_element__2594__word_value))))
                                : ((1U & (IData)(__Vfunc_load_element__2594__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2594__byte_value) 
                                                               >> 7U))))) 
                                        << 8U) | (QData)((IData)(__Vfunc_load_element__2594__byte_value)))
                                    : (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__2594__nibble_value) 
                                                               >> 3U))))) 
                                        << 4U) | (QData)((IData)(__Vfunc_load_element__2594__nibble_value)))));
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q 
                            = __Vfunc_load_element__2594__Vfuncout;
                        if (((0x86U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                             | (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q)))) {
                            if (([&]() {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__dtype 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_dtype;
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__byte_lane 
                                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_addr));
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__Vfuncout 
                                            = (((2U 
                                                 == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__dtype)) 
                                                & (4U 
                                                   < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__byte_lane))) 
                                               | ((3U 
                                                   == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__dtype)) 
                                                  & (6U 
                                                     < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__byte_lane))));
                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2595__Vfuncout))) {
                                __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2596__fail_addr 
                                    = (0xffffffffffffULL 
                                       & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_addr);
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 4U;
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                    = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2596__fail_addr;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                            } else {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xaU;
                            }
                        } else {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xeU;
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 9U;
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                             [4U])) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2597__fail_addr 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_addr;
                            __Vfunc_memory_status_to_task__2598__status 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                                [4U];
                            __Vfunc_memory_status_to_task__2598__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__2598__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2598__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__2598__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2597__fail_status 
                                = __Vfunc_memory_status_to_task__2598__Vfuncout;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2597__fail_status;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2597__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                        } else {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_value_q 
                                = (0U != (0xffU & (IData)(
                                                          (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                                           [4U] 
                                                           >> 
                                                           (0x3fU 
                                                            & VL_SHIFTL_III(6,32,32, 
                                                                            (7U 
                                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_addr)), 3U))))));
                            if ((0U == (0xffU & (IData)(
                                                        (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                                                         [4U] 
                                                         >> 
                                                         (0x3fU 
                                                          & VL_SHIFTL_III(6,32,32, 
                                                                          (7U 
                                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_addr)), 3U))))))) {
                                if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__result_q = 0ULL;
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q 
                                        = (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype)) 
                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_high_nibble))
                                            ? 0x10U
                                            : 0x12U);
                                } else {
                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xfU;
                                }
                            } else if (([&]() {
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__dtype 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_dtype;
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__byte_lane 
                                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_addr));
                                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__Vfuncout 
                                            = (((2U 
                                                 == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__dtype)) 
                                                & (4U 
                                                   < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__byte_lane))) 
                                               | ((3U 
                                                   == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__dtype)) 
                                                  & (6U 
                                                     < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__byte_lane))));
                                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2599__Vfuncout))) {
                                __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2600__fail_addr 
                                    = (0xffffffffffffULL 
                                       & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_addr);
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 4U;
                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                    = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2600__fail_addr;
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                            } else {
                                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 8U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_value_q = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__rmw_beat_q = 0ULL;
                if (((0x81U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                     & (1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_mode))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 6U;
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__current_valid 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__derived_mask_valid;
                    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__current_valid) {
                        if (([&]() {
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__dtype 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_dtype;
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__byte_lane 
                                        = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_addr));
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__Vfuncout 
                                        = (((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__dtype)) 
                                            & (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__byte_lane))) 
                                           | ((3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__dtype)) 
                                              & (6U 
                                                 < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__byte_lane))));
                                }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2601__Vfuncout))) {
                            __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2602__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_addr);
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 4U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                                = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2602__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 8U;
                        }
                    } else if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__result_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q 
                            = (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype)) 
                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_high_nibble))
                                ? 0x10U : 0x12U);
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0xfU;
                    }
                }
            } else if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                if ((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                     [4U])) {
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2603__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_valid_length_addr);
                    __Vfunc_memory_status_to_task__2604__status 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
                        [4U];
                    __Vfunc_memory_status_to_task__2604__Vfuncout 
                        = ((0U == (IData)(__Vfunc_memory_status_to_task__2604__status))
                            ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__2604__status))
                                     ? 6U : ((2U == (IData)(__Vfunc_memory_status_to_task__2604__status))
                                              ? 5U : 4U)));
                    __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2603__fail_status 
                        = __Vfunc_memory_status_to_task__2604__Vfuncout;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2603__fail_status;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                        = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2603__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else {
                    __Vfunc_load_element__2605__byte_lane 
                        = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_valid_length_addr));
                    __Vfunc_load_element__2605__beat 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
                        [4U];
                    __Vfunc_load_element__2605__word_value 
                        = (IData)((__Vfunc_load_element__2605__beat 
                                   >> (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__2605__byte_lane), 3U))));
                    __Vfunc_load_element__2605__Vfuncout 
                        = (((QData)((IData)((- (IData)(
                                                       (__Vfunc_load_element__2605__word_value 
                                                        >> 0x1fU))))) 
                            << 0x20U) | (QData)((IData)(__Vfunc_load_element__2605__word_value)));
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__valid_length_value 
                        = __Vfunc_load_element__2605__Vfuncout;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_key_length_q 
                        = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__valid_length_value);
                    if ((VL_GTS_IQQ(64, 0ULL, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__valid_length_value) 
                         | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__unnamedblk1__DOT__valid_length_value 
                            > (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__length))))) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2606__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_valid_length_addr);
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 3U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2606__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 5U;
                    }
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 4U;
                }
            } else {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q = 0U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_value_q = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_seen_q = 0U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sum_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sumsq_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q = 0xc000000000000001ULL;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_q = 0U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sumsq_q = 0U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_max_q = 0xff800000U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_mean_q = 0U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_invstd_q = 0U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q 
                    = ((0x81U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q))
                        ? 1U : ((0x82U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q))
                                 ? 4U : ((0x84U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q))
                                          ? 6U : 0U)));
                if (((0x81U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                     & (3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_mode))) {
                    if (([&]() {
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2607__byte_lane 
                                    = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_valid_length_addr));
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2607__Vfuncout 
                                    = (4U < (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2607__byte_lane));
                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__crosses_beat__2607__Vfuncout))) {
                        __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2608__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_valid_length_addr);
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 4U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q 
                            = __Vtask_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fail_task__2608__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 3U;
                    }
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_key_length_q 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__length;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 5U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if (([&]() {
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__opcode 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q;
                        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__Vfuncout 
                            = (((((0x80U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__opcode)) 
                                  | (0x81U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__opcode))) 
                                 | (0x82U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__opcode))) 
                                | (0x84U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__opcode))) 
                               | (0x86U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__opcode)));
                    }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_known__2609__Vfuncout))) {
                if ((((1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_version)) 
                      | (4U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_type))) 
                     | (0x100U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_bytes)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if ((IData)((0U != (0xfffe0300U 
                                           & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__numeric_cfg)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if ((1U & ((((((((((((~ ([&]() {
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__function_value 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_mode;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__opcode 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__Vfuncout 
                                                                                = 
                                                                                ((0x80U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__opcode))
                                                                                 ? 
                                                                                (3U 
                                                                                >= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__function_value)
                                                                                 : 
                                                                                ((0x81U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__opcode))
                                                                                 ? 
                                                                                (4U 
                                                                                == __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__function_value)
                                                                                 : 
                                                                                ((0x82U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__opcode))
                                                                                 ? 
                                                                                ((5U 
                                                                                == __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__function_value) 
                                                                                | (6U 
                                                                                == __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__function_value))
                                                                                 : 
                                                                                ((0x84U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__opcode))
                                                                                 ? 
                                                                                ((7U 
                                                                                <= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__function_value) 
                                                                                & (9U 
                                                                                >= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__function_value))
                                                                                 : 
                                                                                ((0x86U 
                                                                                == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__opcode)) 
                                                                                && (0xcU 
                                                                                == __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__function_value))))));
                                                                            }(), (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_matches__2616__Vfuncout))) 
                                            | (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__approx_mode))) 
                                           | (2U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__overflow_mode))) 
                                          | (1U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__all_mask_mode))) 
                                         | (1U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stats_mode))) 
                                        | (3U < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_mode)) 
                                       | (0x1000U < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__scratch_request_elems)) 
                                      | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__zero_point_enable)) 
                                     | (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_zero_point)) 
                                    | (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_zero_point)) 
                                   | (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_zero_point)) 
                                  | (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_zero_point)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if (((((((((0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_base 
                                            >> 0x14U)) 
                                  | (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_base 
                                              >> 0x14U))) 
                                 | (((0x86U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                                     | (0x82U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q))) 
                                    & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_base 
                                                >> 0x14U)))) 
                                | (((0x82U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                                    & (5U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_mode)) 
                                   & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_base 
                                               >> 0x14U)))) 
                               | ((1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_mode) 
                                  & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_base 
                                              >> 0x14U)))) 
                              | ((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_mode) 
                                 & (0ULL != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_length_base 
                                             >> 0x14U)))) 
                             | (0ULL != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__aux0_addr_high)) 
                            | (0ULL != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__aux1_addr_high))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if ((((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__rows) 
                             | (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__length)) 
                            & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_length))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__rows) 
                             & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__length)) 
                            & ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_length) 
                               | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_length 
                                  > vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__length)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__rows) 
                             & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__length)) 
                            & (~ ((0x80U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                                  | (0x86U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if (((0x84U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                            & (2U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if (((0x84U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                            & (((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__scale_mode)) 
                                | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__internal_fp32_enable)) 
                               | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__saturate_enable) 
                                  != (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__overflow_mode)))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if (((0x84U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                            & ((((1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__scale_mode)) 
                                 | (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__internal_fp32_enable))) 
                                | (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__saturate_enable))) 
                               | (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__overflow_mode))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if (((0x84U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                            & ((((~ ([&]() {
                                                __Vfunc_fp32_finite_positive__2625__bits 
                                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_scale_bits;
                                                __Vfunc_fp32_finite_positive__2625__Vfuncout 
                                                    = 
                                                    (((0xffU 
                                                       != 
                                                       (0xffU 
                                                        & (__Vfunc_fp32_finite_positive__2625__bits 
                                                           >> 0x17U))) 
                                                      & (~ 
                                                         (__Vfunc_fp32_finite_positive__2625__bits 
                                                          >> 0x1fU))) 
                                                     & (0U 
                                                        != 
                                                        (0x7fffffffU 
                                                         & __Vfunc_fp32_finite_positive__2625__bits)));
                                            }(), (IData)(__Vfunc_fp32_finite_positive__2625__Vfuncout))) 
                                 | (~ ([&]() {
                                                __Vfunc_fp32_finite_positive__2626__bits 
                                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_scale_bits;
                                                __Vfunc_fp32_finite_positive__2626__Vfuncout 
                                                    = 
                                                    (((0xffU 
                                                       != 
                                                       (0xffU 
                                                        & (__Vfunc_fp32_finite_positive__2626__bits 
                                                           >> 0x17U))) 
                                                      & (~ 
                                                         (__Vfunc_fp32_finite_positive__2626__bits 
                                                          >> 0x1fU))) 
                                                     & (0U 
                                                        != 
                                                        (0x7fffffffU 
                                                         & __Vfunc_fp32_finite_positive__2626__bits)));
                                            }(), (IData)(__Vfunc_fp32_finite_positive__2626__Vfuncout)))) 
                                | (((0x86U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                                    | (0x82U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q))) 
                                   & (~ ([&]() {
                                                __Vfunc_fp32_finite_positive__2627__bits 
                                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_scale_bits;
                                                __Vfunc_fp32_finite_positive__2627__Vfuncout 
                                                    = 
                                                    (((0xffU 
                                                       != 
                                                       (0xffU 
                                                        & (__Vfunc_fp32_finite_positive__2627__bits 
                                                           >> 0x17U))) 
                                                      & (~ 
                                                         (__Vfunc_fp32_finite_positive__2627__bits 
                                                          >> 0x1fU))) 
                                                     & (0U 
                                                        != 
                                                        (0x7fffffffU 
                                                         & __Vfunc_fp32_finite_positive__2627__bits)));
                                            }(), (IData)(__Vfunc_fp32_finite_positive__2627__Vfuncout))))) 
                               | (((0x82U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                                   & (5U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_mode)) 
                                  & (~ ([&]() {
                                            __Vfunc_fp32_finite_positive__2628__bits 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_scale_bits;
                                            __Vfunc_fp32_finite_positive__2628__Vfuncout 
                                                = (
                                                   ((0xffU 
                                                     != 
                                                     (0xffU 
                                                      & (__Vfunc_fp32_finite_positive__2628__bits 
                                                         >> 0x17U))) 
                                                    & (~ 
                                                       (__Vfunc_fp32_finite_positive__2628__bits 
                                                        >> 0x1fU))) 
                                                   & (0U 
                                                      != 
                                                      (0x7fffffffU 
                                                       & __Vfunc_fp32_finite_positive__2628__bits)));
                                        }(), (IData)(__Vfunc_fp32_finite_positive__2628__Vfuncout))))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if (((0x82U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                            & (~ ([&]() {
                                    __Vfunc_fp32_finite_positive__2630__bits 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__epsilon_bits;
                                    __Vfunc_fp32_finite_positive__2630__Vfuncout 
                                        = (((0xffU 
                                             != (0xffU 
                                                 & (__Vfunc_fp32_finite_positive__2630__bits 
                                                    >> 0x17U))) 
                                            & (~ (__Vfunc_fp32_finite_positive__2630__bits 
                                                  >> 0x1fU))) 
                                           & (0U != 
                                              (0x7fffffffU 
                                               & __Vfunc_fp32_finite_positive__2630__bits)));
                                }(), (IData)(__Vfunc_fp32_finite_positive__2630__Vfuncout))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if (((0x82U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                            & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__epsilon_bits))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__input_clip_min_bits) 
                             | (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__input_clip_max_bits)) 
                            & (((~ ([&]() {
                                            __Vfunc_fp32_less_than__2633__rhs 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__input_clip_max_bits;
                                            __Vfunc_fp32_less_than__2633__lhs 
                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__input_clip_min_bits;
                                            {
                                                if (
                                                    ((([&]() {
                                                                    __Vfunc_fp32_is_nan__2634__bits 
                                                                        = __Vfunc_fp32_less_than__2633__lhs;
                                                                    __Vfunc_fp32_is_nan__2634__unused_sign = 0;
                                                                    __Vfunc_fp32_is_nan__2634__unused_sign 
                                                                        = 
                                                                        (__Vfunc_fp32_is_nan__2634__bits 
                                                                         >> 0x1fU);
                                                                    __Vfunc_fp32_is_nan__2634__Vfuncout 
                                                                        = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__2634__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__2634__bits))));
                                                                }(), (IData)(__Vfunc_fp32_is_nan__2634__Vfuncout)) 
                                                      | ([&]() {
                                                                    __Vfunc_fp32_is_nan__2635__bits 
                                                                        = __Vfunc_fp32_less_than__2633__rhs;
                                                                    __Vfunc_fp32_is_nan__2635__unused_sign = 0;
                                                                    __Vfunc_fp32_is_nan__2635__unused_sign 
                                                                        = 
                                                                        (__Vfunc_fp32_is_nan__2635__bits 
                                                                         >> 0x1fU);
                                                                    __Vfunc_fp32_is_nan__2635__Vfuncout 
                                                                        = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__2635__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__2635__bits))));
                                                                }(), (IData)(__Vfunc_fp32_is_nan__2635__Vfuncout))) 
                                                     | ([&]() {
                                                                __Vfunc_fp32_equal__2636__rhs 
                                                                    = __Vfunc_fp32_less_than__2633__rhs;
                                                                __Vfunc_fp32_equal__2636__lhs 
                                                                    = __Vfunc_fp32_less_than__2633__lhs;
                                                                {
                                                                    if (
                                                                        (([&]() {
                                                                                __Vfunc_fp32_is_nan__2637__bits 
                                                                                = __Vfunc_fp32_equal__2636__lhs;
                                                                                __Vfunc_fp32_is_nan__2637__unused_sign = 0;
                                                                                __Vfunc_fp32_is_nan__2637__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_nan__2637__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_nan__2637__Vfuncout 
                                                                                = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__2637__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__2637__bits))));
                                                                                }(), (IData)(__Vfunc_fp32_is_nan__2637__Vfuncout)) 
                                                                         | ([&]() {
                                                                                __Vfunc_fp32_is_nan__2638__bits 
                                                                                = __Vfunc_fp32_equal__2636__rhs;
                                                                                __Vfunc_fp32_is_nan__2638__unused_sign = 0;
                                                                                __Vfunc_fp32_is_nan__2638__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_nan__2638__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_nan__2638__Vfuncout 
                                                                                = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__2638__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__2638__bits))));
                                                                                }(), (IData)(__Vfunc_fp32_is_nan__2638__Vfuncout)))) {
                                                                        __Vfunc_fp32_equal__2636__Vfuncout = 0U;
                                                                        goto __Vlabel15;
                                                                    }
                                                                    if (
                                                                        (([&]() {
                                                                                __Vfunc_fp32_is_zero__2639__bits 
                                                                                = __Vfunc_fp32_equal__2636__lhs;
                                                                                __Vfunc_fp32_is_zero__2639__unused_sign = 0;
                                                                                __Vfunc_fp32_is_zero__2639__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_zero__2639__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_zero__2639__Vfuncout 
                                                                                = 
                                                                                (0U 
                                                                                == 
                                                                                (0x7fffffffU 
                                                                                & __Vfunc_fp32_is_zero__2639__bits));
                                                                                }(), (IData)(__Vfunc_fp32_is_zero__2639__Vfuncout)) 
                                                                         & ([&]() {
                                                                                __Vfunc_fp32_is_zero__2640__bits 
                                                                                = __Vfunc_fp32_equal__2636__rhs;
                                                                                __Vfunc_fp32_is_zero__2640__unused_sign = 0;
                                                                                __Vfunc_fp32_is_zero__2640__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_zero__2640__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_zero__2640__Vfuncout 
                                                                                = 
                                                                                (0U 
                                                                                == 
                                                                                (0x7fffffffU 
                                                                                & __Vfunc_fp32_is_zero__2640__bits));
                                                                                }(), (IData)(__Vfunc_fp32_is_zero__2640__Vfuncout)))) {
                                                                        __Vfunc_fp32_equal__2636__Vfuncout = 1U;
                                                                        goto __Vlabel15;
                                                                    }
                                                                    __Vfunc_fp32_equal__2636__Vfuncout 
                                                                        = 
                                                                        (__Vfunc_fp32_equal__2636__lhs 
                                                                         == __Vfunc_fp32_equal__2636__rhs);
                                                                    __Vlabel15: ;
                                                                }
                                                            }(), (IData)(__Vfunc_fp32_equal__2636__Vfuncout)))) {
                                                    __Vfunc_fp32_less_than__2633__Vfuncout = 0U;
                                                    goto __Vlabel14;
                                                }
                                                if (
                                                    ((__Vfunc_fp32_less_than__2633__lhs 
                                                      >> 0x1fU) 
                                                     != 
                                                     (__Vfunc_fp32_less_than__2633__rhs 
                                                      >> 0x1fU))) {
                                                    __Vfunc_fp32_less_than__2633__Vfuncout 
                                                        = 
                                                        (__Vfunc_fp32_less_than__2633__lhs 
                                                         >> 0x1fU);
                                                    goto __Vlabel14;
                                                }
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (__Vfunc_fp32_less_than__2633__lhs 
                                                         >> 0x1fU)))) {
                                                    __Vfunc_fp32_less_than__2633__Vfuncout 
                                                        = 
                                                        ((0x7fffffffU 
                                                          & __Vfunc_fp32_less_than__2633__lhs) 
                                                         < 
                                                         (0x7fffffffU 
                                                          & __Vfunc_fp32_less_than__2633__rhs));
                                                    goto __Vlabel14;
                                                }
                                                __Vfunc_fp32_less_than__2633__Vfuncout 
                                                    = 
                                                    ((0x7fffffffU 
                                                      & __Vfunc_fp32_less_than__2633__lhs) 
                                                     > 
                                                     (0x7fffffffU 
                                                      & __Vfunc_fp32_less_than__2633__rhs));
                                                __Vlabel14: ;
                                            }
                                        }(), (IData)(__Vfunc_fp32_less_than__2633__Vfuncout))) 
                                | ([&]() {
                                        __Vfunc_fp32_is_nan__2641__bits 
                                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__input_clip_min_bits;
                                        __Vfunc_fp32_is_nan__2641__Vfuncout 
                                            = (IData)(
                                                      ((0x7f800000U 
                                                        == 
                                                        (0x7f800000U 
                                                         & __Vfunc_fp32_is_nan__2641__bits)) 
                                                       & (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & __Vfunc_fp32_is_nan__2641__bits))));
                                    }(), (IData)(__Vfunc_fp32_is_nan__2641__Vfuncout))) 
                               | ([&]() {
                                    __Vfunc_fp32_is_nan__2642__bits 
                                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__input_clip_max_bits;
                                    __Vfunc_fp32_is_nan__2642__Vfuncout 
                                        = (IData)((
                                                   (0x7f800000U 
                                                    == 
                                                    (0x7f800000U 
                                                     & __Vfunc_fp32_is_nan__2642__bits)) 
                                                   & (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & __Vfunc_fp32_is_nan__2642__bits))));
                                }(), (IData)(__Vfunc_fp32_is_nan__2642__Vfuncout))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if (((0x81U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                            & (((1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_mode) 
                                & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_row_stride 
                                   < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__length)) 
                               | ((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_mode) 
                                  & ((4U > vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_length_stride) 
                                     | (0U != (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_length_stride))))))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if (((0x81U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                            & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_mode))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if ((((0x82U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                             & (6U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_mode)) 
                            & (0ULL != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_base))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else if (((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__rows) 
                            | (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__length))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
                } else {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 2U;
                }
            } else {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0x14U;
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__progress_q = 0ULL;
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_task_valid) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[1U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][1U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[2U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][2U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[3U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][3U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[4U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][4U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[5U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][5U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[6U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][6U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[7U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][7U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[8U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][8U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[9U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][9U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xaU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0xaU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xbU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0xbU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xcU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0xcU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xdU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0xdU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0xeU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xfU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0xfU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x10U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x10U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x11U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x11U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x12U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x12U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x13U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x13U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x14U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x14U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x15U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x15U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x16U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x16U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x17U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x17U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x18U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x18U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x19U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x19U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x1aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x1bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x1cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x1dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x1eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x1fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x20U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x20U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x21U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x21U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x22U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x22U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x23U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x23U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x24U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x24U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x25U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x25U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x26U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x26U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x27U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x27U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x28U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x28U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x29U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x29U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x2aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x2aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x2bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x2bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x2cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x2cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x2dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x2dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x2eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x2eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x2fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x2fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x30U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x30U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x31U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x31U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x32U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x32U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x33U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x33U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x34U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x34U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x35U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x35U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x36U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x36U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x37U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x37U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x38U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x38U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x39U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x39U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x3aU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x3aU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x3bU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x3bU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x3cU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x3cU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x3dU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x3dU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x3eU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x3eU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x3fU] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_desc_flat_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select][0x3fU];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select];
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 1U;
            }
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q = 0U;
        IData/*31:0*/ __Vilp5;
        __Vilp5 = 0U;
        while ((__Vilp5 <= 0x3fU)) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[__Vilp5] 
                = Vtb_npu_single_core__ConstPool__CONST_h6be9aa18_0[__Vilp5];
            __Vilp5 = ((IData)(1U) + __Vilp5);
        }
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_key_length_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_value_q = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_seen_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_value_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_value_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sum_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_sumsq_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_max_q = 0xc000000000000001ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sumsq_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_max_q = 0xff800000U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_mean_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_invstd_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__result_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__rmw_beat_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__status_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fault_addr_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__progress_q = 0ULL;
    }
}
