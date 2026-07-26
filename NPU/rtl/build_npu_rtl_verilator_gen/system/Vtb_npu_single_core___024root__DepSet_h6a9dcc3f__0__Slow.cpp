// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core___024root.h"

VL_ATTR_COLD void Vtb_npu_single_core___024root___eval_static(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_static\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_single_core__DOT__core_clk_i__0 
        = vlSelfRef.tb_npu_single_core__DOT__core_clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_single_core__DOT__reset_n__0 
        = vlSelfRef.tb_npu_single_core__DOT__reset_n;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_single_core__DOT__dut__DOT__functional_reset_n__0 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n;
}

VL_ATTR_COLD void Vtb_npu_single_core___024root___eval_final(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_final\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_single_core___024root___dump_triggers__stl(Vtb_npu_single_core___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_npu_single_core___024root___eval_phase__stl(Vtb_npu_single_core___024root* vlSelf);

VL_ATTR_COLD void Vtb_npu_single_core___024root___eval_settle(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_settle\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_npu_single_core___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_npu_single_core.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_npu_single_core___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_single_core___024root___dump_triggers__stl(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___dump_triggers__stl\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__0(Vtb_npu_single_core___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__1(Vtb_npu_single_core___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__2(Vtb_npu_single_core___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__3(Vtb_npu_single_core___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__4(Vtb_npu_single_core___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__5(Vtb_npu_single_core___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__6(Vtb_npu_single_core___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__7(Vtb_npu_single_core___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__8(Vtb_npu_single_core___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__9(Vtb_npu_single_core___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__10(Vtb_npu_single_core___024root* vlSelf);

VL_ATTR_COLD void Vtb_npu_single_core___024root___eval_stl(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_stl\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_npu_single_core___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_npu_single_core___024root___stl_sequent__TOP__1(vlSelf);
        Vtb_npu_single_core___024root___stl_sequent__TOP__2(vlSelf);
        Vtb_npu_single_core___024root___stl_sequent__TOP__3(vlSelf);
        Vtb_npu_single_core___024root___stl_sequent__TOP__4(vlSelf);
        Vtb_npu_single_core___024root___stl_sequent__TOP__5(vlSelf);
        Vtb_npu_single_core___024root___stl_sequent__TOP__6(vlSelf);
        Vtb_npu_single_core___024root___stl_sequent__TOP__7(vlSelf);
        Vtb_npu_single_core___024root___stl_sequent__TOP__8(vlSelf);
        Vtb_npu_single_core___024root___stl_sequent__TOP__9(vlSelf);
        Vtb_npu_single_core___024root___stl_sequent__TOP__10(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__0(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___stl_sequent__TOP__0\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr = 0;
    SData/*8:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock = 0;
    IData/*24:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr = 0;
    SData/*8:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock = 0;
    IData/*24:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr = 0;
    SData/*15:0*/ __Vfunc_npu_desc_bytes_for_engine__2108__Vfuncout;
    __Vfunc_npu_desc_bytes_for_engine__2108__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_npu_desc_bytes_for_engine__2108__engine;
    __Vfunc_npu_desc_bytes_for_engine__2108__engine = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__elem_stride;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__elem_stride = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_stride;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__bcast;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__bcast = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__start_nibble;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__start_nibble = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__elem_stride;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__elem_stride = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_stride;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__bcast;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__bcast = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__start_nibble;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__start_nibble = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__col;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row_stride;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__dtype = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__col_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__col_offset = 0;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_rsp_valid 
        = (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_dtype 
        = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU] 
                 >> 6U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_req_ready 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_rsp_valid 
        = (7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_ready 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_fetch_rsp_valid 
        = (4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[2U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[9U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[8U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_space 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_space 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                    >> 0x10U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_version 
        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0U]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_type 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0U] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_bytes 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0U] 
           >> 0x10U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__numeric_cfg 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rank 
        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__convert_mode 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
           >> 0x18U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__burst_beats_minus1 
        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__max_outstanding 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_nibble 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U] 
                 >> 0x18U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_packed[0U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x12U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_packed[1U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x13U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_packed[2U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x14U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_packed[3U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x15U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__shape_packed[4U] 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x16U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__fill_value 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x24U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__src_region_bytes 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x27U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x26U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__dst_region_bytes 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x29U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x28U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__segment_count 
        = (0xffffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2aU]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__segment_bytes 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2aU] 
           >> 0x10U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__segment_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2bU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__tbu_req_valid 
        = (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__tbu_rsp_ready 
        = (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_bready_o 
        = (6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_arvalid_o 
        = (3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_rready_o 
        = (4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__enqueue_now 
        = (4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[2U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_dtype 
        = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[5U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[4U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU] 
                 >> 2U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_n 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x11U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__transpose_b 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U] 
                 >> 1U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[9U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[8U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU] 
                 >> 6U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__src2_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[7U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[6U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_pack_format 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x24U] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_version 
        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0U]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_type 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0U] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_bytes 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0U] 
           >> 0x10U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xbU])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xaU])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xdU])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xcU])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__numeric_cfg 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__round_mode 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU] 
                 >> 0xaU));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_m 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x10U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_k 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x12U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_count 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x13U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__last_valid_m 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x14U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__last_valid_n 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x15U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__last_valid_k 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x16U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__matrix_flags 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_stride_bytes 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1bU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_pack_format 
        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x24U]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_pack_format 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x24U] 
                    >> 0x10U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__pack_version 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x24U] 
           >> 0x18U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__overflow_mode 
        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x25U]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__activation_mode 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x25U] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__output_zero_point 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x26U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_count 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x27U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_count 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x28U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_mode 
        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x29U]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__residual_mode 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x29U] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_entry_bytes 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x29U] 
                    >> 0x10U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_region_bytes 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2aU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__inline_requant 
        = (1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2cU]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__inline_requant_shift 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2cU] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_enable 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U] 
                 >> 2U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__residual_enable 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U] 
                 >> 3U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__relu_enable 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U] 
                 >> 4U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_enable 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U] 
                 >> 5U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__accum_from_src2 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U] 
                 >> 6U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__final_output 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U] 
                 >> 7U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__broadcast_mode 
        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[2U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_dtype 
        = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[5U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[4U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU] 
                 >> 2U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[7U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[6U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU] 
                 >> 4U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[9U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[8U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU] 
                 >> 6U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_nibble 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU] 
                 >> 0x10U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_version 
        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0U]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_type 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0U] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_bytes 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0U] 
           >> 0x10U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xbU])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xaU])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__numeric_cfg 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rows 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x10U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__length 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x11U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__valid_length 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x12U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__vector_flags 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x13U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar0 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1cU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__scalar1 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1dU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__compare_mode 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__overflow_mode 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU] 
                    >> 0x10U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_mode 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU] 
           >> 0x18U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_elem_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x24U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_row_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x25U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_enable 
        = (1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x13U]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_false_keep_dst 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x13U] 
                 >> 1U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_from_scalar0 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x13U] 
                 >> 2U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_from_scalar1 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x13U] 
                 >> 3U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[2U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_dtype 
        = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[5U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[4U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                 >> 2U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[7U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[6U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                 >> 4U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[9U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[8U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                 >> 6U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__input_clip_min_bits 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x25U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__input_clip_max_bits 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x26U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__rows 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x10U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_length 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x12U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__length 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x11U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__function_mode 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x13U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__epsilon_bits 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x24U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_version 
        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0U]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_type 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0U] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_bytes 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0U] 
           >> 0x10U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__aux0_addr_high 
        = (0xfffffffffffULL & (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xbU])) 
                                << 0xcU) | ((QData)((IData)(
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xaU])) 
                                            >> 0x14U)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__aux1_addr_high 
        = (0xfffffffffffULL & (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xdU])) 
                                << 0xcU) | ((QData)((IData)(
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xcU])) 
                                            >> 0x14U)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__numeric_cfg 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__saturate_enable 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                 >> 0xcU));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__scale_mode 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                 >> 0xdU));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__zero_point_enable 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                 >> 0xfU));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__internal_fp32_enable 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                 >> 0x10U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x19U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x18U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_row_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1aU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_mode 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1bU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_scale_bits 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1cU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_scale_bits 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1dU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_scale_bits 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1eU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_scale_bits 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1fU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_zero_point 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x20U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_zero_point 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x21U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_zero_point 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x22U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_zero_point 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x23U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__approx_mode 
        = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x27U]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__overflow_mode 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x27U] 
                    >> 8U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__all_mask_mode 
        = (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x27U] 
                    >> 0x10U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stats_mode 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x27U] 
           >> 0x18U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__scratch_request_elems 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x2cU];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_length_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x31U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x30U])));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__valid_length_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x32U];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_ready 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_valid_q)));
    vlSelfRef.__VdfgRegularize_h081c6435_0_0 = ((0U 
                                                 != 
                                                 (7U 
                                                  & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q))) 
                                                | (0x3ff8ULL 
                                                   < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_write = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__lookup_valid 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__lookup_sent_q)) 
           & (3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__tbu_req_ready 
        = (1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_valid_q)) 
                 | (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_high_nibble 
        = ((0U == (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU])) 
           & (((0U == (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU])) 
               | (3U == (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU])))
               ? (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q 
                  ^ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU])
               : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU]));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_high_nibble 
        = (IData)(((0U == (0xcU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU])) 
                   & (((0U == (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU] 
                                     >> 2U))) | (3U 
                                                 == 
                                                 (3U 
                                                  & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU] 
                                                     >> 2U))))
                       ? (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q 
                          ^ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU] 
                             >> 8U)) : (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU] 
                                        >> 8U))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_high_nibble 
        = (IData)(((0U == (0x30U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU])) 
                   & (((0U == (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU] 
                                     >> 4U))) | (3U 
                                                 == 
                                                 (3U 
                                                  & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU] 
                                                     >> 4U))))
                       ? (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q 
                          ^ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU] 
                             >> 0x18U)) : (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU] 
                                           >> 0x18U))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_high_nibble 
        = ((0U == (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU])) 
           & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_high_nibble 
        = (IData)(((0U == (0xcU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU])) 
                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_high_nibble 
        = (IData)(((0U == (0x30U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU])) 
                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__ctl_req_ready 
        = (1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_active_q) 
                    | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_rsp_valid_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_requested 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_soft_reset_req_q) 
           | (IData)(vlSelfRef.tb_npu_single_core__DOT__soft_reset_req_i));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_valid = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_addr = 0ULL;
    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error)))) {
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_addr 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_addr_q;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_terminal = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_wait_event_state = 0U;
    if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                         >> 8U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_data 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
            [1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_status 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
            [1U];
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_data 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_rdata_q;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_status 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__write_rsp_status 
        = ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                            >> 0x10U))) ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
           [1U] : (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_high_nibble 
        = ((0U == (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU])) 
           & ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U])
               ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q
               : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_rsp_ready 
        = (((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
            & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q))) 
           | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
              & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__mem_response_handshake 
        = (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q) 
            & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__owner_dma_q)) 
               & (7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)))) 
           & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT____VdfgRegularize_h29da96d0_0_0 
        = ((1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i)))) 
           & ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i)) 
                 & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__fifo_status_w 
        = (QData)((IData)(((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error) 
                             << 0x13U) | ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q)) 
                                          << 0x12U)) 
                           | (((0x10U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q)) 
                               << 0x11U) | ((((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
                                              & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q)) 
                                             << 0x10U) 
                                            | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q) 
                                                << 8U) 
                                               | (0xffU 
                                                  & ((IData)(0x10U) 
                                                     - (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q)))))))));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_arready_i 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_pending_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__reset_n) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_rvalid_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_bus_backpressure)) 
                    | (2U != (3U & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__derived_mask_valid 
        = ((0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1bU]) 
           | ((2U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1bU])
               ? ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x2eU] 
                   + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q) 
                  <= (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x2dU] 
                      + (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q 
                         * vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x2fU])))
               : ((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1bU])
                   ? (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q 
                      < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_key_length_q)
                   : (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_value_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_valid 
        = (((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
            & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_sent_q)) 
               & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)))) 
           | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_req_sent_q)) 
                 & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_mem_req_addr 
        = (0xffffffffffffULL & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_addr_q 
                                + (QData)((IData)(((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__beat_index_q) 
                                                   << 3U)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_status = 0U;
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_valid = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_status = 2U;
    } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_valid = 1U;
        vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_status_q;
        vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__Vfuncout 
            = ((4U & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                ? ((2U & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                    ? 2U : ((1U & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                             ? 2U : 5U)) : ((2U & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                                                 ? 6U
                                                 : 4U)
                                             : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                                                 ? 4U
                                                 : 0U)));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_status 
            = vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__Vfuncout;
    } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_valid = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_status = 2U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 0U;
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
        [0U]) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 0U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [1U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 1U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [2U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 2U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [3U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 3U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [4U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 4U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [5U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 5U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [6U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 6U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [7U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 7U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_rsp_ready = 0U;
    if ((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_rsp_ready = 1U;
        }
    }
    if (((7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q)) 
         | (9U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q)))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_rsp_ready = 1U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_write = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_write = 1U;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_write = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q) 
                  >> 4U)))) {
        if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_write = 1U;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_write = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_write = 1U;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o 
        = ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
           | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
              | (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))));
    if ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_write = 1U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_data 
        = ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q))
            ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem
           [([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__base 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_rptr_q;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__value 
                    = ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__base));
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__Vfuncout 
                    = (0xfU & vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__value);
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_ptr_add__1660__Vfuncout))]
            : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_mem
           [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_rptr_q]);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_write = 0U;
    if ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_write = 1U;
        }
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [0U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [0U]));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 0U;
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [1U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [1U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [0U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 0U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [2U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [2U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [1U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 1U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [3U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [3U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [2U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 2U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [4U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [4U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [4U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [3U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 3U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [5U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [5U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [5U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [4U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 4U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [6U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [6U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [6U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [5U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 5U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [7U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [7U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [7U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [6U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 6U;
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [7U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 7U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_csr_format_w 
        = ((((((0x20000U > vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i) 
               & (1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i))))) 
              & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i))) 
             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i))) 
            & (3U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i))) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low 
                    = (7U & vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size 
                    = vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__Vfuncout 
                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size) 
                                 >> 2U))) && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size))
                                                   ? 
                                                  (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low))
                                                   : 
                                                  (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low))))
                                               : ((1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size))) 
                                                  || (1U 
                                                      & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low))))));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ar_csr_format_w 
        = ((((((0x20000U > vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
               & (1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i))))) 
              & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i))) 
             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i))) 
            & (3U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i))) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low 
                    = (7U & vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size 
                    = vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__Vfuncout 
                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size) 
                                 >> 2U))) && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size))
                                                   ? 
                                                  (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low))
                                                   : 
                                                  (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low))))
                                               : ((1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size))) 
                                                  || (1U 
                                                      & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low))))));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__Vfuncout)));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_pop_w 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_pop_rsp_q) 
              & (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i)));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_awvalid_o 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_done_q)) 
           & (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_wvalid_o 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_done_q)) 
           & (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select = 0U;
    if ((1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
         [0U])) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select = 0U;
    }
    if (((1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [1U]) & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found)) 
                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select = 1U;
    }
    if (((1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [2U]) & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found)) 
                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select = 2U;
    }
    if (((1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [3U]) & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found)) 
                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select = 3U;
    }
    if (((1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [4U]) & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found)) 
                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select = 4U;
    }
    if (((1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [5U]) & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found)) 
                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select = 5U;
    }
    if (((1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [6U]) & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found)) 
                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select = 6U;
    }
    if (((1U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [7U]) & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found)) 
                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__fetch_select = 7U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_rsp_valid 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q) 
           & ((7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
              & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__owner_dma_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_valid 
        = ((2U <= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q)) 
           & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q)) 
              | (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_status_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_failure_seq_q;
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
          & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
             [0U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                       [0U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                       [0U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [0U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [0U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 1U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [1U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [1U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [1U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [1U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [1U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 2U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [2U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [2U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [2U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [2U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [2U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 3U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [3U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [3U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [3U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [3U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [3U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 4U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [4U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [4U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [4U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [4U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [4U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [4U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 5U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [5U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [5U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [5U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [5U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [5U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [5U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 6U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [6U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [6U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [6U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [6U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [6U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [6U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 7U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [7U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [7U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [7U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [7U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [7U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [7U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__m_axi_awready_i 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_valid_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__reset_n) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_bus_backpressure)) 
                    | (0U != (3U & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q))))));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_wready_i 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_valid_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__reset_n) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_bus_backpressure)) 
                    | (1U != (7U & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_cmd_format_w 
        = ((0x20000U == vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i) 
           & ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i)) 
              & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i)) 
                    & ((2U <= (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i)))) 
                       & ((~ ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i))) 
                          & (0x10U >= (0x1ffU & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i))))))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq = 0xffffffffffffffffULL;
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [0U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [0U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [0U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (1U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [1U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [1U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [1U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (2U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [2U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [2U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [2U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (4U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [3U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [3U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [3U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (8U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [4U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [4U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [4U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [4U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [4U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (0x10U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [5U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [5U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [5U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [5U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [5U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (0x20U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [6U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [6U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [6U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [6U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [6U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (0x40U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [7U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [7U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [7U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [7U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [7U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (0x80U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_quiesce 
        = ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)) 
           | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q) 
              | (IData)(vlSelfRef.tb_npu_single_core__DOT__power_down_req_i)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_pulse)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q) 
              >> 1U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_addr 
        = (0xffffffffffffULL & ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xbU])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xaU]))) 
                                + (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__row_q)) 
                                    * (QData)((IData)(
                                                      vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x25U]))) 
                                   + ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q)) 
                                      * (QData)((IData)(
                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x24U]))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_valid_length_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x31U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x30U]))) 
           + ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q)) 
              * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x32U]))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xbU])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xaU]))) 
           + ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q)) 
              * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1bU]))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_addr 
        = (0xffffffffffffULL & ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xdU])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xcU]))) 
                                + ((2U == (0xffU & 
                                           vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x29U]))
                                    ? ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q)) 
                                       << 3U) : 0ULL)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_addr 
        = (0xffffffffffffULL & ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x19U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x18U]))) 
                                + (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q)) 
                                    * (QData)((IData)(
                                                      vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1aU]))) 
                                   + (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q)))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats 
        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i)));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr 
        = (0x1ffffffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr 
                         + (((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats) 
                             - (IData)(1U)) << (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout 
        = ((((((((~ (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock)) 
                 & (1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst))) 
                & (3U >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size))) 
               & ([&]() {
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low 
                                    = (7U & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr);
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size 
                                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size;
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__Vfuncout 
                                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size) 
                                                 >> 2U))) 
                                       && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size))
                                                ? (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low))
                                                : (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low))))
                                            : ((1U 
                                                & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size))) 
                                               || (1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low))))));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__Vfuncout))) 
              & ((1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats)) 
                 | (3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size)))) 
             & (0x100000U <= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr)) 
            & (0x1fffffU >= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr)) 
           & ((0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr 
                         >> 0xcU)) == (0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr 
                                                 >> 0xcU))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_l1_format_w 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats 
        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i)));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr 
        = (0x1ffffffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr 
                         + (((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats) 
                             - (IData)(1U)) << (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout 
        = ((((((((~ (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock)) 
                 & (1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst))) 
                & (3U >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size))) 
               & ([&]() {
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low 
                                    = (7U & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr);
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size 
                                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size;
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__Vfuncout 
                                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size) 
                                                 >> 2U))) 
                                       && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size))
                                                ? (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low))
                                                : (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low))))
                                            : ((1U 
                                                & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size))) 
                                               || (1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low))))));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__Vfuncout))) 
              & ((1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats)) 
                 | (3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size)))) 
             & (0x100000U <= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr)) 
            & (0x1fffffU >= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr)) 
           & ((0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr 
                         >> 0xcU)) == (0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr 
                                                 >> 0xcU))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ar_l1_format_w 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_last_expected_w 
        = ((0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q))) 
           == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_beats_q));
    __Vfunc_npu_desc_bytes_for_engine__2108__engine 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__engine_q;
    __Vfunc_npu_desc_bytes_for_engine__2108__Vfuncout 
        = ((8U & (IData)(__Vfunc_npu_desc_bytes_for_engine__2108__engine))
            ? 0U : ((4U & (IData)(__Vfunc_npu_desc_bytes_for_engine__2108__engine))
                     ? ((2U & (IData)(__Vfunc_npu_desc_bytes_for_engine__2108__engine))
                         ? 0U : ((1U & (IData)(__Vfunc_npu_desc_bytes_for_engine__2108__engine))
                                  ? 0U : 0x100U)) : 
                    ((2U & (IData)(__Vfunc_npu_desc_bytes_for_engine__2108__engine))
                      ? ((1U & (IData)(__Vfunc_npu_desc_bytes_for_engine__2108__engine))
                          ? 0xc0U : 0x100U) : ((1U 
                                                & (IData)(__Vfunc_npu_desc_bytes_for_engine__2108__engine))
                                                ? 0x100U
                                                : 0x40U))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__expected_desc_bytes 
        = __Vfunc_npu_desc_bytes_for_engine__2108__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_high_nibble 
        = (IData)(((0U == (0xc0U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU])) 
                   & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_high_nibble 
        = (IData)(((0U == (0xc0U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU])) 
                   & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q 
                      ^ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU] 
                         >> 0x10U))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__src2_addr 
        = (((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[7U])) 
              << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[6U]))) 
            + ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_q)) 
               * (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x23U])) 
                   << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x22U]))))) 
           + ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2195__row_stride 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1aU];
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2195__col 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2195__row 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2195__element_offset 
                    = VL_SHIFTL_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2195__col)), 2U);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2195__Vfuncout 
                    = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2195__row)) 
                        * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2195__row_stride))) 
                       + vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2195__element_offset);
            }(), vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2195__Vfuncout));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_high_nibble 
        = (IData)((((0U == (0xc0U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU])) 
                    & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q) 
                   & (7U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))));
    if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr 
            = (0xfff8U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_addr_q);
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_space 
            = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_addr_q 
                     >> 0x10U));
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr 
            = (0xfff8U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q);
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_space 
            = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q 
                     >> 0x10U));
    }
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__dtype 
        = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU]);
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x14U];
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__col 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[2U])));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row_offset 
        = ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row)) 
           * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row_stride)));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__col_offset 
        = ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__dtype))
            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__col)), 1U)
            : ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__col)) 
               * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__2336__dtype 
                            = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__2336__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2336__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2336__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2336__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2336__Vfuncout)))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__Vfuncout 
        = ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__base 
            + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__row_offset) 
           + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__col_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_addr 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2335__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__start_nibble 
        = (1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU]);
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__dtype 
        = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU]);
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__bcast 
        = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU]);
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x15U];
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__elem_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x14U];
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__row_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[2U])));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_offset = 0ULL;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col_offset = 0ULL;
    if ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__bcast))) {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_offset 
            = ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row)) 
               * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_stride)));
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col_offset 
            = ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col)) 
                                           + (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__start_nibble))), 1U)
                : ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col)) 
                   * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__elem_stride))));
    } else if ((1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__bcast))) {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_offset = 0ULL;
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col_offset = 0ULL;
    } else if ((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__bcast))) {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_offset 
            = ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row)) 
               * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_stride)));
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col_offset = 0ULL;
    } else {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_offset = 0ULL;
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col_offset 
            = ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col)) 
                                           + (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__start_nibble))), 1U)
                : ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col)) 
                   * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__elem_stride))));
    }
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__Vfuncout 
        = ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__base 
            + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__row_offset) 
           + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__col_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_addr 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2266__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__start_nibble 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU] 
                 >> 8U));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU] 
                 >> 2U));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__bcast 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU] 
                 >> 2U));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x17U];
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__elem_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x16U];
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__row_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[5U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[4U])));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_offset = 0ULL;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col_offset = 0ULL;
    if ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__bcast))) {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_offset 
            = ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row)) 
               * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_stride)));
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col_offset 
            = ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col)) 
                                           + (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__start_nibble))), 1U)
                : ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col)) 
                   * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__elem_stride))));
    } else if ((1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__bcast))) {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_offset = 0ULL;
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col_offset = 0ULL;
    } else if ((2U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__bcast))) {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_offset 
            = ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row)) 
               * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_stride)));
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col_offset = 0ULL;
    } else {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_offset = 0ULL;
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col_offset 
            = ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col)) 
                                           + (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__start_nibble))), 1U)
                : ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col)) 
                   * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__elem_stride))));
    }
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__Vfuncout 
        = ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__base 
            + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__row_offset) 
           + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__col_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_addr 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2267__Vfuncout;
    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__start_nibble 
        = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU] 
                 >> 0x18U));
    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU] 
                 >> 4U));
    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__bcast 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1eU] 
                 >> 4U));
    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x19U];
    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__elem_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x18U];
    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q;
    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__row_q;
}

VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__1(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___stl_sequent__TOP__1\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__base = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col_offset = 0;
    // Body
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[7U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[6U])));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_offset = 0ULL;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col_offset = 0ULL;
    if ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__bcast))) {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_offset 
            = ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row)) 
               * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_stride)));
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col_offset 
            = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col)) 
                                           + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__start_nibble))), 1U)
                : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col)) 
                   * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__elem_stride))));
    } else if ((1U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__bcast))) {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_offset = 0ULL;
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col_offset = 0ULL;
    } else if ((2U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__bcast))) {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_offset 
            = ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row)) 
               * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_stride)));
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col_offset = 0ULL;
    } else {
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_offset = 0ULL;
        __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col_offset 
            = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col)) 
                                           + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__start_nibble))), 1U)
                : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col)) 
                   * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__elem_stride))));
    }
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__Vfuncout 
        = ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__base 
            + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__row_offset) 
           + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__col_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_addr 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__tensor_addr__2268__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_idle 
        = ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)) 
           & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[0U] 
        = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[1U] 
        = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[2U] 
        = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_cmd[3U] 
        = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_addr 
        = (((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[3U])) 
              << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[2U]))) 
            + ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_q)) 
               * (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1dU])) 
                   << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1cU]))))) 
           + ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U])
               ? ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__dtype 
                        = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU]);
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__row_stride 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x18U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__col 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q;
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__row 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q;
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__element_offset 
                        = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__dtype))
                            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__col)), 1U)
                            : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__col)) 
                               * VL_EXTEND_QI(64,3, 
                                              ([&]() {
                                        vlSelfRef.__Vfunc_dtype_bytes__2184__dtype 
                                            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__dtype;
                                        vlSelfRef.__Vfunc_dtype_bytes__2184__Vfuncout 
                                            = ((1U 
                                                == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2184__dtype))
                                                ? 1U
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2184__dtype))
                                                    ? 4U
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2184__dtype))
                                                     ? 2U
                                                     : 0U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2184__Vfuncout)))));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__Vfuncout 
                        = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__row)) 
                            * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__row_stride))) 
                           + vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__element_offset);
                }(), vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2183__Vfuncout)
               : ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__dtype 
                        = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU]);
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__row_stride 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x18U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__col 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q;
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__row 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q;
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__element_offset 
                        = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__dtype))
                            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__col)), 1U)
                            : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__col)) 
                               * VL_EXTEND_QI(64,3, 
                                              ([&]() {
                                        vlSelfRef.__Vfunc_dtype_bytes__2186__dtype 
                                            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__dtype;
                                        vlSelfRef.__Vfunc_dtype_bytes__2186__Vfuncout 
                                            = ((1U 
                                                == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2186__dtype))
                                                ? 1U
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2186__dtype))
                                                    ? 4U
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2186__dtype))
                                                     ? 2U
                                                     : 0U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2186__Vfuncout)))));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__Vfuncout 
                        = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__row)) 
                            * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__row_stride))) 
                           + vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__element_offset);
                }(), vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2185__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__accept_new_cmd_o 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__start_q) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__power_down_req_i)) 
                 & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)))));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_rsp_ready = 0U;
    if ((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_rsp_ready = 1U;
        }
    }
    if (((7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q)) 
         | (9U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q)))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_rsp_ready = 1U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__fe_l1_rsp_ready 
        = (((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
            & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q))) 
           | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
              & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q) 
                  >> 4U)))) {
        if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
                    }
                } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
                    }
                } else {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
            }
        } else {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
            }
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_valid = 0U;
    if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_valid = 1U;
        }
    }
    if ((6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_valid = 1U;
        }
    }
    if ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_valid = 1U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
                    }
                } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
                }
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
                }
            }
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2cU]))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
            }
        } else {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
            }
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
            }
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__fe_l1_req_valid 
        = (((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
            & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_sent_q)) 
               & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)))) 
           | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_req_sent_q)) 
                 & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[9U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[8U]))) 
           + (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__row_q)) 
               * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1bU]))) 
              + ((0U == (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU] 
                               >> 6U))) ? VL_SHIFTR_QQI(64,64,32, 
                                                        ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q)) 
                                                         + (QData)((IData)(
                                                                           (1U 
                                                                            & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1fU] 
                                                                               >> 0x10U))))), 1U)
                  : ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__col_q)) 
                     * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0x1aU]))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_dst_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[9U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[8U]))) 
           + ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q)) 
              * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x17U]))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr 
        = (((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[9U])) 
              << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[8U]))) 
            + ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_q)) 
               * (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x21U])) 
                   << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x20U]))))) 
           + ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__dtype 
                    = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU] 
                             >> 6U));
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__row_stride 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1aU];
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__col 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__row 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_q;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__element_offset 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__dtype))
                        ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__col)), 1U)
                        : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__col)) 
                           * VL_EXTEND_QI(64,3, ([&]() {
                                    vlSelfRef.__Vfunc_dtype_bytes__2194__dtype 
                                        = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__dtype;
                                    vlSelfRef.__Vfunc_dtype_bytes__2194__Vfuncout 
                                        = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2194__dtype))
                                            ? 1U : 
                                           ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2194__dtype))
                                             ? 4U : 
                                            ((3U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2194__dtype))
                                              ? 2U : 0U)));
                                }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2194__Vfuncout)))));
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__Vfuncout 
                    = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__row)) 
                        * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__row_stride))) 
                       + vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__element_offset);
            }(), vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2193__Vfuncout));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[0U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel0;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel0;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel0: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel1;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel1: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[0U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel2;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel2;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel2: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel3;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel3: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [0U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [0U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[1U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel4;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel4;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel4: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel5;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel5;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel5: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[1U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel6;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel6;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel6: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel7;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel7;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel7: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [1U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [1U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[2U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel8;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel8;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel8: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel9;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel9;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel9: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[2U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel10;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel10;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel10: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel11;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel11;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel11: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [2U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [2U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[3U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel12;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel12;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel12: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel13;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel13;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel13: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[3U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel14;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel14;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel14: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel15;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel15;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel15: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [3U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [3U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[4U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel16;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel16;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel16: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel17;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel17;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel17: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
}
